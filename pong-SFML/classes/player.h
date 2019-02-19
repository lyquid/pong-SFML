#ifndef PONG_SFML_CLASSES_PLAYER_H_
#define PONG_SFML_CLASSES_PLAYER_H_

#include <SFML/Graphics.hpp>

#include "../config.h"

class Player {
 public:
  Player(sf::String name, int number) {
    name_ = name;
    number_ = number;
    score_ = 0;
    size_ = sf::Vector2f(10.f, 128.f);
    speed_ = 400.f;
    shape_.setSize(size_);
    shape_.setOrigin(size_ / 2.f);
  }
  ~Player() {}

  sf::String getName();
  int getNumber();
  sf::Vector2f getPosition();
  int getScore();
  sf::RectangleShape getShape();
  sf::Vector2f getSize();
  void incrementScore();
  void incrementScoreBy(int increment);
  void moveDown(float delta_time);
  void moveUp(float delta_time);
  void setPosition(sf::Vector2f position);

 private: 
  sf::String name_;
  int number_;
  sf::Vector2f position_;
  int score_;
  sf::RectangleShape shape_;
  sf::Vector2f size_;
  float speed_;
};

#endif  // PONG_SFML_CLASSES_PLAYER_H_