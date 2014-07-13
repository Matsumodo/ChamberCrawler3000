//
//  human.cc
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-24.
//  Copyright (c) 2013Äê CS246-118. All rights reserved.
//
#include "human.h"
#include "potion.h"

using namespace std;

Human::Human() : playerCharacter(0, 0, 0, 140, 140, 20, 20, true, "Human", NULL){}

Human::~Human(){}

void Human::usePotion(Potion *po) {
    po->usePotion(this);
}