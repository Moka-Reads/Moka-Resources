---
title : Iterators and Closures
author : Mustafif Khan
level: 1
lang: rust
icon: devicon-rust-plain
---

## Iterators in Rust 

An iterator is an object that represents a way to transverse through a sequence of elements one at a time. In 
Rust this is done by implementing traits for a collection, the most common traits are the following: 

- `Iterator` trait (`std::iter::Iterator`): 
    - This is the most fundamental trait for iterators in Rust 
    - Defines methods like `next()`, `map()` and `filter()`, etc. which allow you to work with elements in a sequence. 
- `IntoIterator` trait (`std::iter::IntoIterator`): 
  - This trait allows a type to be converted into an iterator 
  - It's used when you want to turn a collection or an object into an iterator using the `into_iter()` method. 
- `DoubleEndedIterator` trait (`std::iter::DoubleEndedIterator`): 
  - Extends the `Iterator` trait with methods like `next_back()` and `rev()`, enabling bidirectional iteration. 


### Creating Iterators 
- `iter()`: Creates a read-only iterator over a collection. 
- `iter_mut()`: Creates a mutable iterator over a collection. 
- `into_iter()`: Consumes the collection and produces an iterator. 

### Common Iterator Methods 
- `map(|x| f(x))`: Transforms each element using the provided closure `f`. 
- `filter(|x| pred(x))`: Filters elements based on the given predicate. 
- `collect()`: Converts an iterator into a collection (e.g., `Vec`, `HashMap`). 
- `fold(init, |acc, x| f(acc, x))`: Applies a binary operation `f` cumulatively to the elements, with an initial accumulator value. 
- `for_each(|x| f(x))`: Applies a function to each element without collecting the results. 
- `zip(iter)`: Zips two iterators together, creating pairs. 


### Chaining Iterator Methods 
You may chain iterator methods together for complex operations, consider the we have an array where we wish 
only to store the even elements, double them then store it in a new collection. It would look like the following: 

```rust 
fn main() {
    let nums = [1, 2, 3, 4]; // [i32;4]
    // get the even numbers, double them then collect result
    let result = nums
        .iter() // Iter<&i32>
        .filter(|x| *x % 2 == 0) // gets all even numbers 
        .map(|x| x * 2) // doubles each number 
        .collect::<Vec<_>>(); // Vec<&i32>
    println!("Original: {:?}", nums); 
    // Original: [1, 2, 3, 4]
    println!("Result: {:?}", result);
    // Result: [4, 8]
}
```

We first use the `iter()` method to create an Iterator for `i32` elements, after we filter each element (`&i32`) with the predicate `*x % 2 == 0` which checks if a number is even using the modulus operator. Ater we use `map` to double each of the elements which are then stored into a vector with the `collect()` method. 

## Closures in Rust 

A closure is a special kind of anonymous function that can capture variables from its surrounding scope. There are 
three types of closures: 

1. `Fn`: Immutable borrow of captured variables.
2. `FnMut`: Mutable borrow of captured variables. 
3. `FnOnce`: Consumes captured variables. 

A simple closure could look like the following: 
```rust
fn main(){
    let x = 5;
    let add = |y| x + y; // captures a variable y 
    println!("Result: {}", add(4));
    // Result: 9
}
```
As seen to capture a variable you will need to use the `||` operator. 

### Move!
If you would like to force the closure to take ownership of the captured variable, such as spawning 
threads you will need to use the keyword `move`. Consider the following example: 

```rust 
use std::thread;

fn main() {
    // Data to be moved into the thread
    let data = vec![1, 2, 3, 4, 5];

    // Create a new thread and move the data into it
    let handle = thread::spawn(move || {
        // Inside the thread, we have ownership of `data`
        for &num in &data {
            println!("Thread: Got number {}", num);
        }
    });

    // Main thread continues to execute concurrently with the new thread

    // Wait for the new thread to finish
    handle.join().expect("Failed to join the thread");

    // Attempting to access `data` here would result in a compilation error
}
```

### Annotating 

You may also choose to annotate the closure's parameters and return type. 
```rust 
let closure = |x: i32, y: i32| -> i32 { x + y };
```

### Closures as Arguments 

You may also choose to have a closure used as a parameter type in a function, this is common with iterator methods 
where they take in a closure. To do so define a generic type where you will define it as one of the closure types 
mentioned earlier. 

```rust 
fn do_something<F>(i: i32, closure: F) -> i32 
where F: Fn(i32) -> i32{
    closure(i)
}


fn main() {
    let result = do_something(24, |x| x * 2);
    println!("Result: {result}");
    // Result: 48
}
```