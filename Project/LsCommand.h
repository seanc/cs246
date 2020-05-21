#ifndef LS_COMMAND_H
#define LS_COMMAND_H

#include <iostream>
#include "Command.h"
#include "Filesystem.h"

namespace shell {
  class LsCommand : public Command {
    private:
      Filesystem *fs;
    public:
      LsCommand(Filesystem* fs) : Command("ls", "[ . | .. | path ]", -1) {
        this->fs = fs;
      }

      bool Execute (ds::da::Vector<std::string> args) {
        TreeItem* tmp = this->fs->GetFilesystem()->first_child;

        while (tmp != NULL) {
          std::cout << tmp->value << " " << (tmp->is_directory ? "+" : "") << "\n";
          tmp = tmp->next_sibling;
        }
        return true;
      }
  };
}

#endif