#ifndef MUSICABSTRACTXML_H
#define MUSICABSTRACTXML_H

/* =================================================
 * This file is part of the TTK Music Player project
 * Copyright (c) 2015 - 2017 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include <QtXml/QDomDocument>
#include <QTextStream>
#include <QFile>

#include "musicglobaldefine.h"
#include "musicsong.h"
#include "musicobject.h"

/*! @brief The class of the xml attribute.
 * @author Greedysky <greedysky@163.com>
 */
typedef struct MUSIC_CORE_EXPORT MusicXmlAttribute
{
    QString m_key;
    QVariant m_value;

    MusicXmlAttribute(const QString &key, const QVariant &value)
    {
        m_key = key;
        m_value = value;
    }
}MusicXmlAttribute;
MUSIC_DECLARE_LISTS(MusicXmlAttribute)

/*! @brief The class of the base class of xml interface.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_CORE_EXPORT MusicAbstractXml : public QObject
{
    Q_OBJECT
public:
    /*!
     * Object contsructor.
     */
    explicit MusicAbstractXml(QObject *parent = 0);

    ~MusicAbstractXml();

    /*!
     * Get class object name.
     */
    static QString getClassName();

    /*!
     * Read datas from xml file by given name.
     */
    bool readConfig(const QString &name);
    /*!
     * Write datas into xml file by given name.
     */
    bool writeConfig(const QString &name);

    /*!
     * Xml stream data from string.
     */
    bool fromString(const QString &data);
    /*!
     * Xml stream data from byteArray.
     */
    bool fromByteArray(const QByteArray &data);
    /*!
     * Xml stream data to string.
     */
    QString toString() const;
    /*!
     * Xml stream data to byteArray.
     */
    QByteArray toByteArray() const;

    /*!
     * Read xml attribute by tagName and default name "value".
     */
    QString readXmlAttributeByTagNameValue(const QString &tagName) const;
    /*!
     * Read xml attribute by tagName and attribute name.
     */
    QString readXmlAttributeByTagName(const QString &tagName,
                                      const QString &attrName) const;
    /*!
     * Read xml attribute's text by tagName.
     */
    QString readXmlTextByTagName(const QString &tagName) const;
    /*!
     * Read xml attributes by tagName and default name "value".
     */
    MusicObject::MStriantMap readXmlAttributesByTagName(const QString &tagName) const;
    /*!
     * Create processing instruction in header.
     */
    void createProcessingInstruction();
    /*!
     * Create xml node nodes by node name.
     */
    QDomElement createRoot(const QString &node);
    /*!
     * Create xml node nodes by node atrr.
     */
    QDomElement createRoot(const QString &node, const MusicXmlAttribute &attr);
    /*!
     * Create xml node nodes by node atrrs.
     */
    QDomElement createRoot(const QString &node, const MusicXmlAttributes &attrs);
    /*!
     * Append xml element nodes by node name.
     */
    QDomElement writeDom(QDomElement &element, const QString &node);
    /*!
     * Append xml element nodes by node name\ key name and value.
     */
    QDomElement writeDomElement(QDomElement &element, const QString &node,
                                const MusicXmlAttribute &attr);
    /*!
     * Append xml elements nodes by node name\ keys name and values.
     */
    QDomElement writeDomElementMutil(QDomElement &element, const QString &node,
                                     const MusicXmlAttributes &attrs);
    /*!
     * Append xml element nodes by node name\ key name \ value and attribute's text.
     */
    QDomElement writeDomElementText(QDomElement &element, const QString &node,
                                    const MusicXmlAttribute &attr, const QString &text);
    /*!
     * Append xml elements nodes by node name\ keys name \ values and attribute's text.
     */
    QDomElement writeDomElementMutilText(QDomElement &element, const QString &node,
                                         const MusicXmlAttributes &attrs, const QString &text);
    /*!
     * Append xml element nodes by node name and attribute's text.
     */
    QDomElement writeDomText(QDomElement &element, const QString &node, const QString &text);
    /*!
     * Append xml element nodes key name and value.
     */
    void writeAttribute(QDomElement &element, const MusicXmlAttribute &attr);

protected:
    QFile *m_file;
    QDomDocument *m_ddom;

};

#endif // MUSICABSTRACTXML_H
