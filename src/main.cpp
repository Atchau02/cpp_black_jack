#include "blackjack/core/Deck.h"

int main() {
  using namespace blackjack;

  Deck deck;

  Card card = deck.draw();

  std::cout << "Your card is: " << card.toString();

  return 0;
}
