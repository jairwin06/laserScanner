#pragma once

#include "ofMain.h"

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
    int subdivisionsV = height;
    int subdivisionsU = 500;
    float motorRot = TWO_PI / subdivisionsU;
    
    //step2: create vector of coordinates from images
    void initiateVector();
    void updateVector();
    
    vector<ofVec3f> coords;
    size_t tVertCount;
    
    vector<ofVec3f> vertices;
    
    int currentU = 0;
    int currentV = 0;
    bool goRight, stepA, reachedEnd;
    
    float theta;
    float x, y, z;
    
    //step3: create mesh from coordinates
    ofMesh mesh;
    
    ofEasyCam cam;
    
    //ofxSTLExporter model;
};
