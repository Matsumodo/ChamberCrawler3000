//
//  merchanthorde.h
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-24.
//  Copyright (c) 2013年 CS246-118. All rights reserved.
//

#ifndef __CC3K__merchanthorde__
#define __CC3K__merchanthorde__
#include "treasure.h"

class merchantHorde : public Treasure {
public:
    merchantHorde() : Treasure(4, "merchantHorde") {}
};

#endif