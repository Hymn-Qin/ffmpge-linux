#ifndef __PLAYLIST__H__
#define __PLAYLIST__H__

#include <QWidget>
#include <QListWidgetItem>
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QMimeData>
class Playlist : public QWidget {
  public:
    explicit Playlist(QWidget *parent = nullptr);
    ~Playlist();
};

#endif // __PLAYLIST_H__