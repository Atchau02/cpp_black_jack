#include "blackjack/core/Card.h"

namespace blackjack {

Card::Card(Rank rank, Suit suit)
    : rank_(rank), suit_(suit) {}

Rank Card::getRank() const {
    return rank_;
}

Suit Card::getSuit() const {
    return suit_;
}

int Card::getValue() const {
    switch (rank_) {
        case Rank::Jack:
        case Rank::Queen:
        case Rank::King:
            return 10;
        case Rank::Ace:
            return 11; // Could be 1 or 11 — game logic can adjust this
        default:
            return static_cast<int>(rank_);
    }
}

std::string Card::toString() const {
    const std::string ranks[] = {
        "Ace", "2", "3", "4", "5", "6",
        "7", "8", "9", "10", "Jack", "Queen", "King"
    };

    const std::string suits[] = {
        "Hearts", "Diamonds", "Clubs", "Spades"
    };

    int rankIndex = static_cast<int>(rank_);
    int suitIndex = static_cast<int>(suit_);

    return ranks[rankIndex] + " of " + suits[suitIndex];
}

}
