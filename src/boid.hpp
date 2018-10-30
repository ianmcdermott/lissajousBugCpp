//
//  boid.hpp
//  lissajousPulse
//
//  Created by Ian McDermott on 10/8/18.
//
#pragma once

#ifndef boid_hpp
#define boid_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofPoint.h"
#include <vector>
#include "ofMath.h"
#include "ofAppRunner.h"
#include "ofGraphics.h"
#include "ofVec3f.h"


class Boid{
    
public:
    ofPoint position;
    ofPoint velocity;
    ofPoint acceleration;
    float r;
    float maxforce;    // Maximum steering force
    float maxspeed;    // Maximum speed
    int blink   = 0;
    float blinkOffset;
    ofPoint leader;
    float desiredseparation;
    float blinkDepth;
    float speed = 0;
    ofVec2f flat;
    
    Boid(float x, float y, float _r, float ms, float mf, float bo, float bd);
    
    void run(vector<Boid> boid, int displayWingsFrame);
    void applyForce(ofPoint force);
    void flocking(vector<Boid> boid);
    void update() ;
    ofPoint seek(ofPoint target);
    void render(int displayWingsFrame);
    void borders();
    ofPoint separate(vector<Boid> boid);
    ofPoint align(vector<Boid> boid);
    ofPoint cohesion(vector<Boid> boid);
    //    ofPoint follow(Track t);
    ofPoint getNormalPoint(ofPoint p, ofPoint a, ofPoint b);
    ofPoint followLeader (ofPoint target);
    int width;
    int height;
    
    
    bool debug = false;
    bool lissalines = true;
    bool particlesOn = false;
    bool fractalsOn = false;
    bool springsOn = false;
    bool boidOn = false;
    bool flockingOn = false;
    bool pathFollow = true;
    float theta;
    
};

#endif /* boid_hpp */
