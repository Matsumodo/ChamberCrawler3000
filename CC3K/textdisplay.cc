//
//  textdisplay.cc
//  CC3K
//
//  Created by Susu Dong and Xiner Ning on 13-11-25.
//  Copyright (c) 2013年 CS246-118. All rights reserved.
//

#include "textdisplay.h"

using namespace std;

TextDisplay::TextDisplay(int x, int y) : gridWidth(x), gridHeight(y) {
    theDisplay = new char* [gridHeight];
    for (int i = 0; i < gridHeight; i++) {
        theDisplay[i] = new char [gridWidth];
        for (int j = 0; j < gridWidth; j++) {
            theDisplay[i][j] = ' ';
        }
    }
}

void TextDisplay::newFloorDisplay() {
    for (int i = 0; i < gridHeight; i++) {
        for (int j = 0; j < gridWidth; j++) {
            theDisplay[i][j] = ' ';
        }
    }
}

TextDisplay::~TextDisplay() {
    for(int i = 0; i < gridHeight; i++) {
        delete[] theDisplay[i];
    }
    delete[] theDisplay;
}

void TextDisplay::notify(int x, int y, char symbol) {
    theDisplay[x][y] = symbol;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
    for (int i = 0; i < td.gridHeight; i++) {
        for (int j = 0; j < td.gridWidth; j++) {
            out << td.theDisplay[i][j];
        }
        out << endl;
    }
    return out;
}
