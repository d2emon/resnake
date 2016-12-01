#include <SFML/Graphics.hpp>
#include "settings.hpp"

int dir;
int num = 4;
struct Snake
    {int x, y;} s[100];

void Tick()
{
    for(int i=num; i>0; --i)
    {
        s[i].x = s[i-1].x;
        s[i].y = s[i-1].y;
    }

    if(dir == 0)
        s[0].y += 1;
    if(dir == 1)
        s[0].x -= 1;
    if(dir == 2)
        s[0].x += 1;
    if(dir == 3)
        s[0].y -= 1;
}

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

    sf::Clock clock;
    float timer = 0;
    float delay = 0.1;

	// Start the game loop
    while (app.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                app.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            dir = 1;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            dir = 2;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            dir = 3;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            dir = 0;

        if(timer > delay)
        {
            timer = 0;
            Tick();
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

        for(int i=0; i<num; i++)
        {
            sBlock2.setPosition(s[i].x * blockSize, s[i].y * blockSize);
            app.draw(sBlock2);
        }

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
