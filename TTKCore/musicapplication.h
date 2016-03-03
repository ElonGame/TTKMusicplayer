#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/* =================================================
 * This file is part of the TTK Music Player project
 * Copyright (c) 2014 - 2016 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include <QCloseEvent>
#include <QMenu>
#include <QTimer>
#include "musicabstractmovewidget.h"
#include "musicobject.h"

class MusicPlayer;
class MusicPlaylist;
class MusicSongsSummarizied;
class MusicBottomAreaWidget;
class MusicTopAreaWidget;
class MusicRightAreaWidget;
class MusicLeftAreaWidget;
class MusicApplicationObject;

namespace Ui {
class MusicApplication;
}

class MUSIC_GUI_EXPORT MusicApplication : public MusicAbstractMoveWidget
{
    Q_OBJECT
public:
    explicit MusicApplication(QWidget *parent = 0);
    virtual ~MusicApplication();

    QString getCurrentFileName() const;
    bool checkMusicListCurrentIndex() const;
    void musicLoadCurrentSongLrc();
    void musicImportSongsSettingPath(const QStringList &path);

public Q_SLOTS:
    void quitWindowClose();
    void positionChanged(qint64 position);
    void durationChanged(qint64 duration);
    void stateChanged();
    void showCurrentSong(int index);
    void musicKey();
    void musicPlayPrivious();
    void musicPlayNext();
    void musicPlayOrder();
    /*!
     * Set current play mdoe to order.
     */
    void musicPlayRandom();
    /*!
     * Set current play mdoe to random.
     */
    void musicPlayListLoop();
    /*!
     * Set current play mdoe to list loop.
     */
    void musicPlayOneLoop();
    /*!
     * Set current play mdoe to single loop.
     */
    void musicPlayItemOnce();
    /*!
     * Set current play mdoe to just once.
     */
    void musicVolumeMute();
    void musicVolumeChanged(int volume);
    void musicImportSongs();
    void musicImportSongsOnlyFile();
    void musicImportSongsOnlyDir();
    void musicPlayIndex(int row, int col);
    void musicPlayAnyTimeAt(int posValue);
    void musicActionVolumeSub();
    void musicActionVolumePlus();
    void musicSetting();
    void musicCurrentPlayLocation();
    void musicAddSongToLovestListAt();
    void musicWindowConciseChanged();
    void musicEnhancedMusicChanged(int type);
    void musicImportPlay();
    /////////////////////////////////////////////
    //This is a slot by MusicLocalSongSearch's signal emit
    void musicSearchIndexChanged(int row, int col);
    /////////////////////////////////////////////
    //This is a slot by MusicSettingWidget's signal emit
    void getParameterSetting();
    /////////////////////////////////////////////
    //This is a slot by MusicSongsSummarizied's signal emit
    void setDeleteItemAt(const MIntList &index);
    /////////////////////////////////////////////
    //This is a slot by MusicInlineLrcContainer's signal emit
    void musicCurrentLrcUpdated();
    void updateCurrentTime(qint64 pos);
    //This is a slot by MusicTimerAutoObject's signal emit
    void setPlaySongChanged(int index);
    /*!
     * Set current song to play in play list.
     */
    void setStopSongChanged();
    /*!
     * Set current song to stop in play list.
     */
    /////////////////////////////////////////////
    //This is a slot by MusicLeftAreaWidget's signal emit
    void addSongToPlayList(const QStringList &item);
    /*!
     * Add current selected song to play lists.
     */
    void getCurrentPlayList(QStringList &list);
    /*!
     * Get current play lists.
     */

protected:
    void initWindowSurface();
    void createPlayModeMenu(QMenu &menu);
    void createPlayModeMenuIcon(QMenu &menu);
    virtual void closeEvent(QCloseEvent *event) override;
    virtual void dragEnterEvent(QDragEnterEvent *event) override;
    virtual void dragMoveEvent(QDragMoveEvent *event) override;
    virtual void dropEvent(QDropEvent *event) override;
    virtual void contextMenuEvent(QContextMenuEvent *event) override;
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void keyReleaseEvent(QKeyEvent *event) override;
#if defined(Q_OS_WIN)
#  ifdef MUSIC_QT_5
     virtual bool nativeEvent(const QByteArray &, void *, long *) override;
#  else
     virtual bool winEvent(MSG *message, long *result) override;
#  endif
#endif
    /*!
     * Override the widget event.
     */

    void readXMLConfigFromText();
    void writeXMLConfigToText();

private:
    Ui::MusicApplication *ui;
    bool m_playControl;
    int m_currentMusicSongTreeIndex;
    QMenu m_playModeMenu;

    MusicPlayer* m_musicPlayer;
    MusicPlaylist* m_musicList;
    MusicSongsSummarizied *m_musicSongTree;
    MusicBottomAreaWidget *m_bottomAreaWidget;
    MusicTopAreaWidget *m_topAreaWidget;
    MusicRightAreaWidget *m_rightAreaWidget;
    MusicLeftAreaWidget *m_leftAreaWidget;
    MusicApplicationObject *m_object;

};

#endif // MAINWINDOW_H