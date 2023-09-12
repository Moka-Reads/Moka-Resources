---
title: Classes and Objects
author: Mustafif Khan
level: 2
lang: c++
icon: devicon-cpp-plain
---

## Classes and Objects

### Classes

```cpp
// Class declaration
class MyClass {
public: // Access specifier

    // Member variables (fields)
    int property1;
    std::string property2;

    // Constructor: Special member function for initializing objects
    MyClass(int prop1, std::string prop2) {
        property1 = prop1;
        property2 = prop2;
    }

    // Destructor: Special member function for releasing objects
    ~MyClass() {
        // Destructor implementation
    }

    // Member functions (methods)
    void myFunction() {
        // Method implementation
    }
};
```

* **Class Declaration**: Use the `class` keyword to declare a class. Classes encapsulate data (member variables) and behavior (member functions) into a single unit.
    
* **Access Specifier**: public is an access specifier that determines the visibility of class members. Members declared as public can be accessed from outside the class.
    
* **Member Variables (Fields)**: These are properties that hold data within a class.
    
* **Constructor**: A constructor is a special member function used to initialize objects when they are created. Constructors have the same name as the class and no return type.
    
* **Destructor**: A destructor is a special member function used to release objects, this is essential for Resource Acquisition Is Initialized (RAII) in C++. They are created similar to constructors except they are prefixed with `~`.
    
* **Member Functions (Methods)**: These are functions defined within the class that operate on its member variables.
    
```cpp
// Constructor definition
MyClass::MyClass(int prop1, std::string prop2) {
    property1 = prop1;
    property2 = prop2;
}

// Member function definition
void MyClass::myFunction() {
    // Code here
}
```

* **Constructor Definition**: Define the constructor’s implementation outside the class using the scope resolution operator `::`.
    
* **Member Function Definition**: Member functions are defined similarly to regular functions but within the class’s scope.
    

### Objects

```cpp
// Creating an instance of a class
MyClass obj(42, "Hello");

// Accessing member variables
int value1 = obj.property1;
std::string value2 = obj.property2;

// Calling member functions
obj.myFunction();
```

* **Creating an Instance of a Class**: Use the class name followed by parentheses to create an object (instance) of the class.

**Accessing Member Variables**: Use the dot (`.`) operator to access member variables of an object.

**Calling Member Functions**: Call member functions of an object using the dot (`.`) operator.

### Access Specifiers

```cpp
class MyClass {
public: // Public members
    int publicVar;
    void publicFunction();

private: // Private members
    int privateVar;
    void privateFunction();

protected: // Protected members
    int protectedVar;
    void protectedFunction();
};
```

* **Public Members**: Members declared as public can be accessed from anywhere in the program.
    
* **Private Members**: Members declared as private are only accessible within the class.
    
* **Protected Members**: Members declared as protected are accessible within the class and its subclasses (derived classes).
    

### Inheritance

```cpp
// Base class
class ParentClass {
public:
    void parentFunction() {
        // Code for the base class function here
    }
};

// Derived class
class ChildClass : public ParentClass {
public:
    void childFunction() {
        // Code for the derived class function here
    }
};
```

* **Inheritance**: Inheritance allows a derived class to inherit properties and methods from a base class. In this example, `ChildClass` inherits the `parentFunction()` from `ParentClass`.

### Static Members

```cpp
// Class definition
class MyClass {
public:
    // Static member variable
    static int staticVar;

    // Static member function
    static void staticFunction() {
        // Code for the static function here
    }
};

// Define and initialize the static member variable
int MyClass::staticVar = 0;
```

* **Static Members**: Static members belong to the class itself, not to individual objects. They are accessed using the class name, e.g., `MyClass::staticVar`. In this example, `staticVar` is a static member variable initialized to `0`.

### Constructor Overloading

In C++, you can define multiple constructors within a class, each with a different set of parameters. This concept is known as constructor overloading. It allows you to create objects with different initialization options, providing flexibility and convenience for users of your class.


```cpp
// Class definition
class MyClass {
public:
    int property;

    // Default constructor with no arguments
    MyClass() {
        property = 0;
    }

    // Constructor with a single integer parameter
    MyClass(int initialValue) {
        property = initialValue;
    }
};
```

* **Default Constructor**: The default constructor is used when an object is created without providing any arguments. In this example, it initializes property to a default value of `0`.
    
* **Parameterized Constructor**: The parameterized constructor takes one integer argument, allowing users to initialize property with a specific value when creating an object.
    

### Friend Functions

```cpp
// Class definition
class MyClass {
private:
    int secretData;

public:
    MyClass(int value) : secretData(value) {}

    // Friend function declaration
    friend void friendFunction(MyClass& obj);
};

// Friend function definition
void friendFunction(MyClass& obj) {
    // Access private member
    std::cout << "Friend Function: " << obj.secretData << std::endl;
}
```

* **Friend Functions**: Friend functions are functions declared with the `friend` keyword inside a class. They can access private members of that class. In this example, `friendFunction` can access and display the `secretData` private member of MyClass objects.