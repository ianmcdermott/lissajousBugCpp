#pragma once

#include "ofMain.h"
#include "boid.hpp"
#include "flock.hpp"
#include "track.hpp"
#include "wings.hpp"
#include "ofSerial.h"
#include "curve.hpp"
//#include "guide.hpp"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void loadWings();

        int width;
        int height;
    
        bool pulseOn = false;
        bool startCount1 = false;
        bool startCount2 = false;
        bool debug = false;
        bool lissalines = false;
        bool particlesOn = false;
        bool fractalsOn = false;
        bool springsOn = false;
        bool boidsOn = true;
        bool flockingOn = true;
        bool pathFollow = false;
   
        void clearVisuals();
        void autoScanPorts();
        void resetDataTraces();
    
        int textAlpha = 0;
        bool textAlphaIncrease = false;
        int alphaCount = 0;
        bool startAlphaCount = false;
    
        string pulseText1 = "";
        string pulseText2 = "";
    


        int w = 1000;
        int cols;
        int rows;
        float d = w-10;
        float r = d/2;
        float angle = 0;
        float strokeW = 1;
        float angleRes = .0007;
//        vector <Guide> vertGuides;
//        vector <Guide> horizGuides;
        int phaseX = 5;
        int phaseY = 0;
    
        bool beat1 = true;
    
        float osc1 = 50;
        float osc2 = 50;
        int count1 = 0;
        int count2 = 0;
        ofSerial Serial;
    
    
        ofSerial port;
    
        int Sensor;      // HOLDS PULSE SENSOR DATA FROM ARDUINO
        int IBI;         // HOLDS TIME BETWEN HEARTBEATS FROM ARDUINO
        int BPM;         // HOLDS HEART RATE VALUE FROM ARDUINO
        vector<int> RawY;      // HOLDS HEARTBEAT WAVEFORM DATA BEFORE SCALING
        vector<int> ScaledY;   // USED TO POSITION SCALED HEARTBEAT WAVEFORM
        vector<int> rate;      // USED TO POSITION BPM DATA WAVEFORM
        float zoom;      // USED WHEN SCALING PULSE WAVEFORM TO PULSE WINDOW
        float offset;    // USED WHEN SCALING PULSE WAVEFORM TO PULSE WINDOW
//        Color eggshell = color(255, 253, 248);
        int heart = 0;   // This variable times the heart image 'pulse' on screen
        //  THESE VARIABLES DETERMINE THE SIZE OF THE DATA WINDOWS
        int PulseWindowWidth = 490;
        int PulseWindowHeight = 512;
        int BPMWindowWidth = 180;
        int BPMWindowHeight = 340;
        bool beat = false;    // set whlissalinesen a heart beat is detected, then cleared when the BPM graph is advanced
    
        // SERIAL PORT STUFF TO HELP YOU FIND THE CORRECT SERIAL PORT
        string serialPort;
//        vector<string> serialPorts = new string[Serial.list().length];
        bool serialPortFound = false;
//        int numPorts = serialPorts.length;
        bool refreshPorts = false;
        float wave;
        string nf;
        int imageCount = 119;
        vector<ofImage> wingImages;

    private:
        Flock flock;
//        Curve curve;
//        Guide guide;

//        Boid boid;
};
