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
  //ball sides
  float b_left   = ball_.getGlobalBounds().left;
  float b_right  = ball_.getGlobalBounds().left + ball_.getGlobalBounds().width;
  float b_top    = ball_.getGlobalBounds().top;
  float b_bottom = ball_.getGlobalBounds().top + ball_.getGlobalBounds().height;
  // player1 sides
  float p1_left   = p1.getShape().getGlobalBounds().left;
  float p1_right  = p1.getShape().getGlobalBounds().left + p1.getShape().getGlobalBounds().width;
  float p1_top    = p1.getShape().getGlobalBounds().top;
  float p1_bottom = p1.getShape().getGlobalBounds().top + p1.getShape().getGlobalBounds().height;
  // player2 sides
  float p2_left   = p2.getShape().getGlobalBounds().left;
  float p2_right  = p2.getShape().getGlobalBounds().left + p2.getShape().getGlobalBounds().width;
  float p2_top    = p2.getShape().getGlobalBounds().top;
  float p2_bottom = p2.getShape().getGlobalBounds().top + p2.getShape().getGlobalBounds().height;
  // collision check with player1
  if ( b_left >= p1_right 
    || b_right <= p1_left
    || b_top >= p1_bottom
    || b_bottom <= p1_top )
      p1_collision = false;
  // collision check with player2
  if ( b_left >= p2_right 
    || b_right <= p2_left
    || b_top >= p2_bottom
    || b_bottom <= p2_top )
      p2_collision = false;
  
  if (p1_collision || p2_collision) {
    // invert bounce
    // angle_ = (kPi - angle_) + (kPi / 180);
    // random bounce
    angle_ = kPi - angle_ + (std::rand() % 20) * kPi / 180;
  }
}

void Ball::wallCollision() {
  if (ball_.getPosition().y < radius_ 
    || ball_.getPosition().y + radius_ > kScreenHeight) 
      angle_ = -angle_;
}