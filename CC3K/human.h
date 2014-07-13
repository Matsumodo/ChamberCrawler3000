//
//  human.h
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-24.
//  Copyright (c) 2013Äê CS246-118. All rights reserved.
//
#ifndef __HUMAN_H__
#define __HUMAN_H__
#include "playercharacter.h"

class Human : public playerCharacter {
public:
	Human();
    ~Human();
    void usePotion(Potion *po);
};

#endif