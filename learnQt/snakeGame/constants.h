#ifndef CONSTANTS_H
#define CONSTANTS_H

//蛇每个小格的大小
const int TILE_SIZE = 10;

//用来作为碰撞时的判断，来判断撞到的对象类型是不是食物或者墙，这个也还没加到墙的功能里
enum GameObjectsData {
    GD_Type
};

enum GameObjectTypes {
    GO_Food,
    GO_Wall
};

#endif // CONSTANTS_H
