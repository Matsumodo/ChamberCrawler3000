//
//  WD.h
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-24.
//  Copyright (c) 2013年 CS246-118. All rights reserved.
//

#ifndef __CC3K__WD__
#define __CC3K__WD__

#include "potion.h"

class WD : public Potion {
public:
    WD() : Potion("WD") {}
    void usePotion(playerCharacter *p);
};
#endif