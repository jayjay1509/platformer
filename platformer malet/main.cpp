

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>


#include "game.h"
#include "tilemap.h"


int main()
{


    Game game;


    game.tilemap_.Load();

    game.init();

    // run the program as long as the window is open
    while (game.window_.isOpen())
    {


        // check all the window's events that were triggered since the last iteration of the loop

        sf::Event event;
        while (game.window_.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                game.window_.close();

            if (event.type == sf::Event::Resized) //the rezize works but asset size problems were discovered so I advise against doing it for the pleasure of the game
            {
                sf::View view = game.window_.getView();
                view.setSize(event.size.width, event.size.height);
                game.window_.setView(view);
                game.windowResized = !game.windowResized;

            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::F5) {
                    game.tilemap_.Save();
                }
                if (event.key.code == sf::Keyboard::F9) {
                    game.tilemap_.Load();
                }
            }
        }


        game.update();

    }

    return 0;

}