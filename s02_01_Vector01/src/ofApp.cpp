#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60);
    ofBackground(63);
    ofSetCircleResolution(4);
    
    // 摩擦係数を設定
    friction = 0.001;

    // 初期化
    for (int i = 0; i < CIRCLE_NUM; i++) {
        // 初期位置を設定
        position[i] = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
        // 円にかける力を設定
        float length = ofRandom(5);
        float angle = ofRandom(PI * 2);
        velocity[i].x = cos(angle) * length;
        velocity[i].y = sin(angle) * length;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    // 力をリセット
    resetForce();
    // 力の更新 (摩擦)
    updateForce();
    // 円の座標を全て更新
    updatePos();
    // 画面からはみ出たらバウンドさせる
    bounceOffWalls();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    // 画面内のランダムな場所を円の数だけ描画
    for (int i = 0; i < CIRCLE_NUM; i++) {
        ofCircle(position[i], 2);
    }
}

//--------------------------------------------------------------
void ofApp::resetForce(){
    // 力をリセット
    for (int i = 0; i < CIRCLE_NUM; i++) {
        force[i].set(0, 0);
    }
}

//--------------------------------------------------------------
void ofApp::updateForce(){
    // 速度ベクトルから、摩擦力を計算
    for (int i = 0; i < CIRCLE_NUM; i++) {
        force[i] = -velocity[i] * friction;
    }
}

//--------------------------------------------------------------
void ofApp::updatePos(){
    // 円の座標を全て更新
    for (int i = 0; i < CIRCLE_NUM; i++) {
        // 摩擦力を加味して、速度を更新
        velocity[i] += force[i];
        // 計算した速度から、位置を更新
        position[i] += velocity[i];
    }
}

//--------------------------------------------------------------
// 画面の端でバウンドする(改定版)
void ofApp::bounceOffWalls(){
    float minx = 0;
    float miny = 0;
    float maxx = ofGetWidth();
    float maxy = ofGetHeight();
    for (int i = 0; i < CIRCLE_NUM; i++) {
        if (position[i].x > maxx){
            position[i].x = maxx;
            velocity[i].x *= -1;
        }
        if (position[i].x < minx){
            position[i].x = minx;
            velocity[i].x *= -1;
        }
        
        if (position[i].y > maxy){
            position[i].y = maxy;
            velocity[i].y *= -1;
        }
        if (position[i].y < miny){
            position[i].y = miny;
            velocity[i].y *= -1;
        }
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
    // 初期化
    for (int i = 0; i < CIRCLE_NUM; i++) {
        // 初期位置を設定
        position[i] = ofVec2f(x, y);
        // 円にかける力を設定
        float length = ofRandom(5);
        float angle = ofRandom(PI * 2);
        velocity[i].x = cos(angle) * length;
        velocity[i].y = sin(angle) * length;
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
