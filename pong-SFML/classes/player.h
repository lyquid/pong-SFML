#ifndef PONG_SFML_CLASSES_PLAYER_H_
#define PONG_SFML_CLASSES_PLAYER_H_

#include <SFML/Graphics.hpp>

#include "../config.h"

using namespace sf;

class Player {
 public:
  Player(String name, int number) {
    name_ = name;
    number_ = number;
    shape_.setSize(size_);
  }
  ~Player() {}

  String getName();
  int getNumber();
  Vector2f getPosition();
  int getScore();
  RectangleShape getShape();
  Vector2f getSize();
  void incrementScore();
  void incrementScoreBy(int increment);
  void moveDown(float delta_time);
  void moveUp(float delta_time);
  void setPosition(Vector2f position);

 private: 
  String name_ = "";
  int number_ = NULL;
  Vector2f position_;
  int score_ = 0;
  RectangleShape shape_;
  Vector2f size_ = Vector2f(10.f, 128.f);
  float speed_ = 400.f;
};

#endif  // PONG_SFML_CLASSES_PLAYER_H_