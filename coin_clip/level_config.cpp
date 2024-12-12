#include "level_config.h"

LevelConfig::LevelConfig(QObject *parent) : QObject{parent} {
    QVector<QVector<int>> level1 = {{1, 1, 1, 1},
                                    {1, 1, 0, 1},
                                    {1, 0, 0, 0},
                                    {1, 1, 0, 1}};
    level_map_.insert(1, level1);

    QVector<QVector<int>> level2 = {{1, 0, 1, 1},
                                    {0, 0, 1, 1},
                                    {1, 1, 0, 0},
                                    {1, 1, 0, 1}};
    level_map_.insert(2, level2);

    QVector<QVector<int>> level3 = {{0, 0, 0, 0},
                                    {0, 1, 1, 0},
                                    {0, 1, 1, 0},
                                    {0, 0, 0, 0}};
    level_map_.insert(3, level3);
    
    QVector<QVector<int>> level4 = {{0, 1, 1, 1},
                                    {1, 0, 0, 1},
                                    {1, 0, 1, 1},
                                    {1, 1, 1, 1}};
    level_map_.insert(4, level4);
    
    QVector<QVector<int>> level5 = {{1, 0, 0, 1},
                                    {0, 0, 0, 0},
                                    {0, 0, 0, 0},
                                    {1, 0, 0, 1}};
    level_map_.insert(5, level5);

    QVector<QVector<int>> level6 = {{1, 0, 0, 1},
                                    {0, 1, 1, 0},
                                    {0, 1, 1, 0},
                                    {1, 0, 0, 1}};
    level_map_.insert(6, level6);
    
    QVector<QVector<int>> level7 = {{0, 1, 1, 1},
                                    {1, 0, 1, 1},
                                    {1, 1, 0, 1},
                                    {1, 1, 1, 0}};
    level_map_.insert(7, level7);
    
    QVector<QVector<int>> level8 = {{0, 1, 0, 1},
                                    {1, 0, 0, 0},
                                    {0, 0, 0, 1},
                                    {1, 0, 1, 0}};
    level_map_.insert(8, level8);
    
    QVector<QVector<int>> level9 = {{1, 0, 1, 0},
                                    {1, 0, 1, 0},
                                    {0, 0, 1, 0},
                                    {1, 0, 0, 1}};
    level_map_.insert(9, level9);
    
    QVector<QVector<int>> level10 = {{1, 0, 1, 1},
                                     {1, 1, 0, 0},
                                     {0, 0, 1, 1},
                                     {1, 1, 0, 1}};
    level_map_.insert(10, level10);
    
    QVector<QVector<int>> level11 = {{0, 1, 1, 0},
                                     {1, 0, 0, 1},
                                     {1, 0, 0, 1},
                                     {0, 1, 1, 0}};
    level_map_.insert(11, level11);
    
    QVector<QVector<int>> level12 = {{0, 1, 1, 0},
                                     {0, 0, 0, 0},
                                     {1, 1, 1, 1},
                                     {0, 0, 0, 0}};
    level_map_.insert(12, level12);
    
    QVector<QVector<int>> level13 = {{0, 1, 1, 0},
                                     {0, 0, 0, 0},
                                     {0, 0, 0, 0},
                                     {0, 1, 1, 0}};
    level_map_.insert(13, level13);
    
    QVector<QVector<int>> level14 = {{1, 0, 1, 1},
                                     {0, 1, 0, 1},
                                     {1, 0, 1, 0},
                                     {1, 1, 0, 1}};
    level_map_.insert(14, level14);
    
    QVector<QVector<int>> level15 = {{0, 1, 0, 1},
                                     {1, 0, 0, 0},
                                     {1, 0, 0, 0},
                                     {0, 1, 0, 1}};
    level_map_.insert(15, level15);
    
    QVector<QVector<int>> level16 = {{0, 1, 1, 0},
                                     {1, 1, 1, 1},
                                     {1, 1, 1, 1},
                                     {0, 1, 1, 0}};
    level_map_.insert(16, level16);
    
    QVector<QVector<int>> level17 = {{0, 1, 1, 1},
                                     {0, 1, 0, 0},
                                     {0, 0, 1, 0},
                                     {1, 1, 1, 0}};
    level_map_.insert(17, level17);
    
    QVector<QVector<int>> level18 = {{0, 0, 0, 1},
                                     {0, 0, 1, 0},
                                     {0, 1, 0, 0},
                                     {1, 0, 0, 0}};
    level_map_.insert(18, level18);
    
    QVector<QVector<int>> level19 = {{0, 1, 0, 0},
                                     {0, 1, 1, 0},
                                     {0, 0, 1, 1},
                                     {0, 0, 0, 0}};
    level_map_.insert(19, level19);
    
    QVector<QVector<int>> level20 = {{0, 0, 0, 0},
                                     {0, 0, 0, 0},
                                     {0, 0, 0, 0},
                                     {0, 0, 0, 0}};
    level_map_.insert(20, level20);
}
