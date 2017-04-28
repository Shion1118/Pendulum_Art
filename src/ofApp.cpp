#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofEnableSmoothing();
    ofBlendMode(OF_BLENDMODE_ADD);
    
    gui = new ofxDatGui( ofxDatGuiAnchor::TOP_RIGHT );
    gui->addFRM();
    plotA = gui->addValuePlotter("Rotate A", -2*PI, 2*PI);
    plotB = gui->addValuePlotter("Rotate B", -2*PI, 2*PI);
    plotC = gui->addValuePlotter("Rotate C", -2*PI, 2*PI);
    plotD = gui->addValuePlotter("Rotate D", -2*PI, 2*PI);
    plotA->setDrawMode(ofxDatGuiGraph::LINES);
    plotB->setDrawMode(ofxDatGuiGraph::LINES);
    plotC->setDrawMode(ofxDatGuiGraph::LINES);
    plotD->setDrawMode(ofxDatGuiGraph::LINES);
    clear_btn = gui->addButton("Clear");
    gui->onButtonEvent(this, &ofApp::onButtonEvent);
    
    a.setPosition(ofGetWidth()/2,ofGetHeight()/2,0);
    b.setParent(a);
    b.setPosition(0,100,0);
    c.setParent(b);
    c.setPosition(0,200,0);
    d.setParent(c);
    d.setPosition(0,150,0);
    e.setParent(d);
    e.setPosition(0,100,0);
    
    aEnergy = 1;
    bEnergy = 1;
    cEnergy = 1;
    dEnergy = 1;
    
    aEnergySmth = 1;
    bEnergySmth = 1;
    cEnergySmth = 1;
    dEnergySmth = 1;

}

void ofApp::onButtonEvent(ofxDatGuiButtonEvent e) {
    
    if (e.target == clear_btn){
        nodeLine.clear();
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    for (int i = 0; i < nodeLine.size(); i++){
        nodeLine[i] -= ofPoint(4,0);
    }
    
    aEnergySmth = 0.97 * aEnergySmth + (1-0.97) * aEnergy;
    bEnergySmth = 0.97 * bEnergySmth + (1-0.97) * bEnergy;
    cEnergySmth = 0.97 * cEnergySmth + (1-0.97) * cEnergy;
    dEnergySmth = 0.97 * dEnergySmth + (1-0.97) * dEnergy;
    
    a.roll(aEnergySmth);
    b.roll(bEnergySmth);
    c.roll(cEnergySmth);
    d.roll(dEnergySmth);
    
    
    if (ofRandom(0,1) > 0.95){
        aEnergy = 0.4 * ofRandom(4, 8) * (ofRandom(0,1) > 0.5 ? 1 : -1);
    }
    
    if (ofRandom(0,1) > 0.95){
        bEnergy = ofRandom(4,8) * (ofRandom(0,1) > 0.5 ? 1 : -1);
    }
    
    if (ofRandom(0,1) > 0.95){
        cEnergy = ofRandom(6,10) * (ofRandom(0,1) > 0.5 ? 1 : -1);
    }
    
    if (ofRandom(0,1) > 0.95){
        dEnergy = ofRandom(6,10) * (ofRandom(0,1) > 0.5 ? 1 : -1);
    }
    
    nodeLine.addVertex(b.getGlobalPosition());
    nodeLine.addVertex(c.getGlobalPosition());
    nodeLine.addVertex(d.getGlobalPosition());
    nodeLine.addVertex(e.getGlobalPosition());
    
    plotA->setValue(aEnergySmth);
    plotB->setValue(bEnergySmth);
    plotC->setValue(cEnergySmth);
    plotD->setValue(dEnergySmth);

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofDrawCircle(a.getGlobalPosition(), 5);
    ofDrawCircle(b.getGlobalPosition(), 5);
    ofDrawCircle(c.getGlobalPosition(), 5);
    ofDrawCircle(d.getGlobalPosition(), 5);
    ofDrawCircle(e.getGlobalPosition(), 5);
    
    ofSetLineWidth(4);
    ofDrawLine(a.getGlobalPosition(), b.getGlobalPosition());
    ofDrawLine(b.getGlobalPosition(), c.getGlobalPosition());
    ofDrawLine(c.getGlobalPosition(), d.getGlobalPosition());
    ofDrawLine(d.getGlobalPosition(), e.getGlobalPosition());
    
    ofSetLineWidth(0.1);
    nodeLine.draw();

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
