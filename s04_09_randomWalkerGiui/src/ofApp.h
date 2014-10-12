#pragma once

#include "ofMain.h"
#include "RandomWalker.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    static const int NUM = 500000;
    RandomWalker walker[NUM];
    
    ofxPanel gui;
    ofxFloatSlider size;
    ofxFloatSlider pointAlpha;
    ofxFloatSlider bgAlpha;
    ofVboMesh mesh;
};




















