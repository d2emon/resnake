#include <SFML/Graphics.hpp>
#include "settings.hpp"

int main()
{
    srand(time(0));

    // Create the main window
    sf::RenderWindow app(sf::VideoMode(winSize[0], winSize[1]), gameTitle);
    // app.setFramerateLimit(fps);

    // Load a sprite to display
    int backgroundId = rand() % backgroundsCount;

    sf::Texture tBackground;
    if (!tBackground.loadFromFile(backgrounds[backgroundId]))
        return EXIT_FAILURE;
    sf::Sprite sBackground(tBackground);

    sf::Texture tBlock1;
    if (!tBlock1.loadFromFile(blocks[0]))
        return EXIT_FAILURE;
    sf::Sprite sBlock1(tBlock1);

    sf::Texture tBlock2;
    if (!tBlock2.loadFromFile(blocks[1]))
        return EXIT_FAILURE;
    sf::Sprite sBlock2(tBlock2);

	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                app.close();
        }

        // Clear screen
        app.clear();

        // Draw the sprite
        app.draw(sBackground);

        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
            {
                sBlock1.setPosition(i * blockSize, j * blockSize);
                app.draw(sBlock1);
            }

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
