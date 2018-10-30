//
//  flock.hpp
//  lissajousPulse
//
//  Created by Ian McDermott on 10/8/18.
//
//#pragma once

#ifndef flock_hpp
#define flock_hpp

#include "boid.hpp"

#include <stdio.h>
#include "ofMain.h"
#include "ofPoint.h"
#include <vector>
#include "ofMath.h"
#include "ofAppRunner.h"

class Flock{
    public:
        Flock();
        void run(int displayWingsFrame);
        void render();
        void addBoid(Boid b);
    private:
        vector<Boid> boid;
};
#endif /* flock_hpp */
