#ifndef EDITOR_H
#define EDITOR_H

#include <string>
#include "Deque.h"

class Editor
{
private:
  ds::dn::Deque<char>* chars;

  bool IsLetter(char input) {
    return (input >= 'A' && input <= 'Z') || (input >= 'a' && input <= 'z');
  }

  bool IsDigit(char input) {
    return (input >= '0' && input <= '9');
  }

  bool IsSpace(char input) {
    return input == ' ';
  }

  bool IsNewLine(char input) {
    return input == '\n';
  }
public:
  Editor() {
    chars = new ds::dn::Deque<char>;
  };

  Editor(const Editor& obj) {
    chars = obj.chars;
  }

  Editor& operator=(const Editor& rhs) {
    if (this != &rhs) {
      chars = rhs.chars;
    }
    return *this;
  }

  ~Editor() {
    delete chars;
  }

  void Read(char input) {
    if (
      IsLetter(input)
      || IsDigit(input)
      || IsSpace(input)
      || IsNewLine(input)
    ) {
      chars->InsertLast(input);
    } else if (input == '#') {
      if (!chars->IsEmpty()) {
        chars->RemoveLast();
      }
    }
  }

  std::string Write() {
    std::string charString = "";
    while (!chars->IsEmpty()) {
      charString += chars->First();
      chars->RemoveFirst();
    }
    return charString;
  }
};

#endif