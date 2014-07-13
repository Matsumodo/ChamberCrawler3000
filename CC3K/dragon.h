//
//  dragon.h
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-24.
//  Copyright (c) 2013Äê CS246-118. All rights reserved.
//

#ifndef __DRAGON_H__
#define __DRAGON_H__
#include "enemy.h"
#include "tile.h"

class dragonHorde;

class Dragon : public Enemy {
	Tile* treasureLocation;
public:
	Dragon();
    void setTreasureLocation(Tile* t) { treasureLocation = t; }
	~Dragon();
};

#endif