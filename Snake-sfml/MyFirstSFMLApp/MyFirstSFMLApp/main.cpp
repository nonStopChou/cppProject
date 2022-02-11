
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "Snake.hpp"
#include "Board.hpp"
// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

int main(int, char const**)
{
    const int boardSize = 45;
    const int paddingLeft = 10;
    const int paddingTop = 50;
    const int paddingRight = 10;
    const int paddingBottom = 10;
    const int cellSize = 20;
    const int windowsSize = boardSize * cellSize;
    const int dialogWidth = windowsSize / 2;
    const int dialogHeight = windowsSize / 4;
    int speed = 15;
    
    
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(windowsSize + paddingLeft + paddingRight, windowsSize + paddingTop + paddingBottom), "Snake Game");
    window.setFramerateLimit(speed);
    
    // set font
    sf::Font font;
    if (!font.loadFromFile("/Users/pingruchou/Desktop/sfmlPractice/MyFirstSFMLApp/MyFirstSFMLApp/Quicksand-Light.otf")) {
        return EXIT_FAILURE;
    }
    
    // scoreLabel text
    sf::Text scoreLabel("Score : ", font, 30);
    scoreLabel.setFillColor(sf::Color::White);
    scoreLabel.setPosition(10, 10);
    
    
    // score text
    int scoreInt = 0;
    sf::Text scoreString(std::to_string(scoreInt), font, 30);
    scoreString.setFillColor(sf::Color::White);
    scoreString.setPosition(125, 12);
    
    
    // restart dialog
    sf::RectangleShape restartDialog;
    restartDialog.setPosition(windowsSize / 2 -  dialogWidth / 2, windowsSize / 2 - dialogHeight / 2);
    restartDialog.setFillColor(sf::Color(142, 142, 142));
    restartDialog.setSize(sf::Vector2f(dialogWidth, dialogHeight));
    restartDialog.setOutlineThickness(1.0f);
    restartDialog.setOutlineColor(sf::Color(0, 0, 0));
    sf::Text restartString("Restart ? (Y/N)", font, 30);
    restartString.setPosition(windowsSize / 2 -  dialogWidth / 4, windowsSize / 2 - dialogHeight / 4);
    restartString.setFillColor(sf::Color(0, 0, 0));
    
    
    // create board && player
    Board board(boardSize, cellSize,paddingLeft, paddingTop);
    
    Snake player(0, 0);
    
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            
            // Top, Left, Right, Bottom pressed: Change Direction
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                player.setDirection(2);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                player.setDirection(0);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                player.setDirection(1);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                player.setDirection(3);
            }
            if(player.isDead() && sf::Keyboard::isKeyPressed(sf::Keyboard::Y)){
                board.init(boardSize, cellSize,paddingLeft, paddingTop);
                player.init();
                scoreInt = 0;
                speed = 15;
                scoreString.setString(std::to_string(scoreInt));
                window.setFramerateLimit(speed);
            }
            if(player.isDead() && sf::Keyboard::isKeyPressed(sf::Keyboard::N)){
                window.close();
            }
        }
        
        
        if(player.isDead()){
            player.setDirection(-1);
        }else{
            bool isGrow = player.step(&board);
            if(isGrow){
                board.generateFood();
                scoreInt += speed;
                scoreString.setString(std::to_string(scoreInt));
                int score = player.getScore();
                if(score != 0 && score % 2 == 0){
                    speed += 2;
                    window.setFramerateLimit(speed);
                }
            }
        }
        player.render(&board);
        
        
        
        
        // Clear screen
        window.clear();
        
        if(player.isDead()){
            std::printf("HOLY");
            // Draw the board
            for(size_t i = 0 ; i < board.size * board.size; i++){
                window.draw(board.board[i]);
            }
            // Draw the string
            window.draw(scoreLabel);
            window.draw(scoreString);
            window.draw(restartDialog);
            window.draw(restartString);
        }else{
            // Draw the board
            for(size_t i = 0 ; i < board.size * board.size; i++){
                window.draw(board.board[i]);
            }
            // Draw the string
            window.draw(scoreLabel);
            window.draw(scoreString);
        }
        
        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
