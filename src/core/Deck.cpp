#include "blackjack/core/Deck.h"

namespace blackjack {

Deck::Deck()
    : rng_(static_cast<unsigned int>(
          std::chrono::steady_clock::now().time_since_epoch().count())) {
  initializeDeck();
  shuffle();
}

void Deck::initializeDeck() {
  cards_.clear();

  for (int suit = 0; suit < 4; ++suit) {
    for (int rank = static_cast<int>(Rank::Ace);
         rank <= static_cast<int>(Rank::King); ++rank) {
      cards_.emplace_back(static_cast<Rank>(rank), static_cast<Suit>(suit));
    }
  }
}

void Deck::shuffle() { std::shuffle(cards_.begin(), cards_.end(), rng_); }

Card Deck::draw() {
  if (cards_.empty()) {
    throw std::out_of_range("No cards left in the deck");
  }

  Card card{cards_.back()};
  cards_.pop_back();
  return card;
}

bool Deck::isEmpty() const { return cards_.empty(); }

size_t Deck::size() const { return cards_.size(); }

void Deck::printDeck() const {
  for (const auto &card : cards_) {
    std::cout << card.toString() << "\n";
  }
}

} // namespace blackjack
