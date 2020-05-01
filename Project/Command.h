#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <string>
#include "List.h"

namespace shell {
  class Command {
    protected:
      std::string command;
      std::string help;
      int args;
    public:
      virtual bool Execute(ds::da::Vector<char>* signature) = 0;
      virtual std::string GetCommand() const = 0; 
      virtual std::string GetHelp() const = 0;
      virtual int GetRequiredArgs() const = 0;
  };
}

#endif