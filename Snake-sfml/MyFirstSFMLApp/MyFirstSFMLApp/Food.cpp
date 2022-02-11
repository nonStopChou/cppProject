//
//  Food.cpp
//  MyFirstSFMLApp
//
//  Created by pingruchou on 2022/2/10.
//  Copyright © 2022 pingruchou. All rights reserved.
//

#include "Food.hpp"
#include <stdlib.h>

Food::Food(int boardSize){
    int x = rand() % boardSize;
    int y = rand() % boardSize;
    food = sf::Vector2i(x, y);
};

Food::Food(){
    int x = rand() % 50;
    int y = rand() % 50;
    food = sf::Vector2i(x, y);
}
