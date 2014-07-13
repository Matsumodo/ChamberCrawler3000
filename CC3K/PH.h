//
//  PH.h
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-24.
//  Copyright (c) 2013年 CS246-118. All rights reserved.
//

#ifndef __CC3K__PH__
#define __CC3K__PH__

#include "potion.h"

class PH : public Potion {
public:
    PH() : Potion("PH") {}
    void usePotion(playerCharacter *p);
};

#endif