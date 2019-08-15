# Quake-like-Console
C++ SDL Console Prompt to execute commands &amp; cvars 

## TODO'S:

* Create a new Module for the Console
* It should use the UI Module to create needed Labels and Input Text
* Listen to input so on tilde/ESC the console should open / close
* Tilde should be SDL_SCANCODE_GRAVE
* It should accept scroll with center mouse
* Re-route all LOG entries to the output
* define its properties (size, colors, font) in config.xml

### Commands

* Create a small class that represents a command
* Which properties would you use for it ? (name, amount of arguments, … ?)
* The console should process input the same way Zork parsed commands
* Now each module should be able to generate its own commands:
* Module Render: turn on/off sync, fullscreen, etc..
* App: quit, max fps, pause, load level, etc…
* Have a function to generate a new command 
Ex: App->console->AddFunc(const char* command, j1Module* callback, uint min_arg, uint max_args)

### Extra Features

* Scroll with pgUp/pgDown
* Allow mixing uppercase and lowercase as commands
* Pressing UP arrow should write the previous command in history
* Pressing DOWN arrow should write the next command in history
* Pressing TAB should try to autocomplete
* Only if there is 1 hit while you search for commands, if not make a beep with printf(“\a”);
* Allow argument packing with quotes
]log “hello world” ERROR

### Cvars

* Create a class for a CVar and allow the Console Module to create them
* Each module should be able to create its own CVars
* When those CVars are changed by the user, a callback must be called
* Some other CVar properties:
* Read-only, Min/Max, Default Value
