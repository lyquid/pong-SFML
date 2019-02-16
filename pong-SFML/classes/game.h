#ifndef PONG_SFML_CLASSES_GAME_H_
#define PONG_SFML_CLASSES_GAME_H_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "ball.h"
#include "../config.h"
#include "player.h"

using namespace sf;

class Game {
 public:
  Game() {
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
    pauseMessage.setString("Paused. Press space to resume.");
    pauseMessage.setFillColor(Color::White);
    // pauseMessage.setPosition(Vector2f(kScreenWidth / 2, kScreenHeight / 2));
  }
  ~Game() {}

  void clean();
  void handleEvents();
  void init();
  bool isPaused();
  bool isRunning();
  void render();
  void update();

 private:
  Ball ball_;
  Clock clock_;
  Event event_;
  bool paused_ = false;
  Text pauseMessage;
  Player player1_ = Player("player1", 1);
  Player player2_ = Player("player2", 2);
  // bool redraw_ = true;
  bool running_ = false;
  String title_ = kAppName + " - v" + kAppVersion;
  RenderWindow window_;
};

#endif  // PONG_SFML_CLASSES_GAME_H_