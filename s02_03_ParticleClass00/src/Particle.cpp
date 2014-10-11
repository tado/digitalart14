#include "Particle.h"

Particle::Particle(){
    radius = 2.0;
    friction = 0.01;
    mass = 1.0;
    bFixed = false;
}

void Particle::setup(ofVec2f _position, ofVec2f _velocity){
    // 位置を設定
    position = _position;
    // 初期速度を設定
    velocity = _velocity;
}
void Particle::setup(float positionX, float positionY, float velocityX, float velocityY){
    // 位置を設定
    position = ofVec2f(positionX, positionY);
    // 初期速度を設定
    velocity = ofVec2f(velocityX, velocityY);
}

// 力をリセット
void Particle::resetForce(){
    force.set(0, 0);
}

// 力を加える
void Particle::addForce(ofVec2f _force){
    force += _force / mass;
}
void Particle::addForce(float forceX, float forceY){
    force += ofVec2f(forceX, forceY);
}

// 摩擦力の更新
void Particle::updateForce(){
    force -= velocity * friction;
}

// 位置の更新
void Particle::updatePos(){
    if (!bFixed) {
        velocity += force;
        position += velocity;
    }
}

// 力の更新と座標の更新をupdateとしてまとめる
void Particle::update(){
    updateForce();
    updatePos();
}


// 画面の端でバウンドする(改定版)
void Particle::bounceOffWalls(){
    float minx = 0;
    float miny = 0;
    float maxx = ofGetWidth();
    float maxy = ofGetHeight();
    
    if (position.x > maxx){
        position.x = maxx;
        velocity.x *= -1;
    } else if (position.x < minx){
        position.x = minx;
        velocity.x *= -1;
    }
    
    if (position.y > maxy){
        position.y = maxy;
        velocity.y *= -1;
    } else if (position.y < miny){
        position.y = miny;
        velocity.y *= -1;
    }
}

// 画面の反対側から出現
void Particle::throughOfWalls(){
    float minx = 0;
    float miny = 0;
    float maxx = ofGetWidth();
    float maxy = ofGetHeight();
    if (position.x < minx) {
        position.x = maxx;
    }
    if (position.y < miny) {
        position.y = maxy;
    }
    if (position.x > maxx) {
        position.x = minx;
    }
    if (position.y > maxy) {
        position.y = miny;
    }
}

// 描画
void Particle::draw(){
    ofCircle(position, radius);
}