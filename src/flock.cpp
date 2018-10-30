//
//  flock.cpp
//  lissajousPulse
//
//  Created by Ian McDermott on 10/8/18.
//

#include "boid.hpp"

#include "ofPoint.h"
#include "ofMath.h"
#include "ofAppRunner.h"
#include "flock.hpp"
#include <vector>
#include <iostream>

Flock::Flock(){
     boid = vector<Boid>();
}

void Flock::run(int displayWingsFrame){
//    ofDrawEllipse(20, 20, 20, 20);
    ofPushMatrix();
    vector<Boid>::iterator pos;
    for (pos=boid.begin(); pos !=boid.end(); pos++){
        pos->run(boid, displayWingsFrame);  // Passing the entire list of boid to each boid individually
    }
    ofPopMatrix();
}

void Flock::addBoid(Boid b) {
//    int xx = 0;
    boid.push_back(b);
}

void Flock::render(){
    for(int i = 0; i < boid.size(); i++){
        boid[i].render(0);
    }
}
