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
