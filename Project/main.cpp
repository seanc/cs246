#include <iostream>
#include <string>
#include "CdCommand.h"

ds::da::Vector<std::string> Prompt() {
  std::string entry;
  ds::da::Vector<std::string> tokens;
  
  std::cout << "$> ";
  std::getline(std::cin, entry);
  
  int current = entry.find(' '), previous = 0;

  while (current != std::string::npos) {
      tokens.Insert(entry.substr(previous, current - previous));
      previous = current + 1;
      current = entry.find(' ', previous);
  }
  
  tokens.Insert(entry.substr(previous, current - previous));
  
  return tokens;
}

int main() {
  // TODO: Setup command map, add arg check, add execution

  while (true) {
    std::cout << Prompt() << "\n";
  }
  return 0;
}