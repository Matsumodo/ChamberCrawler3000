//
//  ground.h
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-25.
//  Copyright (c) 2013年 CS246-118. All rights reserved.
//

#ifndef __CC3K__ground__
#define __CC3K__ground__

#include "floorelem.h"
class Ground : public floorElem {
public:
    Ground() : floorElem("Ground") {}
    ~Ground() {}
};

#endif /* defined(__CC3K__ground__) */
