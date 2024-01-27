- [Introduction](#introduction)
  - [Variables](#variables)
  - [Printing](#printing)
  - [Symbolic Constants](#symbolic-constants)
- [Types, Operators, and Expressions](#types-operators-and-expressions)
  - [Boolean](#boolean)
  - [Enumeration](#enumeration)
  - [Increment/Decrement Operators](#incrementdecrement-operators)
  - [Bitwise Operators](#bitwise-operators)
  - [Precedence \& Order of Evaluation](#precedence--order-of-evaluation)
- [Control Flow](#control-flow)
  - [`switch`](#switch)
  - [`do-while`](#do-while)
- [Functions and Program Structure](#functions-and-program-structure)
  - [Functions](#functions)
  - [Scope Rules](#scope-rules)
  - [Static Variables](#static-variables)
  - [Register Variables](#register-variables)
  - [Initialization](#initialization)
  - [The C Preprocessor](#the-c-preprocessor)
    - [Macro Substitution](#macro-substitution)
    - [File Inclusion](#file-inclusion)
    - [Compiler Control](#compiler-control)


# Introduction

To compile individual files in C use the command `gcc filename.c -o filename.exe`. Then run the program by calling the executable with `./filename.exe`.

## Variables

All variables must be declared before use.  A declaration specifies a type and a list of variables of that type.  Note that a variable can be declared prior to being assigned a value.

```c
int lower, upper, step;
char c;
```

However, a variable can also be intialized in its declaration.  If an equal sign followed by a corresponding type value is placed after the declaration then the variable is declared and initialized at the same time.

```c
int i = 0;
float eps = 1.0e-5;
```

The qualifier `const` can be applied to the declaration of any variable to specify that its value will not be changed.

## Printing
To output values or print text in C, you can use the `printf()` function.  This function allows for the formatting of strings using conversion specifiers.  Format strings specify notation, alignment, significant digits, field width, and other aspects of output formats.

```C
int a = 0;
float b = 21.756;

printf("The value of a is %d.  The value of b is %f", a, b);
```

## Symbolic Constants
It is bad practice to bury important constants inside a program.  One way to deal with these constants is to give them names.  A `#define` line defines a symbolic constant to be a particular string of characters:

```C
#define PI 3.14159
```

# Types, Operators, and Expressions

There are only a few basic data types in C.  As mentioned in the [variables](#variables) section, every variable must be a specified data type.  Additionally, when printing using the `printf()` function, you must use a format specifier to display it.


| **Data Type** | **Size**     | **Description**                                                       | **Format Specifier** |
|---------------|--------------|-----------------------------------------------------------------------|----------------------|
| `int`         | 2 or 4 bytes | Stores whole numbers, without decimals.                               | `%d` or `%i`         |
| `float`       | 4 bytes      | Stores fractional numbers.  Sufficient for storing 6-7 decimal digits | `%f`                 |
| `double`      | 8 bytes      | Stores fractional numbers.  Sufficient for storing 15 decimal digits. | `%lf`                |
| `char`        | 1 byte       | Stores a single character or ASCII values. This is an integer value that maybe used freely in arithmetic expressions.                           | `%c`                 |

The qualifier `unsigned` may be applied to `char` or `int`.  These are always non-negative values that obey the laws of arithmetic modulo `2^n` and can be leverage to store larger positive numbers.

```
Range of signed int: -2147483648 to 2147483647
Range of unsigned int: 0 to 4294967295

Range of signed short int: -32768 to 32767
Range of unsigned short int: 0 to 65535

Range of signed long int: -9223372036854775808 to 9223372036854775807
Range of unsigned long int: 0 to 18446744073709551615

Range of signed char: -128 to 127
Range of unsigned char: 0 to 255
```

The value of an integer can be specified in binary, octal or hexadecimal instead of decimal:
- A leading `0b` on an integer constant means binary representation. (e.g. `37 == 0b100101`)
- A leading `0` on an integer constant means octal representation. (e.g. `31 == 037`)
- A leading `0X` means hexadecimal (e.g `31 == 0X1f`)
- These can also be followed by `L` to make them `long` and `U` to make them `unsigned` (e.g. 15 == `0XFUL` is an `unsigned long` constant)

## Boolean
In C, the `bool` data type is not a built-in data type and you must import `#include <stdbool.h>` to use it.  Boolean values are returned as integers having binary values.  Therefore you need to use the `%d` format specifier to print them.
- `1` (or any non-zero number) represents `true`
- `0` represents `false`

```C
bool isProgrammingFun = true;
bool isFishTasty = false;

printf("%d", isProgrammingFun);   
// Returns 1 (true)
printf("%d", isFishTasty);        
// Returns 0 (false)
```

## Enumeration

Enumerations are a user-defined type of named integers. They provide a convenient way to associate integers with names, an alternative to `#define`.  Furthermore, they have the advantage that values can be generated for you automatically.

```C
enum day1 {MON, TUE, WED, THU, FRI, SAT, SUN};
// mon=0, tue=1, wed=2,...

enum day2 {MON = 1, TUE, WED, THU, FRI, SAT, SUN};
// mon=1, tue=2, wed=3, ...

int main(){
  ...
}
```

The first name in an `enum` value has value 0 by default, unless explicit values are specified.  If not all values are specified, unspecified values continue the progression from the last specified value, as in the second example above.

Enums are a user-defined data type so **to actually used an enum class you need to instantiate an object of said type**. 

```C

int main(){
    enum day2 launch_date = MON;
    printf("%d", launch_date);
    // 1
}
```

Since enums are used in a similar way to symbolic constants, **identifier names in different enumerations must be distinct**.  However, values (even within the same enumeration) need not be distinct.

## Increment/Decrement Operators

The operators `++` and `--` may be used either as prefix or postfix.  The expression `++n` increments `n` *before* the value is used, while `n++` increments the value *after* it is used.

For instance, consider the function `squeeze(s[], c)` which removes all occurrences of the character `c` from the string `s`.

```c
void squeeze(char s[], char c){
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++)
    {
        if(s[i] != c)
            s[j++] = s[i];
    }
    s[j] = '\0';
}
```

Each time a character that is not `c` occurs, it is copied into the current `j` position and only *after* the copy is made, `j` is incremented to the next position.  The above is equivalent to:

```c
void squeeze(char s[], char c){
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++)
    {
        if(s[i] != c)
            s[j] = s[i];
            j++;
    }
    s[j] = '\0';
}
```

## Bitwise Operators

In the arithmetic-logic unit of the machine mathematical operations are done in bit-level. C provides six operators for for bit manipulation; these can only be applied to integral operands `char`, `short`, `int`, and `long` whether signed or unsigned.

**AND**

The output of bitwise `&` is 1 if the corresponding bits of two operands is 1. If either bit of an operand is 0, the result of corresponding bit is evaluated to 0. Consider the bitwise `&` operation of two integers 12 and 25:

```
12 = 00001100 (In Binary)
25 = 00011001 (In Binary)

Bit Operation of 12 and 25
  00001100
& 00011001
  ________
  00001000  = 8 (In decimal)
```

As you can see from this example, the `&` operator can be used to mask off some set of bits (where all the bits set to `0` in one argument will be turned off).

**OR**

The output of bitwise `|` is 1 if at least one corresponding bit of two operands is 1.

```
12 = 00001100 (In Binary)
25 = 00011001 (In Binary)

Bitwise OR Operation of 12 and 25
  00001100
| 00011001
  ________
  00011101  = 29 (In decimal)
```

The `|` operator can be used to to turn on bits (where all the bits set to `1` in one argument will be turned on).

**XOR**

The result of bitwise `^` operator is 1 if the corresponding bits of two operands are opposite and 0 if the bits are the same.

```
12 = 00001100 (In Binary)
25 = 00011001 (In Binary)

Bitwise XOR Operation of 12 and 25
  00001100
^ 00011001
  ________
  00010101  = 21 (In decimal)
```

**COMPLEMENT**

The bitwise complement operator is a unary operator that negates each bit, i.e. changes 0 to 1 and 1 to 0.

```
35 = 00100011 (In Binary)

Bitwise complement Operation of 35
~ 00100011 
  ________
  11011100  = 220 (In decimal)
```

More on this later...

**SHIFT**

The right shift `>>` and left shift `<<` operators perform bit shift of their left operand by the number of poisitions in the right operand.

```
212 = 11010100 (In binary)
212 >> 2 = 00110101 (In binary)
212 >> 7 = 00000001 (In binary)
212 >> 8 = 00000000 
212 >> 0 = 11010100 (No Shift)

212 = 11010100 (In binary)
212<<1 = 110101000 (In binary)
212<<0 = 11010100 (Shift by 0)
212<<4 = 110101000000 (In binary)
```
## Precedence & Order of Evaluation

For a full list of operator precedence read [this article](https://www.geeksforgeeks.org/operator-precedence-and-associativity-in-c/) which goes into the topic in-depth. 

For instance, notice that the precedence of bitwise operators `&`, `^`, and `|` falls below `==` and `!=`. Therefore, bit-testing expressions such as the one below must be parenthesized to give proper results.

```C
if ((x & mask) == 0) ...
```
C, like most languages, **does not specify the order in which the operands of an operator are calculated**. (Except for `&&`, `||`, `?:`, and `,`)

```C
x = f() + g()
```

So in a statement like the one above `f` may be evaluated before `g` or vice-versa.  Thus if either `f` or `g` alters a variable upon which both functions depend, `x` can yield different values depending on the order of evaluation.  When two function are dependent on a common variable, it is advisable to store intermediate results in temporary variables to ensure a particular sequence.

Another example is the seemingly simple statement,

```C
a[i] = i++
```
where the question is whether the index is the old value of `i` or the incremented one.  The unfortunate answer is that it depends on the compiler.

Similarly, **the order in which function arguments are evaluated is not specified**.  For example, the statement below can produce different results with different compilers, depending on whether `n` is incremented before `power` is called.

```C
printf("%d %d\n", ++n, power(2,n));
```

The way to fix this is to write:

```C
n++;
printf("%d %d\n", n, power(2,n));
```

The moral is that writing code that depends on order of evaluation is a bad programming practice in any language.  Naturally, it is necessary to know which things to avoid but as a rule of thumb leave no ambiguity for the compiler.

# Control Flow

## `switch`
The `switch` statement is a multi-way decision that tests whether an expression matches one of a number of *constant* integer values.  Each case is labeled by at least one integer-valued constant or constant expressions.  Cases can be stacked so as to re-use code:

```C
int main(){
    int a = 10;

    switch (a)
    {
        case 0: case 2: case 14:
            printf("Not a valid id.");
        case 1: case 3: case 4:
            printf("You do not have clearance.");
        default:
            printf("Access granted.");
            break;
    }
    return 0;
}
```

Because cases serve just as labels, after the code for one case is done, execution immediately falls through to the next case unless you take explicit action to explain. The `break` statement causes an immediate exit from the `switch`.

Falling through cases is both a blessing and a curse.  On the positive side, it allows serveral cases to be attached to a single action.  On the negative, normally each case must end with a `break` to prevent falling through to the next.

## `do-while`

The `while` and `for` loops test the termination condition at the top.  By contrast the `do-while` loop tests the condition after running the body of the loop at least once.

```C
do{
  ...
} while (...);
```

# Functions and Program Structure

## Functions

The general form of a function definition is as follows:

```C
return_type function_name(param_list) {
  body;
}
```

The parameter list refers to the type, order, and number of parameters of the function.  

A *function declaration* is exacly as above, minus the body.  This tells the compiler about a function name and how to call the function.  **Function declaration is required when you define a function in one source file and you call that function in another file.** In such case, you should declare the function at the top of the file calling the function.  For example,

```C
int max(int a, int b){
  int result;
}
```

## Scope Rules

If an external variable is to be referred to before it is defined, or if it is defined in a different source file, then an `extern` declaration is mandatory.  It is important to distinguish between a *declaration* - announces the properties of a variable (primarily its type) - and a *definition* which causes storage to be set aside.  

```C
// Declare the variable.
// Causes storage to be set aside.
int a;
double val[10]

// Declare the variable.
// Does not set aside storage.
extern int a;
extern double val[];
```

There must be only one definition of a variable among all the files that make up the source program; other files may only contain `extern` declarations to access it.  Likewise, initialization of an external variable goes only with the definition.  Array sizes must be specified with the definition, but are optional with an extern declaration.

## Static Variables

Sometimes you want variables/functions to be of private use for the functions in their respective source file, and not accessed by other source files even when imported.  The `static` declaration, applied to a variable or function, limits the scope of that object to the rest of the source file being compiled.

Static storage is specified by prefixing a declaration with the word `static`.  If a variable/function is declared static, its name is invisible outside of the file where it is declared.

```C
static int local_freq = 60;
```

The `static` declaration can also be applied to variables within a function.  What is the difference between this and a regular variable declared within a function?  Internal `static` variables are also local to a particular function, but unlike automatic variables, they remain in existence rather than coming each time the function is activated.  **This means `static` variables in a function provide private, permanent storage within a single function.**  Furthermore, `static` variables are only initialized the first time time the block is entered.

For example in the program below, the `counter` variable `print_int` will keep track of how many times the function was ran.  This `counter` variable does not get thrown out everytime `print_int` executes, but seves as storage for the function.

```C
void print_int(int num) {
    static int counter = 0;
    printf("Printing....%d\n", num);
    counter++;
    printf("For the %dth time.\n", counter);
}

int main(){
    for (int i = 0; i < 10; i++)
    {
        print_int(5);
    }
}
```

## Register Variables

A `register` declaration advises the compiler that the variable in question will be heavily used.  These variables are to be placed in machine registers, which may result in smaller and faster programs.  **Register variables can not be made global, but only local to functions or their parameters.**

```C
return_type function(register unsigned m, register long n){
  register int i;
}
```

- The decision to actually put the variable in a register is essentially up to the compiler.  Therefore, there is technically no harm in excess `register` variable declarations.  It is, however, not recommended.
- Only a few variables in each function may be kept in registers, and only certain types are allowed.  These vary from machine to machine.
- It is not possible to take the address of a register variable, reagrdless of whether the variable is actually placed in a register or not.

## Initialization 

In the absence of explicit initialization, global (external) and static variables are guaranteed to be initialized to zero; function (automatic) and register variables have undefined intial values.

For external and static values, the initializer must be a constant expression; the initialization is done once.  For automatic and register variables, the initializer is not restricted to being a constant; it may be any expression involving previously defined values, even function calls.

An array may be initialized by following its declaration with a list of initial values enclosed in braces.  For example:

```C
int days[] = {1, 2, 3, 4, 5, 6, 7}
```

- When the size of the array is omitted, the compiler will compute the length by counting the initial values.
- If there are fewer initializers for an array than the number specified, the missing elements will be zero for global, static, and automatic variables.
- Having more initializers for an array than the number specified will produce and error. 


## The C Preprocessor

A preprocessor is a text substitution tool that instructs the compiler to do required pre-processing before the actual compilation.  It opperates under the command of directives.


### Macro Substitution

This is the process of replacing an identifier with a certain string in the source code.

**Simple Macros**

 ```c
# define NUMBER (10*10)

// NUMBER gets replaced by 100
sum = NUMBER * 10;

// macro inside a string does not get replaced
printf("%d", NUMBER)
 ```

**Argumented Macros**

```c
#define SQUARE(x) ((x)*(x))

// area gets assigned to (a+b) * (a+b)
area = SQUARE(a+b)
```

**Nested Macros**

```c
#define HALF(x) (x/2.0)
#define QUARTER(x) HALF(HALF(x))
```

### File Inclusion

```c
// look for file in std system directory
#include <library.h>
// looks for file in current directory
#include "filename.h"
```

### Compiler Control

This is particularly useful when we want the compiler to "skip" certain lines of code, i.e. **conditional compilation**.

*Scenario 1:* Ensure macros are defined and deactivate some macros in an imported file.

```c
#include "myheader.h"
// defines MESSAGE iff not already defined in myheader.h
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





