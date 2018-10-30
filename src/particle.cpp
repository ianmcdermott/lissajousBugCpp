////
////  particle.cpp
////  lissajousPulse
////
////  Created by Ian McDermott on 10/11/18.
////
//
//#include "particle.hpp"
//#include "ofMath.h"
//#include "ofGraphics.h"
//
//// A simple Particle class
//
//Particle::Particle(ofPoint l) {
//        acceleration = new ofPoint(ofRandom(-.05, .05), random(-.05, .05));
//        velocity = new ofPoint(ofRandom(-.01, .01), random(-.01, .01));
//        position = l.copy();
//        lifespan = 255.0*2;
//        maxLifespan = lifespan;
//        rad = int(ofRandom(1, 5));
//}
//    
//void Particle::run() {
//    update();
//    display();
//}
//    
//    // Method to update position
//void Particle::update() {
//    velocity += acceleration;
//    position += velocity;
//    lifespan -= 1.0;
//    acceleration *= 0;
//        
//    if(position.y > height+rad || position.y < -rad || position.x > width+rad |position.x < -rad){
//        lifespan = -1;
//    }
//}
//    
//    // Method to display
//void Particle::display() {
//    int alpha = int(ofMap(lifespan, 0, maxLifespan, 0, 255));
//    ofNoStroke();
//    ofColor(255, alpha);
//    ofDrawEllipse(position.x, position.y, rad, rad);
//}
//    
//    // Is the particle still useful?
//bool Particle::isDead() {
//    if (lifespan <= 0.0) {
//        return true;
//    } else {
//        return false;
//    }
//}
//
