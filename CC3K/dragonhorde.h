//
//  dragonhorde.h
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-21.
//  Copyright (c) 2013年 CS246-118. All rights reserved.
//

#ifndef __CC3K__dragonhorde__
#define __CC3K__dragonhorde__

#include "treasure.h"
#include "tile.h"

class dragonHorde : public Treasure {
public:
    Tile *dragonLocation;
    dragonHorde() : Treasure(4, "dragonHorde"), dragonLocation(NULL) {}
    void setDragonLocation(Tile *t) { this->dragonLocation = t; }
};
#endif