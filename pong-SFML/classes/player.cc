#include "player.h"

sf::String Player::getName() {
  return name_;
}

int Player::getNumber() {
  return number_;
}

sf::Vector2f Player::getPosition() {
  return shape_.getPosition();
}

int Player::getScore() {
  return score_;
}

sf::RectangleShape Player::getShape() {
  return shape_;
}

sf::Vector2f Player::getSize() {
  return shape_.getSize();
}

void Player::incrementScore() {
  ++score_;
}

void Player::incrementScoreBy(int increment) {
  score_ += increment;
}

void Player::moveDown(float delta_time) {
  shape_.move(0.f, speed_ * delta_time);
}

void Player::moveUp(float delta_time) {
  shape_.move(0.f, -speed_ * delta_time);
}

void Player::setPosition(sf::Vector2f position) {
  shape_.setPosition(position);
}