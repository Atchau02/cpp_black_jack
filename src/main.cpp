#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>

int main() {
  // game initialization
  std::vector<int> deck{};
  for (int i = 2; i <= 14; i++) {
    if (i == 11 || i == 12 || i == 13) {
      deck.push_back(10);
    } else if (i == 14) {
      deck.push_back(11);
    } else {
      deck.push_back(i);
    }
  }

  std::random_device rd{};
  std::mt19937 g{rd()};

  std::shuffle(deck.begin(), deck.end(), g);

  std::cout << "Welcome to Terminal BlackJack!" << std::endl;
  std::cout << "\nEnter your name: ";

  std::string player_name{};
  std::cin >> player_name;

  int player_score{0};
  int dealer_score{0};

  // draw initial card
  std::cout << "You drew a " << deck.back() << std::endl;
  player_score += deck.back();
  deck.pop_back();

  std::cout << "You drew a " << deck.back() << std::endl;
  player_score += deck.back();
  deck.pop_back();

  std::cout << "Dealer drew a " << deck.back() << std::endl;
  dealer_score += deck.back();
  deck.pop_back();

  std::cout << '\n'
            << player_name << " your score is: " << player_score << std::endl;
  std::cout << "Dealer score is: " << dealer_score << std::endl;

  // player's turns
  while (player_score < 21) {
    std::cout << "\nDo you want to hit (y/n)? ";

    char choice{};
    std::cin >> choice;

    if (choice == 'y') {
      std::cout << "\nYou drew a " << deck.back() << std::endl;
      player_score += deck.back();
      deck.pop_back();

      std::cout << player_name << " your score is: " << player_score
                << std::endl;

      if (player_score >= 21) {
        break;
      }
    } else {
      break;
    }
  }

  // dealers turn
  std::cout << "\nDealers turn." << std::endl;
  while (dealer_score < 21 && dealer_score < player_score &&
         player_score <= 21) {
    dealer_score += deck.back();
    deck.pop_back();

    std::cout << "Dealer score is: " << dealer_score << std::endl;
  }

  std::cout << '\n'
            << player_name << " your score is: " << player_score << std::endl;
  std::cout << "Dealer score is: " << dealer_score << std::endl;

  if (player_score > 21) {
    std::cout << "\nYou busted :(";
  } else if (player_score < dealer_score && dealer_score <= 21) {
    std::cout << "\nYou lost :(";
  } else if (player_score == dealer_score) {
    std::cout << "\nDRAW :/";
  } else {
    std::cout << "\nYou won :)";
  }

  return 0;
}
