//
//  Board.cpp
//  MyFirstSFMLApp
//
//  Created by pingruchou on 2022/2/10.
//  Copyright © 2022 pingruchou. All rights reserved.
//

#include "Board.hpp"


Board::Board(int boardSize, int cellSize, int paddingLeft, int paddingTop){
    isEmpty = new bool[boardSize * boardSize];
    memset(isEmpty, true, boardSize * boardSize);
//    for(int i = 0 ; i < boardSize * boardSize; i++){
//        isEmpty[i] = true;
//    }
    board = new sf::RectangleShape[boardSize * boardSize];
    size = boardSize;
    for(size_t i = 0 ; i < boardSize; i ++){
        for(size_t j = 0 ; j < boardSize; j++){
            board[i * boardSize + j].setPosition( paddingLeft + i * cellSize, paddingTop + j * cellSize);
            board[i * boardSize + j].setSize(sf::Vector2f(cellSize, cellSize));
            board[i * boardSize + j].setOutlineThickness(1.0f);
            board[i * boardSize + j].setOutlineColor(sf::Color(0, 0, 0));
            board[i * boardSize + j].setFillColor(sf::Color(255, 255, 255));
        }
    }
    food = Food(boardSize);
    this->generateFood();
}


void Board::init(int boardSize, int cellSize, int paddingLeft, int paddingTop){
    memset(isEmpty, true, size * size);
    for(size_t i = 0 ; i < boardSize; i ++){
        for(size_t j = 0 ; j < boardSize; j++){
            board[i * boardSize + j].setPosition( paddingLeft + i * cellSize, paddingTop + j * cellSize);
            board[i * boardSize + j].setSize(sf::Vector2f(cellSize, cellSize));
            board[i * boardSize + j].setOutlineThickness(1.0f);
            board[i * boardSize + j].setOutlineColor(sf::Color(0, 0, 0));
            board[i * boardSize + j].setFillColor(sf::Color(255, 255, 255));
        }
    }
    food = Food(boardSize);
    this->generateFood();
}


void Board::generateFood(){
    while(true){
        Food newFood = Food(size);
        int x = newFood.food.x;
        int y = newFood.food.y;
        if(isEmpty[x * size + y]){
            board[x * size + y].setFillColor(sf::Color(0, 255, 0));
            food = newFood;
            break;
        }
    }
};
