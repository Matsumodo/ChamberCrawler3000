//
//  enemy.cc
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-24.
//  Copyright (c) 2013Äê CS246-118. All rights reserved.
//
#include "enemy.h"
#include "playercharacter.h"
#include "grid.h"
#include <cmath>
#include <sstream>
using namespace std;

Enemy::Enemy(int x, int y, int HP, int Atk, int Def, bool isAlive, std::string race, Grid *g):
             x(x),y(y),HP(HP),Atk(Atk),Def(Def),isAlive(isAlive),race(race), g(g){}

int Enemy::getX() { return x; }

int Enemy::getY() { return y; }

int Enemy::getHP() { return HP; }

int Enemy::getAtk() { return Atk; }

int Enemy::getDef() { return Def; }

bool Enemy::getStatus() { return isAlive; }

void Enemy::setHP(int currentHP) { HP = currentHP; }

string Enemy::getRace() { return race; }

string Enemy::getType() { return race; }

string Enemy::attack(playerCharacter* player){
    int d = ceil((100/(double)(100 + player->getDef())) * Atk);
    int success = rand() % 2;
    int pcHP = player->getHP()-d;
    std::string result = "";
    if(success) {
        player->setHP((pcHP <= 0) ? 0 : pcHP);
        string damage;
        ostringstream convert;
        convert << d;
        damage = convert.str();
        result = race + " deals "+ damage +" damages on PC. ";
        return result;
    }
    result = race + " missed the attack. ";
    return result;
}

void Enemy::setGrid(Grid *g) {this->g = g; }
