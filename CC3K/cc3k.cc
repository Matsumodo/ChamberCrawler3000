//
//  main.cc
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-27.
//  Copyright (c) 2013年 CS246-118. All rights reserved.
//

#include <iostream>
#include "playercharacter.h"
#include "enemy.h"
#include "item.h"
#include "mediator.h"
#include "grid.h"
#include "textdisplay.h"
using namespace std;

const int width = 79;
const int height = 25;

int main(int argc, char * argv[]) {
    srand(static_cast<unsigned int>(time(NULL)));
    TextDisplay *td = new TextDisplay(width, height);
    Grid* grid = new Grid(width, height, td);
    playerCharacter* player;
    char pcrace = 'q';
    if (argc <= 1) {
        grid->initFloor(pcrace);
        cout << *grid << "Action: " << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Please choose a race: " << endl;
        cout << "h - Human" << endl;
        cout << "d - Dwarf" << endl;
        cout << "o - Orc" << endl;
        cout << "e - Elves" << endl;
        cout << "Your character will be Human if you enter other character. " << endl;
        cout << "Enter your input here:";
        cin >> pcrace;
        player = grid->generatePlayerCharacter(pcrace);
        grid->setGridPCPtr(player);
        grid->generateStairway();
        grid->generateItem('p');
        grid->generateItem('g');
        grid->generateEnemies();
    }
    
    else {
        string conv = argv[1];
        grid->layout = conv;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "You choose the command line option. " << endl;
        cout << "Please choose a race: " << endl;
        cout << "h - Human" << endl;
        cout << "d - Dwarf" << endl;
        cout << "o - Orc" << endl;
        cout << "e - Elves" << endl;
        cout << "Your character will be Human if you enter other character. " << endl;
        cout << "Enter your input here:";
        cin >> pcrace;
        grid->initFloor(pcrace);
        player = grid->getGridPCPtr();
        
    }
    
	bool successMove = false;
	bool gameContinue = true;
    
    	map <string, bool> m;
    	m["RH"] = false;
    	m["BA"] = false;
    	m["BD"] = false;
    	m["PH"] = false;
    	m["WA"] = false;
    	m["WD"] = false;
    
    	int oldFloor = 1;
    	int newFloor = 1;
    	int cheatTimes = 0;
    	Factory factory;
    
    	cout << *grid << "Action: Player character has spawned. " << endl;
    	string userInput;
	while (gameContinue) {
	    if(player->getHP() == 0) {
			cout << "You die." << endl;
            int wallet = player->getWallet();
            if (player->getRace() == "Human") {
                wallet = (wallet / 2) + wallet;
            }
            else if (player->getRace() == "Dwarf") {
                wallet = wallet + wallet;
            }
            else if (player->getRace() == "Orc") {
                wallet = wallet / 2;
            }
            cout << "You end up with " << wallet << " coins! " << endl;
			break;
		}
        cin >> userInput;
		if (userInput == "q") {
			cout << "You quit the game." << endl;
            int wallet = player->getWallet();
            if (player->getRace() == "Human") {
                wallet = (wallet / 2) + wallet;
            }
            else if (player->getRace() == "Dwarf") {
                wallet = wallet + wallet;
            }
            else if (player->getRace() == "Orc") {
                wallet = wallet / 2;
            }
            cout << "You end up with " << wallet << " coins! " << endl;
			break;
		}
		else if (userInput == "r") {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Please choose a new race: " << endl;
            cout << "h - Human" << endl;
            cout << "d - Dwarf" << endl;
            cout << "o - Orc" << endl;
            cout << "e - Elves" << endl;
            cout << "Your character will be Human if you enter other character. " << endl;
            cout << "Enter your input here:";
            cin >> pcrace;
            delete grid;
            td = new TextDisplay(width, height);
            grid = new Grid(width, height, td);
            if (argc <= 1) {
                grid->initFloor(pcrace);
                player = grid->generatePlayerCharacter(pcrace);
                grid->setGridPCPtr(player);
                grid->generateStairway();
                grid->generateItem('p');
                grid->generateItem('g');
                grid->generateEnemies();
            }
            else {
                string conv(argv[1]);
                grid->layout = conv;
                grid->initFloor(pcrace);
                player = grid->getGridPCPtr();
            }
            m["RH"] = false;
            m["BA"] = false;
            m["BD"] = false;
            m["PH"] = false;
            m["WA"] = false;
            m["WD"] = false;
            cheatTimes = 0;
            oldFloor = 1;
            newFloor = 1;
            cout << *grid
            << "Action: " << "PC restarts the game." << endl;
		}
        else if (userInput == "no" || userInput == "so" || userInput == "ea" ||	userInput == "we" ||
  	             userInput == "ne" || userInput == "nw" || userInput == "se" || userInput == "sw" ) {
            successMove = player->move(userInput);
            newFloor = grid->level;
            string res = grid->enemyRandomMove();
            if(newFloor == oldFloor + 1){
                if(newFloor == 8) {
                    cout << "Reach on 8th floor!! You win! Congratulations!!" << endl;
                    int wallet = player->getWallet();
                    if (player->getRace() == "Human") {
                        wallet = (wallet / 2) + wallet;
                    }
                    else if (player->getRace() == "Dwarf") {
                        wallet = wallet + wallet;
                    }
                    else if (player->getRace() == "Orc") {
                        wallet = wallet / 2;
                    }
                    cout << "You end up with " << wallet << " coins! " << endl;
                    break;
                }
                oldFloor = newFloor;
                int H = player->getHP();
                int W = player->getWallet();
                // playerCharacter* temp = player;
                //grid->theGrid[player->getX()][player->getY()].thing = NULL;
                delete grid;
                td = new TextDisplay(width, height);
                grid = new Grid(width, height, td);
                if (argc <= 1) {
                    grid->initFloor(pcrace);
                    grid->level = newFloor;
                    player = grid->generatePlayerCharacter(pcrace);
                    player->setHP(H);
                    player->setWallet(W);
                    grid->setGridPCPtr(player);
                    grid->generateStairway();
                    grid->generateItem('p');
                    grid->generateItem('g');
                    grid->generateEnemies();
                }
                
                else {
                    grid->level = newFloor;
                    string conv(argv[grid->level]);
                    grid->layout = conv;
                    grid->initFloor(pcrace);
                    player = grid->getGridPCPtr();
                }
                cout << *grid
                << "Action: PC is on a new floor." << endl;
                continue;
            }
                // 1 - direction conversion
                string output;
                if (userInput == "no") {
                    output = "North";
                }
                else if (userInput == "so") {
                    output = "South";
                }
                else if (userInput == "ea") {
                    output = "East";
                }
                else if (userInput == "we") {
                    output = "West";
                }
                else if (userInput == "ne") {
                    output = "Northeast";
                }
                else if (userInput == "se") {
                    output = "Southeast";
                }
                else if (userInput == "nw") {
                    output = "Northwest";
                }
                else if (userInput == "sw") {
                    output = "Southwest";
                }
                // 2 - potion detection
                string potionInfo = "";
                // check for potion
                int doubtX, doubtY;
                int currentX, currentY;
                currentX = player->getX();
                currentY = player->getY();
                for (int n = 0; n < 8; n++){
                    if(n == 0) { doubtX = currentX - 1; doubtY = currentY; }
                    else if(n == 1) { doubtX = currentX + 1; doubtY = currentY; }
                    else if(n == 2) { doubtX = currentX; doubtY = currentY + 1;}
                    else if(n == 3) { doubtX = currentX; doubtY = currentY - 1;}
                    else if(n == 4) { doubtX = currentX - 1; doubtY = currentY + 1; }
                    else if(n == 5) { doubtX = currentX - 1; doubtY = currentY - 1; }
                    else if(n == 6) { doubtX = currentX + 1; doubtY = currentY + 1; }
                    else if(n == 7) { doubtX = currentX + 1; doubtY = currentY - 1; }
                    else {}
                    if (grid->theGrid[doubtX][doubtY].thing) {
                        if (grid->theGrid[doubtX][doubtY].thing->getType() == "Potion") {
                            Potion* ppo = dynamic_cast<Potion* >(grid->theGrid[doubtX][doubtY].thing);
                            potionInfo = potionInfo + "PC sees " + ppo->displayPotion(m);
                        }
                    }
                }
                // 3 - dragonHorde and dragon detection              
                string dragonAttackInfo = "";
                // check for dragon attack
                int dragonHX,dragonHY;
                currentX = player->getX();
                currentY = player->getY();
                for (int j = 0; j < 8; j++) {
                    if(j == 0) { dragonHX = currentX - 1; dragonHY = currentY; }
                    else if(j == 1) { dragonHX = currentX + 1; dragonHY = currentY; }
                    else if(j == 2) { dragonHX = currentX; dragonHY = currentY + 1;}
                    else if(j == 3) { dragonHX = currentX; dragonHY = currentY - 1;}
                    else if(j == 4) { dragonHX = currentX - 1; dragonHY = currentY + 1; }
                    else if(j == 5) { dragonHX = currentX - 1; dragonHY = currentY - 1; }
                    else if(j == 6) { dragonHX = currentX + 1; dragonHY = currentY + 1; }
                    else if(j == 7) { dragonHX = currentX + 1; dragonHY = currentY - 1; }
                    else {}
                    if (grid->theGrid[dragonHX][dragonHY].thing) {
                        if (grid->theGrid[dragonHX][dragonHY].thing->getRace() == "dragonHorde") {
                            dragonHorde* dHor = dynamic_cast<dragonHorde*>(grid->theGrid[dragonHX][dragonHY].thing);
                            if(dHor->dragonLocation->thing->getType() == "Dragon") {
                                Dragon* pdr = dynamic_cast<Dragon* >(dHor->dragonLocation->thing);
                                dragonAttackInfo = dragonAttackInfo + pdr->attack(player);
                            }
                        }
                    }
                }
				if(successMove) {
					cout << *grid << "Action: " << "PC moves " << output << ". " << potionInfo << res << dragonAttackInfo << endl;
				}
				else {
                    cout << *grid << "Action: " << "Invalid movement. " << potionInfo << res << dragonAttackInfo <<endl;
				}
        }
        else if (userInput == "u") {
			cin >> userInput;
			int tempX = player->getX();
            int tempY = player->getY();
            string potionInfo = "";
            if(userInput == "no") { tempX = tempX - 1; }
            else if(userInput == "so") { tempX = tempX + 1; }
            else if(userInput == "ea") { tempY = tempY + 1; }
            else if(userInput == "we") { tempY = tempY - 1; }
            else if(userInput == "ne") { tempX = tempX - 1; tempY = tempY + 1; }
            else if(userInput == "nw") { tempX = tempX - 1; tempY = tempY - 1; }
            else if(userInput == "se") { tempX = tempX + 1; tempY = tempY + 1; }
            else if(userInput == "sw") { tempX = tempX + 1; tempY = tempY - 1; }
            else {}
            if (grid->theGrid[tempX][tempY].thing) {
                if(grid->theGrid[tempX][tempY].thing->getType() == "Potion"){
                    Potion* p = dynamic_cast<Potion* >(grid->theGrid[tempX][tempY].thing);
                    player->usePotion(p);
                    m[grid->theGrid[tempX][tempY].thing->getRace()] = true;
                    potionInfo = potionInfo + p->displayPotion(m);
                    delete grid->theGrid[tempX][tempY].thing;
                    grid->theGrid[tempX][tempY].thing = NULL;
                    grid->theGrid[tempX][tempY].thing = factory.createFloorElem("Ground");
                    grid->theGrid[tempX][tempY].notifyDisplay(*td);
                    string res1 = grid->enemyRandomMove();

				    //check dragon attack
            string dragonAttackInfo = "";
            // check for dragon attack
            int dragonHX,dragonHY;
			int currentX, currentY;
            currentX = player->getX();
            currentY = player->getY();
            for (int j = 0; j < 8; j++) {
                if(j == 0) { dragonHX = currentX - 1; dragonHY = currentY; }
                else if(j == 1) { dragonHX = currentX + 1; dragonHY = currentY; }
                else if(j == 2) { dragonHX = currentX; dragonHY = currentY + 1;}
                else if(j == 3) { dragonHX = currentX; dragonHY = currentY - 1;}
                else if(j == 4) { dragonHX = currentX - 1; dragonHY = currentY + 1; }
                else if(j == 5) { dragonHX = currentX - 1; dragonHY = currentY - 1; }
                else if(j == 6) { dragonHX = currentX + 1; dragonHY = currentY + 1; }
                else if(j == 7) { dragonHX = currentX + 1; dragonHY = currentY - 1; }
                else {}
                if (grid->theGrid[dragonHX][dragonHY].thing) {
                    if (grid->theGrid[dragonHX][dragonHY].thing->getRace() == "dragonHorde") {
                        dragonHorde* dHor = dynamic_cast<dragonHorde*>(grid->theGrid[dragonHX][dragonHY].thing);
                        if(dHor->dragonLocation->thing->getType() == "Dragon") {
                            Dragon* pdr = dynamic_cast<Dragon* >(dHor->dragonLocation->thing);
                            dragonAttackInfo = dragonAttackInfo + pdr->attack(player);
                        }
                    }
                }
			}
			   cout << *grid
                    << "Action: PC uses " << potionInfo << dragonAttackInfo << res1 << endl;   
                }
                else {
                    string res2 = grid->enemyRandomMove();
                    string output;
                    if (userInput == "no") {
                        output = "North";
                    }
                    else if (userInput == "so") {
                        output = "South";
                    }
                    else if (userInput == "ea") {
                        output = "East";
                    }
                    else if (userInput == "we") {
                        output = "West";
                    }
                    else if (userInput == "ne") {
                        output = "Northeast";
                    }
                    else if (userInput == "se") {
                        output = "Southeast";
                    }
                    else if (userInput == "nw") {
                        output = "Northwest";
                    }
                    else if (userInput == "sw") {
                        output = "Southwest";
                    }

					//check dragon attack
            string dragonAttackInfo = "";
            // check for dragon attack
            int dragonHX,dragonHY;
			int currentX, currentY;
            currentX = player->getX();
            currentY = player->getY();
            for (int j = 0; j < 8; j++) {
                if(j == 0) { dragonHX = currentX - 1; dragonHY = currentY; }
                else if(j == 1) { dragonHX = currentX + 1; dragonHY = currentY; }
                else if(j == 2) { dragonHX = currentX; dragonHY = currentY + 1;}
                else if(j == 3) { dragonHX = currentX; dragonHY = currentY - 1;}
                else if(j == 4) { dragonHX = currentX - 1; dragonHY = currentY + 1; }
                else if(j == 5) { dragonHX = currentX - 1; dragonHY = currentY - 1; }
                else if(j == 6) { dragonHX = currentX + 1; dragonHY = currentY + 1; }
                else if(j == 7) { dragonHX = currentX + 1; dragonHY = currentY - 1; }
                else {}
                if (grid->theGrid[dragonHX][dragonHY].thing) {
                    if (grid->theGrid[dragonHX][dragonHY].thing->getRace() == "dragonHorde") {
                        dragonHorde* dHor = dynamic_cast<dragonHorde*>(grid->theGrid[dragonHX][dragonHY].thing);
                        if(dHor->dragonLocation->thing->getType() == "Dragon") {
                            Dragon* pdr = dynamic_cast<Dragon* >(dHor->dragonLocation->thing);
                            dragonAttackInfo = dragonAttackInfo + pdr->attack(player);
                        }
                    }
                }
			}


                    cout << *grid
                    << "Action: There is no potion at direction " << output << ". " << res2 << dragonAttackInfo << endl;
				}
            }
			else {
			  cout << *grid
				   << "Action: There is no potion " << "." << endl;
			}
		}
        else if(userInput == "m") {
            string randomMove = grid->enemyRandomMove();

				// 2 - potion detection
                string potionInfo = "";
                // check for potion
                int doubtX, doubtY;
                int currentX, currentY;
                currentX = player->getX();
                currentY = player->getY();
                for (int n = 0; n < 8; n++){
                    if(n == 0) { doubtX = currentX - 1; doubtY = currentY; }
                    else if(n == 1) { doubtX = currentX + 1; doubtY = currentY; }
                    else if(n == 2) { doubtX = currentX; doubtY = currentY + 1;}
                    else if(n == 3) { doubtX = currentX; doubtY = currentY - 1;}
                    else if(n == 4) { doubtX = currentX - 1; doubtY = currentY + 1; }
                    else if(n == 5) { doubtX = currentX - 1; doubtY = currentY - 1; }
                    else if(n == 6) { doubtX = currentX + 1; doubtY = currentY + 1; }
                    else if(n == 7) { doubtX = currentX + 1; doubtY = currentY - 1; }
                    else {}
                    if (grid->theGrid[doubtX][doubtY].thing) {
                        if (grid->theGrid[doubtX][doubtY].thing->getType() == "Potion") {
                            Potion* ppo = dynamic_cast<Potion* >(grid->theGrid[doubtX][doubtY].thing);
                            potionInfo = potionInfo + "PC sees " + ppo->displayPotion(m);
                        }
                    }
                }
            //check dragon attack
            string dragonAttackInfo = "";
            // check for dragon attack
            int dragonHX,dragonHY;
            currentX = player->getX();
            currentY = player->getY();
            for (int j = 0; j < 8; j++) {
                if(j == 0) { dragonHX = currentX - 1; dragonHY = currentY; }
                else if(j == 1) { dragonHX = currentX + 1; dragonHY = currentY; }
                else if(j == 2) { dragonHX = currentX; dragonHY = currentY + 1;}
                else if(j == 3) { dragonHX = currentX; dragonHY = currentY - 1;}
                else if(j == 4) { dragonHX = currentX - 1; dragonHY = currentY + 1; }
                else if(j == 5) { dragonHX = currentX - 1; dragonHY = currentY - 1; }
                else if(j == 6) { dragonHX = currentX + 1; dragonHY = currentY + 1; }
                else if(j == 7) { dragonHX = currentX + 1; dragonHY = currentY - 1; }
                else {}
                if (grid->theGrid[dragonHX][dragonHY].thing) {
                    if (grid->theGrid[dragonHX][dragonHY].thing->getRace() == "dragonHorde") {
                        dragonHorde* dHor = dynamic_cast<dragonHorde*>(grid->theGrid[dragonHX][dragonHY].thing);
                        if(dHor->dragonLocation->thing->getType() == "Dragon") {
                            Dragon* pdr = dynamic_cast<Dragon* >(dHor->dragonLocation->thing);
                            dragonAttackInfo = dragonAttackInfo + pdr->attack(player);
                        }
                    }
                }
            }
            if(cheatTimes < 3) {
                player->setHP(player->getMaxHP());
                cout << *grid << "Action: You used Gloden Finger!" << potionInfo << dragonAttackInfo << randomMove << endl;
                cheatTimes++;
            }
            else {
                cout << *grid << "Action: You can only cheat 3 times!" << potionInfo << dragonAttackInfo << randomMove << endl;
            }
        }
		else if(userInput == "a") {
			string direction;
			cin >> direction;
            		Mediator cm(grid);
			int tempX = 0;
		    	int tempY = 0;
			if(direction == "no") { tempX = player->getX() - 1; tempY =  player->getY(); }
			else if(direction == "so") { tempX = player->getX() + 1; tempY =  player->getY(); }
			else if(direction == "we") { tempX = player->getX(); tempY =  player->getY() - 1; }
			else if(direction == "ea") { tempX = player->getX(); tempY =  player->getY() + 1; }
			else if(direction == "ne") { tempX = player->getX() - 1; tempY =  player->getY() + 1; }
			else if(direction == "nw") { tempX = player->getX() - 1; tempY =  player->getY() - 1; }
			else if(direction == "sw") { tempX = player->getX() + 1; tempY =  player->getY() - 1; }
			else if(direction == "se") { tempX = player->getX() + 1; tempY =  player->getY() + 1; }
			else {}
			string result = cm.combat(player->getX(), player->getY(), tempX, tempY);
			string randomMove = grid->enemyRandomMove();
			// 2 - potion detection
                string potionInfo = "";
                // check for potion
                int doubtX, doubtY;
                int currentX, currentY;
                currentX = player->getX();
                currentY = player->getY();
                for (int n = 0; n < 8; n++){
                    if(n == 0) { doubtX = currentX - 1; doubtY = currentY; }
                    else if(n == 1) { doubtX = currentX + 1; doubtY = currentY; }
                    else if(n == 2) { doubtX = currentX; doubtY = currentY + 1;}
                    else if(n == 3) { doubtX = currentX; doubtY = currentY - 1;}
                    else if(n == 4) { doubtX = currentX - 1; doubtY = currentY + 1; }
                    else if(n == 5) { doubtX = currentX - 1; doubtY = currentY - 1; }
                    else if(n == 6) { doubtX = currentX + 1; doubtY = currentY + 1; }
                    else if(n == 7) { doubtX = currentX + 1; doubtY = currentY - 1; }
                    else {}
                    if (grid->theGrid[doubtX][doubtY].thing) {
                        if (grid->theGrid[doubtX][doubtY].thing->getType() == "Potion") {
                            Potion* ppo = dynamic_cast<Potion* >(grid->theGrid[doubtX][doubtY].thing);
                            potionInfo = potionInfo + "PC sees " + ppo->displayPotion(m);
                        }
                    }
                }
            //check dragon attack
            string dragonAttackInfo = "";
            // check for dragon attack
            int dragonHX,dragonHY;
            currentX = player->getX();
            currentY = player->getY();
            for (int j = 0; j < 8; j++) {
                if(j == 0) { dragonHX = currentX - 1; dragonHY = currentY; }
                else if(j == 1) { dragonHX = currentX + 1; dragonHY = currentY; }
                else if(j == 2) { dragonHX = currentX; dragonHY = currentY + 1;}
                else if(j == 3) { dragonHX = currentX; dragonHY = currentY - 1;}
                else if(j == 4) { dragonHX = currentX - 1; dragonHY = currentY + 1; }
                else if(j == 5) { dragonHX = currentX - 1; dragonHY = currentY - 1; }
                else if(j == 6) { dragonHX = currentX + 1; dragonHY = currentY + 1; }
                else if(j == 7) { dragonHX = currentX + 1; dragonHY = currentY - 1; }
                else {}
                if (grid->theGrid[dragonHX][dragonHY].thing) {
                    if (grid->theGrid[dragonHX][dragonHY].thing->getRace() == "dragonHorde") {
                        dragonHorde* dHor = dynamic_cast<dragonHorde*>(grid->theGrid[dragonHX][dragonHY].thing);
                        if(dHor->dragonLocation->thing->getType() == "Dragon") {
                            Dragon* pdr = dynamic_cast<Dragon* >(dHor->dragonLocation->thing);
                            dragonAttackInfo = dragonAttackInfo + pdr->attack(player);
                        }
                    }
                }
            }
			cout << *grid << "Action: " << result << potionInfo << dragonAttackInfo << " " << randomMove << endl;
		}
		else {
				// 2 - potion detection
                string potionInfo = "";
                // check for potion
                int doubtX, doubtY;
                int currentX, currentY;
                currentX = player->getX();
                currentY = player->getY();
                for (int n = 0; n < 8; n++){
                    if(n == 0) { doubtX = currentX - 1; doubtY = currentY; }
                    else if(n == 1) { doubtX = currentX + 1; doubtY = currentY; }
                    else if(n == 2) { doubtX = currentX; doubtY = currentY + 1;}
                    else if(n == 3) { doubtX = currentX; doubtY = currentY - 1;}
                    else if(n == 4) { doubtX = currentX - 1; doubtY = currentY + 1; }
                    else if(n == 5) { doubtX = currentX - 1; doubtY = currentY - 1; }
                    else if(n == 6) { doubtX = currentX + 1; doubtY = currentY + 1; }
                    else if(n == 7) { doubtX = currentX + 1; doubtY = currentY - 1; }
                    else {}
                    if (grid->theGrid[doubtX][doubtY].thing) {
                        if (grid->theGrid[doubtX][doubtY].thing->getType() == "Potion") {
                            Potion* ppo = dynamic_cast<Potion* >(grid->theGrid[doubtX][doubtY].thing);
                            potionInfo = potionInfo + "PC sees " + ppo->displayPotion(m);
                        }
                    }
                }
            //check dragon attack
            string dragonAttackInfo = "";
            // check for dragon attack
            int dragonHX,dragonHY;
            currentX = player->getX();
            currentY = player->getY();
            for (int j = 0; j < 8; j++) {
                if(j == 0) { dragonHX = currentX - 1; dragonHY = currentY; }
                else if(j == 1) { dragonHX = currentX + 1; dragonHY = currentY; }
                else if(j == 2) { dragonHX = currentX; dragonHY = currentY + 1;}
                else if(j == 3) { dragonHX = currentX; dragonHY = currentY - 1;}
                else if(j == 4) { dragonHX = currentX - 1; dragonHY = currentY + 1; }
                else if(j == 5) { dragonHX = currentX - 1; dragonHY = currentY - 1; }
                else if(j == 6) { dragonHX = currentX + 1; dragonHY = currentY + 1; }
                else if(j == 7) { dragonHX = currentX + 1; dragonHY = currentY - 1; }
                else {}
                if (grid->theGrid[dragonHX][dragonHY].thing) {
                    if (grid->theGrid[dragonHX][dragonHY].thing->getRace() == "dragonHorde") {
                        dragonHorde* dHor = dynamic_cast<dragonHorde*>(grid->theGrid[dragonHX][dragonHY].thing);
                        if(dHor->dragonLocation->thing->getType() == "Dragon") {
                            Dragon* pdr = dynamic_cast<Dragon* >(dHor->dragonLocation->thing);
                            dragonAttackInfo = dragonAttackInfo + pdr->attack(player);
                        }
                    }
                }
            }
			string res3 = grid->enemyRandomMove();
			cout << *grid
            << "Action: " << "Invalid command. " << potionInfo  << dragonAttackInfo << res3 << endl;
		}
	}
	delete grid;
    return 0;
}

