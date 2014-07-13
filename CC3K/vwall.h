//
//  vwall.h
//  CC3K
//
//  Created by Susu Dong on 13-11-24.
//  Copyright (c) 2013年 CS246-118. All rights reserved.
//

#ifndef __CC3K__vwall__
#define __CC3K__vwall__

#include "floorelem.h"
class vWall : public floorElem {
public:
    vWall() : floorElem("verticalWall") {}
};

#endif