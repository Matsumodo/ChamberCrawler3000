//
//  elves.h
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-24.
//  Copyright (c) 2013Äê CS246-118. All rights reserved.
//
#ifndef __ELVES_H__
#define __ELVES_H__
#include "playercharacter.h"

class Elves : public playerCharacter{
public:
	Elves();
    ~Elves();
    void usePotion(Potion *po);
};

#endif