//
//  grid.cc
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-20.
//  Copyright (c) 2013年 CS246-118. All rights reserved.
//
#include <cmath>
#include "grid.h"
#include <map>
#include "tile.h"

using namespace std;

Grid::Grid(int x, int y, TextDisplay* td): width(x), height(y),pc(NULL),factory(new Factory),level(1),theGrid(NULL),td(td),layout("defaultfloor.txt"){}

void Grid::clearGrid() {
    for (size_t i = 0; i < 5; i++) {
        for (size_t j = 0; j < chamber[i].v.size(); j++) {
            //if (chamber[i].v[j]->thing != NULL) {
            //delete chamber[i].v[j];
            //}
chamber[i].v.clear();
        }
    }
    for(int i = 0; i < height; i++) {
        delete [] theGrid[i];
    }
    delete factory;
    delete [] theGrid;
    delete td;
}

Grid::~Grid() {
    clearGrid();
}

void Grid::initFloor(char pcrace) {
    // new 2-d array
    theGrid = new Tile *[height];
    for (int i = 0; i < height; i++) {
        theGrid[i] = new Tile[width];
    }
    // for every tile , setCoords
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            theGrid[i][j].setCoords(i, j);
        }
    }
    ifstream file("defaultfloor.txt");
    // translate the default layout
    for (int i = 0; i < height; i++) {
        string line;
        getline(file, line);
        for (int j = 0; j < width; j++) {
            if (line[j] == '.') {
                theGrid[i][j].isOccupied = false;
                floorElem *gr;
                gr = factory->createFloorElem("Ground");
                theGrid[i][j].setGameObject(gr);
                theGrid[i][j].notifyDisplay(*td);
            }
            else if (line[j] == '|') {
                theGrid[i][j].isOccupied = true;
                floorElem *vw = NULL;
                vw = factory->createFloorElem("verticalWall");
                theGrid[i][j].setGameObject(vw);
                theGrid[i][j].notifyDisplay(*td);
            }
            else if (line[j] == '-') {
                theGrid[i][j].isOccupied = true;
                floorElem *hw = NULL;
                hw = factory->createFloorElem("horizontalWall");
                theGrid[i][j].setGameObject(hw);
                theGrid[i][j].notifyDisplay(*td);
            }
            else if (line[j] == '+') {
                theGrid[i][j].isOccupied = true;
                floorElem *door = NULL;
                door = factory->createFloorElem("Door");
                theGrid[i][j].setGameObject(door);
                theGrid[i][j].notifyDisplay(*td);
            }
            else if (line[j] == '#') {
                theGrid[i][j].isOccupied = true;
                floorElem *pss = NULL;
                pss = factory->createFloorElem("Passage");
                theGrid[i][j].setGameObject(pss);
                theGrid[i][j].notifyDisplay(*td);
            }
            else { }
        }
    }
    // set each Chamber <class>
    chamber[0].setChamberNum(0);
    for(int i = 3; i < 7; i++) {
        for(int j = 3; j < 29; j++) {
            chamber[0].v.push_back(&theGrid[i][j]);
            
        }
    }
    chamber[1].setChamberNum(1);
    for(int i = 15; i < 22; i++) {
        for(int j = 4; j < 25; j++) {
            chamber[1].v.push_back(&theGrid[i][j]);
        }
    }
    chamber[2].setChamberNum(2);
    for(int i = 10; i < 13; i++) {
        for(int j = 38; j < 50; j++) {
            chamber[2].v.push_back(&theGrid[i][j]);
        }
    }
    chamber[3].setChamberNum(3);
    for(int i = 19; i < 22; i++) {
        for(int j = 37; j < 65; j++) {
            chamber[3].v.push_back(&theGrid[i][j]);
        }
    }
    for(int i = 16; i < 22; i++) {
        for(int j = 65; j < 76; j++) {
            chamber[3].v.push_back(&theGrid[i][j]);
        }
    }
    chamber[4].setChamberNum(4);
    for(int i = 3; i < 7; i++) {
        for(int j = 39; j < 61; j++) {
            chamber[4].v.push_back(&theGrid[i][j]);
        }
    }
    for(int i = 6; i < 13; i++) {
        for(int j = 70; j < 73; j++) {
            chamber[4].v.push_back(&theGrid[i][j]);
        }
    }
	for(int i = 7; i < 13; i++) {
		for (int j = 73; j < 76;j++) {
			chamber[4].v.push_back(&theGrid[i][j]);
		}
	}
    for(int i = 5; i < 13; i++) {
        for(int j = 62; j < 70; j++) {
            chamber[4].v.push_back(&theGrid[i][j]);
        }
    }
    
    for (int i = 3; i < 13; i++) {
        chamber[4].v.push_back(&theGrid[i][61]);
    }
    if (layout != "defaultfloor.txt") {
        setLayout(pcrace);
    }
    
}

