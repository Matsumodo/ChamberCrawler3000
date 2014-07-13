//
//  WD.cc
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-24.
//  Copyright (c) 2013年 CS246-118. All rights reserved.
//

#include "WD.h"
#include "playercharacter.h"

void WD::usePotion(playerCharacter *p){
    if (p->getRace() == "Elves") {
        p->setExtraDef(5);
    }
    else {
        p->setExtraDef(-5);
    }
}