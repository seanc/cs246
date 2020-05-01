#include <iostream>
#include <string>
#include "Helper.h"
#include "CLI.h"
#include "Map.h"


int main() {
  // TODO: Setup command map, add arg check, add execution
  shell::CLI* cli = new shell::CLI();
  while (true) {
    auto args = cli->Read();
    cli->Evaluate(args);
  }
  return 0;
}