//
//  Snake.hpp
//  MyFirstSFMLApp
//
//  Created by pingruchou on 2022/2/9.
//  Copyright © 2022 pingruchou. All rights reserved.
//

#ifndef Snake_hpp
#define Snake_hpp

#include <stdio.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Board.hpp"

class Snake{

    std::vector<std::pair<int, int>> body;
    int directionIndex = -1;
    bool isAlive;
    int score = 0;
    
public:
    Snake(int x, int y);
    bool step(Board *board);
    void dead() {isAlive = false;};
    bool isDead(){return isAlive == false;};
    void setDirection(int key);
    void render(Board *board);
    void init();
    int getScore();
};


#endif /* Snake_hpp */
