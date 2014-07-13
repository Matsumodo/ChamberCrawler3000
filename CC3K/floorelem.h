//
//  floorelem.h
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-24.
//  Copyright (c) 2013年 CS246-118. All rights reserved.
//

#ifndef __CC3K__floorelem__
#define __CC3K__floorelem__
#include <string>
#include <iostream>
#include "gameobject.h"

class floorElem : public gameObject {
protected:
    std::string type;
public:
    floorElem(std::string type) : type(type) {}
    std::string getType() { return type; }
    std::string getRace() { return type; }
    ~floorElem() { }
};

#endif