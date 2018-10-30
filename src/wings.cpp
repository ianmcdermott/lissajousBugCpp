//
//  wings.cpp
//  lissajousPulse
//
//  Created by Ian McDermott on 10/10/18.
//

#include "wings.hpp"

Wings::Wings(int count) {
    imageCount = count;
    r = int(ofRandom(20));
}
    
void Wings::display(float xpos, float ypos, int displayWingsFrame, float speed) {
    frame = (displayWingsFrame+1)*(5/int(speed+1))*3 % imageCount;
//    wingImages.draw(xpos, ypos);
    
}
    
int Wings::getWidth() {
//        return images[0].width;
}

