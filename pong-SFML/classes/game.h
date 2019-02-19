#ifndef PONG_SFML_CLASSES_GAME_H_
#define PONG_SFML_CLASSES_GAME_H_

#include <sstream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "ball.h"
#include "../config.h"
#include "menu.h"
#include "player.h"

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
  void update();

 private:
  void initSound();
  void resetPlayersAndPositions();
  template <typename T> std::string toString(T arg);
  void updateAngleText();
  void updateScoreText();

  sf::Text angle_text_;
  Ball ball_;
  sf::SoundBuffer ball_bounce_player_buffer_;
  sf::SoundBuffer ball_bounce_wall_buffer_;
  sf::SoundBuffer ball_point_buffer_;
  sf::Clock clock_;
  sf::Event event_;
  sf::Font font_;
  bool in_menu_ = true;
  Menu menu_ = Menu(&font_); 
  bool paused_ = false;
  sf::Text pause_text_;
  Player player1_ = Player("player1", 1);
  Player player2_ = Player("player2", 2);
  bool running_ = false;
  sf::Text score_text_;
  sf::String title_ = kAppName + " - v" + kAppVersion;
  sf::RenderWindow window_;
};

#endif  // PONG_SFML_CLASSES_GAME_H_