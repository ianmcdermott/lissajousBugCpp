//
//  boid.cpp
//  lissajousPulse
//
//  Created by Ian McDermott on 10/8/18.
//

//
//  boid.cpp
//  lissajousPulse
//
//  Created by Ian McDermott on 10/8/18.
//

#include "boid.hpp"
#include "ofPoint.h"
#include "ofMath.h"
#include "ofAppRunner.h"
#include "ofVec3f.h"


Boid::Boid(float x, float y, float _r, float ms, float mf, float bo, float bd){
    acceleration =  ofPoint(0, 0);
    
    // This is a new ofPoint method not yet implemented in JS
    // velocity = ofPoint.random2D();
    
    // Leaving the code temporarily this way so that this example runs in JS
    float angle = ofRandom(TWO_PI);
    velocity =  ofPoint(cos(angle), sin(angle));
    
    r = _r;
    maxspeed = ms;
    maxforce = mf;
    blinkOffset = bo;
    desiredseparation = r*2;
    blinkDepth  = bd;
    ofVec2f flat(0,1);
    
    width = ofGetWindowWidth();
    height = ofGetWindowHeight();
    position =  ofPoint(ofRandom(width), ofRandom(height));
    
}

void Boid::update(){
    velocity += acceleration;
    // Limit speed
    velocity.limit(maxspeed);
    position += velocity;
    // Reset accelertion to 0 each cycle
    speed = acceleration.length()*3;
    
    acceleration *= 0;
    theta = ofRadToDeg(atan2(velocity.x,velocity.y)-(PI/2));
    
}

void Boid::render(int displayWingsFrame){
    //ofNoStroke();
     ofVec2f origin = ofVec2f(1.0, 0.0);
    float theta2 = origin.angle(velocity) + 90;
    ofPushMatrix();
    ofTranslate(position.x, position.y);
    ofRotate(theta2);
    
    ofSetColor(255, 0, 0);
    ofFill();
    
    ofColor c = ofColor(0);
    c.setHsb(20, 100, 100-blink);
    ofSetColor(c);
    ofFill();
    
    ofDrawEllipse(0, r*2, r*3, r*6);
    
    ofPushMatrix();
    ofScale(r*.075, r*.075);
    ofTranslate(0, -50);
    // wings.display(-100, 0, displayWingsFrame, velocity.mag());
    ofPopMatrix();
    ofPopMatrix();
}

void Boid::borders(){
    if (position.x < -r*3) position.x = ofGetWindowWidth()+r;
    if (position.y < -r*3) position.y = ofGetWindowHeight()+r;
    if (position.x > ofGetWindowWidth()+r*3) position.x = -r;
    if (position.y > ofGetWindowHeight()+r*3) position.y = -r;
}

void Boid::run(vector<Boid> boid, int
               ){
    flocking(boid);
    update();
    borders();
    //leader = new ofPoint(curves[0][0].curr.x, curves[0][0].curr.y);
    
    blink = int(sin((blinkOffset*ofGetFrameNum())/20)*100+blinkDepth);//*.25+.75;
}

void Boid::applyForce(ofPoint force){
    acceleration += force;
    
}

void Boid::flocking(vector<Boid> boid){
    ofPoint sep = separate(boid);   // Separation
    ofPoint ali = align(boid);      // Alignment
    ofPoint coh = cohesion(boid);   // Cohesion
    ofPoint folLead  = followLeader(ofPoint(0,0));//curves[0][0].curr.x, curves[0][0].curr.y));
    // ofPoint fol = follow(curves[0][0].track);
    
    // Arbitrarily weight these forces
    sep *= 1.5;
    ali *= 1.0;
    coh *= 2.0;
    folLead *= .5;
    // Add the force vectors to acceleration
    applyForce(sep);
    
    if (pathFollow) {
        desiredseparation = r*2;
        //                applyForce(fol);
    } else {
        desiredseparation = r*10;
    }
    
    if (flockingOn) {
        applyForce(ali);
        applyForce(coh);
    }
}

ofPoint Boid::seek(ofPoint target){
    //    ofPoint desired = ofPoint.sub(target, position);  // A vector pointing from the position to the target
    ofPoint desired = target - position;  // A vector pointing from the position to the target
    
    desired.normalize();
    desired *= maxspeed;
    
    //    ofPoint steer = ofPoint.sub(desired, velocity);
    ofPoint steer = desired - velocity;
    
    steer.limit(maxforce);  // Limit to maximum steering force
    return steer;
}

ofPoint Boid::separate(vector<Boid> boid){
    ofPoint steer = ofPoint(0, 0, 0);
    int count = 0;
    // For every boid in the system, check if it's too close
    for (Boid other : boid) {
        float d = position.distance(other.position);
        // If the distance is greater than 0 and less than an arbitrary amount (0 when you are yourself)
        if ((d > 0) && (d < desiredseparation)) {
            // Calculate vector pointing away from neighbor
            ofPoint diff = position - other.position;
            diff.normalize();
            diff /= d;        // Weight by distance
            steer += diff;
            count++;            // Keep track of how many
        }
    }
    // Average -- divide by how many
    if (count > 0) {
        steer /= count;
    }
    
    // As long as the vector is greater than 0
    if (steer.length() > 0) {
        // First two lines of code below could be condensed with new ofPoint setMag() method
        // Not using this method until Processing.js catches up
        // steer.setMag(maxspeed);
        
        // Implement Reynolds: Steering = Desired - Velocity
        steer.normalize();
        steer *= maxspeed;
        steer *= velocity;
        steer.limit(maxforce);
    }
    return steer;
}

ofPoint Boid::align(vector<Boid> boid){
    float neighbordist = 50;
    ofPoint sum = ofPoint(0, 0);
    int count = 0;
    for (Boid other : boid) {
        float d = position.distance(other.position);
        if ((d > 0) && (d < neighbordist)) {
            sum += other.velocity;
            count++;
        }
    }
    if (count > 0) {
        sum /= count;
        
        sum.normalize();
        sum *= maxspeed;
        ofPoint steer = sum -= velocity;
        steer.limit(maxforce);
        return steer;
    } else {
        return ofPoint(0, 0);
    }
}

ofPoint Boid::cohesion(vector<Boid> boid){
    ofPoint lissajousTarget =  ofPoint(0,0);//curves[0][0].curr.x, curves[0][0].curr.y);
    
    float neighbordist = 50;
    ofPoint sum =  ofPoint(0, 0);   // Start with empty vector to accumulate all positions
    int count = 0;
    for (Boid other : boid) {
        float d = position.distance(other.position);
        if ((d > 0) && (d < neighbordist)) {
            sum += other.position; // Add position
            count++;
        }
    }
    if (count > 0) {
        sum /= count;
        return seek(sum);  // Steer towards the position
    } else {
        return ofPoint(0, 0);
    }
    
}

ofPoint Boid::getNormalPoint(ofPoint p, ofPoint a, ofPoint b){
    ofPoint ap = p - a;
    ofPoint ab = b - a;
    
    ab.normalize();
    ab *= ap.dot(ab);
    ofPoint normalPoint = a += ab;
    
    return normalPoint;
}

ofPoint Boid::followLeader (ofPoint target){
    ofPoint lissajousTarget = ofPoint(0,0);//curves[0][0].curr.x, curves[0][0].curr.y);
    
    return seek(target);  // Steer towards the position
}

