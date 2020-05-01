#ifndef CD_COMMAND_H
#define CD_COMMAND_H

#include <iostream>
#include "Command.h"

namespace shell {
  class CdCommand : public Command {
    public:
      CdCommand() : Command("cd", "[ . | .. | path ]", 2) {}

      bool Execute (ds::da::Vector<std::string> args) {
        std::cout << "it worked!" << args << "\n";
      }
  };
}

#endif