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
  Game() {}
  ~Game() {}
  void clean();
  void handleEvents();
  void init();
  bool isPaused();
  bool isRunning();
  void render();
  void resetPlayersPositions();
  void update();

 private:
  Ball ball_;
  Clock clock_;
  Event event_;
  Font font_;
  bool paused_ = false;
  Text pauseMessage_;
  Player player1_ = Player("player1", 1);
  Player player2_ = Player("player2", 2);
  bool running_ = false;
  String title_ = kAppName + " - v" + kAppVersion;
  RenderWindow window_;
};

#endif  // PONG_SFML_CLASSES_GAME_H_