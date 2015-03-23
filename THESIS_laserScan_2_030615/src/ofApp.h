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
    
    ofEasyCam cam;
    
    //Motor rotation: will change based on the number of motor steps
    //in this case it's 500, so: 360/500 = 0.72
    float motorRot = 0.72;

    
    /*step2: Create vector of ofVec3fs using the initial data from the images.
    The result of this step will give you a vector with:
    [ tmpX ] - this is the 2D x value of each pixel in each image
    [ y ] - y is going to remain y throughout step 3 as well
    [ theta ] - this is the angle, it's going to increment by the
                the degree amount of each step of the rotating motor
    */
    
    vector<ofVec3f> coords;
    float theta;
    float x, y, z;
    
    //Function to translate values from 2D to 3D coordinates
    void initiateVector();
    
    /*step 3: Update the vector with x and z values (y values stay the same).
    As we rotate around the origin in 3D space, that tmpX actually becomes the
    hypotenuse of a triangle in which x and z are the legnths of the other two sides.
    x and z then translate directly to the coordinate values we need (the y value being
    fixed). Since we have the angle theta and we know the hypotenuse, we can calculate
    the other two sides. We need to account for negative x and z values, but we can
    do that after.
    */
    
    ofMesh mesh;
};
