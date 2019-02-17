#include "ball.h"

void Ball::bounce() {
  angle_ = -angle_;
}

bool Ball::exitLeft() {
  return (ball_.getPosition().x < radius_) ? true : false;
}

bool Ball::exitRight() {
  return (ball_.getPosition().x + radius_ > kScreenWidth) ? true : false;
}

float Ball::getAngle() {
  return angle_;
}

sf::CircleShape Ball::getShape() {
  return ball_;
}

void Ball::move(float delta_time) {
  float factor = speed_ * delta_time;
  ball_.move(std::cos(angle_) * factor, std::sin(angle_) * factor);
}

void Ball::playerCollision(Player p1, Player p2) {
  bool p1_collision = true;
  bool p2_collision = true;
  sf::FloatRect ball_bb = ball_.getGlobalBounds();
  sf::FloatRect p1_bb = p1.getShape().getGlobalBounds();
  sf::FloatRect p2_bb = p2.getShape().getGlobalBounds();
  // player1 collision check
  if (ball_bb.intersects(p1_bb)) {
    if (ball_.getPosition().y > p1.getPosition().y) 
      angle_ = kPi - angle_ + (std::rand() % 20) * kPi / 180;   
    else 
      angle_ = kPi - angle_ - (std::rand() % 20) * kPi / 180; 

    ball_.setPosition(p1.getPosition().x + radius_ + p1.getSize().x / 2 + 0.1f, ball_.getPosition().y);
  }  
  // player2 collision check
  if (ball_bb.intersects(p2_bb)) {
    if (ball_.getPosition().y > p2.getPosition().y) 
      angle_ = kPi - angle_ + (std::rand() % 20) * kPi / 180;   
    else 
      angle_ = kPi - angle_ - (std::rand() % 20) * kPi / 180; 
    // seems that setOrigin isn't working here (r * 2)
    ball_.setPosition(p2.getPosition().x - radius_ * 2 - p2.getSize().x / 2 - 0.1f, ball_.getPosition().y);
  }
}

void Ball::wallCollision() {
  if (ball_.getPosition().y < radius_ 
    || ball_.getPosition().y + radius_ > kScreenHeight) 
      angle_ = -angle_;
}