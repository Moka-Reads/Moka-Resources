---
title : Smart Pointers
author : Mustafif Khan
level: 2
lang: rust
icon: devicon-rust-plain
---

## Smart Pointers?
Smart pointers in Rust provide enhanced memory management and ownership semantics. They offer more control and flexibility over how data is stored and accessed in memory. Unlike primitive data types that store values directly on the stack or heap, smart pointers wrap data and add additional capabilities to improve memory safety, concurrency, and code organization.

## Types of Smart Pointers
1. `Box<T>` - Ownership Transfer
    - Boxes provide heap allocation and automatic deallocation when they go out of scope.
    - Used to store data on the heap when:
        - The size is unknown at compile time.
        - The data must be transferred across threads.
    - Owned data can only have a single owner (Box).

Usage:
```rust
let b: Box<i32> = Box::new(5);
let c: i32 = *b; // c is now 5
```

2. `Rc<T>` - Reference Counting (Non-Mutable)
   - Stands for Reference Counted.
   - Allows multiple ownership of the same data with read-only access.
   - Suitable for cases where you need shared ownership without mutation.
   - Reference count is incremented and decremented as references are created and dropped.
   - Cannot be used for multi-threading.

Usage:
```rust
use std::rc::Rc;
let rc_data: Rc<i32> = Rc::new(42);
let cloned_rc = Rc::clone(&rc_data);
```

3. `Arc<T>` - Atomic Reference Counting (Thread-Safe)
   - Stands for Atomic Reference Counted.
   - Similar to `Rc` but can be used safely in multi-threaded environments.
   - Provides thread-safe reference counting using atomic operations.
   - Allows shared ownership with read-only access across threads.

Usage:
```rust
use std::sync::Arc;
let arc_data: Arc<i32> = Arc::new(42);
let cloned_arc = Arc::clone(&arc_data);
```

4. `Cell<T>` - Interior Mutability (Non-Thread-Safe)
   - Provides a way to mutate data inside an immutable value.
   - Useful for situations where you need to change data through an immutable reference.
   - Enables mutation even when the outer value is considered immutable.
   - Not suitable for multi-threading.

Usage:
```rust
use std::cell::Cell;
let cell_data = Cell::new(42);
cell_data.set(50);
let value = cell_data.get();
```

5. `RefCell<T>` - Interior Mutability with Borrow Checking (Non-Thread-Safe)
   - Similar to `Cell`, but with runtime borrow checking.
   - Allows multiple mutable references as long as Rust's borrowing rules are followed.
   - Allows mutation through interior mutability even when the outer value is considered immutable.
   - Ensures runtime panic if borrowing rules are violated.

Usage:
```rust
use std::cell::RefCell;
let refcell_data = RefCell::new(42);
let mut mutable_ref = refcell_data.borrow_mut();
*mutable_ref = 50;
```

6. Downsides:
   - `Box` is limited to single ownership.
   - `Rc` has runtime overhead due to reference counting.
   - `Arc` has additional overhead for atomic operations.
   - `Cell` and `RefCell` are non-thread-safe.

7. When to Use Which Smart Pointer:
   - `Box` for single ownership and dynamic allocation.
   - `Rc` for non-mutable shared ownership in a single thread.
   - `Arc` for shared ownership across multiple threads (thread-safe).
   - `Cell` for interior mutability in a single thread (non-thread-safe).
   - `RefCell` for interior mutability with borrow checking in a single thread (non-thread-safe).

8. `Deref`, `Drop`, and `DerefMut`:
   - Smart pointers can implement traits like `Deref` and `Drop`.
   - `Deref` allows smart pointers to behave like references.
   - `DerefMut` enables smart pointers with interior mutability to be mutable.
   - `Drop` allows custom cleanup when the smart pointer goes out of scope.
