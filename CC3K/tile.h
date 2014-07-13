//
//  tile.h
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-20.
//  Copyright (c) 2013年 CS246-118. All rights reserved.
//

#ifndef __CC3K__tile__
#define __CC3K__tile__
#include <string>
#include "gameobject.h"
#include "textdisplay.h"

class Tile {
    int x,y;
public:
    gameObject *thing;
    bool isOccupied;
    Tile() : x(0), y(0), thing(NULL), isOccupied(false) {}
    void setCoords(int x, int y);
    int getX();
    int getY();
    void setGameObject(gameObject *thing);
    void notifyDisplay(TextDisplay &td);
    ~Tile() { delete thing; }
};

#endif
