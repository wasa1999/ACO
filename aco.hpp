//
//  aco.hpp
//  aco_objectoriented
//
//  Created by 岩﨑友哉 on 2018/11/05.
//

#ifndef aco_hpp
#define aco_hpp

#include <stdio.h>
#include "ofMain.h"

class Environment{
    
public:
    const static int iteration = 1000;
    const static int theNumberOfCities = 5;
    const static int theNumberOfAnts = 15;
    ofVec2f cities[theNumberOfCities];
    double distanceBetweenCities[theNumberOfCities][theNumberOfCities];
    double pheromone[theNumberOfCities][theNumberOfCities];
    double heuristicinfo[theNumberOfCities][theNumberOfCities];
    double choice[theNumberOfCities][theNumberOfCities];
    
    
    void init();
    int choiceAcsess(int currentCity, int nextCity);
    double distance(ofVec2f pos1, ofVec2f pos2);
    double evaluation(int city1, int city2, int city3, int city4, int city5);
    
    
};


class Ant{

public:
    int visitedCities[Environment::theNumberOfCities];
    int unvisitCities[Environment::theNumberOfCities];
    double score;
    
    void calculateUnvisitCities(int step);
    
    
};


#endif /* aco_hpp */
