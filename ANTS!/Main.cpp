#include <SFML/Graphics.hpp>

int main(void)
{
    sf::RenderWindow window(sf::VideoMode(980, 720), "ANTS!", sf::Style::Close | sf::Style::Titlebar);
    sf::RectangleShape player(sf::Vector2f(100.0f, 142.0f));
    player.setFillColor(sf::Color(95, 189, 156));

    while (window.isOpen())
    {
        sf::Event state;

        while (window.pollEvent(state))
        {
            switch (state.type)
            {
                // Closes the window.
                case sf::Event::Closed:
                    window.close();
                    break;
                // Takes user input.
                case sf::Event::TextEntered:
                    if (state.text.unicode < 128)
                    {
                        printf("%c", state.text.unicode);
                    }
                    break;
                default:
                    break;
            }
        }

        // Takes mouse input from the user.
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Mouse::getPosition();
        }

        window.clear(sf::Color(191, 137, 84));
        window.draw(player);
        window.display();
    }

    return 0;
}