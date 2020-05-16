#ifndef LS_COMMAND_H
#define LS_COMMAND_H

#include <iostream>
#include "Command.h"

namespace shell {
  class LsCommand : public Command {
    public:
      LsCommand() : Command("ls", "[ . | .. | path ]", -1) {}

      bool Execute (ds::da::Vector<std::string> args) {
        std::cout << "Directory contents: " << "\n";
        return true;
      }
  };
}

#endif