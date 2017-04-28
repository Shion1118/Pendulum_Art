#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofxDatGui* gui;
        ofxDatGuiValuePlotter* plotA;
        ofxDatGuiValuePlotter* plotB;
        ofxDatGuiValuePlotter* plotC;
        ofxDatGuiValuePlotter* plotD;
        ofxDatGuiButton* clear_btn;
        void onButtonEvent(ofxDatGuiButtonEvent e);
    
        ofNode a,b,c,d,e;
        float aEnergy;
        float bEnergy;
        float cEnergy;
        float dEnergy;
        float aEnergySmth;
        float bEnergySmth;
        float cEnergySmth;
        float dEnergySmth;
        float time;
        ofPolyline nodeLine;
		
};
