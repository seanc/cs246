#ifndef RM_COMMAND_H
#define RM_COMMAND_H

#include <iostream>
#include "Command.h"

namespace shell {
  class RmCommand : public Command {
    public:
      RmCommand() : Command("rm", "[ path ]", -1) {}

      bool Execute (ds::da::Vector<std::string> args) {
        std::cout << args.Size() << "\n";
        if (args.Size() == 0) return false;
        std::cout << "Removed " << args[0] << "\n";
        return true;
      }
  };
}

#endif