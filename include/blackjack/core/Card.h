#pragma once

#include <string>

namespace blackjack {

enum class Suit { Hearts, Diamonds, Clubs, Spades };
enum class Rank {
  Ace,
  Two,
  Three,
  Four,
  Five,
  Six,
  Seven,
  Eight,
  Nine,
  Ten,
  Jack,
  Queen,
  King
};

class Card {
private:
  Rank rank_;
  Suit suit_;

public:
  Card(Rank rank, Suit suit);

  Rank getRank() const;
  Suit getSuit() const;
  int getValue() const;
  std::string toString() const;
};

} // namespace blackjack
