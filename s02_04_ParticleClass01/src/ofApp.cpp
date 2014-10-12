#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60);
    ofBackground(63);
    ofSetCircleResolution(4);
    
    for (int i = 0; i < CIRCLE_NUM; i++){
        // 摩擦係数を設定
        particle[i].friction = 0.002;
        
        // 初期速度
        ofVec2f velocity;
        float length = ofRandom(10);
        float angle = ofRandom(PI * 2);
        velocity.x = cos(angle) * length;
        velocity.y = sin(angle) * length;
        
        // 初期位置
        ofVec2f position;
        position.set(ofGetWidth()/2, ofGetHeight()/2);
        
        // 初期位置を設定
        particle[i].setup(position, velocity);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < CIRCLE_NUM; i++){
        particle[i].resetForce();
        particle[i].addForce(ofVec2f(0, 0.2));
        particle[i].updateForce();
        particle[i].updatePos();
        particle[i].bounceOffWalls();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    for (int i = 0; i < CIRCLE_NUM; i++) {
        particle[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'f') {
        ofToggleFullscreen();
    }
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
    // マウスをクリックした位置で初期化
    for (int i = 0; i < CIRCLE_NUM; i++){
        // 初期速度
        ofVec2f velocity;
        float length = ofRandom(10);
        float angle = ofRandom(PI * 2);
        velocity.x = cos(angle) * length;
        velocity.y = sin(angle) * length;
        
        // 初期位置
        ofVec2f position;
        position.set(x, y);
        
        // 初期位置を設定
        particle[i].setup(position, velocity);
    }
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
