//
//  playercharacter.cc
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-24.
//  Copyright (c) 2013Äê CS246-118. All rights reserved.
//
#include "playercharacter.h"
#include "textdisplay.h"
#include "grid.h"
#include <iostream>
using namespace std;

playerCharacter::playerCharacter(int wallet, int x, int y, int HP, int maxHP, int Atk, int Def, bool isAlive, std::string race, Grid* g) : wallet(wallet),x(x),y(y),HP(HP),maxHP(maxHP),Atk(Atk),Def(Atk),extraAtk(0), extraDef(0), isAlive(isAlive),race(race),g(g), preTileObject("Ground"){}

bool playerCharacter::move(string direction) {
    bool move = false;
    std::string type;
    int tempX = x;
    int tempY = y;
    Factory factory;
    if(direction == "no") { tempX = x - 1; }
    else if(direction == "so") { tempX = x + 1; }
    else if(direction == "ea") { tempY = y + 1; }
    else if(direction == "we") { tempY = y - 1; }
    else if(direction == "ne") { tempX = x - 1; tempY = y + 1; }
    else if(direction == "nw") { tempX = x - 1; tempY = y - 1; }
    else if(direction == "se") { tempX = x + 1; tempY = y + 1; }
    else if(direction == "sw") { tempX = x + 1; tempY = y - 1; }
    else {}
	if(g->theGrid[tempX][tempY].thing) {
		type = g->theGrid[tempX][tempY].thing->getType();
		if(type == "Treasure") {
			if(g->theGrid[tempX][tempY].thing->getRace() == "dragonHorde") {
				dragonHorde* pgold = dynamic_cast<dragonHorde* >(g->theGrid[tempX][tempY].thing);
				if(pgold->dragonLocation->thing->getType() != "Dragon") {
					setWallet(pgold->getValue());
					move = true;
				}
				else { return false; }
			}
			else {
				Treasure* gold = dynamic_cast<Treasure* >(g->theGrid[tempX][tempY].thing);
				setWallet(gold->getValue());
				move = true;
			}
		}
		else if (type == "Stairway") {
			g->level += 1;
			preTileObject = "Ground";
			moveExtraAtk();
			moveExtraDef();
			return true;
		}
		else if (type == "Ground") {
			move = true;
		}
		else if (type == "Door") {
			move = true;
		}
		else if (type == "Passage") {
			move = true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
	if(move) {
		gameObject* temp = g->theGrid[x][y].thing; // tmp PC
		g->theGrid[x][y].thing = factory.createFloorElem(preTileObject);
		g->theGrid[x][y].notifyDisplay(*(g->td));
        if (type == "Treasure") {
            preTileObject = "Ground";
        }
        else {
            preTileObject = g->theGrid[tempX][tempY].thing->getType();
        }
		delete g->theGrid[tempX][tempY].thing;
		g->theGrid[tempX][tempY].thing = NULL;
		g->theGrid[tempX][tempY].thing = temp;
		g->theGrid[tempX][tempY].notifyDisplay(*(g->td));
		x = tempX;
		y = tempY;
		return true;
	}
    
    else { return false;}
}

void playerCharacter::setHP(int currentHP) {
	 if((0 <= currentHP) && (currentHP <= maxHP)) {
         HP = currentHP;
	 }
}

void playerCharacter::setWallet(int change) {
	 wallet += change;
}

void playerCharacter::setGrid(Grid *g) {this->g = g; }

int playerCharacter::getWallet() { return wallet; }

int playerCharacter::getX() { return x; }

int playerCharacter::getY() { return y; }

int playerCharacter::getHP() { return HP; }

int playerCharacter::getMaxHP() { return maxHP; }

int playerCharacter::getAtk() { return Atk; }

int playerCharacter::getDef() { return Def; }

bool playerCharacter::getStatus() { return isAlive; }

Grid *playerCharacter::getGrid() {return g;}

std::string playerCharacter::getRace() { return race; }

std::string playerCharacter::getType() { return "PC"; }

playerCharacter::~playerCharacter() {}

