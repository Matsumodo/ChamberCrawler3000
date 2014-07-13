//
//  WA.h
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-24.
//  Copyright (c) 2013年 CS246-118. All rights reserved.
//

#ifndef __CC3K__WA__
#define __CC3K__WA__

#include "potion.h"

class WA : public Potion {
public:
    WA() : Potion("WA") {}
    void usePotion(playerCharacter *p);
};
#endif