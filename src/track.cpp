//
//  track.cpp
//  lissajousPulse
//
//  Created by Ian McDermott on 10/10/18.
//

#include "track.hpp"

Track::Track(vector<ofPoint>  pts) {
    radius = 3;
    points = pts;
    revDir = true;
}
    
void Track::update(vector<ofPoint>  pts) {
    points = pts;
}
