//
//  elves.cc
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-24.
//  Copyright (c) 2013Äê CS246-118. All rights reserved.
//
#include "elves.h"
#include "potion.h"

using namespace std;

Elves::Elves() : playerCharacter(0, 0, 0, 140, 140, 30, 10, true, "Elves", NULL) {}

Elves::~Elves(){}

void Elves::usePotion(Potion *po) {
    po->usePotion(this);
}