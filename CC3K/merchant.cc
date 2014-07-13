//
//  merchant.cc
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-24.
//  Copyright (c) 2013Äê CS246-118. All rights reserved.
//
#include "merchant.h"
#include "playercharacter.h"
#include "grid.h"
#include <cmath>
Merchant::Merchant() : Enemy(0, 0, 30, 70, 5, true, "Merchant", NULL) {}

Merchant::~Merchant(){}

void Merchant::turnOnHostile() { isHostileToPc = true; }

bool Merchant::checkHostile() { return isHostileToPc; }

bool Merchant::isHostileToPc = false;
