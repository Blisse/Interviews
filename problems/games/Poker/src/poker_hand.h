#ifndef _POKER_HAND_H__
#define _POKER_HAND_H__

#include "poker_card.h"

#include <vector>
#include <iostream>
#include <string>

namespace Poker {

class Hand {
    friend std::ostream& operator<< (std::ostream& stream, const Hand& hand);
public:
    const std::vector<Card>& cards() const;

    class Factory {
    public:
        static const Hand create(const std::string& handString);
    private:
        static const Hand create(const std::vector<Card>& cards);
    };
protected:
    Hand(const std::vector<Card>& cards);
private:
    std::vector<Card> m_cards;
};

}

#endif // _POKER_HAND_H__
