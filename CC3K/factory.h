//
//  factory.h
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-25.
//  Copyright (c) 2013年 CS246-118. All rights reserved.
//

#ifndef __CC3K__factory__
#define __CC3K__factory__
#include <string>
//
#include "vwall.h"
#include "hwall.h"
#include "door.h"
#include "passage.h"
#include "stairway.h"
#include "ground.h"
//
#include "orc.h"
#include "human.h"
#include "dwarf.h"
#include "elves.h"
//
#include "RH.h"
#include "BA.h"
#include "BD.h"
#include "PH.h"
#include "WA.h"
#include "WD.h"
#include "merchanthorde.h"
#include "smallhorde.h"
#include "dragonhorde.h"
#include "normalgold.h"
//
#include "werewolf.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "merchant.h"
#include "phoenix.h"
#include "dragon.h"


class Factory {
public:
    floorElem *createFloorElem(std::string type);
    playerCharacter* createPlayerCharacter(std::string type);
    Item* createItem(std::string type);
    Enemy* createEnemy(std::string type);
};

#endif