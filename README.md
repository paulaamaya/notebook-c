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
printf("%d", NUMBER)
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
// lookf for file in std system directory
#include <library.h>
// looks for file in current directory
#include "filename.h"
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
int paymentMethod(){
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

## User I/O

```printf()``` is used to print a formatted string.  Its first argument should be a atring literal and, if needed, any values of another type.

```c
#include <stdio.h>
int main()
{
    float number1 = 13.5;

    printf("literal string");
    printf("number1 = %f\n", number1);
    return 0;
}
```

```scanf()``` reads formatted input.  Its first argument should be a atring literal specifying what kind of input we expect and the second is the memory address of where to store the value.

```c
#include <stdio.h>
int main()
{
    int a;
    printf("Enter an integer: ");
    scanf("%d", &a);
    return 0;
}
```

You do not need ```&``` if you are reading a string as an array of chars.

## Enums

Data type that allows you to define a variable and specify the valid values that could be stored in it.

```c  
int main() 
{ 
    // define enum type
    enum weekday {Mon, Tue, Wed, Thur, Fri, Sat, Sun};

    // declare a variable of type enum 
    enum weekday today = Wed; 

    // prints out value of enumeration, i.e. 2
    printf("%d",day); 

    // can loop through well-ordered enums
    int i; 
    for (i=Jan; i<=Dec; i++)       
        printf("%d ", i); 

    return 0; 
} 
```

Enum names are assigned to a number, the default is "index" number.  But we can also specify the number of enum names.

```c
int main(){

    enum state {working = 1, failed = 0};
    enum state myCarState = working;

    // prints out 1
    printf("d%", myCarState);

    return 0;
}
```

1. Two enum names can have same value
```c
int main(){

    enum state {working = 1, failed = 0, frozen = 0};

    // prints out 1 0 0
    printf("%d, %d, %d", working, failed, frozen)

    return 0;
}
```
2. We can assign values to some name in any order. All unassigned names get value as value of previous name plus one.
```c
int main(){

    enum state {apple = 1, orange = 5, grapefruit};

    // prints out 1 5 6
    printf("%d, %d, %d", apple, orange, grapefruit)

    return 0;
}
```
3. All enum names must be unique in their scope. 
```c
int main(){

    // Compile Error: 'failed' has a previous declaration as 'state failed'
    enum state {working, failed};
    enum result {passed, failed};

    return 0;
}
```


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