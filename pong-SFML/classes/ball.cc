#include "ball.h"

void Ball::bounce() {
  angle_ = -angle_;
}

bool Ball::checkCollisions() {
  return (playerCollision() || wallCollision()) ? true : false;
}

bool Ball::exitLeft() {
  return (ball_.getPosition().x < radius_) ? true : false;
}

bool Ball::exitRight() {
  return (ball_.getPosition().x + radius_ > kScreenWidth) ? true : false;
}

CircleShape Ball::getShape() {
  return ball_;
}

void Ball::move(float delta_time) {
  float factor = speed_ * delta_time;
  ball_.move(std::cos(angle_) * factor, std::sin(angle_) * factor);
}

bool Ball::playerCollision() {
  return false;
}

bool Ball::wallCollision() {
  if (ball_.getPosition().y < radius_ 
    || ball_.getPosition().y + radius_ > kScreenHeight) 
      return true;
  return false;
}