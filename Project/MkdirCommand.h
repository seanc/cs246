#ifndef MKDIR_COMMAND_H
#define MKDIR_COMMAND_H

#include <iostream>
#include "Command.h"
#include "Filesystem.h"

namespace shell {
  class MkdirCommand : public Command {
    private:
      Filesystem *fs;
    public:
      MkdirCommand() : Command("ls", "[ . | .. | path ]", -1) {}
      MkdirCommand(Filesystem* fs) : Command("ls", "[ . | .. | path ]", -1) {
        this->fs = fs;
      }

      bool Execute (ds::da::Vector<std::string> args) {
        if (this->fs->GetFilesystem()->Find(args[0]) != NULL) {
          std::cout << "mkdir: cannot create directory " << "'" << args[0] << "': File exists" << "\n";
        } else {
          this->fs->GetFilesystem()->Add(args[0], true);
          std::cout << "Created directory: " << args[0] << "\n";
          std::cout << this->fs->GetFilesystem()->Find(args[0])->value << "\n";
        }
        return true;
      }
  };
}

#endif