#ifndef SHELL_H
#define SHELL_H

#include <iostream>
#include <string>
#include "List.h"
#include "Filesystem.h"
#include "Helper.h"
#include "Map.h"
#include "Command.h"
#include "CdCommand.h"
#include "LsCommand.h"
#include "TouchCommand.h"
#include "MkdirCommand.h"
#include "RmCommand.h"

namespace shell {

  class CLI {
    private:
      ds::da::Map<std::string, shell::Command*> commands;
      Filesystem fs;
    public:
      CLI() {
        ds::da::Map<std::string, shell::Command*> commands;
        commands.Put("cd", new shell::CdCommand());
        commands.Put("ls", new shell::LsCommand(&this->fs));
        commands.Put("touch", new shell::TouchCommand(&this->fs));
        commands.Put("mkdir", new shell::MkdirCommand(&this->fs));
        commands.Put("rm", new shell::RmCommand());
        this->commands = commands;
      }

      ds::da::Vector<std::string> Read() {
        std::string entry;
        
        std::cout << "$> ";
        std::getline(std::cin, entry);

        return SplitString(trim(entry), ' ');
      }

      void Evaluate(ds::da::Vector<std::string> args) {
        if (args.Size() > 0) {
          if (commands.Contains(args[0])) {
            shell::Command* command = commands.Get(args[0]);
            args.RemoveFirst();

            if ((args.Size() == command->GetRequiredArgs()) || command->GetRequiredArgs() == -1) {
              bool executed = command->Execute(args);
              if (!executed) {
                std::cerr << command->GetCommand() << ": incorrect usage" << "\n";
                std::cerr << "Correct Usage: " << command->GetCommand() << " " << command->GetHelp() << "\n";
              }
            } else {
              std::cerr << command->GetCommand() << ": incorrect usage" << "\n";
              std::cerr << "Correct Usage: " << command->GetCommand() << " " << command->GetHelp() << "\n";
            }
          } else {
            std::cerr << "Unknown Command: " << args[0] << "\n";
          }
        }
      }
  };
};

#endif