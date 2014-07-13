//
//  enemy.h
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-24.
//  Copyright (c) 2013Äê CS246-118. All rights reserved.
//
#ifndef __ENEMY_H__
#define __ENEMY_H__
#include <string>
#include "gameobject.h"
class Grid;
class playerCharacter;
class Enemy : public gameObject {
protected:
	int x;
	int y;
	int HP;
	int Atk;
	int Def;
	bool isAlive;
	std::string race;
	Grid* g;
public:
	Enemy(int x, int y, int HP, int Atk, int Def, bool isAlive, std::string race, Grid* theGrid);
	int getX();
	int getY();
    void setCoords(int x, int y) { this->x = x;  this->y = y; }
	int getHP();
	int getAtk();
	int getDef();
	bool getStatus();
	void setHP(int currentHP);
	std::string getType();
    std::string getRace();
    std::string attack(playerCharacter* p);
    void setGrid(Grid * g);
	virtual ~Enemy() {};
};

#endif