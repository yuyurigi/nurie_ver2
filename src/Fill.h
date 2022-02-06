#pragma once

#include "ofMain.h"

#define MAX_STACK_COUNT 100000

struct Segment {
    int iY;
    int iXL;
    int iXR;
    int iDeltaY;
};

struct Cell {
    int iX;
    int iY;
};

class Fill {
private:
    ofPixels pixels, pixels2, patternPixels;
    ofImage image;
    ofFbo pFbo;
    int x, y, patternNum, gy0, gy1;
    ofColor newColor, newColor2, newColor_copy, pixels2Color, strokeColor, oldColor, oldColor2;
    vector<ofFbo> patterns;
    //グラデーションのときに使うスタック
    Cell aCellStack[MAX_STACK_COUNT*20];
    int iCountCell;
    void makePattern();
    void pushSegment(Segment* aSegmentStack, int& riCountSegment, int iY, int iXL, int iXR, int iDeltaY);
    void popSegment(Segment* aSegmentStack, int& riCountSegment, int& riY, int& riXL, int& riXR, int& riDeltaY);
    void pushCell(Cell* aCellStack, int& riCountCell, int iX, int iY);
    void popCell(Cell* aCellStack, int& riCountCell, int& riX, int &riY);
    void scanLineSeedFill();
    void cellFill(int cx, int cy);
    void fillGradation();
public:
    Fill();
    void setup(ofFbo fbo, ofColor _strokeColor, ofColor backColor);
    void setPattern(vector<ofFbo> _patterns);
    void setPos(int _x, int _y, ofColor _newColor, int _patternNum);
    void setGColor(ofColor _newColor2);
    void draw();
};
