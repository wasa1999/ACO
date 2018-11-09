#pragma once

#include "ofMain.h"
#include "aco.hpp"

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
        int nextCity(int city1, int city2, int city3, int city4, int city5, int currentCity);
        void pheromoneRenew(int city1, int city2, int city3, int city4, int city5, double score);
        void choiceRenew();
        int t = 0;
    
    
    
    Environment fivecitiesTSP;
    Ant ants[Environment::theNumberOfAnts];
    
    
		
};
