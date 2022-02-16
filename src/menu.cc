#include "menu.h"

void Menu::centerTextOrigin(sf::Text* text) {
  text->setOrigin(
    (text->getLocalBounds().left + text->getLocalBounds().width) / 2.f,
    (text->getLocalBounds().top + text->getLocalBounds().height) / 2.f
  );
}

void Menu::draw(sf::RenderWindow* window) {
  window->draw(title_);
  for(int i = 0; i < kNumOptions; ++i) {
    window->draw(options_[i]);
  } 
}

void Menu::initOptions(sf::Font* font) {
  menu_options_[0].option_key = "1";
  menu_options_[0].option_text = "1 Player.....[1]";
  menu_options_[0].selected = true;
  menu_options_[1].option_key = "2";
  menu_options_[1].option_text = "2 Players....[2]";
  menu_options_[1].selected = false;
  menu_options_[2].option_key = "3";
  menu_options_[2].option_text = "Chaos mode...[3]";
  menu_options_[2].selected = false;
  menu_options_[3].option_key = "ESC";
  menu_options_[3].option_text = "Exit.......[ESC]";
  menu_options_[3].selected = false;

  for (int i = 0; i < kNumOptions; ++i) {
    // TODO: sf::String finalString = "";
    initText(font, &options_[i], 20);
    options_[i].setString(menu_options_[i].option_text);
    centerTextOrigin(&options_[i]);
    options_[i].setPosition(sf::Vector2f(kScreenWidth / 4, (kScreenHeight / 2) + i * 32));
  }
} 

void Menu::initText(sf::Font* font, sf::Text* text, int size) {
  text->setFont(*font);
  text->setCharacterSize(size);
  text->setFillColor(sf::Color::White);
}

void Menu::initTitle(sf::Font* font) {
  initText(font, &title_, 60);
  title_.setString(kAppName);
  /// TODO: something here isn't working
  float text_w = title_.getLocalBounds().left + title_.getLocalBounds().width;
  // printf("title_.getLocalBounds().left: %f\n", title_.getLocalBounds().left);
  // printf("title_.getLocalBounds().width: %f\n", title_.getLocalBounds().width);
  // printf("text_w: %f\n", text_w);
  // centerTextOrigin(&title_);
  title_.setOrigin(
    (title_.getLocalBounds().left + title_.getLocalBounds().width) / 2.f,
    (title_.getLocalBounds().top + title_.getLocalBounds().height) / 2.f
  );
  title_.setPosition(sf::Vector2f(kScreenWidth / 4, kScreenHeight / 4));
}
