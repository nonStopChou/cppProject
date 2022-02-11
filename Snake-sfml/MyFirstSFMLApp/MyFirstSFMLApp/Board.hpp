//
//  Board.hpp
//  MyFirstSFMLApp
//
//  Created by pingruchou on 2022/2/10.
//  Copyright © 2022 pingruchou. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp


#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Food.hpp"

class Board{
    
public:
    sf::RectangleShape *board;
    bool *isEmpty;
    size_t size;
    Food food;
    
    
    Board(int boardSize, int cellSize, int paddingLeft, int paddingTop);
    Board(int boardSize);
    void init(int boardSize, int cellSize, int paddingLeft, int paddingTop);
    void generateFood();
    
    
};

#endif /* Board_hpp */
