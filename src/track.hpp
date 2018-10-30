//
//  track.hpp
//  lissajousPulse
//
//  Created by Ian McDermott on 10/10/18.
//

#ifndef track_hpp
#define track_hpp

#include <stdio.h>
#include <vector>
#include "ofMain.h"

class Track {
public:
    vector<ofPoint> points;
    float radius;
    bool revDir;
    vector<ofPoint>  offsetPts;
    Track(vector<ofPoint>  pts);
    void update(vector<ofPoint>  pts);
};
#endif /* track_hpp */
