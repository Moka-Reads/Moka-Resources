---
title: Data Types and Variables
author: Mustafif Khan
level: 1
lang: python
icon: devicon-python-plain

---
## Data Types and Variables

Python has several built-in data types that can store different kinds of values. Some of the most common data types are:

- `str`: a string is a sequence of characters enclosed in quotes. 
  - For example, `name = "Alice"` assigns a string value to the variable `name`.
- `int`: an integer is a whole number without a decimal point. 
  - For example, `age = 21` assigns an integer value to the variable `age`.
- `float`: a float is a number with a decimal point. 
  - For example, `pi = 3.14` assigns a float value to the variable `pi`.
- `bool`: a boolean is a logical value that can be either True or False. 
  - For example, flag = True assigns a boolean value to the variable flag.
- `list`: a list is an ordered collection of values that can be of different types. 
  - For example, `colors = ["red", "green", "blue"]` assigns a list value to the variable `colors`.
- `tuple`: a tuple is an immutable ordered collection of values that can be of different types. 
  - For example, `point = (1, 2)` assigns a tuple value to the variable `point`.
- `dict`: a dictionary is an unordered collection of key-value pairs that can be of different types. 
  - For example, `person = {"name": "Bob", "age": 25}` assigns a dictionary value to the variable `person`.
- `set`: a set is an unordered collection of unique values that can be of different types. 
  - For example, `letters = {"a", "b", "c"}` assigns a set value to the variable `letters`.

- Python does not require explicit declaration of variables. A variable is created when a value is assigned to it using the `=` operator. For example, `x = 5` creates a variable named `x` and assigns it the value `5`.

- Python variables are dynamically typed, which means that their data type is determined at runtime based on the type of the value assigned to them. For example, if you assign a string value to a variable that previously had an integer value, the data type of the variable will change from `int` to `str`. For example, `x = 5` makes `x` an `int`, but `x = "hello"` makes `x` a `str`.

- You can check the data type of any variable or value by using the built-in function `type()`. For example, `type(x)` will return the data type of `x`.

- You can also convert one data type to another by using the built-in functions that correspond to each data type. For example, `int(x)` will convert `x` to an `int`, and `str(x)` will convert `x` to a `str`.
