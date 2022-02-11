//
//  Food.hpp
//  MyFirstSFMLApp
//
//  Created by pingruchou on 2022/2/10.
//  Copyright © 2022 pingruchou. All rights reserved.
//

#ifndef Food_hpp
#define Food_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>


class Food{
    
public:
    sf::Vector2i food;
    Food(int boardSize);
    Food();
};

#endif /* Food_hpp */
