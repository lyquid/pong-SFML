#ifndef PONG_SFML_CONFIG_H_
#define PONG_SFML_CONFIG_H_

enum GameModes {
  k1Player,
  k2Players,
  k1PChaos,
  k2PChaos
};

const sf::String kAppName = "SFML Pong";
const sf::String kAppVersion = "0.0"; 
const float kPi = 3.14159f;
const int kScreenHeight = 768;
const int kScreenWidth = 1024;

#endif  // PONG_SFML_CONFIG_H_