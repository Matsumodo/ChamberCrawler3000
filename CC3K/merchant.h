//
//  merchant.h
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-24.
//  Copyright (c) 2013Äê CS246-118. All rights reserved.
//
#ifndef __MERCHANT_H__
#define __MERCHANT_H__
#include "enemy.h"

class Merchant : public Enemy {
	static bool isHostileToPc;
public:
	Merchant();
	static void turnOnHostile();
	bool checkHostile();
	~Merchant();
};

#endif