import dictionary.dictionary as local_dictionary

# The scoring system for words is a = 1, b = 2, c = 3, ... , z = 26
# Given a dictionary, find all the words that score to exactly 100

# input: word string
def score(word):
    word = word.lower()
    return sum(ord(c) - ord('a') + 1 for c in word)

def print_words_with_score_100(dictionary):
    for check_word in dictionary:
        if score(check_word) == 100:
            print(check_word)

def main():
    dictionary = local_dictionary.get_dictionary()
    print_words_with_score_100(dictionary)

main()
