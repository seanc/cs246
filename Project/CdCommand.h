#ifndef CD_COMMAND_H
#define CD_COMMAND_H

#include <iostream>
#include "Command.h"

namespace shell {
  class CdCommand : public Command {
    public:
      CdCommand() : Command() {
        this->command = "cd";
        this->help = "[ . | .. | path ]";
        this->args = args;
      }

      bool Execute (ds::da::Vector<char>* signature) {

      }
  };
}

#endif