#include "ball.h"

void Ball::accelerate() {
  boost_ += 0.9 * speed_;
}

void Ball::decelerate() {
  (boost_ > 0) ? boost_ -= boost_ * 0.003 : boost_ = 0;
}

bool Ball::exitLeft() {
  return (shape_.getPosition().x < radius_) ? true : false;
}

bool Ball::exitRight() {
  return (shape_.getPosition().x + radius_ > kScreenWidth) ? true : false;
}

float Ball::getAngle() {
  return angle_;
}

sf::CircleShape Ball::getShape() {
  return shape_;
}

void Ball::move(float delta_time) {
  float factor = (speed_ + boost_) * delta_time;
  shape_.move(std::cos(angle_) * factor, std::sin(angle_) * factor);
}

void Ball::playerCollision(Player p1, Player p2) {
  bool p1_collision = true;
  bool p2_collision = true;
  sf::FloatRect ball_bb = shape_.getGlobalBounds();
  sf::FloatRect p1_bb = p1.getShape().getGlobalBounds();
  sf::FloatRect p2_bb = p2.getShape().getGlobalBounds();
  // player1 collision check
  if (ball_bb.intersects(p1_bb)) {
    playSound(kBouncePlayer);
    if (p1.isMoving()) 
      accelerate();
    if (shape_.getPosition().y > p1.getPosition().y) 
      angle_ = kPi - angle_ + (std::rand() % 20) * kPi / 180;   
    else 
      angle_ = kPi - angle_ - (std::rand() % 20) * kPi / 180; 

    shape_.setPosition(p1.getPosition().x + radius_ + p1.getSize().x / 2 + 0.1f, shape_.getPosition().y);
    // player2 collision check
  } else if (ball_bb.intersects(p2_bb)) {
    playSound(kBouncePlayer);
    if (p2.isMoving()) 
      accelerate();
    if (shape_.getPosition().y > p2.getPosition().y) 
      angle_ = kPi - angle_ + (std::rand() % 20) * kPi / 180;   
    else 
      angle_ = kPi - angle_ - (std::rand() % 20) * kPi / 180; 
    // seems that setOrigin isn't working here (r * 2)
    shape_.setPosition(p2.getPosition().x - radius_ - p2.getSize().x / 2 - 0.1f, shape_.getPosition().y);
  }
}

void Ball::playSound(int sound) {
  switch (sound) {
    case kBouncePlayer:
      bounce_player_sound_.play();
      break;
    case kBounceWall:
      bounce_wall_sound_.play();
      break;
    case kPoint:
      point_sound_.play();
      break;
    default:
      break;
  }
}

void Ball::resetShape() {
  boost_ = 0.f;
  shape_.setPosition(kScreenWidth / 2.f, kScreenHeight / 2.f);
  do {
    angle_ = (std::rand() % 360) * 2 * kPi / 360;
  } while (std::abs(std::cos(angle_)) < 0.7f);
}

void Ball::setSounds(sf::SoundBuffer* bounce_player_buffer, 
                     sf::SoundBuffer* bounce_wall_buffer, 
                     sf::SoundBuffer* point_buffer) {
  bounce_player_sound_.setBuffer(*bounce_player_buffer);
  bounce_wall_sound_.setBuffer(*bounce_wall_buffer);
  point_sound_.setBuffer(*point_buffer);
} 

void Ball::wallCollision() {
  // up collision
  if (shape_.getPosition().y < radius_ ) {
    shape_.setPosition(shape_.getPosition().x, radius_);
    angle_ = -angle_;
    playSound(kBounceWall);
  // down collision  
  } else if (shape_.getPosition().y > kScreenHeight - radius_) {
    shape_.setPosition(shape_.getPosition().x, kScreenHeight - radius_);
    angle_ = -angle_;
    playSound(kBounceWall);
  }
}