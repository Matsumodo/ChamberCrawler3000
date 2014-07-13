//
//  grid.h
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-20.
//  Copyright (c) 2013年 CS246-118. All rights reserved.
//

#ifndef __CC3K__grid__
#define __CC3K__grid__
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <fstream>

class Tile;
class TextDisplay;
#include "factory.h"
#include "chamber.h"

class Grid {
    int width, height;
    Chamber chamber[5];
    playerCharacter* pc;
    Factory* factory;
public:
    int level;
    Tile** theGrid;
    TextDisplay* td;
    std::string layout; // file name for floor layout
    Grid(int x, int y, TextDisplay* td);
    ~Grid();
    playerCharacter* getGridPCPtr() { return pc; }
    void setGridPCPtr(playerCharacter* pc) { this->pc = pc; }
    void clearGrid();
    void initFloor(char pcrace);
    playerCharacter* generatePlayerCharacter(char pcrace);
    void generateStairway();
    void generateEnemies();
    void generateItem(char itemType);  // itemType = p / g represents potion or gold
    std::string enemyRandomMove();
    friend std::ostream& operator<<(std::ostream &out, const Grid &g);
     /*
     void setPotions();
     void setTreasure();*/
     void setLayout(char c); // c = p / g represents potion or gold
     
};

#endif
