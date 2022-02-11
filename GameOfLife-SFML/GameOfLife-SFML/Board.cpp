//
//  board.cpp
//  GameOfLife-SFML
//
//  Created by pingruchou on 2022/2/11.
//  Copyright © 2022 pingruchou. All rights reserved.
//

#include "Board.hpp"

Board::Board(int size){
    size = size;
    board = new sf::RectangleShape[size * size];
    cellStatus = new bool[size * size];
    for(size_t i = 0 ; i < size; i++){
        for(size_t j = 0 ; j < size ; j++){
            sf::RectangleShape *ptrBoard = &board[i * size + j];
            ptrBoard->setSize(sf::Vector2f(10, 10));
            ptrBoard->setFillColor(sf::Color(255, 255, 255));
            ptrBoard->setPosition(10 + i * 10, 10 + j * 10);
            ptrBoard->setOutlineColor(sf::Color(0, 0, 0));
            ptrBoard->setOutlineThickness(1.0f);
            cellStatus[i * size + j] = false;
        }
    }
};


void Board::update(){
    bool newCellStatus[size * size];
    memset(newCellStatus, false, size * size);
    for(size_t i = 0 ; i < size; i++){
        for(size_t j = 0 ; j < size ; j++){
            int cnt = 0;
            if(i - 1 >= 0){
                cnt += (cellStatus[(i - 1) * size + j] == true) ? 1 : 0;
            }
            if(i + 1 < size){
                cnt += (cellStatus[(i + 1) * size + j] == true) ? 1 : 0;
            }
            if(j - 1 >= 0){
                cnt += (cellStatus[i * size + j - 1] == true) ? 1 : 0;
            }
            if(j + 1 >= 0){
                cnt += (cellStatus[i * size + j + 1] == true) ? 1 : 0;
            }
            if(i - 1 >= 0 && j - 1 >= 0){
                cnt += (cellStatus[(i - 1) * size + j - 1] == true) ? 1 : 0;
            }
            if(i - 1 >= 0 && j + 1 < size){
                cnt += (cellStatus[(i - 1) * size + j + 1] == true) ? 1 : 0;
            }
            if(i + 1 < size && j - 1 >= 0){
                cnt += (cellStatus[(i + 1) * size + j - 1] == true) ? 1 : 0;
            }
            if(i + 1 < size && j + 1 < size){
                cnt += (cellStatus[(i + 1) * size + j + 1] == true) ? 1 : 0;
            }
            if(cnt > 3 || cnt < 2){
                newCellStatus[i * 100 + j] = false;
            }else if(cnt == 3){
                newCellStatus[i * 100 + j] = true;
            }else{
                newCellStatus[i * 100 + j] = cellStatus[i * 100 + j];
            }
            
        }
    }
    for(size_t i = 0 ; i < size; i++){
        for(size_t j = 0 ; j < size ; j++){
            cellStatus[i * 100 + j] = newCellStatus[i * 100 + j];
        }
    }
    
};

void Board::render(){
    for(size_t i = 0 ; i < size; i++){
        for(size_t j = 0 ; j < size ; j++){
            if(cellStatus[i * 100 + j]){
                board[i * 100 + j].setFillColor(sf::Color(0, 0, 0));
            }else{
                board[i * 100 + j].setFillColor(sf::Color(255, 255, 255));
            }
        }
    }
};

void Board::setCell(int x, int y){
    x -= 10;
    y -= 10;
    if(x > 1000) x = 999;
    if(y > 1000) y = 999;
    if(x > 1000 || x < 0 || y > 1000 || y < 0){
        return;
    }
    int row = x / 10, col = y / 10;
    std::printf("%d, %d\n", row, col);
    board[row * 100 + col].setFillColor(sf::Color(0, 0, 0));
    cellStatus[row * 100 + col] = true;
}
