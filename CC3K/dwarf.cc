//
//  dwarf.cc
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-24.
//  Copyright (c) 2013Äê CS246-118. All rights reserved.
//
#include "dwarf.h"
#include "potion.h"

using namespace std;

Dwarf::Dwarf() : playerCharacter(0, 0, 0, 100, 100, 20, 30, true, "Dwarf", NULL) {}

Dwarf::~Dwarf(){}

void Dwarf::usePotion(Potion *po) {
    po->usePotion(this);
}