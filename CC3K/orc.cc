//
//  orc.cc
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-24.
//  Copyright (c) 2013Äê CS246-118. All rights reserved.
//
#include "orc.h"
#include "potion.h"

using namespace std;

Orc::Orc() : playerCharacter(0, 0, 0, 180, 180, 30, 25, true, "Orc", NULL){}

Orc::~Orc(){}

void Orc::usePotion(Potion *po) {
    po->usePotion(this);
}