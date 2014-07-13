//
//  textdisplay.h
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-25.
//  Copyright (c) 2013年 CS246-118. All rights reserved.
//

#ifndef __CC3K__textdisplay__
#define __CC3K__textdisplay__
#include <iostream>

class TextDisplay {
    char **theDisplay;
    const int gridWidth;
    const int gridHeight;
public:
    TextDisplay(int x, int y);
    void newFloorDisplay();
    ~TextDisplay();
    void notify(int x, int y, char symbol);
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};
#endif