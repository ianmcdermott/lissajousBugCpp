//
//  guide.cpp
//  lissajousPulse
//
//  Created by Ian McDermott on 10/11/18.
//

#include "guide.hpp"
#include "ofPoint.h"
#include "ofMath.h"
#include "ofAppRunner.h"
#include "ofVec3f.h"

Guide::Guide(bool rev) {
    reversed = rev;
    width = ofGetWindowWidth();
    height = ofGetWindowHeight();
}

void Guide::update(float i) {
if (reversed) {
        cy = height/2; // w + i * w + w/2;
        cx = width/2; // w/2 - i*w;
    } else {
        cy = height/2; //w/2;
        cx = width/2; //w + i * w + w/2 - i*w;
    }
    x = r*cos(angle * (i+1) - HALF_PI);
    y = r*sin(angle * (i+1)  - HALF_PI);
}
    
void Guide::display() {
        if (debug) {
            
        ofSetLineWidth(strokeW);
        ofSetColor(255, 0, 0);
        ofNoFill();
        ofDrawEllipse(cx, cy, d, d);
            
        ofSetLineWidth(strokeW*8);
        ofPoint(cx+x, cy+y);
            
        ofSetColor(255, 50);
            ofNoFill();
        ofSetLineWidth(strokeW);
        if (reversed) {
            ofDrawLine(0, cy+y, width, cy+y);
        } else {
            ofDrawLine(cx+x, 0, cx+x, height);
        }
    }
}