playerCharacter* Grid::generatePlayerCharacter(char pcrace) {
    string race;
    switch (pcrace) {
        case 'h':
            race = "Human";
            break;
        case 'o':
            race = "Orc";
            break;
        case 'd':
            race = "Dwarf";
            break;
        case 'e':
            race = "Elves";
            break;
        default:
            race = "Human";
            break;
    }
    int chamberNum = rand() % 5;
    int tileNum = rand() % chamber[chamberNum].v.size();
    int i = chamber[chamberNum].v[tileNum]->getX();
    int j = chamber[chamberNum].v[tileNum]->getY();
    if (theGrid[i][j].thing != NULL) {
        delete theGrid[i][j].thing;
    }
    theGrid[i][j].thing = NULL;
    playerCharacter *pc = factory->createPlayerCharacter(race);
    pc->setGrid(this);
    pc->setCoords(i, j);
    theGrid[i][j].setGameObject(pc);
    theGrid[i][j].isOccupied = true;
    
    setGridPCPtr(pc);
    theGrid[i][j].notifyDisplay(*td);
    return pc;
}

void Grid::generateStairway() {
    //srand( static_cast<unsigned int>(time(NULL)));
    int chamberNum = rand() % 5;
    //srand( static_cast<unsigned int>(time(NULL)));
    int tileNum = rand() % chamber[chamberNum].v.size();
    
    int x = chamber[chamberNum].v[tileNum]->getX();
    int y = chamber[chamberNum].v[tileNum]->getY();
    
    if(theGrid[x][y].isOccupied) {
        generateStairway();
    }
    else {
        if (theGrid[x][y].thing != NULL) {
            delete theGrid[x][y].thing;
        }
        theGrid[x][y].thing = NULL;
        floorElem *s = factory->createFloorElem("Stairway");
        theGrid[x][y].setGameObject(s);
        theGrid[x][y].isOccupied = true;
        theGrid[x][y].notifyDisplay(*td);
    }
}

void Grid::generateItem(char c) {
    map <int, string> m;
    m[0] = "RH"; m[1] = "BA"; m[2] = "BD"; m[3] = "PH"; m[4] = "WA"; m[5] = "WD";
    m[10] = "normalGold"; m[11] = "smallHorde"; m[12] = "merchantHorde"; m[13] = "dragonHorde";
    int itemType;
    // rand()
    for(int i = 0; i < 10; i++) {
        if (c == 'p') {
            itemType = rand() % 6;
        }
        else {
            itemType = rand() % 4 + 10;
        }
        int chamberNum = rand() % 5;
        int tileNum = rand() % chamber[chamberNum].v.size();
        
        int x = chamber[chamberNum].v[tileNum]->getX();
        int y = chamber[chamberNum].v[tileNum]->getY();
        
        if(theGrid[x][y].isOccupied) {
            i--;
        }
        else {
            if (c == 'g' && m[itemType] == "dragonHorde") {
                int xcoord,ycoord;
                bool isFound = false;
                vector<int> v;
                for (int n = 0; n < 8; n++){
                    v.push_back(n);
                }
                while (v.size()) {
                    // 0-no,1-so,2-ea,3-we,4-ne,5-nw,6-se,7-sw
                    int direction = rand() % v.size();
                    if(direction == 0) { xcoord = x - 1; ycoord = y; }
                    else if(direction == 1) { xcoord = x + 1; ycoord = y; }
                    else if(direction == 2) { xcoord = x; ycoord = y + 1;}
                    else if(direction == 3) { xcoord = x; ycoord = y - 1;}
                    else if(direction == 4) { xcoord = x - 1; ycoord = y + 1; }
                    else if(direction == 5) { xcoord = x - 1; ycoord = y - 1; }
                    else if(direction == 6) { xcoord = x + 1; ycoord = y + 1; }
                    else if(direction == 7) { xcoord = x + 1; ycoord = y - 1; }
                    else {}
                    if (theGrid[xcoord][ycoord].isOccupied != true) {
                        isFound = true;
                        break;
                    }
                    v.erase(v.begin() + direction);
                } // end of while loop
                // whether there is no unoccupied spot near dragonhorde
                if (isFound == false) {
                    i--;
                    continue;
                }
                else {
                    // now we know the coords of both dragonHorde and Dragon
                    Item *dh = NULL;
                    dh = factory->createItem("dragonHorde");
                    if (theGrid[x][y].thing != NULL) {
                        delete theGrid[x][y].thing;
                    }
                    theGrid[x][y].thing = NULL;
                    
                    dragonHorde* pgold = dynamic_cast < dragonHorde * >( dh );
                    theGrid[x][y].setGameObject(pgold);
                    pgold->setDragonLocation(&theGrid[xcoord][ycoord]);
                    theGrid[x][y].isOccupied = true;
                    theGrid[x][y].notifyDisplay(*td);
                    
                    // for the dragon part
                    Enemy *dra = NULL;
                    dra = factory->createEnemy("Dragon");
                    if (theGrid[xcoord][ycoord].thing != NULL) {
                        delete theGrid[xcoord][ycoord].thing;
                    }
                    theGrid[xcoord][ycoord].thing = NULL;
                    Dragon* pdragon = dynamic_cast < Dragon * >( dra );
                    
                    theGrid[xcoord][ycoord].setGameObject(pdragon);
                    pdragon->setTreasureLocation(&theGrid[x][y]);
                    theGrid[xcoord][ycoord].isOccupied = true;
                    theGrid[xcoord][ycoord].notifyDisplay(*td);
                }
            }
            // potion or treasure that is not dragonhorde
            else  {
                if (theGrid[x][y].thing != NULL) {
                    delete theGrid[x][y].thing;
                }
                theGrid[x][y].thing = NULL;
                Item *p = factory->createItem(m[itemType]);
                theGrid[x][y].setGameObject(p);
                theGrid[x][y].isOccupied = true;
                theGrid[x][y].notifyDisplay(*td);
            }
        }
    }
}

