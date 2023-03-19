#include <QFile>
#include <QPainter>
#include <QtMath>
#include <QDebug>
#include <QAbstractItemView>
#include <QMimeData>
#include <QSizeGrip>
#include <QWindow>
#include <QScreen>
#include <QRect>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonParseError>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_nShadoWidth(0)
    , m_stMenu(this)
    , m_stPlayList(this)
    , m_stTitle(this)
    , m_bMoveDrag(false)
    , m_stActFullscreen(this) {
    ui->setupUi(this);
    ui->pushButton->setText(tr("new window"));

    // 无边框、无系统菜单、任务栏点击最小化
    setWindowFlags(
        Qt::FramelessWindowHint | Qt::WindowSystemMenuHint
        | Qt::WindowMinimizeButtonHint);
    // 设置任务栏图标
    this->setWindowIcon(QIcon(":/image/resource/player.png"));
    // 加载样式
}

MainWindow::~MainWindow() {
    delete ui;
}

bool MainWindow::Init() {
    return false;
}

bool MainWindow::ConnectSignalSlots() {
    return false;
}
