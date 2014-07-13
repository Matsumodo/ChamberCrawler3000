//
//  factory.cc
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-25.
//  Copyright (c) 2013年 CS246-118. All rights reserved.
//

#include "factory.h"

using namespace std;

floorElem *Factory::createFloorElem(std::string type) {
    floorElem* f = NULL;
    if (type == "verticalWall") {
        f = new vWall;
    }
    else if (type == "horizontalWall") {
        f = new hWall;
    }
    else if (type == "Door") {
        f = new Door;
    }
    else if (type == "Passage") {
        f = new Passage;
    }
    else if (type == "Stairway") {
        f = new Stairway;
    }
    else if (type == "Ground") {
        f = new Ground;
    }
    else {}
    return f;
}

playerCharacter* Factory::createPlayerCharacter(std::string type) {
    playerCharacter* c = NULL;
    if (type == "Dwarf") {
        c = new Dwarf;
    }
    else if (type == "Human") {
        c = new Human;
    }
    else if (type == "Orc") {
        c = new Orc;
    }
    else if (type == "Elves") {
        c = new Elves;
    }
    else {}
    return c;
}

Item* Factory::createItem(std::string type) {
    Item* i = NULL;
    if (type == "RH") {
        i = new RH;
    }
    else if (type == "BA") {
        i = new BA;
    }
    else if (type == "BD") {
        i = new BD;
    }
    else if (type == "PH") {
        i = new PH;
    }
    else if (type == "WA") {
        i = new WA;
    }
    else if (type == "WD") {
        i = new WD;
    }
    else if (type == "normalGold") {
        i = new normalGold;
    }
    else if (type == "smallHorde") {
        i = new smallHorde;
    }
    else if (type == "merchantHorde") {
        i = new merchantHorde;
    }
    else if (type == "dragonHorde") {
        i = new dragonHorde;
    }
    else {}
    return i;
}

Enemy* Factory::createEnemy(std::string type) {
    Enemy* e = NULL;
    if (type == "Troll") {
        e = new Troll;
    }
    else if (type == "Goblin") {
        e = new Goblin;
    }
    else if (type == "Phoenix") {
        e = new Phoenix;
    }
    else if (type == "Vampire") {
        e = new Vampire;
    }
    else if (type == "Werewolf") {
        e = new Werewolf;
    }
    else if (type == "Merchant") {
        e = new Merchant;
    }
    else if (type == "Dragon") {
        e = new Dragon;
    }
    else {}
    return e;
}