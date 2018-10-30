#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    width = ofGetWindowWidth();
    height = ofGetWindowHeight();
    ofSetVerticalSync(true);
    flock = Flock();

    for(int i = 0; i < 300; i++){
        flock.addBoid(Boid(width/2, height/2, ofRandom(.25, 3), ofRandom(1, 4), ofRandom(.09, .5), ofRandom(0, 1), ofRandom(.1, .9)));
    }
    
    cols = 1;//width/w;
    rows = 1;//height/w;
    for (int i =0; i < cols; i++) {
        for (int j =0; j < rows; j++) {
//            curve = Curve();
        }
    }
    wingImages.reserve(imageCount);
    
    loadWings();
//    lbug = loadImage("bug-01.png");
//    smooth();
//    vertGuides = new Guide[rows];
    for (int i = 0; i < rows; i ++) {
//        vertGuides[i] = new Guide(true);
    }
//    horizGuides = new Guide[cols];
    
    for (int i = 0; i < cols; i ++) {
//        horizGuides[i] = new Guide(false);
    }
    
    //try {
    //  port = new Serial(this, Serial.list()[i], 115200);  // make sure Arduino is talking serial at this baud rate
    //  delay(1000);
    //  println(port.read());
    //  port.clear();            // flush buffer
    //  port.bufferUntil('\n');  // set buffer full flag on receipt of carriage return
    //  serialPortFound = true;
    //}
    
//    port = new Serial(this, "/dev/cu.usbmodem1441", 115200);
    
//    wings sprite
//    wings = new Wings(imageCount);
    ofHideCursor();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    flock.run(ofGetFrameNum());
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    flock.render();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'p' || key == 'P') particlesOn = !particlesOn;
    if (key == 'l' || key == 'L') lissalines = !lissalines;
    if (key == 'd' || key == 'D') debug = !debug;
    if (key == 'f' || key == 'F') fractalsOn = !fractalsOn;
    if (key == 'b' || key == 'B') boidsOn = !boidsOn;
    if (key == 's' || key == 'S') springsOn = !springsOn;
    if (key == 'f' || key == 'F') {
        flockingOn = !flockingOn;
        pathFollow = !pathFollow;
    }
    if (key == 'c' || key == 'C') clearVisuals();
    if (key == 'q') {
        textAlphaIncrease = true;
        if (beat1) {
            count1 = 0;
            startCount1 = true;
        } else {
            count2 = 0;
            startCount2 = true;
        }
        
        flockingOn = true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::clearVisuals() {
    debug = false;
    lissalines = false;
    particlesOn = false;
    fractalsOn = false;
    springsOn = false;
    boidsOn = false;
}


void ofApp::autoScanPorts() {
//    if (Serial.list().length != numPorts) {
//        if (Serial.list().length > numPorts) {
//            println("New Ports Opened!");
//            println(Serial.list());
//            int diff = Serial.list().length - numPorts;  // was serialPorts.length
//            serialPorts = expand(serialPorts, diff);
//            numPorts = Serial.list().length;
//        } else if (Serial.list().length < numPorts) {
//            println("Some Ports Closed!");
//            numPorts = Serial.list().length;
//        }
//        refreshPorts = true;
//        return;
//    }
}

void ofApp::resetDataTraces() {
//    for (int i=0; i< rate.length; i++) {
//        rate[i] = 555;      // Place BPM graph line at bottom of BPM Window
//    }
//    for (int i=0; i<RawY.length; i++) {
//        RawY[i] = height/2; // initialize the pulse window data line to V/2
//    }
}

string nf(string format, int number) {
    char buffer[100];
    sprintf(buffer, format.c_str(), number);
    return (string)buffer;
}


void ofApp::loadWings() {
    for (int i = 0; i < imageCount; i++) {
        // Use nf() to number format 'i' into four digits
        string filename = "data/lighteningbug_00001.png"; //nf("%05d", i) +
        //wImage = loadImage(filename);
        wingImages.push_back(filename);
    }
}


