#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "playlist.h"
#include "title.h"
#include <QMainWindow>
#include <QWidget>
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QMenu>
#include <QAction>
#include <QPropertyAnimation>
#include <QTimer>
#include <qaction.h>
#include <qevent.h>
#include <qmap.h>
#include <qmenu.h>
#include <qpoint.h>
#include <qpropertyanimation.h>
#include <qtimer.h>
#include <qwidget.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // 是否已经初始化
    bool Init();

  protected:
    // 生命周期
    // 绘制
    // void paintEvent(QPaintEvent *event) override;

    // void enterEvent(QEvent *event) override;

    // void leaveEvent(QEvent *event) override;

    // // 按键事件
    // void keyReleaseEvent(QKeyEvent *event) override;

    // void mousePressEvent(QMouseEvent *event) override;

    // void mouseReleaseEvent(QMouseEvent *event) override;

    // void mouseMoveEvent(QMouseEvent *event) override;

    // void contextMenuEvent(QContextMenuEvent *event) override;

  private:
    // 连接信号槽
    bool ConnectSignalSlots();

    Ui::MainWindow *ui;
    bool m_bPlaying;         // 是否正在播放
    const int m_nShadoWidth; // 阴影宽度
    bool m_bFullScreenPlay;  // 全屏播放标志

    QPropertyAnimation *m_stCtrlbarAnimationShow; // 全屏时控制面板浮动显示
    QPropertyAnimation *m_stCtrlbarAnimationHide; //...
    QRect m_stCtrlbarAnimationShowRect;           // 控制面板显示区域
    QRect m_stCtrlbarAnimationHideRectl;          // 隐藏区域

    QTimer m_stCtrlbarAnimationTimer;
    QTimer m_stFullscreenMouseDetectTimer; // 全屏时鼠标位置监控时钟
    bool m_bFullscreenCtrlbarShow;
    QTimer stCtrlbarHideTimer;

    Playlist m_stPlayList;
    Title m_stTitle;

    bool m_bMoveDrag;      // 移动窗口标志
    QPoint m_DragPosition; //

    QMenu m_stMenu;
    QAction m_stActFullscreen;
    QMap<QString, void (MainWindow::*)()> map_act_;
};
#endif // MAINWINDOW_H
