#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundColor(0, 0, 0);
    ofSetFrameRate(30);
    t = 0;
    
    fivecitiesTSP.init();
    
    for(int i = 0; i < fivecitiesTSP.theNumberOfAnts; i++){
     //   std::cout << "ant " << i << " : ";
        for (int j = 0; j < fivecitiesTSP.theNumberOfCities; j++){
            if (j == 0) {
                ants[i].visitedCities[j] = ofRandom(0,5);
                ants[i].unvisitCities[j] = j;
            }
            
            else {
            
                ants[i].visitedCities[j] = 50;
                ants[i].unvisitCities[j] = j;
            }
           // std::cout << ants[i].unvisitCities[j] << " ";
    //        std::cout << ants[i].visitedCities[j] << " ";
            
        } 
    //    std::cout << endl;
        
        
            
    }
    
    for (int i = 0; i < fivecitiesTSP.theNumberOfCities; i++) {
        for (int j = 0; j < fivecitiesTSP.theNumberOfCities; j++) {
            std::cout << fivecitiesTSP.choice[i][j] << " ";
        }
        std::cout << endl;
    }
    
    std::cout << endl;
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    while (t <= fivecitiesTSP.iteration){
//        std::cout << "iteration : " << t << endl;
//        std::cout << endl;
    
    
    
        //解の構築
        for(int i = 1; i <= fivecitiesTSP.theNumberOfCities; i++){
//        std::cout << "visitCity : " << i << endl;
//        std::cout << endl;
        
        
            for(int j = 0; j < fivecitiesTSP.theNumberOfAnts; j++){
            
           // std::cout << "unvisit" << j << " : ";
//            std::cout << "unvisit(before)" << j << " : "<< ants[j].unvisitCities[0] << " " << ants[j].unvisitCities[1] << " " << ants[j].unvisitCities[2] << " " << ants[j].unvisitCities[3] << " " << ants[j].unvisitCities[4] << " " << endl;
            
                ants[j].calculateUnvisitCities(i); //まだ訪問していない都市を特定

            
            //            std::cout << "unvisit(after)" << j << " : "<< ants[j].unvisitCities[0] << " " << ants[j].unvisitCities[1] << " " << ants[j].unvisitCities[2] << " " << ants[j].unvisitCities[3] << " " << ants[j].unvisitCities[4] << " " << endl;
            
            //std::cout << endl;
            
            
                ants[j].visitedCities[i] = nextCity(ants[j].unvisitCities[0],ants[j].unvisitCities[1],ants[j].unvisitCities[2],ants[j].unvisitCities[3],ants[j].unvisitCities[4],ants[j].visitedCities[i-1]); //確率的に選択
            
            
            }
            std::cout << endl;
        }
        
        // 解の評価値を取得(都市間の距離の総和)する
        
        for (int i = 0; i < fivecitiesTSP.theNumberOfAnts; i++){
            ants[i].score = fivecitiesTSP.evaluation(ants[i].visitedCities[0],ants[i].visitedCities[1],ants[i].visitedCities[2],ants[i].visitedCities[3],ants[i].visitedCities[4]);
           // cout << ants[i].score << endl;
            pheromoneRenew(ants[i].visitedCities[0],ants[i].visitedCities[1],ants[i].visitedCities[2],ants[i].visitedCities[3],ants[i].visitedCities[4], ants[i].score);
            
        }
        
        // 解の評価値に基づいてフェロモン行列を更新する
        choiceRenew();
        
        for (int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++){
                std::cout << fivecitiesTSP.choice[i][j] << " ";
            }
            std::cout << endl;
        }
        
    
        // アリを最初の都市に戻す。
//        for(int i = 0; i < fivecitiesTSP.theNumberOfAnts; i++){
//            //   std::cout << "ant " << i << " : ";
//            for (int j = 0; j < fivecitiesTSP.theNumberOfCities; j++){
//                if (j == 0) {
//                    ants[i].visitedCities[j] = ofRandom(0,5);
//                    ants[i].unvisitCities[j] = j;
//                }
//                
//                else {
//                    
//                    ants[i].visitedCities[j] = 50;
//                    ants[i].unvisitCities[j] = j;
//                }
//                // std::cout << ants[i].unvisitCities[j] << " ";
//                //        std::cout << ants[i].visitedCities[j] << " ";
//                
//            }
//            
//        }
    
    
    t++;
        
       
        
        
        
        
        
        
        
      //出力ゾーン  
//        for (int i = 0; i < fivecitiesTSP.theNumberOfAnts; i++) {
//            std::cout << "ant" << i << " : ";
//            for (int j = 0; j < fivecitiesTSP.theNumberOfCities; j++) {
//                std::cout << ants[i].visitedCities[j] << " ";
//            }
//            std::cout << endl;
//        }

    }
    

}

