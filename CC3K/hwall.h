//
//  hwall.h
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-24.
//  Copyright (c) 2013年 CS246-118. All rights reserved.
//

#ifndef __CC3K__hwall__
#define __CC3K__hwall__

#include "floorelem.h"
class hWall : public floorElem {
public:
    hWall() : floorElem("horizontalWall") {}
};

#endif