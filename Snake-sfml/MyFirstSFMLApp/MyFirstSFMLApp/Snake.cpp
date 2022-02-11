//
//  Snake.cpp
//  MyFirstSFMLApp
//
//  Created by pingruchou on 2022/2/9.
//  Copyright © 2022 pingruchou. All rights reserved.
//

#include "Snake.hpp"
#include <SFML/Graphics.hpp>
#include "Board.hpp"

Snake::Snake(int x, int y){
    isAlive = true;
    std::pair<int, int> head(x, y);
    body.push_back(head);
}

void Snake::init(){
    isAlive = true;
    std::pair<int, int> head(0, 0);
    body = std::vector<std::pair<int, int>>();
    body.push_back(head);
}


bool Snake::step(Board *board){
    std::pair<int, int> oldHead = body.front();
    bool isGrow = false;
    // 0 : down, 1 : left, 2 : up, 3 : right
    int x = body.front().first, y = body.front().second;
    switch (directionIndex) {
        case 0:
            x = oldHead.first;
            y = oldHead.second + 1;
            break;
        case 1:
            x = oldHead.first - 1;
            y = oldHead.second;
            break;
        case 2:
            x = oldHead.first;
            y = oldHead.second - 1;
            break;
        case 3:
            x = oldHead.first + 1;
            y = oldHead.second;
            break;
        default:
            return false;
    }
    if(x >= 0 && y >= 0 && x < board->size && y < board->size){
        if(directionIndex >= 0){
            std::pair<int, int> newHead(x, y);
            body.insert(body.begin(), newHead);
            if(x != board->food.food.x || y != board->food.food.y){
                std::pair<int, int> tail = body.back();
                int tail_x = tail.first, tail_y = tail.second;
                board->board[tail_x * board->size + tail_y].setFillColor(sf::Color(255, 255, 255));
                board->isEmpty[tail_x * board->size + tail_y] = true;
                body.pop_back();
                isGrow = false;
            }else{
                score += 1;
                isGrow = true;
            }
            if(!board->isEmpty[x * board->size + y]){
                dead();
                isGrow = false;
            }
        }
    }else{
        dead();
        isGrow = false;
    }
    return isGrow;
}

void Snake::setDirection(int key){
    if(directionIndex == 0 && key == 2) return;
    if(directionIndex == 2 && key == 0) return;
    if(directionIndex == 3 && key == 1) return;
    if(directionIndex == 1 && key == 3) return;
    directionIndex = key;
}

void Snake::render(Board *board){
    for(size_t i = 0; i < body.size(); i++){
        int x = body[i].first, y = body[i].second;
        board->board[x * board->size + y].setFillColor(sf::Color(255, 0, 0));
        board->isEmpty[x * board->size + y] = false;
    }
}


int Snake::getScore(){
    return score;
}
