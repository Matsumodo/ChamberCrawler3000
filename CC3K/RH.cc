//
//  RH.cc
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-24,
//  Copyright (c) 2013年 CS246-118. All rights reserved.
//

#include "RH.h"
#include "playercharacter.h"

void RH::usePotion(playerCharacter *p) {
    if (p->getHP() + 10 > p->getMaxHP()) {
        p->setHP(p->getMaxHP());
    }
    else {
        p->setHP(p->getHP() + 10);
    }
}