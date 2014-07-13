//
//  treasure.h
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-19.
//  Copyright (c) 2013年 CS246-118. All rights reserved.
//

#ifndef __CC3K__treasure__
#define __CC3K__treasure__
#include "playercharacter.h"
#include "item.h"
#include <string>

class Treasure : public Item {
    int value;
protected:
    std::string race;
public:
    Treasure(int value, std::string race) : value(value), race(race) {}
    void useGold(playerCharacter *p);
    int getValue();
    std::string getRace() { return race; }
    std::string getType() { return "Treasure"; }
    virtual ~Treasure() {};
};
#endif