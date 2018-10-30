//
//  guide.hpp
//  lissajousPulse
//
//  Created by Ian McDermott on 10/11/18.
//

#ifndef guide_hpp
#define guide_hpp

#include <stdio.h>
#include "ofMain.h"

class Guide {
public:
    float cy;
    float cx;
    int width;
    int height;
    
    float x ;
    float y ;
    bool reversed;
    
    Guide(bool rev);
    void update(float i);
    void display() ;
    
    float strokeW = 1;
    
    bool debug = false;
    float angle = 0;
    float r = 0;
    float d = 30;
};

#endif /* guide_hpp */
