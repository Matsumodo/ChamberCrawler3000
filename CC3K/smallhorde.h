//
//  smallhorde.h
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-24.
//  Copyright (c) 2013年 CS246-118. All rights reserved.
//

#ifndef __CC3K__smallhorde__
#define __CC3K__smallhorde__
#include "treasure.h"

class smallHorde : public Treasure {
public:
    smallHorde() : Treasure(2, "smallHorde") {}
};
    
#endif /* defined(__CC3K__smallhorde__) */
