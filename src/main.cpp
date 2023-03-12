#include "mainwindow.h"

#include <QApplication>

// C++ 引入 ffmpeg
#ifdef __cplusplus
extern "C" {
#include "libavutil/avutil.h"
}

#endif //__cplusplus

int main(int argc, char *argv[]) {
  // QApplication a(argc, argv);

  printf("Hello FFMPEG, version is %s\n", av_version_info());

  // MainWindow w;
  // w.show();
  // return a.exec();
  return 0;
}
