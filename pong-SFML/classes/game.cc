#include "game.h"

void Game::clean() {
  window_.close();
}

void Game::handleEvents() {
  while (window_.pollEvent(event_)) {
    if (event_.type == Event::Closed)
      running_ = false;
  }
}

void Game::init() {
  window_.create(
    VideoMode(kScreenWidth, kScreenHeight, 32), 
    kAppName, 
    Style::Titlebar | Style::Close
  );
  window_.setVerticalSyncEnabled(true);
  running_ = true;
}

bool Game::isPaused() {
  return paused_;
}

bool Game::isRunning() {
  return running_;
}

void Game::mustInit(bool test, const char* desc) {}

void Game::render() {}

void Game::update() {}