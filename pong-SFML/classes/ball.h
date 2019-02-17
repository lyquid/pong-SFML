#ifndef PONG_SFML_CLASSES_BALL_H_
#define PONG_SFML_CLASSES_BALL_H_

#include <cstdlib>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "../config.h"
#include "player.h"

class Ball {
 public:
  Ball() {
    ball_.setRadius(radius_);
    ball_.setFillColor(sf::Color::White);
    ball_.setOrigin(radius_ / 2, radius_ / 2);
    ball_.setPosition(kScreenWidth / 2, kScreenHeight / 2);
    do {
      angle_ = (std::rand() % 360) * 2 * kPi / 360;
    } while (std::abs(std::cos(angle_)) < 0.7f);
    
  }
  ~Ball() {}

  void bounce();
  bool exitLeft();
  bool exitRight();
  float getAngle();
  sf::CircleShape getShape();
  void move(float delta_time);
  void playerCollision(Player p1, Player p2);
  void playSound(int sound);
  void setSound(sf::SoundBuffer* sound_buffer);
  void wallCollision();

 private:
  enum BallSounds {
    kBounce,
    kDestroy,
    kPoint
  };
  float angle_ = 0.f;
  sf::CircleShape ball_;
  sf::Sound bounce_sound_;
  float radius_ = 10.f;
  float speed_ = 400.f;
};

#endif  // PONG_SFML_CLASSES_BALL_H_