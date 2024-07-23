//
// Created by Lenovo on 7/10/2024.
//

#ifndef UNTITLED22_BULLET_H
#define UNTITLED22_BULLET_H


#include <SFML/Graphics.hpp>

class Bullet: public  sf::Transformable, public sf::Drawable   {
private:
    sf::Texture* texture;
    float magnitude=-0.07;
    sf::Vector2f  speed;
    sf::RectangleShape rectangle=sf::RectangleShape(sf::Vector2f (20,20));
public:
    //~Bullet(){delete texture;}
    Bullet(){
        texture=new sf::Texture;
        texture->loadFromFile("arrow.png");
        rectangle.setTexture(texture);
    };

    bool isOutOfScreen(){
        sf::Vector2f position=getPosition();
        if (position.x>710 || position.x<-10||position.y<-10){
            return true;
        }
        else{
            return false;
        }
    };
    float getMagnitude(){return magnitude;}
    void changeColor(sf::Color color){rectangle.setFillColor(color);}
    void setSpeed (float x, float y){speed=sf::Vector2f(x,y);}
    sf::Vector2f getSpeed(){return speed;}
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{
        states.transform*=getTransform();
        target.draw(rectangle,states);
    };
};


#endif //UNTITLED22_BULLET_H
