# CS246 Final Project

For the final project, I did the Shell proposal

I plan to structure my project in the following way:
- Command Interface
  - Fields
    - string command
    - string help
    - int args
  - Methods
    - Execute
    - GetCommand
    - GetHelp
    - GetRequiredArgs
  - Commands extend CommandInterface
    - CdCommand
    - LsCommand
    - TouchCommand
    - MkDirCommand
    - RemoveCommand

Commands are registered on run in a Map with key of command and value of Command object

There will be a central while loop which asks the user for input. Once received, it will call ParseEntry which returns a vector of the entry parts: [ command [...args] ]

After parsing the command, it takes the first argument and checks the command map

If the command exists in the map, it will check the arguments count vs the required arguments. If the arg count matches, it will call Execute passing the vector of parts, otherwise it will send an error printing GetHelp