#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60);
    ofBackground(0);
    
    for (int i = 0; i < 10000; i++) {
        ofVec2f pos = ofVec2f(ofRandom(ofGetWidth()),
                              ofRandom(ofGetHeight()));
        ofVec2f vel = ofVec2f(ofRandom(-10, 10),
                              ofRandom(-10, 10));
        myParticle[i].setup(pos, vel);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < 10000; i++) {
        myParticle[i].resetForce();
        myParticle[i].updateForce();
        myParticle[i].updatePos();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < 10000; i++) {
        myParticle[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
