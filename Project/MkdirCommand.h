#ifndef MKDIR_COMMAND_H
#define MKDIR_COMMAND_H

#include <iostream>
#include "Command.h"

namespace shell {
  class MkdirCommand : public Command {
    public:
      MkdirCommand() : Command("ls", "[ . | .. | path ]", -1) {}

      bool Execute (ds::da::Vector<std::string> args) {
        std::cout << "Created directory: " << args[0] << "\n";
        return true;
      }
  };
}

#endif