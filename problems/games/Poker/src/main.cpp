#include "poker.h"
#include <iostream>
#include <memory>

using namespace Poker;

int main(int argc, char const *argv[])
{
    Hand hand1(std::vector<Card>{
        Card{Suit::Diamond, Rank::Ten},
        Card{Suit::Diamond, Rank::Jack},
        Card{Suit::Diamond, Rank::Queen},
        Card{Suit::Diamond, Rank::King},
        Card{Suit::Diamond, Rank::Ace},
    });

    Hand hand2(std::vector<Card>{
        Card{Suit::Spade, Rank::Ten},
        Card{Suit::Spade, Rank::Jack},
        Card{Suit::Spade, Rank::Queen},
        Card{Suit::Spade, Rank::King},
        Card{Suit::Spade, Rank::Nine},
    });

    std::shared_ptr<HandEvaluator> evaluator = std::make_shared<HandEvaluator>();

    std::cout << evaluator->compare(hand1, hand2) << std::endl;
    return 0;
}
