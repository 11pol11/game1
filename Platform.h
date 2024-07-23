//
// Created by Lenovo on 7/7/2024.
//

#ifndef UNTITLED22_PLATFORM_H
#define UNTITLED22_PLATFORM_H
#include <SFML/Graphics.hpp>
#include "Bullet.h"
class Platform: public  sf::Transformable, public sf::Drawable   {
private:
    float speed=0.06;
    sf::RectangleShape rectangle=sf::RectangleShape(sf::Vector2f(150.0f,30.0f));
    sf::RectangleShape rectangle2=sf::RectangleShape(sf::Vector2f(50.0f,30.0f));
public:
    Platform(){rectangle2.move(50,0);
    rectangle2.setFillColor(sf::Color::Yellow);
    }

    int isColliding(Bullet& bullet){
        sf::Vector2f platformposition=getPosition();

        sf::Vector2f bulletposition=bullet.getPosition();
        if(bulletposition.x>platformposition.x+50 && bulletposition.x<platformposition.x+100 && bulletposition.y>platformposition.y && bulletposition.y<platformposition.y+30){
            return 10;
        }
        else if(bulletposition.x>platformposition.x && bulletposition.x<platformposition.x+150 && bulletposition.y>platformposition.y && bulletposition.y<platformposition.y+30){
            return 4;
        }
        else return 0;
    };

    void changeDirection(){speed*=-1;}
    float getSpeed(){return speed;}
    void changeColor(sf::Color color){rectangle.setFillColor(color);}
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{
        states.transform*=getTransform();
        target.draw(rectangle,states);
        target.draw(rectangle2,states);
    };
};



#endif //UNTITLED22_PLATFORM_H
