#include "player.h"

bool Player::checkBottomBound() {
  return (getPosition().y < kScreenHeight - (getSize().y / 2)) ? true : false;
}

bool Player::checkUpperBound() {
  return (getPosition().y > getSize().y / 2) ? true : false;
}

void Player::computerPlay(float ball_y, float delta_time) {
  float player_y = getPosition().y;
  int minThreshold = getSize().y / 3;
  int xThreshold = (getSize().y * 1.1) - minThreshold;
  float threshold = rand() % xThreshold + minThreshold;
  if (abs(player_y - ball_y) > threshold) {
    // ball is down
    if (player_y < ball_y && checkBottomBound()) {
      float modifier = rand() % 201;
      moveDown(delta_time, modifier);
    // ball is up
    } else if (player_y > ball_y && checkUpperBound()){ 
      float modifier = rand() % 201;
      moveUp(delta_time, modifier);
    }
  }
}

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

void Player::moveDown(float delta_time, float modifier) {
  shape_.move(0.f, speed_ * delta_time);
}

void Player::moveUp(float delta_time, float modifier) {
  shape_.move(0.f, -speed_ * delta_time);
}

void Player::setPosition(sf::Vector2f position) {
  shape_.setPosition(position);
}