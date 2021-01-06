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