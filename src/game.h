#ifndef PONG_SFML_CLASSES_GAME_H_
#define PONG_SFML_CLASSES_GAME_H_

#include <sstream>
#include <SFML/Graphics.hpp>

#include "ball.h"
#include "config.h"
#include "menu.h"
#include "player.h"

class Game {
 public:
  Game() {
    game_mode_ = kGMNotSet;
    in_menu_ = true;
    paused_ = false;
    quit_ = false;
    title_ = kAppName + " - v" + kAppVersion;
  }
  ~Game() {}
  void clean();
  void handleEvents();
  void init();
  bool isPaused();
  bool quit();
  void render();
  void update();

 private:
  void initSound();
  void resetPlayersAndPositions();
  template <typename T> std::string toString(T arg);
  void updateScoreText();

  Ball ball_;
  sf::Clock ball_delay_;
  sf::SoundBuffer ball_bounce_player_buffer_;
  sf::SoundBuffer ball_bounce_wall_buffer_;
  sf::SoundBuffer ball_point_buffer_;
  sf::Clock clock_;
  sf::Event event_;
  sf::Font font_;
  int game_mode_;
  bool in_menu_;
  Menu menu_ = Menu(&font_);
  bool paused_;
  sf::Text pause_text_;
  sf::Clock pause_text_clock_;
  Player player1_ = Player("player1", 1);
  Player player2_ = Player("player2", 2);
  bool quit_;
  sf::Text score_text_;
  sf::String title_;
  sf::RenderWindow window_;
};

#endif  // PONG_SFML_CLASSES_GAME_H_
