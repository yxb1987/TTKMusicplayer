#ifndef MUSICENHANCEDPOPWIDGET_H
#define MUSICENHANCEDPOPWIDGET_H

/* =================================================
 * This file is part of the TTK Music Player project
 * Copyright (c) 2015 - 2017 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include "musictoolmenuwidget.h"

class QLabel;
class QPropertyAnimation;

/*! @brief The class of the enhanced tool button.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_WIDGET_EXPORT MusicEnhancedToolButton : public QToolButton
{
    Q_OBJECT
public:
    /*!
     * Object contsructor.
     */
    explicit MusicEnhancedToolButton(QWidget *parent = 0);

    virtual ~MusicEnhancedToolButton();

    /*!
     * Get class object name.
     */
    static QString getClassName();

    /*!
     * Set object style sheet.
     */
    void setStyleSheet(const QString &styleSheet, bool state = false);
    /*!
     * Start label animation .
     */
    void start();
    /*!
     * Stop label animation.
     */
    void stop();

private Q_SLOTS:
    /*!
     * Label animation just finished.
     */
    void finished();

protected:
    /*!
     * Override the widget event.
     */
    virtual void enterEvent(QEvent *event) override;

    bool m_state;
    QLabel *m_foreLabel, *m_animationLabel;
    QPropertyAnimation *m_animation;
};


/*! @brief The class of the enhanced pop widget.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_WIDGET_EXPORT MusicEnhancedPopWidget : public MusicToolMenuWidget
{
    Q_OBJECT
public:
    /*!
     * Object contsructor.
     */
    explicit MusicEnhancedPopWidget(QWidget *parent = 0);

    virtual ~MusicEnhancedPopWidget();

    /*!
     * Get class object name.
     */
    static QString getClassName();

Q_SIGNALS:
    /*!
     * Set enhanced music config changed return selected index.
     */
    void enhancedMusicChanged(int type);

public Q_SLOTS:
    /*!
     * Set enhanced music config.
     */
    void setEnhancedMusicConfig(int type);
    /*!
     * Case button on and off.
     */
    void caseButtonOnAndOff();
    /*!
     * Button animation state changed.
     */
    void buttonAnimationChanged(bool state);
    /*!
     * Help button clicked.
     */
    void helpButtonClicked();

protected:
    /*!
     * Create all widget in layout.
     */
    void initWidget();

    int m_lastSelectedIndex;
    QToolButton *m_caseButton;
    QList<MusicEnhancedToolButton*> m_buttons;

};

#endif // MUSICENHANCEDPOPWIDGET_H
