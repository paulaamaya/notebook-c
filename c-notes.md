# Preprocessor

A preprocessor is a text substitution tool that instructs the compiler to do required pre-processing before the actual compilation.  It opperates under the command of directives.

## Macro Substitution

This is the process of replacing an identifier with a certain string in the source code.

### Simple Macros

 ```c
# define NUMBER (10*10)

// NUMBER gets replaced by 100
sum = NUMBER * 10;

// macro inside a string does not get replaced
printf("NUMBER")
 ```

### Argumented Macros

```c
#define SQUARE(x) ((x)*(x))

// area gets assigned to (a+b) * (a+b)
area = SQUARE(a+b)
```

### Nested Macros

```c
#define HALF(x) (x/2.0)
#define QUARTER(x) HALF(HALF(x))
```

## File Inclusion

```c
// preprocessor inserts the entire file
# include "filename.c"
```

## Compiler Control

This is particularly useful when we want the comiler to "skip" certain lines of code, i.e. **conditional compilation**.

*Scenario 1:* Ensure macros are defined and deactivate some macros in an imported file.

```c
#include "myheader.h"
// defines MESSAGE iff not already defined in myheader.c
#ifndef MESSAGE
    # define MESSAGE "You wish!"
#endif
// ensure we never have RUDE defined
# ifdef RUDE
    #ndef RUDE
#endif
```

*Scenario 2:* Run different code depending on payment type.

```c
int PaymentMethod(){
    ...
    #if defined(CASH)
        cash();
    #elif defined(DEBIT) || defined(CREDIT)
        interac();
    #else
        printerror();
    #endif
    ...
}
```
Notice that we can use compile control directives in-code and use of the ```defined(macro)``` operator in conditional compiling.

# Basics



# Vscode Set Up

To use most IDEs you will have to configure the compiler path, tell the IDE how to build, and specify a debugger if you wish.

**Build:** *Ctrl + Shift + B* which executes ```gcc -g -o helloworld helloworld.c```
**Launch Debugger:**: ```F5```

## Compiler

In vscode, go to *Edit Configurations (UI)* and set the compiler path with appropiate IntelliSense mode.  This creates a ```c_cpp_properties.json``` file in the workspace configurations folder.

```json
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**"
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "_UNICODE"
            ],
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "gcc-x64",
            // specify compiler path
            "compilerPath": "C:\\cygwin64\\bin\\gcc.exe"
        }
    ],
    "version": 4
}
```

## Build Tasks

In vscode go to, *Configure Default Build Task*.  This will create a ```tasks.json``` file in the workspace configurations folder. Here you will specify some arguments for compilation.

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            //name of your app here
            "label": "build hello world",
            "type": "shell",
            // name of compiler here
            "command": "gcc",
            // -g: debuggging info for use with gdb
            // -o: specifies the output executable filename 
            // list of source files
            "args": [
                "-g", 
                "-o", "helloworld",
                "helloworld.c"
            ], 
            // define task group and set default
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}
```

## Debugger

In vscode, go to *Debug: Open launch.json* and select the GDB environment.  This will create a ```launch.json``` file in the workspace configurations folder.  

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) Launch",
            "type": "cppdbg",
            "request": "launch",
            // specify this to .exe you want to run
            "program": "${workspaceFolder}/helloworld.exe",
            "args": [],
            // set this to true
            "stopAtEntry": true,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            // specify debugger path
            "miDebuggerPath": "C:\\cygwin64\\bin\\gdb.exe",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ]
        }
    ]
}
```