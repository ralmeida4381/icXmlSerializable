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
#ifndef ICXMLSERIALIZABLE_H
#define ICXMLSERIALIZABLE_H

#include <QtCore>
#include <QtXml>

/**
	@author Roberto Almeida <ralmeida@ingenieriacreativa.com>
*/
class icXmlSerializable : public QObject {
    Q_OBJECT
public:
    icXmlSerializable(QObject *parent = 0);
    virtual ~icXmlSerializable();

    QString                     serializeMetaComponent(const QString& metaComponentName);
    bool                        deserializeMetaComponent(const QString& metaComponentName);

    void                        setMetaContent(const QString& theValue);
    QString                     metaContent() const;
    QString                     metaComponent();
    
    QVariant			 getSerialProperty(const QString& propertyName);
    QString			 getStringProperty(const QString& propertyName);
    bool                        getSerialObject(const QString& objectName, icXmlSerializable *object);
    bool			 getSerialObject(const QString& objectName, icXmlSerializable *object, int index);
    int				 getSerialObjectCount(const QString& objectName);
    QHash< QString, QString >   serialObjects() const;
    QHash< QString, QString >   serialProperties() const;
    void 			 setMetaID(const QString& theValue);
    QString 			 metaID() const;

    void 			 setSerialId(const QString&	theValue);
    QString			 serialId() const;
	
    QString			 encode(const QString content);
    QString			 decode(const QString content);
	    	    
protected:

    virtual bool 		deserialize() = 0;
    virtual bool		serialize() = 0;
    void			setSerialProperty(const QString& property, int value);
    void			setSerialProperty(const QString& property, long value);
    void			setSerialProperty(const QString& property, bool value);
    void			setSerialProperty(const QString& property, const QString& value);
    void			setSerialProperty(const QString& property, float value);
    void			setSerialProperty(const QString& property, double value);
    void			setSerialProperty(const QString& property, QDateTime value);
    void			setSerialObject(const QString& property, icXmlSerializable	*);
    void			setSerialObject(const QString& property, QVector<icXmlSerializable	*> vector);
    void			setSerialObject(const QString& property, QList<icXmlSerializable	*> list);
    void			setSerialObject(const QString& property, QHash<QString, icXmlSerializable	*> hash);
    
    	
private:
		
	enum	META_TYPE {
		META_TYPE_OBJECT,
		META_TYPE_VECTOR,
		META_TYPE_LIST,
		META_TYPE_HASH
	};
		
	static	QString		META_TAG_PREFIX()	{ return "meta_";};			//meta_
	static	QString		META_TAG_KEY()		{ return "meta_key";};		//meta_key
	static	QString		META_TAG_INDEX() 	{ return "meta_index";};	//meta_index
	static	QString		META_TAG_SIZE() 	{ return "meta_size";};		//meta_size
	static	QString		META_TAG_TYPE() 	{ return "meta_type";};		//meta_type
	static	QString		META_TAG_OBJECT() 	{ return "object";};		
	static	QString		META_TAG_VECTOR() 	{ return "vector";};
	static	QString		META_TAG_LIST() 	{ return "list";};
	static	QString		META_TAG_HASH() 	{ return "hash";};
			
    void				addBuffer(const 	QString& buffer);
    QString				buffer();
    QStringList				extractSegments(const QString& content);
    
    QString                            fillSpaces(const QString& value);
    QString				m_content;
    QString				m_component;
    QStringList				m_properties;
    QStringList				m_contentItems;
    QStringList				m_subItems;
    QHash<QString, QString>		m_elements;
    QHash<QString, QString>		m_serialObjects;
    QHash<QString, QString>		m_serialProperties;
    QString				m_metaID;
    QString				m_serialId;
};


#endif
