# Storage Duration

All C++ objects have a storage duration (the time from allocation to de-allocation) which determines their lifetime (the portion) of program execution over which they have a constant memory address and retain their values.

## Types of Storage Duration

There are four types of storage duration:

1. Automatic
2. Static
3. Dynamic
4. Thread

### Automatic Storage Duration

Objects with automatic storage duration are allocated at the beginning of an enclosing block and de-allocated at the end of this block. All local variables in block scope that are not explicitly declared with another type of storage duration have automatic storage duration.

### Static Storage Duration

Objects with static storage duration are allocated at the beginning of the program and de-allocated at the end. All variables declared in namespace scope have static storage duration unless they are explicitly declared with thread storage duration or dynamic storage duration. In addition, objects declared in block scope with the `static` keyword have static storage duration.

### Dynamic Storage Duration

Objects with dynamic storage duration are allocated and de-allocated by request using explicit commands in the program, as ordered by the user. Any object in any scope can have dynamic storage duration. The determining factor is whether the declaration uses dynamic memory allocation.

### Thread Storage Duration

Objects with thread storage duration are allocated when a thread begins and de-allocated when it ends. Each thread has its own instance of an object. Only objects explicitly declared with the `thread_local` keyword have thread storage duration.

## Lifetime

Every object and reference in C++ has a runtime property known as its "lifetime": the time between its creation and destruction. The lifetime of an object is a subset of its storage duration: there is time between storage being allocated for an object and the object being placed into the storage, as well as time between an object being destroyed and its storage being de-allocated.

### Objects

The lifetime of an object begins when:
- Storage with the proper size and alignment for its type is obtained AND
- Its initialization is complete

(Note: There are 3 exceptions to the above; see [the C++ standard](https://en.cppreference.com/w/cpp/language/lifetime) for details)

The lifetime of an object ends when:
- The object is destroyed (if it's not a class object) OR
- Its destructor is called (if it's a class object) OR
- Its storage is released or reused by another object 

#### Temporary Objects

Temporary objects may sometimes be created during expression evaluation (specifically, when a prvalue is materialized for use as a glvalue; see the expressions library README for details). All temporary objects are destroyed as the last step of evaluating the expression in which they were created. If multiple temporary objects were created, they are destroyed in reverse order of creation. There are only two exceptions to this rule, which can be found in [the C++ standard](https://en.cppreference.com/w/cpp/language/lifetime).

### References

The lifetime of a reference begins when its initialization is complete and ends when it is destroyed.

### Access Outside of Lifetime

In certain cases, it's possible to access the storage of an object during its storage duration but outside of its lifetime (before creation or after destruction). In almost all such cases, the behaviour is undefined. See [the C++ standard](https://en.cppreference.com/w/cpp/language/lifetime) for more details.
