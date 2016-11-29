#include "ofApp.h"
#include <vector>
#include <random>

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255,255,255);
    ofSetFrameRate(60); // if vertical sync is off, we can go a bit fast... this caps the framerate at 60fps.
    vector<pair<double, double> >v(4);
    v[0] = make_pair(100, 500);
    v[1] = make_pair(400, 500);
    v[2] = make_pair(700, 500);
    v[3] = make_pair(400, 500);
    Points.push_back(v);
    count = MOVE_COUNT;
}

//--------------------------------------------------------------
void ofApp::update(){
    if(count == MOVE_COUNT){
        random_device rnd;
        mt19937 mt(rnd());
        uniform_int_distribution<> rand01(0, 1);
        Targets = Points;
        for(int i = 0; i < Points.size(); i++){
            int pm = rand01(mt);
            if(pm != 1) pm = -1;
            vector<pair<double, double> >p = Points[i];
            if(Targets[i][0].first == Targets[i][1].first){
                Targets[i][0] = make_pair(p[0].first+pm*(p[1].second-p[0].second), p[1].second);
                Targets[i][1] = make_pair(p[1].first+pm*(p[1].second-p[0].second), p[2].second);
            }else{
                Targets[i][0] = make_pair(p[1].first, p[0].second-pm*(p[1].first-p[0].first));
                Targets[i][1] = make_pair(p[2].first, p[1].second-pm*(p[1].first-p[0].first));
            }
        }
    }
    
    for(int i = 0; i < Points.size(); i++){
        int iPs = Points[i].size();
        for(int j = 0; j < iPs; j++){
            pair<double, double> *s = &Points[i][j];
            pair<double, double> t = Targets[i][j];
            s->first += (t.first-s->first)/count;
            s->second += (t.second-s->second)/count;
        }
    }
    
    --count;
    if(!count){
        count = MOVE_COUNT;
        int ps = Points.size();
        for(int i=0;i<ps;i++){
            vector<pair<double, double> >p = Points[0]; Points.pop_front();
            for(int i = 0;i<p.size();i++){
                pair<double, double>s, t; s = p[i], t = p[(i+1)%(int)p.size()];
                vector<pair<double, double> >v(4);
                v[0] = s;
                v[1] = make_pair((s.first+t.first)/2, (s.second+t.second)/2);
                v[2] = t;
                v[3] = make_pair((s.first+t.first)/2, (s.second+t.second)/2);
                Points.push_back(v);
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i < Points.size(); i++){
        int iPs = Points[i].size();
        for(int j = 0; j < iPs; j++){
            pair<int, int>s, t; s = Points[i][j]; t = Points[i][(j+1)%iPs];
            ofSetColor(0,0,0);
            ofDrawLine(s.first, s.second, t.first, t.second);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
