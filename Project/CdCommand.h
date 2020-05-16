#ifndef CD_COMMAND_H
#define CD_COMMAND_H

#include <iostream>
#include "Command.h"

namespace shell {
  class CdCommand : public Command {
    public:
      CdCommand() : Command("cd", "[ . | .. | path ]", 1) {}

      bool Execute (ds::da::Vector<std::string> args) {
        std::cout << "Changed directory to " << args[0] << "\n";
        return true;
      }
  };
}

#endif