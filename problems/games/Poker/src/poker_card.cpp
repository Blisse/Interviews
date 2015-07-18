#include "poker_card.h"
#include <cassert>

namespace Poker {

CardRank::CardRank(const CardRank& rank) :
    CardRank(rank.value(), rank.character())
{
}

CardRank::CardRank(const Value& value, const Character& character) :
    m_value(value), m_character(character)
{
}

const CardRank::Value& CardRank::value() const {
    return m_value;
}

const CardRank::Character& CardRank::character() const {
    return m_character;
}

std::ostream& operator<< (std::ostream& stream, const CardRank& rank)
{
    stream << static_cast<unsigned char>(rank.character());
    return stream;
}

CardRank::Value CardRank::toValue(const CardRank::Character& character)
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

CardRank::Character CardRank::toCharacter(const CardRank::Value& value)
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

CardSuit::CardSuit(const CardSuit& suit) :
    CardSuit(suit.value(), suit.character())
{
}

CardSuit::CardSuit(const Value& value, const Character& character) :
    m_value(value), m_character(character)
{
}

const CardSuit::Value& CardSuit::value() const {
    return m_value;
}

const CardSuit::Character& CardSuit::character() const {
    return m_character;
}

std::ostream& operator<< (std::ostream& stream, const CardSuit& suit)
{
    stream << static_cast<unsigned char>(suit.character());
    return stream;
}

CardSuit::Value CardSuit::toValue(const CardSuit::Character& character)
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

CardSuit::Character CardSuit::toCharacter(const CardSuit::Value& value)
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

Card::Card(const CardRank& rank, const CardSuit& suit) :
    m_rank(rank),
    m_suit(suit)
{
}

const CardSuit& Card::suit() const
{
    return m_suit;
}

const CardRank& Card::rank() const
{
    return m_rank;
}

std::ostream& operator<< (std::ostream& stream, const Card& card)
{
    stream << card.rank() << card.suit();
    return stream;
}

const Card Card::CardFactory::create(const CardRank& rank, const CardSuit& suit)
{
    return Card(rank, suit);
}

const Card Card::CardFactory::createFromValues(unsigned int rankValue, unsigned int suitValue)
{
    return createFromValues(static_cast<CardRank::Value>(rankValue), static_cast<CardSuit::Value>(suitValue));
}

const Card Card::CardFactory::createFromCharacters(unsigned char rankCharacter, unsigned char suitCharacter)
{
    return createFromCharacters(static_cast<CardRank::Character>(rankCharacter), static_cast<CardSuit::Character>(suitCharacter));
}

const Card Card::CardFactory::createFromString(const std::string& cardString)
{
    assert(cardString.length() == 2);
    return createFromCharacters(cardString[0], cardString[1]);
}

const Card Card::CardFactory::createFromValues(const CardRank::Value& rankValue, const CardSuit::Value& suitValue)
{
    return create(CardRank(rankValue, CardRank::toCharacter(rankValue)), CardSuit(suitValue, CardSuit::toCharacter(suitValue)));
}

const Card Card::CardFactory::createFromCharacters(const CardRank::Character& rankCharacter, const CardSuit::Character& suitCharacter)
{
    return create(CardRank(CardRank::toValue(rankCharacter), rankCharacter), CardSuit(CardSuit::toValue(suitCharacter), suitCharacter));
}

}
