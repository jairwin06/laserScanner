#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //ofSetupOpenGL(800,800,OF_WINDOW);
    mesh.setMode(OF_PRIMITIVE_POINTS);
    
    //---------------LOAD FROM DIRECTORY----------------//
    ofDirectory dir;
    int nFiles = dir.listDir("../../../../../../../Desktop/THESIS/Week3_laserScan/JPEG_processed2");
    if(nFiles){
        for(int i=0; i<dir.numFiles(); i++){
            string filePath = dir.getPath(i);
            images.push_back(ofImage());
            images.back().loadImage(filePath);
        }
        
        initiateVector();
        
        for (int n = 0; n<coords.size(); n++) {
            //cout << coords[n] << endl;
            mesh.addVertex(coords[n]);
            mesh.addColor(255);
        }
    }
}

//--------------------------------------------------------------
void ofApp::initiateVector(){
    //for (int n=0; n<images.size(); n+=4) {
    for (int n=0; n<images.size(); n++) {
        //theta = motorRot * n;
        theta = 0.0126 * n;
        for (int j = 0; j<height; j++) {
            for (int i=width; i>0; i--) {
                ofColor color = images[n].getColor(i, j);
                ofColor lastCol = images[n].getColor(i-1, j);
                if (color.a > 0 && lastCol.a <= 0) {
                    //cout << i*cos(theta) << "  " << j << "  " << i*sin(theta) << endl;
                    x = i*cos(theta);
                    y = j;
                    z = i*sin(theta);
                    coords.push_back(ofVec3f(x, y, z));
                    cout << n << "      " << theta << "      " << x << endl;
                }
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);

    cam.begin();
    ofPushMatrix();
    cam.enableMouseMiddleButton();
    mesh.draw();
    ofPopMatrix();
    cam.end();

    //---------------DRAW FROM DIRECTORY----------------//
    //This section places the images in space; good for testing
    /*if( (int)images.size() <= 0 ){
     ofSetColor( 255 );
     ofDrawBitmapString("No Images...", 150, ofGetHeight()/2 );
     return;
     }
     
     cam.begin();
     float angle = 0.72;
     int inc = 1;
     ofTranslate(0, -100, 0);
     for( int i = 0; i<images.size(); i+=inc ){
     
     ofRotateY( 0.72 );
     //ofTranslate(i*inc, 0, 0);
     images[i].draw( 0,0,0 );
     }
     cam.end();//*/

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
