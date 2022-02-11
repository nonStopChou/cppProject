
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

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"
#include "Board.hpp"
int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1000 + 20, 1000 + 20), "SFML window", sf::Style::Close);
    
    
    
    Board board(100);
    // Start the game loop
    bool start = false;
    bool mouseControl = true;
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
            
            if( mouseControl && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                board.setCell(mousePos.x, mousePos.y);
            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                start = true;
                mouseControl = false;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
                start = false;
                mouseControl = true;
            }
            
        }
        if(start){
            board.update();
            board.render();
        }
        // Clear screen
        window.clear();
        for(size_t i = 0 ; i < 100 * 100; i++){
            window.draw(board.board[i]);
        }
        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
