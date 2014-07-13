//
//  BD.h
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-24.
//  Copyright (c) 2013年 CS246-118. All rights reserved.
//

#ifndef __CC3K__BD__
#define __CC3K__BD__

#include "potion.h"


class BD : public Potion {
public:
    BD() : Potion("BD") {}
    void usePotion(playerCharacter *p);
};

#endif