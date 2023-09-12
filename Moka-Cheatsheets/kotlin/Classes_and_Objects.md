---
title: Classes and Objects
author: Mustafif Khan
level: 1
lang: kotlin
icon: devicon-kotlin-plain
---

## Classes and Objects

### Classes

In Kotlin, a class is a blueprint for creating objects (instances). It defines the structure and behavior of objects. Here’s an explanation of the elements within a class:

* **Class Declaration**: A class is declared using the class keyword followed by the class name.
    
* **Properties (Fields)**: Properties are variables that hold data within a class. They define the characteristics or attributes of an object.
    
* **Constructors**: Constructors are special functions responsible for initializing the properties of a class when an object is created. In the code example, there are two constructors: a primary constructor and a secondary constructor. The primary constructor is declared in the class header, and secondary constructors are defined using the constructor keyword.
    
* **Member Functions**: These are functions defined within the class. They encapsulate behavior associated with the class.

```kotlin
// Class declaration
class MyClass {
    // Properties (fields)
    var property1: Int = 0
    var property2: String = ""

    // Primary Constructor: Initializes properties when an instance is created.
    constructor(prop1: Int, prop2: String) {
        this.property1 = prop1
        this.property2 = prop2
    }

    // Secondary Constructor: Allows different ways to create instances.
    constructor(prop1: Int) : this(prop1, "Default")

    // Member functions: Functions defined within the class.
    fun myFunction() {
        println("property1: $property1, property2: $property2")
    }
}
```

### Objects

Objects in Kotlin are instances of classes. They allow you to create and manipulate instances of a class. Here’s an explanation of the elements related to objects:

* **Creating an Instance of a Class**: You create an instance (object) of a class using the class’s constructor.
    
* **Accessing Properties**: You can access the properties of an object using the dot notation to retrieve their values.
    
* **Calling Member Functions**: To execute functions defined within a class, you call them using the object followed by the function name (obj.myFunction()).
    
* **Companion Objects**: In Kotlin, you can define a companion object within a class. A companion object is like a singleton associated with the class, used for defining properties and functions that are associated with the class itself rather than its instances. It’s similar to a static context in other languages.
    

```kotlin
// Creating an instance of a class
val obj = MyClass(42, "Hello")

// Accessing properties
val value1 = obj.property1
val value2 = obj.property2

// Calling member functions
obj.myFunction()

// Companion Objects: A companion object is like a singleton associated with the class.
class MyClass {
    companion object {
        // Properties and functions within the companion object
        var count: Int = 0

        // Function to create instances of MyClass
        fun create(): MyClass {
            count++
            return MyClass()
        }
    }
}

val newObj = MyClass.create() // Creates an instance using the companion object
val objCount = MyClass.count // Accesses the companion object properties
```

### Inheritance

Inheritance is a fundamental concept in object-oriented programming, allowing one class to inherit properties and methods from another class. Here’s an explanation:

* **Inheriting from a Class**: To create a new class that inherits from an existing class, you use the `:` symbol followed by the name of the parent class (`class ChildClass : ParentClass()`). This establishes a parent-child relationship, where ChildClass inherits properties and functions from ParentClass.
    
* **Overriding**: When a child class wants to provide a specialized implementation of a function inherited from its parent class, it can override that function using the override keyword. The overridden function is then customized in the child class.
    

```kotlin
// Inheriting from a class
open class ParentClass {
    open fun parentFunction() {
        println("This is the parent function.")
    }
}

class ChildClass : ParentClass() {
    override fun parentFunction() {
        println("This is the overridden child function.")
    }
}
```

### Abstract Classes

Abstract classes are classes that cannot be instantiated directly but can be subclassed. They often contain abstract functions that must be implemented by their subclasses:

* **Abstract Function**: An abstract function is declared using the abstract keyword and lacks an implementation within the abstract class itself. Subclasses must provide implementations for abstract functions.
    
* **Concrete Function**: A concrete function is a regular function that has an implementation. It may be overridden by subclasses but doesn’t have to be.
    

```kotlin
abstract class AbstractClass {
    // Abstract function: Must be implemented by subclasses.
    abstract fun abstractFunction()

    // Concrete function: Optional and can have a default implementation.
    open fun concreteFunction() {
        println("This is a concrete function.")
    }
}

// Creating an instance of the abstract class is not allowed.
// val abstractObj = AbstractClass() // Error

// Creating an instance of a subclass and implementing the abstract function
class Subclass : AbstractClass() {
    override fun abstractFunction() {
        println("This is the implementation of abstractFunction.")
    }
}

val subObj = Subclass()
subObj.abstractFunction()
subObj.concreteFunction() // Calls the inherited concrete function
```

### Interfaces

Interfaces define a contract for classes, specifying a set of functions that must be implemented by any class that implements the interface:

* **Interface Declaration**: An interface is declared using the interface keyword, followed by the interface name. It contains function declarations but no implementations.
    
* **Implementing an Interface**: To implement an interface, a class uses the `:` symbol followed by the interface name in its class declaration. The implementing class must provide implementations for all the functions declared in the interface.
    
```kotlin
interface MyInterface {
    // Function declaration: Interface defines a contract without implementation.
    fun interfaceFunction()
}

class MyClass : MyInterface {
    override fun interfaceFunction() {
        println("This is the implementation of interfaceFunction.")
    }
}

// Creating an instance of the class that implements the interface
val obj = MyClass()
obj.interfaceFunction() // Calls the implemented interface function
```

### Data Classes

Data classes are a concise way to create classes that primarily hold data. Kotlin generates common methods like toString(), equals(), hashCode(), and copy() for data classes automatically:

* **Data Class Declaration**: You declare a data class using the data keyword before the class keyword. Data classes typically have properties as their primary focus.
    
* **Automatically Generated Methods**: Data classes automatically generate methods like `toString()` (for human-readable string representation), `equals()` (for comparing objects by content), `hashCode()` (for use in hash-based collections), and `copy()` (for creating a copy with optional property changes).
    

```kotlin
data class UserData(val name: String, val age: Int)

// Creating instances of data classes
val user1 = UserData("Alice", 30)
val user2 = UserData("Bob", 25)

// Automatically generated methods
println(user1.toString()) // Prints: UserData(name=Alice, age=30)
println(user1 == user2) // Prints: false
```

### Sealed Classes

A sealed class is a restricted class hierarchy used when you want to represent a limited set of types, often used in expressions like when:

* **Sealed Class Declaration**: You declare a sealed class using the sealed keyword before the `class` keyword. Sealed classes can have subclasses, but these subclasses are typically defined within the same file.
    
* **Subclasses**: Subclasses of sealed classes are defined within the same file as the sealed class itself. These subclasses are often used in when expressions to handle specific cases.
    
* **Use in when Expressions**: Sealed classes are particularly useful in when expressions because you can ensure that all possible cases are covered, making your code more robust.
    
```kotlin
sealed class Result {
    data class Success(val data: String) : Result()
    data class Error(val message: String) : Result()
}

// Creating instances of sealed classes
val result: Result = Result.Success("Data")

when (result) {
    is Result.Success -> println(result.data) // Prints the data
    is Result.Error -> println(result.message) // Doesn't execute in this case
}
```