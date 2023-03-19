#include "mainwindow.h"

#include <QApplication>
#include <qfont.h>
#include <qfontdatabase.h>

// C++ 引入 ffmpeg
#ifdef __cplusplus
extern "C" {
#include "libavutil/avutil.h"
}

#endif //__cplusplus

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QFontDatabase::addApplicationFont(
        ":/font/resource/fontawesome-webfont.ttf");

    printf("Hello FFMPEG 欢迎, version is %s\n", av_version_info());

    MainWindow w;
    w.show();
    return a.exec();
    // return 0;
}
