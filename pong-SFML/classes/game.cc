#include "game.h"

void Game::clean() {
  window_.close();
}

void Game::handleEvents() {
  while (window_.pollEvent(event_)) {
    switch (event_.type) {
      case sf::Event::Closed: 
        quit_ = true;
        break;
      case sf::Event::KeyPressed: {
        if (in_menu_) {
          switch (event_.key.code) {
            case sf::Keyboard::Num1:
              in_menu_ = false;
              resetPlayersAndPositions();
              ball_ = Ball();
              break;
            case sf::Keyboard::Num2:
              in_menu_ = false;
              resetPlayersAndPositions();
              ball_ = Ball();
              break;
            case sf::Keyboard::Escape:
              quit_ = true;
              break;
            default:
              break;
          }
        } else { // not in menu
          switch (event_.key.code) {
            case sf::Keyboard::Escape:
              paused_ = false;
              in_menu_ = true;
              break;
            case sf::Keyboard::Space:
              paused_ = !paused_;
              break;
            default:
              break;
          }
        }
        break;
      }
      default:
        break;
    } 
  }
}

void Game::init() {
  // aplication window
  window_.create(
    sf::VideoMode(kScreenWidth, kScreenHeight, 32), 
    title_, 
    sf::Style::Titlebar | sf::Style::Close
  );
  window_.setVerticalSyncEnabled(true);
  // sounds
  initSound();
  // font for texts
  if (!font_.loadFromFile("assets/AtariClassic-Regular.ttf")) {
    exit(EXIT_FAILURE);
  } else { 
    // pause text
    Menu::initText(&font_, &pause_text_, 15);
    pause_text_.setString("Paused. Press space to resume.");
    Menu::centerTextOrigin(&pause_text_);
    pause_text_.setPosition(sf::Vector2f(kScreenWidth / 2, kScreenHeight / 2));
    // score text
    Menu::initText(&font_, &score_text_, 15);
    updateScoreText();
    // angle text
    Menu::initText(&font_, &angle_text_, 15);
  }
  // put players in place
  resetPlayersAndPositions();
}

void Game::initSound() {
  if (!ball_bounce_player_buffer_.loadFromFile("assets/ping_pong_8bit_beeep.wav") 
  || (!ball_bounce_wall_buffer_.loadFromFile("assets/ping_pong_8bit_plop.wav"))
  || (!ball_point_buffer_.loadFromFile("assets/ping_pong_8bit_peeeeeep.wav"))) {
    exit(EXIT_FAILURE);
  }
  ball_.setSound(&ball_bounce_player_buffer_, &ball_bounce_wall_buffer_, &ball_point_buffer_);
}

bool Game::isPaused() {
  return paused_;
}

bool Game::quit() {
  return quit_;
}

void Game::render() {
  window_.clear();
  if (in_menu_) {
    menu_.draw(&window_);
  } else {
    window_.draw(score_text_);
    // window_.draw(angle_text_);
    window_.draw(ball_.getShape());
    window_.draw(player1_.getShape());
    window_.draw(player2_.getShape());
    if (paused_) 
      window_.draw(pause_text_);
  }
  // display the updated frame
  window_.display();
}

void Game::resetPlayersAndPositions() {
  player1_.~Player();
  player1_ = Player("player1", 1);
  player1_.setPosition(
    sf::Vector2f(
      (kScreenWidth * 0.05f) - (player1_.getSize().x / 2), 
      (kScreenHeight / 2) - (player1_.getSize().y / 2))
  );
  player2_.~Player();
  player2_ = Player("player2", 2);
  player2_.setPosition(
    sf::Vector2f(
      (kScreenWidth * 0.95f) - (player2_.getSize().x / 2), 
      (kScreenHeight / 2) - (player2_.getSize().y / 2))
  );
}

template <typename T> std::string Game::toString(T arg) {
  std::stringstream ss;
  ss << arg;
  return ss.str();
}

void Game::update() {
  float delta_time = clock_.restart().asSeconds();
  if (!in_menu_) {
    if (!paused_) {
      // ball movement
      ball_.move(delta_time);
      if (ball_.exitLeft()) {
        ball_.playSound(kPoint); 
        player2_.incrementScore();
        ball_ = Ball();
      } 
      if (ball_.exitRight()) {
        ball_.playSound(kPoint);
        player1_.incrementScore();
        ball_ = Ball();
      }
      updateScoreText();
      // ball collisions
      ball_.wallCollision();
      ball_.playerCollision(player1_, player2_);
      updateAngleText();
      // player1
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
          && player1_.getPosition().y > player1_.getSize().y / 2)
        player1_.moveUp(delta_time);

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
          && player1_.getPosition().y < kScreenHeight - (player1_.getSize().y / 2))
        player1_.moveDown(delta_time);
      // player2
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
          && player2_.getPosition().y > player2_.getSize().y / 2)
        player2_.moveUp(delta_time);

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
          && player2_.getPosition().y < kScreenHeight - (player2_.getSize().y / 2))
        player2_.moveDown(delta_time);
    }
  }
}

void Game::updateAngleText() {
  angle_text_.setString("ball angle: " + toString<float>(ball_.getAngle()));
}

void Game::updateScoreText() {
  // todo: make score like
  // 00001 -> 00120
  score_text_.setString(
    toString<int>(player1_.getScore()) 
    + " - SCORE - " 
    + toString<int>(player2_.getScore())
  );
  Menu::centerTextOrigin(&score_text_);
  score_text_.setPosition(kScreenWidth / 2, 8);
}
