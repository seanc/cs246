#ifndef HELPER_H
#define HELPER_H

#include <string>
#include "List.h"

// Split string by delimiter
ds::da::Vector<std::string> SplitString(std::string str, char delimiter) {
  ds::da::Vector<std::string> tokens;

  if (str.length() > 0) {
    int current = str.find(delimiter), previous = 0;
    while (current != std::string::npos) {
        tokens.Insert(str.substr(previous, current - previous));
        previous = current + 1;
        current = str.find(delimiter, previous);
    }
    tokens.Insert(str.substr(previous, current - previous));
  }

  return tokens;
}

std::string& ltrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
  str.erase(0, str.find_first_not_of(chars));
  return str;
}
 
std::string& rtrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
  str.erase(str.find_last_not_of(chars) + 1);
  return str;
}
 
std::string& trim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
  return ltrim(rtrim(str, chars), chars);
}


#endif