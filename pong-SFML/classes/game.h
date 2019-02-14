#ifndef PONGSFML_CLASSES_GAME_H_
#define PONGSFML_CLASSES_GAME_H_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "../config.h"

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
  // void registerEvents();
  void render();
  void update();

 private:
  // void checkPlayermevem...
  void mustInit(bool test, const char* desc);

  Event event_;
  bool paused_ = true;
  bool redraw_ = true;
  bool running_ = false;
  RenderWindow window_;
};

#endif  // PONGSFML_CLASSES_GAME_H_