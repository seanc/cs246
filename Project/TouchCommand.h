#ifndef TOUCH_COMMAND_H
#define TOUCH_COMMAND_H

#include <iostream>
#include "Command.h"

namespace shell {
  class TouchCommand : public Command {
    public:
      TouchCommand() : Command("touch", "[ . | .. | path ]", 1) {}

      bool Execute (ds::da::Vector<std::string> args) {
        std::cout << "Created file: " << args[0] << "\n";
        return true;
      }
  };
}

#endif