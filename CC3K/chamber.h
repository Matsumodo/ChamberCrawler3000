//
//  chamber.h
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-25.
//  Copyright (c) 2013年 CS246-118. All rights reserved.
//

#ifndef __CC3K__chamber__
#define __CC3K__chamber__

#include <vector>
class Tile;

class Chamber {
    int chamberNum;
public:
    std::vector<Tile* > v;
    void setChamberNum(int n) { chamberNum = n; }
};
#endif