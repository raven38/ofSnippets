#pragma once

#include "ofMain.h"
#include <vector>
#include <deque>

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    deque<vector<pair<double, double> > >Points;
    deque<vector<pair<double, double> > >Targets;
    int count;
    
    const int MOVE_COUNT = 300;
};
