//
//  mediator.h
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-24.
//  Copyright (c) 2013Äê CS246-118. All rights reserved.
//
#ifndef __COMBATMEDIATOR_H__
#define __COMBATMEDIATOR_H__

class Grid;

class Mediator{
public:
	Grid* g;
	Mediator(Grid* g);
	std::string combat(int Ax, int Ay, int Dx, int Dy);
	~Mediator();
};

#endif