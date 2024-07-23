//
// Created by Lenovo on 7/7/2024.
//

#ifndef UNTITLED22_PLAYER_H
#define UNTITLED22_PLAYER_H
#include <SFML/Graphics.hpp>

class Player: public  sf::Transformable, public sf::Drawable   {
private:
    sf::Texture* texture;
    float speed=0.2;
    sf::RectangleShape rectangle=sf::RectangleShape(sf::Vector2f(100.0f,50.0f));
public:
    ~Player(){delete texture;}
    Player(){
         texture=new sf::Texture;
        texture->loadFromFile("player.png");
        rectangle.setTexture(texture);
    };
    float getSpeed(){return speed;}
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{
     states.transform*=getTransform();
     target.draw(rectangle,states);
    };
};


#endif //UNTITLED22_PLAYER_H
