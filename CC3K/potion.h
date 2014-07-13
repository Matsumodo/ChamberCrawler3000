//
//  potion.h
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-19.
//  Copyright (c) 2013年 CS246-118. All rights reserved.
//

#ifndef __CC3K__potion__
#define __CC3K__potion__

#include "item.h"
#include <string>
#include <map>

class playerCharacter;

class Potion : public Item {
protected:
    std::string race;
public:
    Potion(std::string race);
    std::string getRace() { return race; }
    std::string getType() { return "Potion"; }
    std::string displayPotion(std::map <std::string, bool> &m);
    virtual void usePotion(playerCharacter *pc) = 0;
    virtual ~Potion() {};
};
#endif