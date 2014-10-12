#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60);
    ofBackground(63);
    ofSetCircleResolution(4);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < particles.size(); i++){
        particles[i].resetForce();
        particles[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    
    // 塗りつぶしなし
    ofNoFill();
    
    // パーティクルを曲線で結ぶ
    ofBeginShape();
    for (int i = 0; i < particles.size(); i++) {
        ofCurveVertex(particles[i].position.x, particles[i].position.y);
    }
    ofEndShape();
    
    // ログを表示
    ofDrawBitmapString("Particle num = " + ofToString(particles.size()), 10, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'f') {
        ofToggleFullscreen();
    }
    if (key == 'c') {
        particles.clear();
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
    Particle p;
    // 摩擦係数を設定
    p.friction = 0.01;
    // 初期速度を設定
    ofVec2f velocity;
    float length = ofRandom(3.0);
    float angle = ofRandom(PI * 2);
    velocity.x = cos(angle) * length;
    velocity.y = sin(angle) * length;
    // パーティクル初期化
    p.setup(ofVec2f(x, y), velocity);
    // Vectorに追加
    particles.push_back(p);    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    particles.clear();
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
