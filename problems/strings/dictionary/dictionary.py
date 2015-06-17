import os

def get_dictionary():
    dictionary_path = os.path.dirname(__file__)

    files = []

    for (dirpath, dirnames, filenames) in os.walk(dictionary_path):
        for filename in filenames:
            files.append(os.path.abspath(os.path.join(dirpath, filename)))

        break

    words = []

    for filename in files:
        with open(filename, "r") as ofile:
            words.extend(line.rstrip('\n') for line in ofile)

    return words
