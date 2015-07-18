#ifndef _POKER_CARD_H__
#define _POKER_CARD_H__

#include <iostream>
#include <string>

namespace Poker {

class CardRank {
    friend std::ostream& operator<< (std::ostream& stream, const CardRank& rank);
public:
    enum class Value : unsigned int {
        ACE = 0,
        TWO = 1,
        THREE = 2,
        FOUR = 3,
        FIVE = 4,
        SIX = 5,
        SEVEN = 6,
        EIGHT = 7,
        NINE = 8,
        TEN = 9,
        JACK = 10,
        QUEEN = 11,
        KING = 12,
        MAX_COUNT = 13,
    };

    enum class Character : unsigned char {
        ACE = 'A',
        TWO = '2',
        THREE = '3',
        FOUR = '4',
        FIVE = '5',
        SIX = '6',
        SEVEN = '7',
        EIGHT = '8',
        NINE = '9',
        TEN = 'T',
        JACK = 'J',
        QUEEN = 'Q',
        KING = 'K',
    };

    CardRank(const CardRank& rank);
    CardRank(const Value& value, const Character& character);
    const Value& value() const;
    const Character& character() const;
    static Value toValue(const Character& character);
    static Character toCharacter(const Value& value);
private:
    Value m_value;
    Character m_character;
};

class CardSuit {
    friend std::ostream& operator<< (std::ostream& stream, const CardSuit& suit);
public:
    enum class Value : unsigned int {
        DIAMOND = 0,
        CLUB = 1,
        HEART = 2,
        SPADE = 3,
        MAX_COUNT = 4,
    };

    enum class Character : unsigned char {
        DIAMOND = 'd',
        CLUB = 'c',
        HEART = 'h',
        SPADE = 's',
    };

    CardSuit(const CardSuit& suit);
    CardSuit(const Value& value, const Character& character);
    const Value& value() const;
    const Character& character() const;
    static Value toValue(const Character& character);
    static Character toCharacter(const Value& value);
private:
    Value m_value;
    Character m_character;
};

class Card {
    friend std::ostream& operator<< (std::ostream& stream, const Card& card);
public:
    const CardSuit& suit() const;
    const CardRank& rank() const;

    class CardFactory {
    public:
        static const Card createFromString(const std::string& cardString);
        static const Card createFromValues(unsigned int rankValue, unsigned int suitValue);
        static const Card createFromCharacters(unsigned char rankCharacter, unsigned char suitCharacter);
    private:
        static const Card create(const CardRank& rank, const CardSuit& suit);
        static const Card createFromValues(const CardRank::Value& rankValue, const CardSuit::Value& suitValue);
        static const Card createFromCharacters(const CardRank::Character& rankCharacter, const CardSuit::Character& suitCharacter);
    };
protected:
    Card(const CardRank& rank, const CardSuit& suit);
private:
    CardRank m_rank;
    CardSuit m_suit;
};

}

#endif // _POKER_CARD_H__
