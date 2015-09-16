#ifndef MUSICMYDOWNLOADRECORDWIDGET_H
#define MUSICMYDOWNLOADRECORDWIDGET_H

/* =================================================
 * This file is part of the Music Player project
 * Copyright (c) 2014 - 2015 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include "musicabstracttablewidget.h"

class MusicProgressBarDelegate;

class MUSIC_TOOL_EXPORT MusicMyDownloadRecordWidget : public MusicAbstractTableWidget
{
    Q_OBJECT
public:
    explicit MusicMyDownloadRecordWidget(QWidget *parent = 0);
    virtual ~MusicMyDownloadRecordWidget();

    void musicSongsFileName();
    void clearAllItems();

signals:
    void addSongToPlay(const QStringList &list);

public slots:
    void musicPlay();
    void setDeleteItemAt();
    void setDeleteItemAll();
    void listCellClicked(int row, int column);
    void listCellDoubleClicked(int row, int column);
    void musicOpenFileDir();

protected:
    virtual void contextMenuEvent(QContextMenuEvent *event);

    MusicProgressBarDelegate *m_delegate;
    QStringList m_musicFileNameList;
    QStringList m_musicFilePathList;

};

#endif // MUSICMYDOWNLOADRECORDWIDGET_H
