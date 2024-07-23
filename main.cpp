#include <SFML/Graphics.hpp>
#include<iostream>
#include "Player.h"
#include "Platform.h"
#include <cmath>
#include"Bullet.h"
#include <vector>

int main()
{   //text initialization
    sf::Text scoretext;
    sf::Text timetext;
    timetext.setPosition(625,100);
    timetext.setFillColor(sf::Color::Blue);
    scoretext.setPosition(625,50);
    sf::Font font;
    if (!font.loadFromFile( "font/ArialMT.ttf" ));
    timetext.setFont(font);
    scoretext.setFont(font);
    scoretext.setString("0");
    scoretext.setFillColor(sf::Color::Blue);
    float gametimer=60;
    int points=0;
    float timer=0;
    // entity initialization
    std::vector<Bullet >bullets;
    Platform platform;
    platform.changeColor(sf::Color::Red);
    Player player;
    player.setPosition(300,750);
    player.setOrigin(50,25);
    //window initialization
    sf::RenderWindow window(sf::VideoMode(700, 800), "SFML works!");
    sf::Clock clock;
    //main game loop
    while (window.isOpen())
    {
        float dt=clock.getElapsedTime().asSeconds();
        timer+=dt;
        gametimer-=dt;
        timetext.setString(std::to_string(gametimer));
        if (gametimer<0){
            window.close();
        }
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //checking for player inputs
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            if(player.getPosition().x>50) {
                player.move(-player.getSpeed(), 0.0);
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            if(player.getPosition().x<650) {
                player.move(player.getSpeed(), 0.0);
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            if(player.getRotation()>=325 ||player.getRotation()<=45) {
                player.rotate(-0.03);
            }
            else if(player.getRotation()>=45 && player.getRotation()<=50 ){player.setRotation(45);};

        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            if(player.getRotation()>=325 ||player.getRotation()<=45) {

                player.rotate(0.03);
            }
            else if(player.getRotation()<=325 && player.getRotation()>=310 ){player.setRotation(325);};
        }
        //check if platform is ut of window
        if(platform.getPosition().x>550) {
           platform.changeDirection();

        }
        else if(platform.getPosition().x<0){
            platform.changeDirection();
        }
        //bullet spawn
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            if(timer>0.5){
                timer=0;
                bullets.emplace_back();
                Bullet & bullet=bullets.back();
                bullet.setRotation(player.getRotation());
                bullet.changeColor(sf::Color::Blue);
                bullet.setOrigin(5,5);
                bullet.setPosition(300,750);
                bullet.setSpeed(-bullet.getMagnitude()*sin(player.getRotation()/180 *3.14),bullet.getMagnitude()*cos(player.getRotation()/180 *3.14));
                bullet.setPosition(player.getPosition());
                //std::cout<<bullets.size()<<std::endl;

            }

        }//move platform
        platform.move( platform.getSpeed(),0);
        //move all the bullets and check for collision
        for(Bullet & bullet:bullets){
            bullet.move(bullet.getSpeed());
            int pointstoadd=platform.isColliding(bullet);
         if (pointstoadd){
             points+=pointstoadd;
             scoretext.setString(std::to_string(points));
         }
        }//if bullet is out of bounds or is colliding the platfrom then delete it
        auto it=bullets.begin();
        while(it!=bullets.end()){
            if(it->isOutOfScreen()||platform.isColliding(*it))
                it=bullets.erase(it);
            else it++;
        }
        clock.restart();
        //draw entities on window
        window.clear();
        window.draw(timetext);
        window.draw(scoretext);
        window.draw(player);
        window.draw(platform);
        for(Bullet & bullet:bullets){window.draw(bullet);}
        window.display();


    }

    return 0;
}