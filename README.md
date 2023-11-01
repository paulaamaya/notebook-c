- [Basics](#basics)
  - [Variables](#variables)
  - [Data Types](#data-types)
    - [Boolean](#boolean)
    - [Enumeration](#enumeration)
  - [Increment/Decrement Operators](#incrementdecrement-operators)


# Basics

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

## Data Types

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

### Boolean
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

### Enumeration

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




