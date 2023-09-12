---
title: Variables and Operators
author: Mustafif Khan
level: 1
lang: c
icon: devicon-c-plain
---

## Variables and Operators

### Variables

```c
// Variable declaration
datatype variable_name;

// Initialization
datatype variable_name = value;

// Common data types
int     // Integer
float   // Floating-point number
char    // Character
double  // Double-precision floating-point number
```

* **Variable Declaration**: In C, you declare variables by specifying their data type followed by the variable name. This informs the compiler about the type of data the variable can hold.
    
* **Initialization**: You can initialize a variable at the time of declaration by providing an initial value. If an initial value is not provided, the variable contains garbage values.
    
* **Common Data Types**: C provides various data types to represent different kinds of values, including integers, floating-point numbers, characters, and double-precision floating-point numbers.
    

### Operators

#### Arithmetic Operators

These operators perform basic mathematical operations.

```c
// Addition: +
// Subtraction: -
// Multiplication: *
// Division: /
// Modulus (remainder): %
```

#### Assignment Operators

Assignment operators are used to assign values to variables. Compound assignment operators combine an operation with assignment.

```c
// Assignment: =
// Addition assignment: +=
// Subtraction assignment: -=
// Multiplication assignment: *=
// Division assignment: /=
// Modulus assignment: %=
```

#### Increment and Decrement Operators

These operators increase or decrease the value of a variable by 1.

```c
// Increment by 1: ++
// Decrement by 1: --
```

#### Relational Operators

Relational operators compare two values and return a Boolean result.

```c
// Equal to: ==
// Not equal to: !=
// Greater than: >
// Less than: <
// Greater than or equal to: >=
// Less than or equal to: <=
```

#### Logical Operators

Logical operators perform logical operations on Boolean values.

```c
// Logical AND: &&
// Logical OR: ||
// Logical NOT: !
```

#### Bitwise Operators

Bitwise operators work at the bit level and are often used for low-level bit manipulation.

```c
// Bitwise AND: &
// Bitwise OR: |
// Bitwise XOR (exclusive OR): ^
// Bitwise NOT (complement): ~
// Left shift: <<
// Right shift: >>
```

#### Conditional (Ternary) Operator

This operator is a shorthand way to write an if-else statement in a single line.

```c
condition
    ? expression_if_true
    : expression_if_false
```

#### Assignment Operators

These operators perform an operation and assignment in a single step, making code more concise
```c
x += y;  // Equivalent to x = x + y;
x -= y;  // Equivalent to x = x - y;
x *= y;  // Equivalent to x = x * y;
x /= y;  // Equivalent to x = x / y;
x %= y;  // Equivalent to x = x % y;
```
