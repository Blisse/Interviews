#include "poker_hand.h"

namespace Poker {

Hand::Hand(const std::vector<Card>& cards) :
    m_cards(cards)
{
}

const std::vector<Card>& Hand::cards() const
{
    return m_cards;
}

std::ostream& operator<< (std::ostream& stream, const Hand& hand)
{
    for (const Card& card : hand.cards()) {
        stream << card;
    }
    return stream;
}

Hand::Factory::create(const std::string& handString)
{

}

Hand::Factory::create(const std::vector<Card>& cards)
{

}

}
