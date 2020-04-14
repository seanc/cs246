#include <string>
#include <iostream>
#include <map>

int main () {
    std::string letters = "AAABCDEEEFGHHHIJKJKLMNOPQQRTUVWXXYZZZZZ";
    std::map<char, int> occur;
    for (char letter : letters) {
        if (occur.find(letter) != occur.end()) {
            occur[letter] = occur[letter] + 1;
        } else {
            occur.insert(std::make_pair(letter, 1));
        }
    }

    std::map<char, int>::iterator it = occur.begin();
    for (it = occur.begin(); it != occur.end(); it++) {
        std::cout << it->first << ":" << it->second << " ";
    }
    std::cout << "\n";
    return 0;
}
