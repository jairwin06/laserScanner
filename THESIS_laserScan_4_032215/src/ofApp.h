#pragma once

#include "ofMain.h"
#include "ofxSTL.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
    //step 1: create vector of images:
    vector<ofImage> images;
    int width = 102;
    int height = 294;
    
    int subdivisions = 500;
    float motorRot = TWO_PI / subdivisions;
    //float motorRot = 0.0126;      //0.72 - this is how much it was rotating in physical space
    
    //step2: create vector of coordinates from images
    void initiateVector();
    vector<ofVec3f> coords;
    float theta;
    float x, y, z;
    
    //step3: create mesh from coordinates
    ofMesh mesh;
    
    ofEasyCam cam;
    
    //ofxSTLExporter model;
		
};
