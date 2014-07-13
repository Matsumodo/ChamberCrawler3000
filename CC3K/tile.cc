//
//  tile.cc
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-20.
//  Copyright (c) 2013年 CS246-118. All rights reserved.
//

#include "tile.h"

using namespace std;

void Tile::setCoords(int x, int y) {
    this->x = x;
    this->y = y;
}

int Tile::getX() {
    return x;
}
int Tile::getY() {
    return y;
}

void Tile::setGameObject(gameObject *thing) {
    this->thing = thing;
}

void Tile::notifyDisplay(TextDisplay &td) {
    char type = ' ';
    if (thing) {
        string mytype = thing->getType();
        if (mytype == "horizontalWall") {
            type = '-';
        }
        else if (mytype == "verticalWall") {
            type = '|';
        }
        else if (mytype == "Ground") {
            type = '.';
            //cout << "tile at: x = " << x << " y = " << y << "is Ground!" << endl;
        }
        else if (mytype == "Door") {
            type = '+';
        }
        else if (mytype == "Passage") {
            type = '#';
        }
        else if (mytype == "PC") {
            type = '@';
        }
        else if(mytype == "Stairway") {
            type = '/';
        }
        else if(mytype == "Werewolf") {
            type = 'W';
        }
        else if(mytype == "Vampire") {
            type = 'V';
        }
        else if(mytype == "Troll") {
            type = 'T';
        }
        else if(mytype == "Goblin") {
            type = 'N';
        }
        else if(mytype == "Merchant") {
            type = 'M';
        }
        else if(mytype == "Phoenix") {
            type = 'X';
        }
        else if(mytype == "Dragon") {
            type = 'D';
        }
        else if(mytype == "Potion") {
            type = 'P';
        }
        else if(mytype == "Treasure") {
            type = 'G';
        }
        else { }
        //cout << "type at tile x = " << x << " y = " << y << "is of type" << mytype<< endl;
        
    }
    td.notify(getX(), getY(), type);
}