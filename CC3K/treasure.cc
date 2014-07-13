//
//  treasure.cc
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-19.
//  Copyright (c) 2013年 CS246-118. All rights reserved.
//

#include "treasure.h"

using namespace std;

void Treasure::useGold(playerCharacter *p) { p->setWallet(getValue()); }

int Treasure::getValue() { return value; }