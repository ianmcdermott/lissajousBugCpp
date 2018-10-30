//
//  curve.hpp
//  lissajousPulse
//
//  Created by Ian McDermott on 10/10/18.
//
#pragma once

#ifndef curve_hpp
#define curve_hpp

#include "flock.hpp"
#include "track.hpp"

#include "ofApp.h"
#include <stdio.h>
#include "ofMain.h"
#include "ofPoint.h"
#include <vector>
#include "ofMath.h"
#include "ofAppRunner.h"
#include "ofGraphics.h"
#include "ofVec3f.h"


class Curve {
    public:
        Curve();
        vector<ofPoint> path;
        ofPoint curr;
        int numBoids = 500;
        int boidCounter;
        Flock flock;
    
    
        void addPoint(int displayWingsFrame);
        void setX(float x);
        void reset();
        void setY(float y);
        void show(float noiseWeight);
        bool * particlesOn;
        bool * fractalsOn;
        bool * boidsOn;
        bool * lissalines;
        bool * debug;
    
        float wave;
        int  height ;
        int  width;
        float strokeW = 1;
        float angle;
    private:
        Track track;
    
    //    ParticleSystem ps;
};
#endif /* curve_hpp */
