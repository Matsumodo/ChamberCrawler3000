//
//  dwarf.h
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-24.
//  Copyright (c) 2013Äê CS246-118. All rights reserved.
//
#ifndef __DWARF_H__
#define __DWARF_H__
#include "playercharacter.h"

class Dwarf : public playerCharacter{
public:
	Dwarf();
    ~Dwarf();
    void usePotion(Potion *po);
};

#endif