#include "ball.h"

void Ball::accelerate() {
  boost_ += 0.9f * speed_;
  if (game_mode_ == kGM1PChaos || game_mode_ == kGM2PChaos) {
    heatUp();
  }
}

void Ball::decelerate() {
  switch (game_mode_) {
    case kGM1Player:
    case kGM2Players:
      (boost_ > 0) ? boost_ -= boost_ * 0.003f : boost_ = 0;
      break;
    case kGM1PChaos:
    case kGM2PChaos:
      (boost_ > 0) ? boost_ -= boost_ * 0.002f : boost_ = 0;
      heatDown();
      break;
    default:
      break;
  }
}

bool Ball::exitLeft() {
  return (shape_.getPosition().x < radius_) ? true : false;
}

bool Ball::exitRight() {
  return (shape_.getPosition().x + radius_ > kScreenWidth) ? true : false;
}

sf::CircleShape Ball::getShape() {
  return shape_;
}

void Ball::heatDown() {
  if (heat_clock_.getElapsedTime().asMilliseconds() > 500) {
    heat_clock_.restart();
    int heat_ratio = 2;
    if (color_.g <= 255 - heat_ratio && color_.b <= 255 - heat_ratio) {
      color_.g += heat_ratio;
      color_.b += heat_ratio; 
    }
    shape_.setFillColor(color_);
  }
}

void Ball::heatUp() {
  int heat_ratio = 20;
  if (color_.g >= heat_ratio && color_.b >= heat_ratio) {
    color_.g -= heat_ratio;
    color_.b -= heat_ratio; 
  }
  shape_.setFillColor(color_);
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
  color_ = sf::Color::White;
  boost_ = 0.f;
  shape_.setPosition(kScreenWidth / 2.f, kScreenHeight / 2.f);
  do {
    angle_ = (std::rand() % 360) * 2 * kPi / 360;
  } while (std::abs(std::cos(angle_)) < 0.7f);
}

void Ball::setGameMode(int game_mode) {
  game_mode_ = game_mode;
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