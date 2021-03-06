#ifndef MUSICRESIZEGRABITEMWIDGET_H
#define MUSICRESIZEGRABITEMWIDGET_H

/* =================================================
 * This file is part of the TTK Music Player project
 * Copyright (c) 2015 - 2017 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include <QWidget>
#include "musicglobaldefine.h"

/*! @brief The class of the resize grab label item widget.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_WIDGET_EXPORT MusicResizeGrabItemWidget : public QWidget
{
    Q_OBJECT
public:
    enum Direction
    {
        Direction_No = 0,                                           /*!< no direction*/
        Direction_Left = 1,                                         /*!< left direction*/
        Direction_Top = 2,                                          /*!< top direction*/
        Direction_Right = 4,                                        /*!< right direction*/
        Direction_Bottom = 8,                                       /*!< bottom direction*/
        Direction_LeftTop = Direction_Left + Direction_Top,         /*!< left top direction*/
        Direction_LeftBottom = Direction_Left + Direction_Bottom,   /*!< left bottom direction*/
        Direction_RightTop = Direction_Right + Direction_Top,       /*!< right top direction*/
        Direction_RightBottom = Direction_Right + Direction_Bottom  /*!< right bottom direction*/
    };
    /*!
     * Object contsructor.
     */
    explicit MusicResizeGrabItemWidget(QWidget *parent = 0);

    /*!
     * Get class object name.
     */
    static QString getClassName();
    /*!
     * Set border rect.
     */
    virtual void setBorderRect(const QRect &rect);
    /*!
     * Set Geometric Stretch.
     */
    inline void setGeometricStretch(bool g) { m_geometricStretch = g;}
    /*!
     * Get Geometric Stretch.
     */
    inline bool getGeometricStretch() const { return m_geometricStretch;}
    /*!
     * Set Cross Stretch.
     */
    inline void setCrossStretch(bool c) { m_crossStretch = c;}
    /*!
     * Get Cross Stretch.
     */
    inline bool gettCrossStretch() const { return m_crossStretch;}

Q_SIGNALS:
    /*!
     * Current rect changed.
     */
    void rectChanged();

private Q_SLOTS:
    /*!
     * On mouse changed.
     */
    void onMouseChange(int x,int y);

protected:
    /*!
     * Override the widget event.
     */
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void resizeEvent(QResizeEvent *event);
    virtual void paintEvent(QPaintEvent *event);
    /*!
     * Get region rect.
     */
    Direction getRegion(const QPoint &cursor);

    bool m_isPressed;
    bool m_crossStretch, m_geometricStretch;
    Direction m_direction;
    QPoint m_originPoint, m_movePos;
    QPolygon m_listMarker;
    QRect m_currentRect, m_borderRect;

};


#if QT_VERSION < QT_VERSION_CHECK(5,3,0)
inline QRect operator-(const QRect &rect, const QMargins &margins);
#endif


#endif // MUSICRESIZEGRABITEMWIDGET_H
