//
//  playercharacter.h
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-24.
//  Copyright (c) 2013Äê CS246-118. All rights reserved.
//
#ifndef __PLAYERCHARACTER_H__
#define __PLAYERCHARACTER_H__

#include <string>
#include "gameobject.h"
#include "tile.h"

class Grid;
class TextDisplay;
class Potion;
class Enemy;

class playerCharacter : public gameObject {
	//char floorType; 
protected:
	int wallet;
	int x;  // coordinate x
	int y;  // coordinate y
	int HP; // current health
	int maxHP; // maximum health
	int Atk; // Attack
	int Def; // Defense
    	int extraAtk;
   	int extraDef;
	bool isAlive; //whether the character is alive or not
	std::string race; //player choice of race
	Grid *g;
public:
    	std::string preTileObject;
	playerCharacter(int wallet, int x, int y, int HP, int maxHP, int Atk, int Def, bool isAlive, std::string race, Grid* g);
        bool move(std::string direction);    // move the character
	//void setAlive(bool alive); 
	void setHP(int currentHP);           // reset HP due to damage or heal
    	void setCoords(int x, int y) { this->x = x;  this->y = y; }
	void setWallet(int change);          // reset golds in wallet
    	int getWallet();
	int getX();                          // get X postion
	int getY();                          // get Y position
	int getHP();                         // get the current health
	int getMaxHP();                      // get the maximum health
	int getAtk();                        // get the Atk power
	int getDef();                        // get the defense power
    	int getExtraAtk() { return extraAtk; }
    	int getExtraDef() { return extraDef; }
    	void setExtraAtk(int change) { extraAtk += change; }
    	void setExtraDef(int change) { extraDef += change; }
    	void moveExtraAtk() { extraAtk = 0; }
    	void moveExtraDef() { extraDef = 0; }
	bool getStatus();                    // check whether the character is dead or alive
    	std::string getType();
    	std::string getRace();
    	Grid *getGrid();
    	void setGrid(Grid * g);
    	virtual void usePotion(Potion *po) = 0;
	virtual ~playerCharacter();
};





#endif
