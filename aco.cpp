//
//  aco.cpp
//  aco_objectoriented
//
//  Created by 岩﨑友哉 on 2018/11/05.
//

#include "aco.hpp"

void Environment::init(){
    
    cities[0].set(280, 280);
    cities[1].set(50, -20);
    cities[2].set(120, -150);
    cities[3].set(-250, -10);
    cities[4].set(-150, -100);
    
    
    
    for (int i = 0; i < theNumberOfCities; i++){
        for (int j = 0; j < theNumberOfCities;j++){
            
            if (i==j) 
            {
                distanceBetweenCities[i][j] = 0;
                choice[i][j]=0;
                pheromone[i][j] = 0;
                heuristicinfo[i][j] = 0;
            }
            else
            {
                distanceBetweenCities[i][j] = distance(cities[i], cities[j]);
                choice[i][j] = ofRandom(0.499,0.510);
                pheromone[i][j] = 0;
                heuristicinfo[i][j] = 1 / distance(cities[i], cities[j]);
            }
            
            choice[j][i] = choice[i][j];
            //std::cout << heuristicinfo[i][j] << " ";
            //cout << pheromone[i][j] << " ";
            //cout << heuristicinfo[i][j] << " ";
            //cout << choice[i][j] << " ";
        }
        //std::cout << endl;
        
    }
}



double Environment::distance(ofVec2f pos1, ofVec2f pos2){
    
    double d;
    d = sqrt((abs(pos1.x - pos2.x)*abs(pos1.x - pos2.x))+(abs(pos1.y - pos2.y)*abs(pos1.y -pos2.y)));
    return d;
    
}

int Environment::choiceAcsess(int currentCity, int nextCity){
    
    return choice[currentCity-1][nextCity-1];
}

double Environment::evaluation(int city1, int city2, int city3, int city4, int city5){
    return Environment::distanceBetweenCities[city1][city2] + Environment::distanceBetweenCities[city2][city3] + Environment::distanceBetweenCities[city3][city4] + Environment::distanceBetweenCities[city4][city5];
}

void Ant::calculateUnvisitCities(int step){
    

    //未訪問の都市の配列を作る
    for (int i=0; i<step ; i++) {
        switch (visitedCities[i]) {
            case 0:
                unvisitCities[0] = 100;
                break;
            case 1:
                unvisitCities[1] = 100;
                break;
                
            case 2:
                unvisitCities[2] = 100;
                break;
                
            case 3:
                unvisitCities[3] = 100;
                break;
                
            case 4:
                unvisitCities[4] = 100;
                break;
                
            default:
                break;
        }
//        for (int j = 0; j < 5; j++) {
//            if (visitedCities[i] == unvisitCities[j]) {
//                unvisitCities[j] = 100;
//                
//            } else if (visitedCities[i] == 50){
//                unvisitCities[j] = j;
//            }
//            
//        }
    }
}


