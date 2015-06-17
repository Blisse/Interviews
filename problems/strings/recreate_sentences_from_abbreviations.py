import itertools
import dictionary.dictionary as local_dictionary

# Problem:
# Given a sentence of abbreviated words and a dictionary,
# print out all possibilities for that sentence
#
# Abbreviation:
# The abbreviation of allies would be: a4s
# The abbreviation of alliance would be: a6e
# The abbreviation of atmosphere would be: a8e

# input: word string
def abbreviate(word):
    word = word.lower()
    if len(word) == 1:
        return word
    if len(word) >= 2:
        return word[0] + str(len(word) - 2) + word[-1]

def print_permutations_of_sentence(sentence, dictionary):
    sentence_possibilities = []
    for word_abbreviation in sentence.split(" "):

        word_possibilities = []
        for check_word in dictionary:
            check_abbreviation = abbreviate(check_word)

            if check_abbreviation == word_abbreviation:
                word_possibilities.append(check_word)

        sentence_possibilities.append(word_possibilities)

    for possibilities in sentence_possibilities:
        print(possibilities)

def main():
    abbreviated_sentence = "w2n w0e a8e e3y w2d t2s w1y"
    dictionary = local_dictionary.get_dictionary()

    print_permutations_of_sentence(abbreviated_sentence, dictionary)

main()
