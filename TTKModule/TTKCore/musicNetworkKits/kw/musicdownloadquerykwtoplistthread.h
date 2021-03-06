#ifndef MUSICDOWNLOADQUERYKWTOPLISTTHREAD_H
#define MUSICDOWNLOADQUERYKWTOPLISTTHREAD_H

/* =================================================
 * This file is part of the TTK Music Player project
 * Copyright (c) 2015 - 2017 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include "musicdownloadkwinterface.h"
#include "musicdownloadquerythreadabstract.h"

/*! @brief The class to kuwo query toplist download data from net.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_NETWORK_EXPORT MusicDownLoadQueryKWToplistThread : public MusicDownLoadQueryThreadAbstract,
                                                               private MusicDownLoadKWInterface
{
    Q_OBJECT
public:
    /*!
     * Object contsructor.
     */
    explicit MusicDownLoadQueryKWToplistThread(QObject *parent = 0);

    /*!
     * Get class object name.
     */
    static QString getClassName();

    /*!
     * Start to Search data from name and type.
     */
    virtual void startToSearch(QueryType type, const QString &toplist) override;
    /*!
     * Start to Search data from name and type.
     */
    void startToSearch(const QString &toplist);

Q_SIGNALS:
    /*!
     * Create the current toplist info item.
     */
    void createToplistInfoItem(const MusicPlaylistItem &item);

public Q_SLOTS:
    /*!
     * Download data from net finished.
     */
    virtual void downLoadFinished() override;

};

#endif // MUSICDOWNLOADQUERYKWTOPLISTTHREAD_H
