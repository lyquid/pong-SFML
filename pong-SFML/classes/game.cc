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
            // start the game or something
            break;
        }
        break;
      }
      // default
    } 
  }
}

void Game::init() {
  window_.create(
    VideoMode(kScreenWidth, kScreenHeight, 32), 
    title_, 
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

void Game::render() {
  window_.clear();
  window_.display();
}

void Game::update() {}