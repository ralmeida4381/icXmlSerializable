/***************************************************************************
 *   Copyright (C) 2007 by Roberto Almeida   *
 *   ralmeida@ingenieriacreativa.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "icxmlserializable.h"

#include <QDomDocument>
#include <QDomElement>

icXmlSerializable::icXmlSerializable(QObject *parent)
: QObject(parent) {
    m_component = "";
    m_serialId = "";
}

icXmlSerializable::~icXmlSerializable() {
}

void icXmlSerializable::addBuffer(const QString & buffer) {
    m_properties.append(buffer);
}


QString icXmlSerializable::serializeMetaComponent(const QString& pMetaComponent) {

    QString lbuffer;
    QString	body;
    QString                 metaComponent = fillSpaces(pMetaComponent);
	
// 	setSerialProperty("icXmlSerializable-serialId", m_serialId );
	m_contentItems.clear();
	m_properties.clear();
	
	serialize();
	
    
    if (m_contentItems.size() > 0)
        body = m_contentItems.join(" ");
    else
        body = "";

    if (body.size() > 0)
        lbuffer = "<" + metaComponent + buffer() +">" + body.trimmed() + "</" + metaComponent + ">";
    else
        lbuffer = "<" + metaComponent + buffer() + " />";

    return lbuffer;

}


void icXmlSerializable::setSerialProperty(const QString & pProperty, int value) {
    QString                 property = fillSpaces(pProperty);
    QString buffer = property + "=\"" + QString::number(value) + "\"";
    addBuffer(buffer);
}

void icXmlSerializable::setSerialProperty(const QString & pProperty, long value) {
    QString                 property = fillSpaces(pProperty);
    QString buffer = property + "=\"" + QString::number(value) + "\"";
    addBuffer(buffer);
}

void icXmlSerializable::setSerialProperty(const QString & pProperty, bool value) {
    QString                 property = fillSpaces(pProperty);

    QString buffer;
    if (value)
        buffer = property + "=\"true\"";
    else
        buffer = property + "=\"false\"";

    addBuffer(buffer);
}

void icXmlSerializable::setSerialProperty(const QString & pProperty, const QString & value) {
    QString                 property = fillSpaces(pProperty);
	QString dummy = value;
    
	dummy = encode(value);
    
    QString buffer = property + "=\"" + dummy.trimmed() + "\"";
    addBuffer(buffer);
}

void icXmlSerializable::setSerialProperty(const QString & pProperty, QDateTime value) {
    QString                 property = fillSpaces(pProperty);
    QString buffer = property + "=\"" + value.toString(Qt::ISODate) + "\"";
    addBuffer(buffer);
}

void icXmlSerializable::setSerialProperty(const QString & pProperty, float value) {
    QString                 property = fillSpaces(pProperty);
    QString buffer = property + "=\"" + QString::number(value) + "\"";
    addBuffer(buffer);
}

void icXmlSerializable::setSerialProperty(const QString & pProperty, double value) {
    QString                 property = fillSpaces(pProperty);
    QString buffer = property + "=\"" + QString::number(value) + "\"";
    addBuffer(buffer);
}


void icXmlSerializable::setSerialObject(const QString& pProperty, icXmlSerializable *item)
{
    QString		content;
    QString                 property = fillSpaces(pProperty);
    if (item !=0) {
        content = item->serializeMetaComponent(property);
        m_contentItems.append(content);
    }	
}

void icXmlSerializable::setSerialObject(const QString & pProperty, QVector< icXmlSerializable * > vector)
{
	QString			buf;
	QString			dummy;
	icXmlSerializable	*item;
	int		index;
        QString                 property = fillSpaces(pProperty);

	buf = "<" + property + ">";
	for (index=0; index < vector.size(); index++) {
		item = vector.at(index); 
		if (item != 0)
			buf += item->serializeMetaComponent("it_" + property); 
	}
	buf +=  "</" + property + ">";
	
	m_contentItems.append(buf);
}

void icXmlSerializable::setSerialObject(const QString & pProperty, QList< icXmlSerializable * > list)
{
	QString			buf;
	QString			dummy;
	icXmlSerializable	*item;
        QString                 property = fillSpaces(pProperty);
	int		index;
		
	buf = "<" + property + ">";
	for (index=0; index < list.size(); index++) {
		item = list.at(index); 
		if (item != 0)
			buf += item->serializeMetaComponent("it_" + property); 
	}
	buf +=  "</" + property + ">";
	
	m_contentItems.append(buf);
}

void icXmlSerializable::setSerialObject(const QString & pProperty, QHash< QString, icXmlSerializable * > hash)
{
	QString			buf;
	QString			dummy;
	icXmlSerializable	*item;
        QString                 property = fillSpaces(pProperty);
		
        buf = "<" + property + ">";
	QHashIterator<QString, icXmlSerializable *> i(hash);
	while (i.hasNext()) {
		i.next();
		item = i.value();
		if (item != 0)
                        buf += item->serializeMetaComponent("it_" + property);
	}
	buf +=  "</" + property + ">";
	
	m_contentItems.append(buf);
}

QString		icXmlSerializable::buffer() {
    QString	buff;
    int		index;

    buff = "";
    for (index=0; index < m_properties.size(); index++) {
        buff += " " + m_properties.at(index);
    }

    return buff;
}



QString icXmlSerializable::metaContent() const {
    return m_content;
}


void icXmlSerializable::setMetaContent(const QString& theValue) {
    m_content = theValue;
}


bool	icXmlSerializable::deserializeMetaComponent(const QString& metaComponentName) {
    QDomDocument	doc;
    int				index;
    QDomNamedNodeMap map;
    QDomElement 	element;
    QString			subcontent;
    QStringList		elementSubcontent;
    QDomNode 		nodemap;
    QString			fieldcontent;
	bool			res;
	
    fieldcontent = m_content;
	res = false;
	
    QString errMsg;
    int     errLine;
    int     errColumn;

    if (!doc.setContent(fieldcontent, false, &errMsg, &errLine, &errColumn)) {
        qDebug() << "ERROR ("<<errLine << "," << errColumn << "): " << errMsg;
        return res;
    }

    QDomElement docElement = doc.documentElement();
	if (metaComponentName != docElement.nodeName()) {
		qDebug() << "xml: field " << metaComponentName << " missing";
		return res;
	}
	
	//Extraemos las propiedades del objeto
    map = docElement.attributes();
    for (index=0; index < map.count(); index++) {
        nodemap = map.item(index);
        if (META_TAG_PREFIX() != nodemap.nodeName().left(5)) {
        	m_serialProperties.insert(nodemap.nodeName(), nodemap.nodeValue());
        }
    }

	//Extraemos los elementos hijos del objeto 
    QDomNode node = doc.documentElement().firstChild();
    while (! node.isNull()) {
    	subcontent = "";
        element = node.toElement();
		QTextStream text(&subcontent);
		element.save(text,1);
			
		m_serialObjects.insert(node.nodeName(), subcontent);
		
		node = node.nextSibling();
    }    
    
    res = deserialize();
    
//     m_serialId = getSerialProperty("icXmlSerializable-serialId").toString();
    
    m_subItems.clear();
    m_properties.clear();
    m_elements.clear();
    m_serialProperties.clear();
    m_serialObjects.clear();

    return res;
}

QVariant icXmlSerializable::getSerialProperty(const QString & propertyName)
{
	QString 	sprop = m_serialProperties.value(propertyName);
	QVariant 	property(sprop);
	
	return property;
}

bool icXmlSerializable::getSerialObject(const QString & objectName, icXmlSerializable * object)
{
	QString 	sobj = m_serialObjects.value(objectName);
	object->setMetaContent(sobj);
	return object->deserializeMetaComponent(objectName);	
}

bool icXmlSerializable::getSerialObject(const QString & objectName, icXmlSerializable * object, int index)
{
	if ((index < 0) || (index >= m_subItems.size())) 
		return false;
		
	QString	sobj = m_subItems.at(index);
	object->setMetaContent(sobj);
	bool	res = object->deserializeMetaComponent("it_" + objectName);
	return res;
}


int icXmlSerializable::getSerialObjectCount(const QString & objectName)
{
    QDomDocument	doc;
    QDomElement 	element;
    QString			subcontent;
	QString			objectArray;
		
	m_subItems.clear();
    if (!doc.setContent( m_serialObjects.value(objectName))) {
    	qDebug() << "xml: field " << objectName << " bad content";
        return 0;
	}

    QDomElement docElement = doc.documentElement();
	if (objectName != docElement.nodeName()) {
		qDebug() << "xml: field " << objectName << " missing";
		return 0;
	}
	
	//Extraemos los elementos hijos del objeto 
    QDomNode node = doc.documentElement().firstChild();
    while (! node.isNull()) {
    	subcontent = "";
        element = node.toElement();
		QTextStream text(&subcontent);
		element.save(text,1);
			
		m_subItems.append(subcontent);
		node = node.nextSibling();
    }    

// 	qDebug() << "xml childs count: " << m_subItems.size();
	return m_subItems.size();
}

QHash< QString, QString > icXmlSerializable::serialObjects() const
{
	return m_serialObjects;
}


QHash< QString, QString > icXmlSerializable::serialProperties() const
{
	return m_serialProperties;
}

QString icXmlSerializable::metaComponent()
{
    QDomDocument	doc;

    if (!doc.setContent(m_content))
        return "";

    QDomElement docElement = doc.documentElement();
	return docElement.nodeName();
}



QString icXmlSerializable::metaID() const {
    return m_metaID;
}


void icXmlSerializable::setMetaID(const QString& theValue) {
    m_metaID = theValue;
}


QString icXmlSerializable::serialId() const {
    return m_serialId;
}


void icXmlSerializable::setSerialId(const QString& theValue) {
    m_serialId = theValue;
}


QString icXmlSerializable::encode(const QString content)
{
	QString buffer = content;

	buffer.replace(QChar('"'), "&quot;");
	buffer.replace(QChar('<'), "&lt;");
	buffer.replace(QChar('>'), "&gt;");
	buffer.replace(QChar('\''), "&apos;");
	buffer.replace(QChar('/'), "&#047;");
	buffer.replace(QChar(0x0A), "+00A+");
	buffer.replace(QChar(0x13), "+013+");
	buffer.replace(QChar(0x10), "+010+");
	buffer.replace("“", "&ldquo;");
	buffer.replace("”", "&rdquo;");
	buffer.replace(QChar('{'), "&#123;");
	buffer.replace(QChar('}'), "&#125;");
	buffer.replace(QChar('['), "&#091;");
	buffer.replace(QChar(']'), "&#093;");
	
	return buffer;
}

QString icXmlSerializable::decode(const QString content)
{
	QString buffer = content;

	buffer.replace("&quot;", 	QChar('"'));
	buffer.replace("&lt;",		QChar('<'));
	buffer.replace("&gt;",		QChar('>'));
	buffer.replace("&apos;",	QChar('\''));
	buffer.replace("&#047;",	QChar('/'));
	buffer.replace("+013+",	QChar(0x13));
	buffer.replace("+010+",	QChar(0x10));
	buffer.replace("&ldquo;",	"“");
	buffer.replace("&rdquo;",	"”");
	buffer.replace("+00A+",	QChar(0x0A));
	buffer.replace("&#123;",	QChar('{'));
	buffer.replace("&#125;",	QChar('}'));
	buffer.replace("&#091;",	QChar('['));
	buffer.replace("&#093;",	QChar(']'));
	
	return buffer;
}

QString icXmlSerializable::getStringProperty(const QString & propertyName)
{
	QString value = getSerialProperty(propertyName).toString();	
	return decode(value);
}

QString icXmlSerializable::fillSpaces(const QString &value) {
    QString newValue = value;
    newValue.replace(" ","_");
    return newValue;
}
