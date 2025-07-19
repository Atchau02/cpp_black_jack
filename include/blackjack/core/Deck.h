#pragma once

#include <string>
#include <vector>

#include <algorithm>
#include <chrono>
#include <random>

#include <iostream>

#include "blackjack/core/Card.h"

namespace blackjack {

class Deck {
private:
  std::vector<blackjack::Card> cards_;
  std::mt19937 rng_;

  void initializeDeck();

public:
  Deck();

  Card draw();
  size_t size() const;

  void shuffle();
  void reset();
  bool isEmpty() const;
  void printDeck() const;
};

} // namespace blackjack
