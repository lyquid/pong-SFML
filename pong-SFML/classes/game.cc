#include "game.h"

void Game::clean() {
  window_.close();
}

void Game::handleEvents() {
  while (window_.pollEvent(event_)) {
    switch (event_.type) {
      case Event::Closed: 
        running_ = false;
        break;

      case Event::KeyPressed: {
        switch (event_.key.code) {
          case Keyboard::Escape:
            running_ = false;
            break;

          case Keyboard::Space:
            paused_ = !paused_;
            break;
        }
        break;
      }
      // default
    } 
  }
}

void Game::init() {
  // aplication window
  window_.create(
    VideoMode(kScreenWidth, kScreenHeight, 32), 
    title_, 
    Style::Titlebar | Style::Close
  );
  window_.setVerticalSyncEnabled(true);
  // font for texts and  pause message
  if (!font_.loadFromFile("assets/AtariClassic-Regular.ttf")) {
    exit(EXIT_FAILURE);
  } else {
    pauseMessage_.setFont(font_);
    pauseMessage_.setString("Paused. Press space to resume.");
    pauseMessage_.setCharacterSize(15);
    pauseMessage_.setFillColor(Color::White);
    pauseMessage_.setOrigin(
      (pauseMessage_.getLocalBounds().left + pauseMessage_.getLocalBounds().width) / 2.f,
      (pauseMessage_.getLocalBounds().top + pauseMessage_.getLocalBounds().height) / 2.f
    );
    pauseMessage_.setPosition(Vector2f(kScreenWidth / 2, kScreenHeight / 2));
  }
  // put players in place
  resetPlayersPositions();
  // activate running flag
  running_ = true;
}

bool Game::isPaused() {
  return paused_;
}

bool Game::isRunning() {
  return running_;
}

void Game::render() {
  window_.clear();
  window_.draw(ball_.getShape());
  window_.draw(player1_.getShape());
  window_.draw(player2_.getShape());
  if (paused_) 
    window_.draw(pauseMessage_);
  window_.display();
}

void Game::resetPlayersPositions() {
  player1_.setPosition(
    Vector2f(
      (kScreenWidth * 0.05) - (player1_.getSize().x / 2), 
      (kScreenHeight / 2) - (player1_.getSize().y / 2))
  );
  player2_.setPosition(
    Vector2f(
      (kScreenWidth * 0.95) - (player2_.getSize().x / 2), 
      (kScreenHeight / 2) - (player2_.getSize().y / 2))
  );
}

void Game::update() {
  float delta_time = clock_.restart().asSeconds();
  if (!paused_) {
    // ball
    ball_.move(delta_time);
    if (ball_.exitLeft() || ball_.exitRight()) {
      ball_ = Ball();
    } else {
      if (ball_.checkCollisions()) {
        ball_.bounce();
      }
    }
    // player1
    if (Keyboard::isKeyPressed(Keyboard::W)
        && player1_.getPosition().y > 0)
      player1_.moveUp(delta_time);

    if (Keyboard::isKeyPressed(Keyboard::S)
        && (player1_.getPosition().y + player1_.getSize().y) < kScreenHeight)
      player1_.moveDown(delta_time);
    // player2
    if (Keyboard::isKeyPressed(Keyboard::Up)
        && player2_.getPosition().y > 0)
      player2_.moveUp(delta_time);

    if (Keyboard::isKeyPressed(Keyboard::Down)
        && (player2_.getPosition().y + player2_.getSize().y) < kScreenHeight)
      player2_.moveDown(delta_time);
  }
}