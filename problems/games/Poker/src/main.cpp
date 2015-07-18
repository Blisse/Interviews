#include "poker_card.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    const Poker::Card& aceSpadesString = Poker::Card::CardFactory::createFromString("Ad");
    const Poker::Card& aceSpadesValues = Poker::Card::CardFactory::createFromValues(0, 0);
    const Poker::Card& aceSpadesCharacters = Poker::Card::CardFactory::createFromCharacters('A', 'd');

    std::cout << aceSpadesString << std::endl;
    std::cout << aceSpadesValues << std::endl;
    std::cout << aceSpadesCharacters << std::endl;

    return 0;
}
