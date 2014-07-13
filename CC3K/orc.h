//
//  orc.h
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-24.
//  Copyright (c) 2013Äê CS246-118. All rights reserved.
//
#ifndef __ORC_H__
#define __ORC_H__
#include "playercharacter.h"

class Orc : public playerCharacter {
public:
	Orc();
    ~Orc();
    void usePotion(Potion *po);
};

#endif