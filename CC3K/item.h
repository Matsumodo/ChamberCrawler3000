//
//  item.h
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-19.
//  Copyright (c) 2013年 CS246-118. All rights reserved.
//

#ifndef CC3K_item_h
#define CC3K_item_h

#include "gameobject.h"
#include <string>

class Item : public gameObject {
public:
    virtual std::string getType() = 0;
    virtual std::string getRace() = 0;
};

#endif