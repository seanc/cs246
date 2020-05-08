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
      int args; // 0 = no args, -1 = infinite args
    public:
      Command(std::string command, std::string help, int args) : command(command), help(help), args(args) {}

      virtual bool Execute(ds::da::Vector<std::string> signature) = 0;
      virtual const std::string GetCommand() const {
        return command;
      }
      virtual const std::string GetHelp() const {
        return help;
      }
      const int GetRequiredArgs() const {
        return args;
      };
  };
}

#endif