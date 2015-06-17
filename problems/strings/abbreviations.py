import os
import dictionary.dictionary as local_dictionary

# Given a word and a dictionary, check if the abbreviation of the word is unique
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


def check_if_abbreviation_is_unique(word, dictionary):
    unique_word = abbreviate(word)

    for check_word in dictionary:
        # if the abbreviation matches
        # and the words are not the same
        # then the abbreviation is not unique

        print (check_word, unique_word)

        if abbreviate(check_word) == unique_word and not unique_word == check_word:
            return (check_word, unique_word)

    return

def main():
    word = "hello"
    d = local_dictionary.get_dictionary()
    print(check_if_abbreviation_is_unique(word, d))


main()
