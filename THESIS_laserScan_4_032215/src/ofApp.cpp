#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    //mesh.setMode(OF_PRIMITIVE_POINTS);
    mesh.setMode(OF_PRIMITIVE_LINES);
    //mesh.setMode(OF_PRIMITIVE_LINE_LOOP);
    
    
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
        
        //---------------CREATE VERTICES----------------//
        for (int n = 0; n<coords.size(); n++) {
            //cout << coords[n] << endl;
            if (n % 4 == 0){                    //controls the resolution (number of vertices)
                mesh.addVertex(coords[n]);
                mesh.addColor(255);
            }
        }
        
        //---------------CREATE LINES----------------//
        float connectionDistance = 3;           //controls resolution of the mesh's connection points
        int numVerts = mesh.getNumVertices();
        for (int a=0; a<numVerts; a++){
            ofVec3f verta = mesh.getVertex(a);
            for (int b=a+1; b<numVerts; b++){
                ofVec3f vertb = mesh.getVertex(b);
                float dist = verta.distance(vertb);
                if (dist <= connectionDistance){
                mesh.addIndex(a);
                mesh.addIndex(b);
                }
            }
        }
        //cout << mesh.getNumVertices() << endl;
        
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
                    x = i*cos(theta);
                    y = j;
                    z = i*sin(theta);
                    coords.push_back(ofVec3f(x, y, z));

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
    mesh.draw();     //mesh.drawFaces();
    ofPopMatrix();
    cam.end();
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
