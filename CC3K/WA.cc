//
//  WA.cc
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-24.
//  Copyright (c) 2013年 CS246-118. All rights reserved.
//

#include "WA.h"
#include "playercharacter.h"

void WA::usePotion(playerCharacter *p){
    if (p->getRace() == "Elves") {
        p->setExtraAtk(5);
    }
    else {
        p->setExtraAtk(-5);
    }
}