void Grid::generateEnemies() {
    for (int i = 0; i < 20; i++) {
        map <int, string> m;
        m[0]=m[1]=m[2]=m[3]= "Werewolf"; m[4]=m[5]=m[6]= "Vampire"; m[7]=m[8]=m[9]=m[10]=m[11] = "Goblin";
        m[12]=m[13] = "Troll"; m[14]=m[15] ="Phoenix"; m[16]=m[17] = "Merchant";
        int race = rand() % m.size();
        int chamberNum = rand() % 5;
        int tileNum = rand() % chamber[chamberNum].v.size();
        int x = chamber[chamberNum].v[tileNum]->getX();
        int y = chamber[chamberNum].v[tileNum]->getY();
        if (theGrid[x][y].isOccupied) {
            i--;
        }
        else {
            delete theGrid[x][y].thing;
            theGrid[x][y].thing = NULL;
            Enemy *e = NULL;
            e = factory->createEnemy(m[race]);
            e->setGrid(this);
            e->setCoords(x, y);
            theGrid[x][y].setGameObject(e);
            theGrid[x][y].isOccupied = true;
            theGrid[x][y].notifyDisplay(*td);
        }
    }
}


string Grid::enemyRandomMove() {
    vector<Enemy* > v;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (theGrid[i][j].thing) {
                string tempType = theGrid[i][j].thing->getType();
                // check for all enemies
                if (tempType != "Dragon" && tempType != "horizontalWall" && tempType != "verticalWall" &&
                    tempType != "Door" && tempType != "Passage" && tempType != "Stairway" &&
                    tempType != "Ground" && tempType != "Potion" && tempType != "Treasure" && tempType != "PC") {
                    Enemy* e = dynamic_cast<Enemy*>(theGrid[i][j].thing);
                    v.push_back(e);
                }
            }
        }
    }
    vector<int> d;
    for (int n = 0; n < 8; n++){
        d.push_back(n);
    }
    int x, y; // present coord
    bool goToFight = false;
    string tmp = "";
    for (size_t i = 0; i < v.size(); i++) {
        x = v[i]->getX(); // present coord
        y = v[i]->getY();
		int doubtX,doubtY;
        for (int n = 0; n < 8; n++){
            if(n == 0) { doubtX = x - 1; doubtY = y; }
            else if(n == 1) { doubtX = x + 1; doubtY = y; }
            else if(n == 2) { doubtX = x; doubtY = y + 1;}
            else if(n == 3) { doubtX = x; doubtY = y - 1;}
            else if(n == 4) { doubtX = x - 1; doubtY = y + 1; }
            else if(n == 5) { doubtX = x - 1; doubtY = y - 1; }
            else if(n == 6) { doubtX = x + 1; doubtY = y + 1; }
            else if(n == 7) { doubtX = x + 1; doubtY = y - 1; }
            else {}
            
            if (theGrid[doubtX][doubtY].thing) {
                if (theGrid[doubtX][doubtY].thing->getType() == "PC") {
                    if (v[i]->getType() == "Merchant") {
                        Merchant* m = dynamic_cast < Merchant * >(v[i]);
                        playerCharacter* ppcc = dynamic_cast < playerCharacter * >( theGrid[doubtX][doubtY].thing );
                        if (m->checkHostile()) {
                            tmp = tmp + " " + m->attack(ppcc);
                            goToFight = true;
                            break;
                        }
                    }
                    else {
                        playerCharacter* ppcc = dynamic_cast < playerCharacter * >( theGrid[doubtX][doubtY].thing );
                        tmp = tmp + " " + v[i]->attack(ppcc);
                        goToFight = true;
                        break;
                    }
                }
            }
            else {}
        }
        int r,c; // future coord
        bool isFound = false;
        vector<int> directionStat;
        for (int i = 0; i < 8; i++){
            directionStat.push_back(i);
        }
        while (directionStat.size()) {
            size_t direction = rand() % 8;
            if (direction >= directionStat.size()) {
                continue;
            }
            if(direction == 0) { r = x - 1; c = y; }
            else if(direction == 1) { r = x + 1; c = y; }
            else if(direction == 2) { r = x; c = y + 1;}
            else if(direction == 3) { r = x; c = y - 1;}
            else if(direction == 4) { r = x - 1; c = y + 1; }
            else if(direction == 5) { r = x - 1; c = y - 1; }
            else if(direction == 6) { r = x + 1; c = y + 1; }
            else if(direction == 7) { r = x + 1; c = y - 1; }
            else { }
            if (theGrid[r][c].thing) {
                if (theGrid[r][c].thing->getType() == "Ground") { // ground tile
                    isFound = true;
                    break;
                }
            }
            directionStat.erase(directionStat.begin() + direction);
        }
        if (isFound && !goToFight) {  // enemy will move
            gameObject *tmp;
            tmp= theGrid[x][y].thing;
            theGrid[x][y].isOccupied = false;
            floorElem *floor;
            floor = factory->createFloorElem("Ground");
            theGrid[x][y].setGameObject(floor);
            
            // set the enemy to the new tile
            delete theGrid[r][c].thing;
            theGrid[r][c].thing = NULL;
            theGrid[r][c].isOccupied = true;
            theGrid[r][c].setGameObject(tmp);
            v[i]->setCoords(r, c);
            theGrid[x][y].notifyDisplay(*td);
            theGrid[r][c].notifyDisplay(*td);
        }
        else {}
    }
    return tmp;
}

