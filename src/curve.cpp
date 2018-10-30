//
//  curve.cpp
//  lissajousPulse
//
//  Created by Ian McDermott on 10/10/18.
//

#include "curve.hpp"
#include "ofMath.h"
#include "ofGraphics.h"




Curve::Curve() : track(vector<ofPoint>()){
    width = ofGetWindowWidth();
    height = ofGetWindowHeight();
    
    path = vector<ofPoint>();
    curr = ofPoint();
    //       ps = new ParticleSystem(new PVector(0, 0));
    
    flock = Flock();
    // Add an initial set of boids into the system
    for (int i = 0; i < numBoids; i++) {
        flock.addBoid(Boid(width/2, height/2, ofRandom(.25, 3), ofRandom(1, 4), ofRandom(.09, .5), ofRandom(0, 10), ofRandom(.1, .9)));
    }
        track = Track(path);
}

void Curve::addPoint(int displayWingsFrame) {
    if (angle > -TWO_PI) {
        path.push_back(curr);
                track.update(path);
    }
    if (particlesOn) {
        //            ps.addParticle(new ofPoint(curr.x, curr.y));
        //            ps.run();
    }
    
    // Add an initial set of boids into the system
    
    if (fractalsOn) {
    }
    
    
    if (boidsOn) {
        flock.run(displayWingsFrame);
    }
}

void Curve::setX(float x) {
    curr.x = x;
}

void Curve::reset() {
    path.clear();
}

void Curve::setY(float y) {
    curr.y = y;
}
void Curve::show(float noiseWeight) {
    ofNoFill();
    ofSetColor(255, 50);
    ofFill();
    ofSetColor(255, 50);
    ofSetLineWidth(strokeW);
    ofNoFill();
    if (lissalines) {
        ofPushMatrix();
        //translate(-w*3/4, -w*3/4);
        ofBeginShape();
        for ( ofPoint v : path) {
            //vertex(v.x, v.y);
            wave = ofNoise(((noiseWeight+v.x)*.01), (noiseWeight+v.y)*.008)*6-.5;
            ofSetLineWidth(wave);
            ofNoFill();
            ofSetColor(255, 255-ofMap(wave, 0, 6, 0, 150));
            boidCounter++;
            //strokeWeight(1);
            ofPoint(v.x, v.y);
        }
        ofEndShape();
        ofPopMatrix();
    }
    if (debug) {
        ofNoFill();
        ofSetLineWidth(strokeW*8);
        ofPoint(curr.x, curr.y);
    }
    curr = ofPoint();
}

