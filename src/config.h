#ifndef PONG_SFML_CONFIG_H_
#define PONG_SFML_CONFIG_H_

enum GameModes {
  kGMNotSet,
  kGM1Player,
  kGM2Players,
  kGM1PChaos,
  kGM2PChaos,
  kGMCount
};

const sf::String kAppName = "SFML Pong";
const sf::String kAppVersion = "0.5"; 
const sf::String kDefaultPauseMessage = "Paused. Press space to resume.";
const float kPi = 3.14159f;
const int kScreenHeight = 768;
const int kScreenWidth = 1024;

#endif  // PONG_SFML_CONFIG_H_