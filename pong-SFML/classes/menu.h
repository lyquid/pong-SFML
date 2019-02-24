#ifndef PONG_SFML_CLASSES_MENU_H_
#define PONG_SFML_CLASSES_MENU_H_

#include <SFML/Graphics.hpp>

#include "../config.h"

const int kNumOptions = 4;

class Menu {
 public:
  Menu(sf::Font* font) {
    initTitle(font);
    initOptions(font);
  }
  ~Menu() {}
  static void centerTextOrigin(sf::Text* text);
  void draw(sf::RenderWindow* window);
  static void initText(sf::Font* font, sf::Text* text, int size);

 private:
  void initOptions(sf::Font* font);
  void initTitle(sf::Font* font);
  struct MenuOptions {
    sf::String option_key;
    sf::String option_text;
    bool selected;
  } menu_options_[kNumOptions];
  sf::Text options_[kNumOptions]; 
  sf::Text title_;
};

#endif  // PONG_SFML_CLASSES_MENU_H_