#ifndef LEVEL_CONFIG_H
#define LEVEL_CONFIG_H

#include <QObject>
#include <QMap>
#include <QVector>

class LevelConfig : public QObject {
    Q_OBJECT
  public:
    explicit LevelConfig(QObject *parent = nullptr);
    
    QMap<int, QVector<QVector<int>>> level_map_;
};

#endif  // LEVEL_CONFIG_H
