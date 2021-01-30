# Functions

Functions are C++ entities that associate a sequence of statements and zero or more parameters with a name. Using the name, the sequence of statements can be repeatedly called on a potentially changing set of parameters. A function terminates by either returning to the instruction that called it (potentially with some value) via a jump statement or by throwing an exception.

Function declarations may appear in any scope, but function definitions may only appear in namespace scopes.

Functions are not objects: there can be no arrays of functions, nor can functions be passed as arguments or return values. However, pointers and references to functions are allowed.

The type of a function depends on its return type, the number of function parameters, and their types. Therefore, it's possible to have multiple functions with the same name so long as their parameter counts/types are different (known as "overloading").

## Coroutines

Coroutines are functions that can suspend execution and resume again later. Coroutines are stackless: the data required by the function is not stored on the stack and they suspend execution by returning to the caller. The purpose of coroutines is to support asynchronous operations and lazy computations.

A function is a coroutine if it uses any of the following operators: `co_await`, `co_yield`, `co_return`. However, coroutines cannot use variadic arguments or placeholder return types. Furthermore, `constexpr` functions, constructors, destructors, and the main function cannot be coroutines.

There are three core components to the coroutine:
1. Promise object: The object which the coroutine promises to return, manipulated from inside the coroutine.
2. Coroutine handle: A handle used to refer to the coroutine from outside of the coroutine, to resume or cancel execution.
3. Coroutine state: A heap-allocated object which contains the coroutine arguments, local variables, promise object, and a representation of the point of suspension.

When a coroutine begins execution, prior to executing the function body it first:
- Allocates heap storage for the coroutine state
- Copies function arguments to the coroutine state
- Calls the constructor for the promise object

When a coroutine state is destroyed, due to either successful termination, early termination via handle, or uncaught exception, it:
- Calls the destructor of the promise object
- Calls the destructor or each argument
- Deallocates the heap storage of the coroutine state
- transfers execution back to the caller

## Lambda Expressions

Lambda expressions are anonymous, possibly unnamed functions with block scope. They are a convenient way to specify a sequence of statements which are:
- Trivial to understand and execute
- Need to be repeated many times during a short portion of runtime, then never again
- Need to be passed to another function to refine its behaviour

In C++, lambda expressions are also closures. However, their closure functionality is entirely optional.

### Closures

A closure is a special type of function which is linked with the environment in which it is declared. A closure can contain one or more “captures”: variables from a scope accessible by the function at declaration time. The function can access the values of these captured variables either by copy or by reference, even when invoked from outside of their scope.
