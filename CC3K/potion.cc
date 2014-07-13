//
//  potion.cc
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-19.
//  Copyright (c) 2013年 CS246-118. All rights reserved.
//
#include "potion.h"
using namespace std;

Potion::Potion(std::string race) : race(race) { }

string Potion::displayPotion(map <string, bool> &m) {
    string potionType = getRace();
    if (m[potionType] == false) {
        return "an unknown potion. ";
    }
    else {
        return "a "+ getRace() + ". ";
    }
}