#include <string>
#include <iostream>
#include <map>

/**
 * Modification from 4/16 with hash function
 **/
int hash (char key) {
    if (key >= 'a' && key <= 'z') {
        return (key - 'a');	
    } else if (key >= 'A' && key <= 'Z') {
        return (key - 'A');
    } else {
        return 26;
    }
}

void LetterCount(std::string word) {
    int counts[27];
    for (int i = 0; i < 27; i++) {
        counts[i] = 0;
    }

    for (int i = 0; word[i] != '\0'; i++) {
        counts[hash(word[i])] += 1;
    }

    std::string letters = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 28; i++) {
        std::cout << letters[i] << " - " << counts[i];
        std::cout << "\n";
    }
}
// END


int main () {
    std::string word = "AAABCDEEEFGHHHIJKJKLMNOPQQRTUVWXXYZZZZZ";
    // std::map<char, int> occur;
    // for (char letter : letters) {
    //     if (occur.find(letter) != occur.end()) {
    //         occur[letter] = occur[letter] + 1;
    //     } else {
    //         occur.insert(std::make_pair(letter, 1));
    //     }
    // }

    // std::map<char, int>::iterator it = occur.begin();
    // for (it = occur.begin(); it != occur.end(); it++) {
    //     std::cout << it->first << ":" << it->second << " ";
    // }
    // std::cout << "\n";
    LetterCount(word);
    return 0;
}
