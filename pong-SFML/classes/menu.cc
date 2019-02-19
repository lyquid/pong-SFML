#include "menu.h"

void Menu::centerTextOrigin(sf::Text* text) {
  text->setOrigin(
    (text->getLocalBounds().left + text->getLocalBounds().width) / 2.f,
    (text->getLocalBounds().top + text->getLocalBounds().height) / 2.f
  );
}

void Menu::draw(sf::RenderWindow* window) {
  window->draw(title_);
  for(int i = 0; i < kNumOptions; i++) {
    window->draw(options_[i]);
  } 
}

void Menu::initOptions(sf::Font* font) {
  menu_options_[0].option_key = "1";
  menu_options_[0].option_text = "1 Player";
  menu_options_[0].selected = true;
  menu_options_[1].option_key = "2";
  menu_options_[1].option_text = "2 Players";
  menu_options_[1].selected = false;
  menu_options_[2].option_key = "ESC";
  menu_options_[2].option_text = "Exit";
  menu_options_[2].selected = false;

  for (int i = 0; i < kNumOptions; i++) {
    // sf::String finalString = "";
    options_[i].setString(menu_options_[i].option_text);
    initText(font, &options_[i], 20);
    centerTextOrigin(&options_[i]);
    options_[i].setPosition(sf::Vector2f(kScreenWidth / 2, (kScreenHeight / 2) + i * 25));
  }
} 

void Menu::initText(sf::Font* font, sf::Text* text, int size) {
  text->setFont(*font);
  text->setCharacterSize(size);
  text->setFillColor(sf::Color::White);
}

void Menu::initTitle(sf::Font* font) {
  title_.setString(kAppName);
  initText(font, &title_, 60);
  centerTextOrigin(&title_);
  title_.setPosition(sf::Vector2f(kScreenWidth / 2, kScreenHeight / 4));
}