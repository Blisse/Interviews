#include "poker.h"

#include <algorithm>
#include <iterator>
#include <cassert>
#include <iostream>

using namespace Poker;

Card::Card(Suit suit, Rank rank) :
    _suit(suit),
    _rank(rank)
{
}

Suit Card::suit() const {
    return _suit;
}

Rank Card::rank() const {
    return _rank;
}

Hand::Hand(std::vector<Card> cards) :
    _cards(cards)
{
    assert(_cards.size() == 5);
}

std::vector<Card> Hand::cards() const {
    return _cards;
}

int HandEvaluator::compare(const Hand& our_hand, const Hand& their_hand) const {
    return evaluate(our_hand, their_hand);
}

int HandEvaluator::evaluate(const Hand& our_hand, const Hand& their_hand) const {
    HandStrength ourStrength = strength(our_hand);
    HandStrength theirStrength = strength(their_hand);

    if (ourStrength > theirStrength) {
        return 1;
    } else if (theirStrength > ourStrength) {
        return -1;
    } else {
        return evaluateEqualStrength(our_hand, their_hand);
    }
}

int HandEvaluator::evaluateEqualStrength(const Hand& our_hand, const Hand& their_hand) const {
    assert(strength(our_hand) == strength(their_hand));

    switch (strength(our_hand)) {
        case HandStrength::StraightFlush:
            return evaluateStraightFlush(our_hand, their_hand);
        case HandStrength::FourOfAKind:
            return evaluateFourOfAKind(our_hand, their_hand);
        case HandStrength::FullHouse:
            return evaluateFullHouse(our_hand, their_hand);
        case HandStrength::Flush:
            return evaluateFlush(our_hand, their_hand);
        case HandStrength::Straight:
            return evaluateStraight(our_hand, their_hand);
        case HandStrength::Set:
            return evaluateSet(our_hand, their_hand);
        case HandStrength::TwoPair:
            return evaluateTwoPair(our_hand, their_hand);
        case HandStrength::OnePair:
            return evaluateOnePair(our_hand, their_hand);
        case HandStrength::HighCard:
            return evaluateHighCard(our_hand, their_hand);
    }

    return 0;
}

HandStrength HandEvaluator::strength(const Hand& hand) const {
    if (isStraightFlush(hand)) {
        return HandStrength::StraightFlush;
    } else if (isFourOfAKind(hand)) {
        return HandStrength::FourOfAKind;
    } else if (isFullHouse(hand)) {
        return HandStrength::FullHouse;
    } else if (isFlush(hand)) {
        return HandStrength::Flush;
    } else if (isStraight(hand)) {
        return HandStrength::Straight;
    } else if (isSet(hand)) {
        return HandStrength::Set;
    } else if (isTwoPair(hand)) {
        return HandStrength::TwoPair;
    } else if (isOnePair(hand)) {
        return HandStrength::OnePair;
    } else {
        return HandStrength::HighCard;
    }
}

int HandEvaluator::evaluateStraightFlush(const Hand& our_hand, const Hand& their_hand) const {
    assert(strength(our_hand) == HandStrength::StraightFlush);
    assert(strength(their_hand) == HandStrength::StraightFlush);

    int our_rank = getStraightRank(our_hand);
    int their_rank = getStraightRank(their_hand);

    if (our_rank > their_rank) {
        return 1;
    } else if (our_rank < their_rank) {
        return -1;
    }

    return 0;
}

int HandEvaluator::evaluateFourOfAKind(const Hand& our_hand, const Hand& their_hand) const {
    assert(strength(our_hand) == HandStrength::FourOfAKind);
    assert(strength(their_hand) == HandStrength::FourOfAKind);

    int our_rank = getFourOfAKindRank(our_hand);
    int our_kicker = getFourOfAKindKicker(our_hand);

    int their_rank = getFourOfAKindRank(their_hand);
    int their_kicker = getFourOfAKindKicker(their_hand);

    if (our_rank == their_rank) {
        if (our_kicker == their_kicker) {
            return 0;
        } else if (our_kicker > their_kicker) {
            return 1;
        } else if (our_kicker < their_kicker) {
            return -1;
        }
    } else if (our_rank > their_rank) {
        return 1;
    } else if (our_rank < their_rank) {
        return -1;
    }

    return 0;
}

int HandEvaluator::evaluateFullHouse(const Hand& our_hand, const Hand& their_hand) const {
    assert(strength(our_hand) == HandStrength::FullHouse);
    assert(strength(their_hand) == HandStrength::FullHouse);



    return 0;
}

int HandEvaluator::evaluateFlush(const Hand& our_hand, const Hand& their_hand) const {
    assert(strength(our_hand) == HandStrength::Flush);
    assert(strength(their_hand) == HandStrength::Flush);

    return 0;
}

int HandEvaluator::evaluateStraight(const Hand& our_hand, const Hand& their_hand) const {
    assert(strength(our_hand) == HandStrength::Straight);
    assert(strength(their_hand) == HandStrength::Straight);

    return 0;
}

int HandEvaluator::evaluateSet(const Hand& our_hand, const Hand& their_hand) const {
    assert(strength(our_hand) == HandStrength::Set);
    assert(strength(their_hand) == HandStrength::Set);

    return 0;
}

int HandEvaluator::evaluateTwoPair(const Hand& our_hand, const Hand& their_hand) const {
    assert(strength(our_hand) == HandStrength::TwoPair);
    assert(strength(their_hand) == HandStrength::TwoPair);

    return 0;
}

