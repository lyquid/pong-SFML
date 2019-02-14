#include "classes/game.h"

Game* game = NULL;

int main(int argc, char* argv[]) {
  std::srand(static_cast<unsigned int>(std::time(NULL)));

  game = new Game();
  game->init();

  while (game->isRunning()) {
    game->handleEvents();
    game->update();
    game->render();
  }
  game->clean();
  delete game;
  return EXIT_SUCCESS;
}

  /*   sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    window.clear();
    window.draw(shape);
    window.display();
  }
  */  
  
