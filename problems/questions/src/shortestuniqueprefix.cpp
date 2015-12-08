#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <memory>
#include <sstream>

class ShortestUniquePrefixContainer {
public:
    ShortestUniquePrefixContainer(std::set<std::string> strings);

    const std::map<std::string, std::string>& prefixes();
private:
    std::map<std::string, std::set<std::string>> groupStringsByPrefix(std::set<std::string> strings, int prefix_length);
    void calculateShortestUniquePrefixes(std::set<std::string> strings, int prefix_length);

    std::map<std::string, std::string> _prefixes;
};


ShortestUniquePrefixContainer::ShortestUniquePrefixContainer(std::set<std::string> strings) :
    _prefixes()
{
    calculateShortestUniquePrefixes(strings, 1);
}

const std::map<std::string, std::string>& ShortestUniquePrefixContainer::prefixes() {
    return _prefixes;
}

std::map<std::string, std::set<std::string>>
ShortestUniquePrefixContainer::groupStringsByPrefix(
    std::set<std::string> strings,
    int prefix_length
    )
{
    std::map<std::string, std::set<std::string>> map_prefix_to_strings;

    for (std::string s : strings) {

        std::string prefix = s.substr(0, prefix_length);

        if (map_prefix_to_strings.count(prefix) == 0) {
            map_prefix_to_strings[prefix] = {};
        }

        map_prefix_to_strings[prefix].insert(s);
    }

    return map_prefix_to_strings;
}

void
ShortestUniquePrefixContainer::calculateShortestUniquePrefixes(
    std::set<std::string> strings,
    int prefix_length
    )
{
    for (auto& kvp : groupStringsByPrefix(strings, prefix_length)) {

        std::string prefix = kvp.first;
        std::set<std::string> group = kvp.second;

        if (group.size() == 1) {
            _prefixes[*group.begin()] = prefix;
        } else {
            calculateShortestUniquePrefixes(group, prefix_length + 1);
        }
    }
}

int main(int argc, char const *argv[]) {

    std::stringstream ss("cohesiveness,cognate,collaborate,convene,commitment,compress,contemporary,converge,compact,confluence,convenient,concatenate,conjoin,combine,correct");

    std::set<std::string> strings;
    std::string token;
    while (std::getline(ss, token, ',')) {
        strings.insert(token);
    }

    std::shared_ptr<ShortestUniquePrefixContainer> container = std::make_shared<ShortestUniquePrefixContainer>(strings);

    for (auto& kvp : container->prefixes()) {
        std::cout << kvp.first << " -> " << kvp.second << std::endl;
    }

    return 0;
}