int HandEvaluator::evaluateOnePair(const Hand& our_hand, const Hand& their_hand) const {
    assert(strength(our_hand) == HandStrength::OnePair);
    assert(strength(their_hand) == HandStrength::OnePair);

    return 0;
}

int HandEvaluator::evaluateHighCard(const Hand& our_hand, const Hand& their_hand) const {
    assert(strength(our_hand) == HandStrength::HighCard);
    assert(strength(their_hand) == HandStrength::HighCard);

    return 0;
}


bool HandEvaluator::isStraightFlush(const Hand& hand) const {
    return isFlush(hand) && isStraight(hand);
}

bool HandEvaluator::isFourOfAKind(const Hand& hand) const {
    std::vector<int> allocated_ranks = allocatedRanks(hand);

    return find(allocated_ranks.begin(), allocated_ranks.end(), 4) != allocated_ranks.end();
}

bool HandEvaluator::isFullHouse(const Hand& hand) const {
    return isSet(hand) && isOnePair(hand);
}

bool HandEvaluator::isFlush(const Hand& hand) const {
    std::vector<int> allocated_suits = allocatedSuits(hand);

    return find(allocated_suits.begin(), allocated_suits.end(), 5) != allocated_suits.end();
}

bool HandEvaluator::isStraight(const Hand& hand) const {
    std::vector<int> allocated_ranks = allocatedRanks(hand);

    if (count(allocated_ranks.begin(), allocated_ranks.end(), 1) != 5) {
        return false;
    }

    std::vector<int> consecutive_ranks = consecutiveRanks(hand);

    const unsigned int SCAN_AHEAD = 4;
    for (unsigned int i = 0; i < consecutive_ranks.size() - SCAN_AHEAD; i++) {
        if ((consecutive_ranks[i] == 1)
            && (consecutive_ranks[i+1] == 1)
            && (consecutive_ranks[i+2] == 1)
            && (consecutive_ranks[i+3] == 1)
            && (consecutive_ranks[i+4] == 1)) {
            return true;
        }
    }

    return false;
}

bool HandEvaluator::isSet(const Hand& hand) const {
    std::vector<int> allocated_ranks = allocatedRanks(hand);

    return find(allocated_ranks.begin(), allocated_ranks.end(), 3) != allocated_ranks.end();
}

bool HandEvaluator::isTwoPair(const Hand& hand) const {
    std::vector<int> allocated_ranks = allocatedRanks(hand);

    return count(allocated_ranks.begin(), allocated_ranks.end(), 2) == 2;
}

bool HandEvaluator::isOnePair(const Hand& hand) const {
    std::vector<int> allocated_ranks = allocatedRanks(hand);

    return find(allocated_ranks.begin(), allocated_ranks.end(), 2) != allocated_ranks.end();
}

std::vector<int> HandEvaluator::allocatedRanks(const Hand& hand) const {
    std::vector<int> allocated_ranks(NUM_RANKS, 0);

    for (auto& card : hand.cards()) {
        allocated_ranks[static_cast<int>(card.rank())]++;
    }

    return allocated_ranks;
}

std::vector<int> HandEvaluator::allocatedSuits(const Hand& hand) const {
    std::vector<int> allocated_suits(NUM_SUITS, 0);

    for (auto& card : hand.cards()) {
        allocated_suits[static_cast<int>(card.suit())]++;
    }

    return allocated_suits;
}

std::vector<int> HandEvaluator::consecutiveRanks(const Hand& hand) const {
    std::vector<int> consecutive_ranks(NUM_RANKS + 1, 0);

    for (auto& card : hand.cards()) {
        consecutive_ranks[static_cast<int>(card.rank())]++;
    }

    consecutive_ranks[consecutive_ranks.size() - 1] = consecutive_ranks[0];

    return consecutive_ranks;
}

int HandEvaluator::getStraightRank(const Hand& hand) const {
    assert(strength(hand) == HandStrength::StraightFlush || strength(hand) == HandStrength::Straight);

    std::vector<int> ranks = consecutiveRanks(hand);

    const unsigned int SCAN_AHEAD = 4;
    for (unsigned int i = 0; i < ranks.size() - SCAN_AHEAD; i++) {
        if ((ranks[i] == 1)
            && (ranks[i+1] == 1)
            && (ranks[i+2] == 1)
            && (ranks[i+3] == 1)
            && (ranks[i+4] == 1)) {
            return i+4;
        }
    }

    return 0;
}

int HandEvaluator::getFourOfAKindRank(const Hand& hand) const {
    assert(strength(hand) == HandStrength::FourOfAKind);

    std::vector<int> ranks = consecutiveRanks(hand);

    for (int i = ranks.size() - 1; i >= 0; i--) {
        if (ranks[i] == 4) {
            return i;
        }
    }

    return 0;
}

int HandEvaluator::getFourOfAKindKicker(const Hand& hand) const {
    assert(strength(hand) == HandStrength::FourOfAKind);

    std::vector<int> ranks = consecutiveRanks(hand);

    for (int i = ranks.size() - 1; i >= 0; i--) {
        if (ranks[i] == 1) {
            return i;
        }
    }

    return 0;
}

int HandEvaluator::getSet(const Hand& hand) const {
    assert(strength(hand) == HandStrength::FullHouse || strength(hand) == HandStrength::Set);

    std::vector<int> ranks = consecutiveRanks(hand);

    for (int i = ranks.size() - 1; i >= 0; i--) {
        if (ranks[i] == 3) {
            return i;
        }
    }

    return 0;
}