ostream& operator<<(ostream &out, const Grid &g) {
    out << *(g.td);
    if (g.pc != NULL) {
        string race = g.pc->getRace();
        int wallet = g.pc->getWallet();
        if (race == "Orc") { wallet = wallet / 2; }
        else if (race == "Dwarf") { wallet = wallet * 2; }
        out << "Race: " << race << " ";
        out << "Gold: " << wallet;
        out << "                                       Floor: " << g.level << endl;
        out << "HP: " << g.pc->getHP() << endl;
        out << "Atk: " << g.pc->getAtk() + g.pc->getExtraAtk() << endl;
        out << "Def: " << g.pc->getDef() + g.pc->getExtraDef()<< endl;
    }
    else {
        out << "Race: " << "Human" << " ";
        out << "Gold: " << 0;
        out << "                                       Floor: " << 1 << endl;
        out << "HP: " << 20 << endl;
        out << "Atk: " << 20 << endl;
        out << "Def: " << 20 << endl;
    }
    return out;
}


void Grid::setLayout(char pcrace) {
    ifstream file(layout.c_str());
    for (int i = 0; i < height; i++) {
        string line;
        getline(file, line);
        for(int j = 0; j < width; j++) {
            if(line[j] == 'N') {
                Enemy* enemy = factory->createEnemy("Goblin");
                delete theGrid[i][j].thing;
                theGrid[i][j].setGameObject(enemy);
                enemy->setGrid(this);
                enemy->setCoords(i, j);
                theGrid[i][j].isOccupied = true;
                theGrid[i][j].notifyDisplay(*td);
            }
            else if(line[j] == 'X') {
                Enemy* enemy = factory->createEnemy("Phoenix");
                delete theGrid[i][j].thing;
                theGrid[i][j].setGameObject(enemy);
                enemy->setGrid(this);
                enemy->setCoords(i, j);
                theGrid[i][j].isOccupied = true;
                theGrid[i][j].notifyDisplay(*td);
            }
            else if(line[j] == 'W') {
                Enemy* enemy = factory->createEnemy("Werewolf");
                delete theGrid[i][j].thing;
                theGrid[i][j].setGameObject(enemy);
                enemy->setGrid(this);
                enemy->setCoords(i, j);
                theGrid[i][j].isOccupied = true;
                theGrid[i][j].notifyDisplay(*td);
            }
            else if(line[j] == 'V') {
                Enemy* enemy = factory->createEnemy("Vampire");
                delete theGrid[i][j].thing;
                theGrid[i][j].setGameObject(enemy);
                enemy->setGrid(this);
                enemy->setCoords(i, j);
                theGrid[i][j].isOccupied = true;
                theGrid[i][j].notifyDisplay(*td);
            }
            else if(line[j] == 'T') {
                Enemy* enemy = factory->createEnemy("Troll");
                delete theGrid[i][j].thing;
                theGrid[i][j].setGameObject(enemy);
                enemy->setGrid(this);
                enemy->setCoords(i, j);
                theGrid[i][j].isOccupied = true;
                theGrid[i][j].notifyDisplay(*td);
            }
            else if(line[j] == 'M') {
                Enemy* enemy = factory->createEnemy("Merchant");
                delete theGrid[i][j].thing;
                theGrid[i][j].setGameObject(enemy);
                enemy->setGrid(this);
                enemy->setCoords(i, j);
                theGrid[i][j].isOccupied = true;
                theGrid[i][j].notifyDisplay(*td);
            }
            else if (line[j] == '0') {
                Item* item = factory->createItem("RH");
                delete theGrid[i][j].thing;
                theGrid[i][j].setGameObject(item);
                theGrid[i][j].isOccupied = true;
                theGrid[i][j].notifyDisplay(*td);
            }
            else if (line[j] == '1') {
                Item* item = factory->createItem("BA");
                delete theGrid[i][j].thing;
                theGrid[i][j].setGameObject(item);
                theGrid[i][j].isOccupied = true;
                theGrid[i][j].notifyDisplay(*td);
            }
            else if (line[j] == '2') {
                Item* item = factory->createItem("BD");
                delete theGrid[i][j].thing;
                theGrid[i][j].setGameObject(item);
                theGrid[i][j].isOccupied = true;
                theGrid[i][j].notifyDisplay(*td);
            }
            else if (line[j] == '3') {
                Item* item = factory->createItem("PH");
                delete theGrid[i][j].thing;
                theGrid[i][j].setGameObject(item);
                theGrid[i][j].isOccupied = true;
                theGrid[i][j].notifyDisplay(*td);
            }
            else if (line[j] == '4') {
                Item* item = factory->createItem("WA");
                delete theGrid[i][j].thing;
                theGrid[i][j].setGameObject(item);
                theGrid[i][j].isOccupied = true;
                theGrid[i][j].notifyDisplay(*td);
            }
            else if (line[j] == '5') {
                Item* item = factory->createItem("WD");
                delete theGrid[i][j].thing;
                theGrid[i][j].setGameObject(item);
                theGrid[i][j].isOccupied = true;
                theGrid[i][j].notifyDisplay(*td);
            }
            else if (line[j] == '6') {
                Item* item = factory->createItem("normalGold");
                delete theGrid[i][j].thing;
                theGrid[i][j].setGameObject(item);
                theGrid[i][j].isOccupied = true;
                theGrid[i][j].notifyDisplay(*td);
            }
            else if (line[j] == '7') {
                Item* item = factory->createItem("smallHorde");
                delete theGrid[i][j].thing;
                theGrid[i][j].setGameObject(item);
                theGrid[i][j].isOccupied = true;
                theGrid[i][j].notifyDisplay(*td);
            }
            else if (line[j] == '8') {
                Item* item = factory->createItem("merchantHorde");
                delete theGrid[i][j].thing;
                theGrid[i][j].setGameObject(item);
                theGrid[i][j].isOccupied = true;
                theGrid[i][j].notifyDisplay(*td);
            }
            else if (line[j] == '9') {
                Item* item = factory->createItem("dragonHorde");
                delete theGrid[i][j].thing;
                theGrid[i][j].setGameObject(item);
                theGrid[i][j].isOccupied = true;
                theGrid[i][j].notifyDisplay(*td);
            }
            else if (line[j] == 'D') {
                Enemy* e = factory->createEnemy("Dragon");
                delete theGrid[i][j].thing;
                theGrid[i][j].setGameObject(e);
                theGrid[i][j].isOccupied = true;
                theGrid[i][j].notifyDisplay(*td);
            }
            else if(line[j] == '/') {
                floorElem* floor = factory->createFloorElem("Stairway");
                delete theGrid[i][j].thing;
                theGrid[i][j].setGameObject(floor);
                theGrid[i][j].isOccupied = true;
                theGrid[i][j].notifyDisplay(*td);
            }
            else if (line[j] == '.') {
                theGrid[i][j].isOccupied = false;
                floorElem *gr;
                gr = factory->createFloorElem("Ground");
                delete theGrid[i][j].thing;
                theGrid[i][j].setGameObject(gr);
                theGrid[i][j].notifyDisplay(*td);
            }
            else if (line[j] == '|') {
                theGrid[i][j].isOccupied = true;
                floorElem *gr;
                gr = factory->createFloorElem("verticalWall");
                delete theGrid[i][j].thing;
                theGrid[i][j].setGameObject(gr);
                theGrid[i][j].notifyDisplay(*td);
            }
            else if (line[j] == '-') {
                theGrid[i][j].isOccupied = true;
                floorElem *gr;
                gr = factory->createFloorElem("horizontalWall");
                delete theGrid[i][j].thing;
                theGrid[i][j].setGameObject(gr);
                theGrid[i][j].notifyDisplay(*td);
            }
            else if (line[j] == '+') {
                theGrid[i][j].isOccupied = true;
                floorElem *gr;
                gr = factory->createFloorElem("Door");
                delete theGrid[i][j].thing;
                theGrid[i][j].setGameObject(gr);
                theGrid[i][j].notifyDisplay(*td);
            }
            else if (line[j] == '#') {
                theGrid[i][j].isOccupied = true;
                floorElem *gr;
                gr = factory->createFloorElem("Passage");
                delete theGrid[i][j].thing;
                theGrid[i][j].setGameObject(gr);
                theGrid[i][j].notifyDisplay(*td);
            }
            else if(line[j] == '@') {
                string race;
                switch (pcrace) {
                    case 'h':
                        race = "Human";
                        break;
                    case 'o':
                        race = "Orc";
                        break;
                    case 'd':
                        race = "Dwarf";
                        break;
                    case 'e':
                        race = "Elves";
                        break;
                    default:
                        race = "Human";
                        break;
                }
                delete theGrid[i][j].thing;
                theGrid[i][j].thing = NULL;
                playerCharacter *pc = factory->createPlayerCharacter(race);
                pc->setGrid(this);
                pc->setCoords(i, j);
                theGrid[i][j].setGameObject(pc);
                theGrid[i][j].isOccupied = true;
                setGridPCPtr(pc);
                theGrid[i][j].notifyDisplay(*td);
            }
        }
    }
    
    int xcoord,ycoord;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (theGrid[i][j].thing) {
                if (theGrid[i][j].thing->getType() == "Dragon") {
                    for (int n = 0; n < 8; n++) {
                        if(n == 0) { xcoord = i - 1; ycoord = j; }
                        else if(n == 1) { xcoord = i + 1; ycoord = j; }
                        else if(n == 2) { xcoord = i; ycoord = j + 1;}
                        else if(n == 3) { xcoord = i; ycoord = j - 1;}
                        else if(n == 4) { xcoord = i - 1; ycoord = j + 1; }
                        else if(n == 5) { xcoord = i - 1; ycoord = j - 1; }
                        else if(n == 6) { xcoord = i + 1; ycoord = j + 1; }
                        else if(n == 7) { xcoord = i + 1; ycoord = j - 1; }
                        else {}
                        if (theGrid[xcoord][ycoord].thing) {
                            if (theGrid[xcoord][ycoord].thing->getRace() == "dragonHorde") {
                                dragonHorde* pgold = dynamic_cast < dragonHorde * >( theGrid[xcoord][ycoord].thing );
                                Dragon* pdragon = dynamic_cast < Dragon * >( theGrid[i][j].thing );
                                pdragon->setTreasureLocation(&theGrid[xcoord][ycoord]);
                                pgold->setDragonLocation(&theGrid[i][j]);
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
}
