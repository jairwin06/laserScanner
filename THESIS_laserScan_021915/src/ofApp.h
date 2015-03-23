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
     
    
        vector<ofImage> imagesNT;
        ofImage img;
        ofImage img2;
    
        vector<ofMesh> meshes;
        ofMesh mesh;
        ofMesh mesh2;
    
        void addMeshVertices();
        ofVec3f getVertexFromImg(ofImage& img, int x, int y);
    
        ofEasyCam cam;
		
};
