#ifndef MUSICDOWNLOADQUERYTHREADABSTRACT_H
#define MUSICDOWNLOADQUERYTHREADABSTRACT_H

/* =================================================
 * This file is part of the TTK Music Player project
 * Copyright (c) 2015 - 2017 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include "musicobject.h"
#include "musicdownloadpagingthread.h"

/*! @brief The class of the searched data item.
 * @author Greedysky <greedysky@163.com>
 */
typedef struct MUSIC_NETWORK_EXPORT MusicSearchedItem
{
    QString m_songname;
    QString m_artistname;
    QString m_time;
    QString m_type;
}MusicSearchedItem;
MUSIC_DECLARE_LISTS(MusicSearchedItem)

/*! @brief The class of the playlist data item.
 * @author Greedysky <greedysky@163.com>
 */
typedef struct MUSIC_NETWORK_EXPORT MusicPlaylistItem
{
    QString m_id;
    QString m_name;
    QString m_nickname;
    QString m_coverUrl;
    QString m_playCount;
    QString m_description;
    QString m_updateTime;
    QString m_tags;

    MusicPlaylistItem()
    {
        m_id = "-";
        m_name = "-";
        m_nickname = "-";
        m_coverUrl = "-";
        m_playCount = "-";
        m_description = "-";
        m_updateTime = "-";
        m_tags = "-";
    }
}MusicPlaylistItem;
MUSIC_DECLARE_LISTS(MusicPlaylistItem)

/*! @brief The class to abstract query download data from net.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_NETWORK_EXPORT MusicDownLoadQueryThreadAbstract : public MusicDownLoadPagingThread
{
    Q_OBJECT
public:
    enum QueryType
    {
        MusicQuery, /*!< query music*/
        MovieQuery, /*!< query movie*/
        LrcQuery,   /*!< query lrc*/
        OtherQuery, /*!< query external*/
    };

    /*!
     * Object contsructor.
     */
    explicit MusicDownLoadQueryThreadAbstract(QObject *parent = 0);

    virtual ~MusicDownLoadQueryThreadAbstract();

    /*!
     * Get class object name.
     */
    static QString getClassName();

    /*!
     * Start to search data from name and type.
     * Subclass should implement this function.
     */
    virtual void startToSearch(QueryType type, const QString &text) = 0;

    /*!
     * Set search data quality.
     */
    inline void setSearchQuality(const QString &qual) { m_searchQuality = qual;}
    /*!
     * Get search data quality.
     */
    inline QString getSearchQuality() const { return m_searchQuality;}
    /*!
     * Set wheather query all quality of records.
     */
    inline void setQueryAllRecords(bool state) { m_queryAllRecords = state;}
    /*!
     * Get query all records flag.
     */
    inline bool getQueryAllRecords() const { return m_queryAllRecords;}
    /*!
     * Set query simplify mode.
     */
    inline void setQuerySimplify(bool state) { m_querySimplify = state;}
    /*!
     * Get query simplify flag.
     */
    inline bool getQuerySimplify() const { return m_querySimplify;}
    /*!
     * Set query extra movie flag.
     */
    inline void setQueryExtraMovie(bool state) { m_queryExtraMovie = state;}
    /*!
     * Return the current song query type.
     */
    inline QueryType getQueryType() const { return m_currentType;}
    /*!
     * Return the current song query server.
     */
    inline QString getQueryServer() const { return m_queryServer;}
    /*!
     * Return the current song name.
     */
    inline QString getSearchedText() const { return m_searchText;}
    /*!
     * Return the current song container.
     */
    inline const MusicObject::MusicSongInformations& getMusicSongInfos() const { return m_musicSongInfos; }

Q_SIGNALS:
    /*!
     * Clear all items before the new query start.
     */
    void clearAllItems();
    /*!
     * Create the current items by song name\ artist name and time.
     */
    void createSearchedItems(const MusicSearchedItem &songItem);

protected:
    /*!
     * Map query server string.
     */
    QString mapQueryServerString() const;

    MusicObject::MusicSongInformations m_musicSongInfos;
    QString m_searchText, m_searchQuality;
    QString m_queryServer;
    QueryType m_currentType;
    bool m_queryAllRecords, m_querySimplify, m_queryExtraMovie;

};

#endif // MUSICDOWNLOADQUERYTHREADABSTRACT_H