//

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofTranslate(400, 400);
    ofScale(1, -1);
    
    if (0 < t){
    
    for (int i = 0; i < 10; i++) {
        
        ofDrawBitmapString("ant " + ofToString(i) +"  : "+" "+ ofToString(ants[i].visitedCities[0])+" "+ ofToString(ants[i].visitedCities[1])+" "+ ofToString(ants[i].visitedCities[2])+" "+ ofToString(ants[i].visitedCities[3])+" "+ ofToString(ants[i].visitedCities[4]), -300, 300-(i*20));

        ofDrawBitmapString(ofToString(ants[i].score), -100, 300-(i*20));
    }

    for (int i = 10; i < fivecitiesTSP.theNumberOfAnts; i++) {
        
        ofDrawBitmapString("ant " + ofToString(i) +" : "+" "+ ofToString(ants[i].visitedCities[0])+" "+ ofToString(ants[i].visitedCities[1])+" "+ ofToString(ants[i].visitedCities[2])+" "+ ofToString(ants[i].visitedCities[3])+" "+ ofToString(ants[i].visitedCities[4]), -300, 300-(i*20));
        
        ofDrawBitmapString(ofToString(ants[i].score), -100, 300-(i*20));
        
        std::cout << endl;
    }
    
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            ofDrawBitmapString(ofToString(fivecitiesTSP.choice[i][j]), -390 + (i*100), -100 - (j*15));
        }
    }

    ofDrawBitmapString("iteration : " + ofToString(t), 250, 350);
        std::cout << endl;
       
            for (int i = 0; i < fivecitiesTSP.theNumberOfCities; i++) {
                ofSetColor(255, 255, 255);
                ofDrawCircle(fivecitiesTSP.cities[i], 10);
                //ofDrawBitmapString("no" + ofToString(i) + ofToString(dis[i]), 150, 10*i);
                ofSetColor(255,0,0);
                ofDrawBitmapString(ofToString(i), fivecitiesTSP.cities[i]);
                
            }
        
    }
    
   //経路の初期化 
    
    
    if (0 < t && t < fivecitiesTSP.iteration - 1){    
        for(int i = 0; i < fivecitiesTSP.theNumberOfAnts; i++){
        //   std::cout << "ant " << i << " : ";
            for (int j = 0; j < fivecitiesTSP.theNumberOfCities; j++){
                if (j == 0) {
                    ants[i].visitedCities[j] = ofRandom(0,5);
                    ants[i].unvisitCities[j] = j;
                }
            
                else {
                
                    ants[i].visitedCities[j] = 50;
                    ants[i].unvisitCities[j] = j;
                }
            // std::cout << ants[i].unvisitCities[j] << " ";
            //        std::cout << ants[i].visitedCities[j] << " ";
            
            }
        
        }
        
    }

    
            
//            //line
//            
    for(int i = 0; i < fivecitiesTSP.theNumberOfCities; i++){
        ofSetColor(255,255,255);
            for (int j = 0; j < fivecitiesTSP.theNumberOfCities; j++){
                if ( i != j){
                    ofDrawLine(fivecitiesTSP.cities[i],fivecitiesTSP.cities[j]);
                }
            }
    }
//    
//    ofSetColor(0, 255, 0);
//    for (int i = 0; i < fivecitiesTSP.theNumberOfAnts; i++) {
//        for (int j = 0; j < fivecitiesTSP.theNumberOfCities - 1; j++) {
//            ofDrawLine(fivecitiesTSP.cities[ants[i].visitedCities[j]],fivecitiesTSP.cities[ants[i].visitedCities[j+1]]);
//        }
//    }
    
//    for (int j = 0; j < fivecitiesTSP.theNumberOfCities - 1; j++) {
//        ofDrawLine(fivecitiesTSP.cities[ants[0].visitedCities[j]],fivecitiesTSP.cities[ants[0].visitedCities[j+1]]);
//    }
//    ofDrawLine(fivecitiesTSP.cities[ants[0].visitedCities[0]],fivecitiesTSP.cities[ants[0].visitedCities[1]]);
//    std::cout << fivecitiesTSP.cities[ants[0].visitedCities[0]] << endl;
//    std::cout << fivecitiesTSP.cities[ants[0].visitedCities[1]] << endl;
//    
//    
//    


}

int ofApp::nextCity(int city1, int city2, int city3, int city4, int city5, int currentCity){
    double max = -100;
    int cityNumber = 0;
    double candidate;
    int unvisit[5] = {city1,city2,city3,city4,city5};
    for (int i = 0; i < 5; i++) {
        if (unvisit[i] != 100){
            candidate = fivecitiesTSP.choice[currentCity][unvisit[i]];
          //  std::cout << candidate << " : " << "[" << currentCity << "][" << unvisit[i] << "]";
            if (candidate > max) {
                max = candidate;
                cityNumber = unvisit[i];
            }
            
        }
        
    }
  //  std::cout << "max : " << max << endl;
    return cityNumber;
}

void ofApp::pheromoneRenew(int city1, int city2, int city3, int city4, int city5, double score){
    fivecitiesTSP.pheromone[city1][city2] += (1 / score); 
    fivecitiesTSP.pheromone[city2][city3] += (1 / score); 
    fivecitiesTSP.pheromone[city3][city4] += (1 / score); 
    fivecitiesTSP.pheromone[city4][city5] += (1 / score);
    fivecitiesTSP.pheromone[city5][city1] += (1 / score); 
    fivecitiesTSP.pheromone[city2][city1] += (1 / score); 
    fivecitiesTSP.pheromone[city3][city2] += (1 / score); 
    fivecitiesTSP.pheromone[city4][city3] += (1 / score); 
    fivecitiesTSP.pheromone[city5][city4] += (1 / score);
    fivecitiesTSP.pheromone[city1][city5] += (1 / score); 
}
void ofApp::choiceRenew(){
    for(int i = 0; i < fivecitiesTSP.theNumberOfCities; i++){
        for (int j = 0; j < fivecitiesTSP.theNumberOfCities; j ++){
            fivecitiesTSP.choice[i][j] = fivecitiesTSP.pheromone[i][j] + fivecitiesTSP.heuristicinfo[i][j];
        }
    }
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
