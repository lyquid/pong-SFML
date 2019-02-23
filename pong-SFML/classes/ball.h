#ifndef PONG_SFML_CLASSES_BALL_H_
#define PONG_SFML_CLASSES_BALL_H_

#include <cstdlib>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "../config.h"
#include "player.h"

enum BallSounds {
  kBouncePlayer,
  kBounceWall,
  kPoint
};

class Ball {
 public:
  Ball() {
    boost_ = 0.f;
    radius_ = 10.f;
    speed_ = 400.f;
    shape_.setRadius(radius_);
    shape_.setFillColor(sf::Color::White);
    shape_.setOrigin(radius_, radius_);
    shape_.setPosition(kScreenWidth / 2.f, kScreenHeight / 2.f);
    do {
      angle_ = (std::rand() % 360) * 2 * kPi / 360;
    } while (std::abs(std::cos(angle_)) < 0.7f);
  }
  ~Ball() {}
  void decelerate();
  bool exitLeft();
  bool exitRight();
  float getAngle();
  sf::CircleShape getShape();
  void move(float delta_time);
  void playerCollision(Player p1, Player p2);
  void playSound(int sound);
  void setSound(sf::SoundBuffer* bounce_player_buffer, 
                sf::SoundBuffer* bounce_wall_buffer, 
                sf::SoundBuffer* point_buffer);
  void wallCollision();

 private:
  void accelerate();
  float angle_;
  float boost_;
  float radius_;
  sf::CircleShape shape_;
  float speed_;
  // ball sounds
  sf::Sound bounce_player_sound_;
  sf::Sound bounce_wall_sound_;
  sf::Sound point_sound_;
};

#endif  // PONG_SFML_CLASSES_BALL_H_