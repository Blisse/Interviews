#include "poker_card.h"
#include <cassert>

namespace Poker {

Card::Rank::Rank(const Card::Rank& rank) :
    Rank(rank.value(), rank.character())
{
}

Card::Rank::Rank(const Value& value, const Character& character) :
    m_value(value), m_character(character)
{
}

const Card::Rank::Value& Card::Rank::value() const {
    return m_value;
}

const Card::Rank::Character& Card::Rank::character() const {
    return m_character;
}

std::ostream& operator<< (std::ostream& stream, const Card::Rank& rank)
{
    stream << static_cast<unsigned char>(rank.character());
    return stream;
}

Card::Rank::Value Card::Rank::toValue(const Card::Rank::Character& character)
{
    Value value;
    switch (character) {
        case Character::ACE:   value = Value::ACE;      break;
        case Character::TWO:   value = Value::TWO;      break;
        case Character::THREE: value = Value::THREE;    break;
        case Character::FOUR:  value = Value::FOUR;     break;
        case Character::FIVE:  value = Value::FIVE;     break;
        case Character::SIX:   value = Value::SIX;      break;
        case Character::SEVEN: value = Value::SEVEN;    break;
        case Character::EIGHT: value = Value::EIGHT;    break;
        case Character::NINE:  value = Value::NINE;     break;
        case Character::TEN:   value = Value::TEN;      break;
        case Character::JACK:  value = Value::JACK;     break;
        case Character::QUEEN: value = Value::QUEEN;    break;
        case Character::KING:  value = Value::KING;     break;
        default:
            assert(false);
    }
    return value;
}

Card::Rank::Character Card::Rank::toCharacter(const Card::Rank::Value& value)
{
    Character character;
    switch (value) {
        case Value::ACE:   character = Character::ACE;      break;
        case Value::TWO:   character = Character::TWO;      break;
        case Value::THREE: character = Character::THREE;    break;
        case Value::FOUR:  character = Character::FOUR;     break;
        case Value::FIVE:  character = Character::FIVE;     break;
        case Value::SIX:   character = Character::SIX;      break;
        case Value::SEVEN: character = Character::SEVEN;    break;
        case Value::EIGHT: character = Character::EIGHT;    break;
        case Value::NINE:  character = Character::NINE;     break;
        case Value::TEN:   character = Character::TEN;      break;
        case Value::JACK:  character = Character::JACK;     break;
        case Value::QUEEN: character = Character::QUEEN;    break;
        case Value::KING:  character = Character::KING;     break;
        default:
            assert(false);
    }
    return character;
}

Card::Suit::Suit(const Card::Suit& suit) :
    Suit(suit.value(), suit.character())
{
}

Card::Suit::Suit(const Value& value, const Character& character) :
    m_value(value), m_character(character)
{
}

const Card::Suit::Value& Card::Suit::value() const {
    return m_value;
}

const Card::Suit::Character& Card::Suit::character() const {
    return m_character;
}

std::ostream& operator<< (std::ostream& stream, const Card::Suit& suit)
{
    stream << static_cast<unsigned char>(suit.character());
    return stream;
}

Card::Suit::Value Card::Suit::toValue(const Card::Suit::Character& character)
{
    Value value;
    switch (character) {
        case Character::DIAMOND:    value = Value::DIAMOND;     break;
        case Character::CLUB:       value = Value::CLUB;        break;
        case Character::HEART:      value = Value::HEART;       break;
        case Character::SPADE:      value = Value::SPADE;       break;
        default:
            assert(false);
    }
    return value;
}

Card::Suit::Character Card::Suit::toCharacter(const Card::Suit::Value& value)
{
    Character character;
    switch (value) {
        case Value::DIAMOND:    character = Character::DIAMOND;     break;
        case Value::CLUB:       character = Character::CLUB;        break;
        case Value::HEART:      character = Character::HEART;       break;
        case Value::SPADE:      character = Character::SPADE;       break;
        default:
            assert(false);
    }
    return character;
}

Card::Card(const Card::Rank& rank, const Card::Suit& suit) :
    m_rank(rank),
    m_suit(suit)
{
}

const Card::Suit& Card::suit() const
{
    return m_suit;
}

const Card::Rank& Card::rank() const
{
    return m_rank;
}

std::ostream& operator<< (std::ostream& stream, const Card& card)
{
    stream << card.rank() << card.suit();
    return stream;
}

const Card Card::Factory::create(const Card::Rank& rank, const Card::Suit& suit)
{
    return Card(rank, suit);
}

const Card Card::Factory::createFromValues(unsigned int rankValue, unsigned int suitValue)
{
    return createFromValues(static_cast<Card::Rank::Value>(rankValue), static_cast<Card::Suit::Value>(suitValue));
}

const Card Card::Factory::createFromCharacters(unsigned char rankCharacter, unsigned char suitCharacter)
{
    return createFromCharacters(static_cast<Card::Rank::Character>(rankCharacter), static_cast<Card::Suit::Character>(suitCharacter));
}

const Card Card::Factory::createFromString(const std::string& cardString)
{
    assert(cardString.length() == 2);
    return createFromCharacters(cardString[0], cardString[1]);
}

const Card Card::Factory::createFromValues(const Card::Rank::Value& rankValue, const Card::Suit::Value& suitValue)
{
    return create(Rank(rankValue, Card::Rank::toCharacter(rankValue)), Suit(suitValue, Card::Suit::toCharacter(suitValue)));
}

const Card Card::Factory::createFromCharacters(const Card::Rank::Character& rankCharacter, const Card::Suit::Character& suitCharacter)
{
    return create(Rank(Card::Rank::toValue(rankCharacter), rankCharacter), Suit(Card::Suit::toValue(suitCharacter), suitCharacter));
}

}
