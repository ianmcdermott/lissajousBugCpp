//
//  wings.hpp
//  lissajousPulse
//
//  Created by Ian McDermott on 10/10/18.
//

#ifndef wings_hpp
#define wings_hpp

#include <stdio.h>
#include <vector>
#include "ofMain.h"
#include "ofPoint.h"

class Wings {
    public:
        vector<ofImage> images;
        int frame;
        int r;
        int imageCount = 119;
        Wings(int count);
        void display(float xpos, float ypos, int displayWingsFrame, float speed);
        int getWidth();
};
#endif /* wings_hpp */
