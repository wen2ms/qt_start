#ifndef TVSHOW_H
#define TVSHOW_H

#include <QString>

class TVShow {
  public:
    TVShow(QString title = "", float rating = -1, int release_year = 0);
    
    QString title_;
    float rating_;
    int release_year_;
};

#endif  // TVSHOW_H
