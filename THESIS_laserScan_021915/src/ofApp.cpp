#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFullscreen(true);
    
    //---------------LOAD FROM DIRECTORY----------------//
    ofDirectory dir;
    int nFiles = dir.listDir("../../../../../../../Desktop/THESIS/Week3_laserScan/JPEG_processed2");
    if( nFiles ){
        for( int i=0; i<dir.numFiles(); i++ ){
            string filePath = dir.getPath( i );
            imagesNT.push_back(ofImage());
            imagesNT.back().loadImage(filePath);
            meshes.push_back(ofMesh());
        }
    }//*/
    //---------------LOAD FROM DIRECTORY----------------//
    
    
    //---------------SETUP MESH----------------//
    //---------------LOAD INDIVIDUAL IMAGES FOR MESH----------------//
    /*img.loadImage("../../../../../../../Desktop/THESIS/Week3_laserScan/JPEG_processed2/1laserScan.png");
    img2.loadImage("../../../../../../../Desktop/THESIS/Week3_laserScan/JPEG_processed2/2laserScan.png");

    //set point for point cloud
    mesh.setMode(OF_PRIMITIVE_POINTS);
    mesh2.setMode(OF_PRIMITIVE_POINTS);//*/
    //---------------LOAD INDIVIDUAL IMAGES FOR MESH----------------//
    
    
    
    //---------------VECTOR OF MESHES----------------//
    
    for( int m=0; m<meshes.size(); m++ ){
        meshes[m].setMode(OF_PRIMITIVE_POINTS);
    }//*/
    
    //---------------VECTOR OF MESHES----------------//
    
    
    
    addMeshVertices();
    
    glEnable( GL_POINT_SMOOTH );  //circular points
    glPointSize( 1 );
    //---------------SETUP MESH----------------//

}


//--------------------------------------------------------------
ofVec3f ofApp::getVertexFromImg( ofImage& img, int x, int y ){
    ofColor color = img.getColor( x, y );
    if( color.a>0 ){
        return ofVec3f( x-img.getWidth() / 2, y-img.getHeight() / 2, 0 );
    } else return ofVec3f( 0,0,0 );
}

//--------------------------------------------------------------
void ofApp::addMeshVertices(){

    int gap = 2;  //subset of points
    int w = 102;
    int h = 294;
    ofVec3f zero(0,0,0);
    
    //---------------CREATE THE MESH FROM INDIVIDUAL OR VEC OF IMAGE(S)----------------//
    
    for( int i = 0; i<imagesNT.size(); i+=gap ){
        //loop through pixels
        for( int y=0; y<h; y+=gap ) {
            for( int x=0; x<w; x+=gap ) {
                ofVec3f v = getVertexFromImg( imagesNT[i], x, y );
                
                //for dealing with individual imagages/meshes
                //ofVec3f v = getVertexFromImg( img, x, y );
                //ofVec3f v2 = getVertexFromImg( img2, x, y );
                
                ofColor ptCol( 255,0,0 );
                
                if( v!= zero ){
                    for( int m=0; m<meshes.size(); m++) {
                        meshes[m].addVertex( v );
                        meshes[m].addColor( ptCol );
                    }//*/
                    
                    //for dealing with individual imagages/meshes
                     /*mesh.addVertex( v );
                     mesh.addColor( ptCol );
                     mesh2.addVertex( v2 );
                     mesh2.addColor( 255 );//*/
                }
            }
        }
    }
    //---------------CREATE THE MESH FROM INDIVIDUAL IMAGE(S)----------------//
}


//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    
    //---------------DRAW THE MESH FROM INDIVIDUAL IMAGE(S)----------------//
    /*cam.begin();
    ofPushMatrix();
    ofScale( 1.5,-1.5,1.5 );
    mesh.draw();
    ofRotateY(90);
    mesh2.draw();
    ofPopMatrix();
    cam.end();//*/
    //---------------DRAW THE MESH FROM INDIVIDUAL IMAGE(S)----------------//
    
    //---------------LOOP THROUGH VEC OF MESHES & DRAW----------------//
    /*cam.begin();
    
    ofPushMatrix();
    ofScale( 1,-1,1 );
    for( int m=0; m<meshes.size(); m++ ){

        ofRotateY(5);
        meshes[m].draw();

    }
    
    ofPopMatrix();
    cam.end();//*/
    //---------------LOOP THROUGH VEC OF MESHES & DRAW----------------//
    
    
    //---------------DRAW FROM DIRECTORY----------------//
    if( (int)imagesNT.size() <= 0 ){
        ofSetColor( 255 );
        ofDrawBitmapString("No Images...", 150, ofGetHeight()/2 );
        return;
    }
    
    cam.begin();
    float angle = 0.72;
    int inc = 1;
    ofTranslate(0, -100, 0);
    for( int i = 0; i<imagesNT.size(); i+=inc ){
        
        ofRotateY( 0.72 );
        //ofTranslate(i*inc, 0, 0);
        imagesNT[i].draw( 0,0,0 );
    }
    cam.end();//*/
    //---------------DRAW FROM DIRECTORY----------------//
    
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
