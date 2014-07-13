//
//  RH.h
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-24.
//  Copyright (c) 2013年 CS246-118. All rights reserved.
//

#ifndef __CC3K__RH__
#define __CC3K__RH__
#include "potion.h"

class RH : public Potion {
public:
    RH() : Potion("RH") {}
    void usePotion(playerCharacter *p);
};

#endif