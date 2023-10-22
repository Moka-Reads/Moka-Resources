---
title: Understanding Memory Leaks
description: Lets take a look at memory leaks with Rust, Zig, C/C++
author: Mustafif Khan
icon: devicon-github-plain
date: 2023-09-27
tags: Zig, C
---
## Understanding Memory Leaks

A memory leak occurs when a computer program fails to properly clean up after itself when it no longer needs a piece of computer memory. This is similar to forgetting to put a toy or tool back in its proper place. As time passes, these forgotten memory blocks accumulate, causing the program to use more memory than necessary. If too much memory is leaked, it can negatively impact the program's performance or even cause it to crash due to insufficient memory for essential tasks. Therefore, just like tidying up after oneself, programs must clean up the memory they use to ensure smooth operation.

Consider the following example (`simple_leak.c`): 

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory for an integer
    int *num = (int *)malloc(sizeof(int));

    if (num == NULL) {
        perror("Failed to allocate memory");
        return 1;
    }

    // Assign a value to the integer
    *num = 42;

    // Simulate some operations with the allocated memory
    // ...

    // Forget to free the allocated memory
    // free(num);

    return 0;
}
```

In this example we allocate memory for a integer pointer and assign it a number, however we never free the 
memory that it had allocated. If we compile this program using `clang` with warnings all set, let's see if the 
compiler advises us about this: 

```shell
$ clang -Wall simple_leak.c -o simple_leak
# file compiled fine...
```

But how do we see if this is an issue and that we had lost memory from the heap? Well we will make use of the tool
`valgrind` which provides the flag `--leak-check=full` that allows us to check for leaks from the binary. 

```shell
$ valgrind --leak-check=full ./simple_leak
==59580== Memcheck, a memory error detector
==59580== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==59580== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==59580== Command: ./simple_leak
==59580== 
==59580== 
==59580== HEAP SUMMARY:
==59580==     in use at exit: 4 bytes in 1 blocks
==59580==   total heap usage: 1 allocs, 0 frees, 4 bytes allocated
==59580== 
==59580== 4 bytes in 1 blocks are definitely lost in loss record 1 of 1
==59580==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==59580==    by 0x109168: main (in simple_leak)
==59580== 
==59580== LEAK SUMMARY:
==59580==    definitely lost: 4 bytes in 1 blocks
==59580==    indirectly lost: 0 bytes in 0 blocks
==59580==      possibly lost: 0 bytes in 0 blocks
==59580==    still reachable: 0 bytes in 0 blocks
==59580==         suppressed: 0 bytes in 0 blocks
==59580== 
==59580== For lists of detected and suppressed errors, rerun with: -s
==59580== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```

As you can see the report given to use shows that we definitely lost 4 bytes of memory, and this was found with
an allocation from `malloc` in the `main` function in the `simple_leak` binary. 

This is kind of worrying that is happening under our radar, so what if we tried to do something similar in Zig? 
Will it give us an error for this memory leak? Let's see 

```zig
const std = @import("std");

pub fn main() !void {
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    defer {
        const check = gpa.deinit();
        if (check == .leak) @panic("Memory Leak Occured!");
    }
    const allocator = gpa.allocator();

    const ptr = try allocator.alloc(i32, 1);
    // assign value to ptr
    ptr[0] = 42;
    // forgot to free oh no!
}
```

In our example we are using a general purpose allocator to allocate an integer pointer, the 
general purpose allocator also checks if there has been any memory leaks when it is deinitialized. 
If it does we panic!!! As you can see with our allocator we allocated an integer and we forgot to free 
it. Let's see what happens when we compile and run the program: 

```shell
$ zig build-exe simple_leak.zig 
$ ./simple_leak
error(gpa): memory address 0x7f0cad28c000 leaked: 
simple_leak.zig:11:36: 0x220fd5 in main (simple_leak)
    const ptr = try allocator.alloc(i32, 1);
                                   ^
/snap/zig/8241/lib/std/start.zig:574:37: 0x220ebe in posixCallMainAndExit (simple_leak)
            const result = root.main() catch |err| {
                                    ^
/snap/zig/8241/lib/std/start.zig:243:5: 0x2209a1 in _start (simple_leak)
    asm volatile (switch (native_arch) {
    ^

thread 145846 panic: Memory Leak Occured!
simple_leak.zig:7:29: 0x2210e0 in main (simple_leak)
        if (check == .leak) @panic("Memory Leak Occured!");
                            ^
/snap/zig/8241/lib/std/start.zig:574:37: 0x220ebe in posixCallMainAndExit (simple_leak)
            const result = root.main() catch |err| {
                                    ^
/snap/zig/8241/lib/std/start.zig:243:5: 0x2209a1 in _start (simple_leak)
    asm volatile (switch (native_arch) {
    ^
???:?:?: 0x0 in ??? (???)
Aborted (core dumped
```

Although we didn't see any compile errors, when we run our program which the allocators allocate 
during runtime we are able to detect this memory leak, and return a runtime error. It also shows where 
the allocation happened, in best practice it is best to use the `defer` keyword after you allocate so 
you are able to free it once it goes out of scope. 

