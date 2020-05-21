#ifndef TOUCH_COMMAND_H
#define TOUCH_COMMAND_H

#include <iostream>
#include "Command.h"
#include "Filesystem.h"

namespace shell {
  class TouchCommand : public Command {
    private:
      Filesystem *fs;
    public:
      TouchCommand(Filesystem* fs) : Command("touch", "[ . | .. | path ]", 1) {
        this->fs = fs;
      }

      bool Execute (ds::da::Vector<std::string> args) {
        for (int i = 0; i < args.Size(); i++) {
          if (this->fs->GetFilesystem()->Find(args[i])) {
            continue;
          }

          this->fs->GetFilesystem()->Add(args[i], false);
        }
        return true;
      }
  };
}

#endif