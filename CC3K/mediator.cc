//
//  mediator.cc
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-24.
//  Copyright (c) 2013Äê CS246-118. All rights reserved.
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include "mediator.h"
#include "playercharacter.h"
#include "enemy.h"
#include "grid.h"
#include "merchant.h"
#include "factory.h"

using namespace std;


Mediator::Mediator(Grid* g):g(g){}

std::string Mediator::combat(int Ax, int Ay, int Dx, int Dy){
	Factory factory;
	string result = "";
	if(g->theGrid[Dx][Dy].thing == NULL ||
           g->theGrid[Dx][Dy].thing->getType() == "Potion" ||
	   g->theGrid[Dx][Dy].thing->getType() == "Ground" ||
	   g->theGrid[Dx][Dy].thing->getType() == "horizontalWall" ||
	   g->theGrid[Dx][Dy].thing->getType() == "verticalWall" ||
	   g->theGrid[Dx][Dy].thing->getType() == "Door" ||
	   g->theGrid[Dx][Dy].thing->getType() == "Passage" ||
	   g->theGrid[Dx][Dy].thing->getType() == "Stairway" ||
	   g->theGrid[Dx][Dy].thing->getType() == "Treasure")
    {
		result = "PC deals an invalid attack. ";
	}
	else {
        gameObject* thing;
        int dam;
		playerCharacter* player = dynamic_cast<playerCharacter* >(g->theGrid[Ax][Ay].thing);
        string enemytype = g->theGrid[Dx][Dy].thing->getType();
		if(enemytype == "Merchant") {
			Merchant* merchant = dynamic_cast<Merchant*>(g->theGrid[Dx][Dy].thing);
			merchant->turnOnHostile();
            dam = ceil((100/(double)(100 + merchant->getDef())) * player->getAtk());
            if (merchant->getHP() - dam <= 0) {
                result = "PC killed " + merchant->getRace() + ". ";
                thing = factory.createItem("merchantHorde");
                delete g->theGrid[Dx][Dy].thing;
                g->theGrid[Dx][Dy].thing = thing;
                g->theGrid[Dx][Dy].notifyDisplay(*(g->td));
            }
            else {
                merchant->setHP(merchant->getHP() - dam);
                int enemyHP = merchant->getHP();
                string HP;
                string damage;
                ostringstream convert1;
                ostringstream convert2;
                convert1 << enemyHP;
                convert2 << dam;
                HP = convert1.str();
                damage = convert2.str();
                result = "PC deals " + damage + " damage to Merchant (" + HP + "). " ;
            }
		}
        else if (enemytype == "Dragon") {
            Dragon* dragon = dynamic_cast<Dragon*>(g->theGrid[Dx][Dy].thing);
			dam = ceil((100/(double)(100 + dragon->getDef())) * player->getAtk());
            if (dragon->getHP() - dam <= 0) {
                result = "PC killed " + dragon->getRace() + ". ";
                thing = factory.createFloorElem("Ground");
                delete g->theGrid[Dx][Dy].thing;
                g->theGrid[Dx][Dy].thing = thing;
                g->theGrid[Dx][Dy].notifyDisplay(*(g->td));
            }
            else {
                dragon->setHP(dragon->getHP() - dam);
                int enemyHP = dragon->getHP();
                string HP;
                string damage;
                ostringstream convert1;
                ostringstream convert2;
                convert1 << enemyHP;
                convert2 << dam;
                HP = convert1.str();
                damage = convert2.str();
                result = "PC deals " + damage + " damage to Dragon (" + HP + "). " ;
            }
        }
        else {
            Enemy* enemy = dynamic_cast<Enemy*>(g->theGrid[Dx][Dy].thing);
            dam = ceil((100/(double)(100 + enemy->getDef())) * player->getAtk());
            if (enemy->getHP() - dam <= 0) {
                result = "PC killed " + enemy->getRace() + ".";
                player->setWallet(1);
                thing = factory.createFloorElem("Ground");
                delete g->theGrid[Dx][Dy].thing;
                g->theGrid[Dx][Dy].thing = thing;
                g->theGrid[Dx][Dy].notifyDisplay(*(g->td));
            }
            else {
                enemy->setHP(enemy->getHP() - dam);
                int enemyHP = enemy->getHP();
                string HP;
                string damage;
                ostringstream convert1;
                ostringstream convert2;
                convert1 << enemyHP;
                convert2 << dam;
                HP = convert1.str();
                damage = convert2.str();
                result = "PC deals " + damage + " damage to "+ enemy->getRace() + " (" + HP + "). " ;
            }
        }
    }
    return result;
}


Mediator::~Mediator() {}
