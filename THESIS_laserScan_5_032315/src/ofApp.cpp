#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetVerticalSync(true);
    //mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
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
    }
}

//--------------------------------------------------------------
//To get number of vertices
void ofApp::initiateVector(){
    for (int j = 0; j<height; j++) {
        for (int n=0; n<images.size(); n+=4) { //look through very 4th photo to lower res
        theta = motorRot * n;
            for (int i=width; i>0; i--) {
                ofColor color = images[n].getColor(i, j);
                ofColor lastCol = images[n].getColor(i-1, j);
                if (color.a > 0 && lastCol.a <= 0) {
                    coords.push_back(ofVec3f(i, j, theta));
                    tVertCount = coords.size();
                }
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::updateVector(){
    for (int j = 0; j<height; j++) {
        for (int n=0; n<images.size(); n+=4) {
            theta = motorRot * n;
            for (int i=width; i>0; i--) {
                ofColor color = images[n].getColor(i, j);
                ofColor lastCol = images[n].getColor(i-1, j);
                if (color.a > 0 && lastCol.a <= 0) {
                    x = i*cos(theta);
                    y = j;
                    z = i*sin(theta);
                    ofVec3f currVert = ofVec3f(x, y, z);
                    vertices.push_back(currVert);
                    
                    cam.begin();
                    ofPushMatrix();
                    cam.enableMouseMiddleButton();
                    mesh.addVertex(currVert);
                    mesh.draw();
                    ofPopMatrix();
                    cam.end();
                    
                    
                    if (!stepA && (( goRight && currentU == subdivisionsU) || (!goRight && currentU == 0))) {
                        vertices.push_back(currVert);
                        vertices.push_back(currVert);
                        
                        stepA = true;
                        goRight =! goRight;
                        reachedEnd = (currentV == subdivisionsV);
                    }
                    
                    if (goRight) {
                        if (stepA) {
                            currentV++;
                        }
                        else {
                            currentU++;
                            currentV--;
                        }
                    }
                    
                    else {
                        if (stepA) {
                            currentV++;
                        }
                        else {
                            currentU--;
                            currentV--;
                        }
                    }
                    stepA =! stepA;
                    
                    cout << tVertCount << endl;
                    cout << mesh.getNumVertices() << endl;
                    if (mesh.getNumVertices() > tVertCount) {
                        reachedEnd;
                        break;
                    }
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
    
    updateVector();
    
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
