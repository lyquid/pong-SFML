#ifndef PONG_SFML_CLASSES_BALL_H_
#define PONG_SFML_CLASSES_BALL_H_

#include <cstdlib>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "config.h"
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
    game_mode_ = kGMNotSet;
    radius_ = 10.f;
    speed_ = 400.f;
    color_ = sf::Color::White;
    shape_.setRadius(radius_);
    shape_.setFillColor(color_);
    shape_.setOrigin(radius_, radius_);
    resetShape();
  }
  ~Ball() {}
  void decelerate();
  bool exitLeft();
  bool exitRight();
  sf::CircleShape getShape();
  void move(float delta_time);
  void playerCollision(Player p1, Player p2);
  void playSound(int sound);
  void resetShape();
  void setGameMode(int game_mode);
  void setSounds(sf::SoundBuffer* bounce_player_buffer,
                 sf::SoundBuffer* bounce_wall_buffer,
                 sf::SoundBuffer* point_buffer);
  void wallCollision();

 private:
  void accelerate();
  void heatDown();
  void heatUp();

  float angle_;
  float boost_;
  sf::Color color_;
  sf::Clock heat_clock_;
  int game_mode_;
  float radius_;
  sf::CircleShape shape_;
  float speed_;
  // ball sounds
  sf::Sound bounce_player_sound_;
  sf::Sound bounce_wall_sound_;
  sf::Sound point_sound_;
};

#endif  // PONG_SFML_CLASSES_BALL_H_
