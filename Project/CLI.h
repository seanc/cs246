#ifndef SHELL_H
#define SHELL_H

#include <iostream>
#include <string>
#include "List.h"
#include "Helper.h"
#include "Map.h"
#include "Command.h"
#include "CdCommand.h"

namespace shell {

  class CLI {
    private:
      ds::da::Map<std::string, shell::Command*> commands;
    public:
      CLI() {
        ds::da::Map<std::string, shell::Command*> commands;
        commands.Put("cd", new shell::CdCommand());
        this->commands = commands;
      }

      ds::da::Vector<std::string> Read() {
        std::string entry;
        
        std::cout << "$> ";
        std::getline(std::cin, entry);

        return SplitString(trim(entry), ' ');
      }

      bool Evaluate(ds::da::Vector<std::string> args) {
        if (args.Size() > 0) {
          if (commands.Contains(args[0])) {
            shell::Command* command = commands.Get(args[0]);
            if (args.Size() == command->GetRequiredArgs() + 1) {

            } else {
              std::cerr << command->GetCommand() << ": incorrect usage" << "\n";
              std::cerr << "Correct Usage: " << command ->GetCommand() << " " << command->GetHelp() << "\n";
            }
          } else {
            std::cerr << "Unknown Command: " << args[0] << "\n";
          }
        }
      }
  };
};

#endif