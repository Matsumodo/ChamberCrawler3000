//
//  gameobject.h
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-21.
//  Copyright (c) 2013年 CS246-118. All rights reserved.
//

#ifndef __CC3K__gameobject__
#define __CC3K__gameobject__
#include <string>

class gameObject {
public:
    gameObject() {}
    virtual std::string getType() { return "hello"; }; // return general type except for enemy and floorelem for display
    virtual std::string getRace() { return "hello"; }; // return detailed type
    //virtual std::string getType() = 0;
    //virtual std::string getRace() = 0;
    virtual ~gameObject() {}
};

#endif