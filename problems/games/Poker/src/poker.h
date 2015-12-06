#ifndef _POKER_H__
#define _POKER_H__

#include <vector>

namespace Poker {

static const int NUM_SUITS = 4;
static const int NUM_RANKS = 13;

enum class Suit {
    Diamond = 0,
    Club,
    Heart,
    Spade,
};

enum class Rank {
    Ace = 0,
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
    King,
};

class Card {
public:
    Card(Suit suit, Rank rank);
    Suit suit() const;
    Rank rank() const;
private:
    const Suit _suit;
    const Rank _rank;
};

enum class HandStrength {
    HighCard = 0,
    OnePair,
    TwoPair,
    Set,
    Straight,
    Flush,
    FullHouse,
    FourOfAKind,
    StraightFlush
};

class Hand {
public:
    Hand(std::vector<Card> cards);
    std::vector<Card> cards() const;
private:
    std::vector<Card> _cards;
};

class HandEvaluator {
public:
    // Returns 1 if this hand is stronger than the hand to compare to.
    // Returns 0 if this hand is tied than the hand to compare to.
    // Returns -1 if this hand is weaker than the hand to compare to.
    int compare(const Hand& our_hand, const Hand& their_hand) const;
private:
    int evaluate(const Hand& our_hand, const Hand& their_hand) const;
    int evaluateEqualStrength(const Hand& our_hand, const Hand& their_hand) const;

    HandStrength strength(const Hand& hand) const;

    int evaluateStraightFlush(const Hand& our_hand, const Hand& their_hand) const;
    int evaluateFourOfAKind(const Hand& our_hand, const Hand& their_hand) const;
    int evaluateFullHouse(const Hand& our_hand, const Hand& their_hand) const;
    int evaluateFlush(const Hand& our_hand, const Hand& their_hand) const;
    int evaluateStraight(const Hand& our_hand, const Hand& their_hand) const;
    int evaluateSet(const Hand& our_hand, const Hand& their_hand) const;
    int evaluateTwoPair(const Hand& our_hand, const Hand& their_hand) const;
    int evaluateOnePair(const Hand& our_hand, const Hand& their_hand) const;
    int evaluateHighCard(const Hand& our_hand, const Hand& their_hand) const;

    bool isStraightFlush(const Hand& hand) const;
    bool isFourOfAKind(const Hand& hand) const;
    bool isFullHouse(const Hand& hand) const;
    bool isFlush(const Hand& hand) const;
    bool isStraight(const Hand& hand) const;
    bool isSet(const Hand& hand) const;
    bool isTwoPair(const Hand& hand) const;
    bool isOnePair(const Hand& hand) const;

    std::vector<int> allocatedRanks(const Hand& hand) const;
    std::vector<int> allocatedSuits(const Hand& hand) const;
    std::vector<int> consecutiveRanks(const Hand& hand) const;
    int getStraightRank(const Hand& hand) const;
    int getFourOfAKindRank(const Hand& hand) const;
    int getFourOfAKindKicker(const Hand& hand) const;
    int getSet(const Hand& hand) const;
};

};

#endif
