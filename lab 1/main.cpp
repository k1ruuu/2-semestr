#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

#define EPS 0.1


class AnimatedText {
private:
    int m_duration = 0;
    Text text;
    Font font;
    string finalString;
    string currentString;
    int i = 0;
    Clock clock;
public:
    
    
    AnimatedText(const string& s) {
        if (!font.loadFromFile("arkhip.ttf"))
        {
            cout << "error...";
        }
        text.setFont(font);
        text.setStyle(Text::Bold);
        text.setCharacterSize(24);
        finalString = s;
        text.setColor(Color::Red);
        text.setPosition(100, 100);

    };
    void logic(float duration) {
        
        float time = clock.getElapsedTime().asSeconds();
        if (time > finalString.length() / duration) {

            if (i < finalString.length()) {
                currentString += finalString[i];
                i++;
            }
            text.setString(currentString);

            clock.restart();

        }
    }
    
    void drawText() {
        RenderWindow window(VideoMode(600, 600), "lab 1");
        
        
        
            while (window.isOpen())
            {
                logic(12);
                Event event;
                while (window.pollEvent(event)) {
                    if (event.type == Event::Closed) {
                        window.close();
                    }
                }
                window.clear(Color::White);
                window.draw(text);
                window.display();
            }
        
    }

    //~AnimatedText();
};

int main()
{
    AnimatedText at("Hello world!");
    at.drawText();
    
    
    return 0;
}