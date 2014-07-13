//
//  BA.h
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-24.
//  Copyright (c) 2013年 CS246-118. All rights reserved.
//

#ifndef __CC3K__BA__
#define __CC3K__BA__
#include "potion.h"

class BA : public Potion {
public:
    BA() : Potion("BA") {}
    void usePotion(playerCharacter *p);
};

#endif