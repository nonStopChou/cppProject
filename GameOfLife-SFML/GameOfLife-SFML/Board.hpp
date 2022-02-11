//
//  board.hpp
//  GameOfLife-SFML
//
//  Created by pingruchou on 2022/2/11.
//  Copyright © 2022 pingruchou. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>


class Board{
    int size = 100;
    bool *cellStatus;
public:
    
    sf::RectangleShape *board;
    Board(int size);
    void render();
    void update();
    void setCell(int x, int y);
    
};



#endif /* board_hpp */
