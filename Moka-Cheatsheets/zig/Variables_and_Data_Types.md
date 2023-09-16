---
title: Variables and Data Types
author: Mustafif Khan
level: 1
lang: zig
icon: devicon-zig-original
---

## Variables and Data Types

### Var vs Const 

In Zig we have two ways to create variables which differ from mutability, where `var` declares a mutable variable and `const` is immutable. 
Most cases will only require an immutable variable and its recommended to use `const` in most cases unless mutability is required, this improves
security in your program and thus a key reason languages like Swift and Rust also provide abstractions like this. 

### Declaring a Variable 
Now that we understand the difference between `var` and `const`, to declare a variable we can either declare its datatype 
explicitly (using the `:` operator) or implicitly. To look at the difference consider the following: 

```zig
// syntax: <var/const> <ident>: <type> = <value>;

// Explicitly declared a floating point variable 
const float_num: f64 = 20.4; // data type f64

// Implicitly declared a floating point variable 
const float2 = 50.4; // data type comptime_float 
```

> Variables cannot be left undeclared, if you do not have a known value when needing to declare the value 
> you may use the `undefined` keyword. 

### Primitive Data Types 

| Type            | C Equivalent       | Description                                        |
|-----------------|--------------------|----------------------------------------------------|
| `i8`            | `int8_t`           | Signed 8-bit integer                               |
| `u8`            | `uint8_t`          | Unsigned 8-bit integer                             |
| `i16`           | `int16_t`          | Signed 16-bit integer                              |
| `u16`           | `uint16_t`         | Unsigned 16-bit integer                            |
| `i32`           | `int32_t`          | Signed 32-bit integer                              |
| `u32`           | `uint32_t`         | Unsigned 32-bit integer                            |
| `i64`           | `int64_t`          | Signed 64-bit integer                              |
| `u64`           | `uint64_t`         | Unsigned 64-bit integer                            |
| `i128`          | `__int128`         | Signed 128-bit integer                             |
| `u128`          | `unsigned __int128`| Unsigned 128-bit integer                           |
| `isize`         | `intptr_t`         | Signed pointer-sized integer                      |
| `usize`         | `uintptr_t`, `size_t`| Unsigned pointer-sized integer                   |
| `16`            | `_Float16`         | 16-bit floating point (10-bit mantissa) IEEE-754-2008 binary16       |
| `f32`           | `float`            | 32-bit floating point (23-bit mantissa) IEEE-754-2008 binary32       |
| `f64`           | `double`           | 64-bit floating point (52-bit mantissa) IEEE-754-2008 binary64       |
| `f80`           | `double`           | 80-bit floating point (64-bit mantissa) IEEE-754-2008 80-bit extended precision |
| `f128`          | `_Float128`        | 128-bit floating point (112-bit mantissa) IEEE-754-2008 binary128     |
| `bool`          | `bool`             | True or false                                      |
| `comptime_int`  | (none)             | Only allowed for comptime-known values. The type of integer literals.     |
| `comptime_float`| (none)             | Only allowed for comptime-known values. The type of float literals.       |

> These are provided by the official Zig Documentation, for more information check it out [here](https://ziglang.org/documentation/master/#Primitive-Types). 
