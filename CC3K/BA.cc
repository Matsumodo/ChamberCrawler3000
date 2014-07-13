//
//  BA.cc
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-24.
//  Copyright (c) 2013年 CS246-118. All rights reserved.
//

#include "BA.h"
#include "playercharacter.h"

void BA::usePotion(playerCharacter *p) {
    p->setExtraAtk(5);
}