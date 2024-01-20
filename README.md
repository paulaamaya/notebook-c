- [Introduction](#introduction)
  - [Variables](#variables)
- [Types, Operators, and Expressions](#types-operators-and-expressions)
  - [Boolean](#boolean)
  - [Enumeration](#enumeration)
  - [Increment/Decrement Operators](#incrementdecrement-operators)
  - [Bitwise Operators](#bitwise-operators)
  - [Precedence \& Order of Evaluation](#precedence--order-of-evaluation)


# Introduction

## Variables

All variables must be declared before use.  A declaration specifies a type and a list of 1+ variable names of that type.  Note that a variable can be declared prior to being assigned a value.

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

The value of an integer can be specified in octal or hexadecimal instead of decimal:
- A leading `0` on an integer constant means octal (e.g. `31 == 037`)
- A leading `0X` means hexadecimal (e.g `31 == 0X1f`)
- These can also be followed by `L` to make them `long` and `U` to make them `unsigned` (e.g. 15 == `0XFUL` is an `unsigned long` constant)

## Boolean
In C, the `bool` data type is not a built-in data type and you must import `#include <stdbool.h>` to use it.  Boolean values are returned as integers having binary values.  Therefore you need to use the `%d` format specifier to print them.
- `1` (or any non-zero number) represents `true`
- `0` represents `false`

```C
// Create boolean variables
bool isProgrammingFun = true;
bool isFishTasty = false;

// Return boolean values
printf("%d", isProgrammingFun);   // Returns 1 (true)
printf("%d", isFishTasty);        // Returns 0 (false)
```

## Enumeration

Enumerations provide a convenient way to associate constant values with names, an alternative to `#define` with the advantage that values can be generated for you. 

```C
enum daysOfWeek1 {sun, mon, tue, wed, thu, fri, sat};
// sun=0, mon=1, tue=2,...

enum daysOfWeek2 {sun=1, mon, tue, wed, thu, fri, sat};
// sun=1, mon=2, tue=3,...
```

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






