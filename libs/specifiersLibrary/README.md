# Specifiers

This library documents C++ specifiers that do not warrant their own library and are not best documented elsewhere.

Specifiers are keywords which explicitly specify a particular property of a C++ entity or modify its behaviour. For example, type specifiers declare the type of an object, and access specifiers declare the inheritance and visibility rules for class member objects (note that both of these specifiers are documented in separate modules: in the type and class modules respectively).

## `alignas`

The `alignas` specifier can be prepended to the declaration of an object or class to change its alignment property from the default value for its particular type. It takes as input either a constant expression which evaluates to an integer or a type.

If the alignment value is `0`, it is ignored. If the alignment value is negative, non-integer, or not a power of 2, then the program is ill-formed. If the alignment value is weaker than the default alignment for the object/class, then the program is ill-formed. 

Technically, the `alignas` specifier is an attribute (see below), but it has its own syntax.

## `inline`

The `inline` specifier can be prepended to the declaration of a function or object.

The original intent of the `inline` keyword was to hint to the compiler that inline substitution of a function is preferable to a function call; that is to say, instead of executing a jump CPU instruction to another part of the program, it is preferable to copy the CPU instructions of the function body into any location where the function would otherwise be called. Generally, this results in better performance but larger executable size. However, the `inline` keyword is non-binding, meaning that the compiler is free to make use of this hint or not. Furthermore, the compiler may choose to "inline" functions which are not `inline` specified.

Later, the meaning of the `inline` keyword was extended to mean that multiple definitions of a function are allowed, if the following conditions are met:
- A definition must be reachable from any translation unit which uses the function
- Each definition must appear in a different translation unit
- All definitions must be identical
- The function must be declared "inline" in each translation unit
- The function must have the same address in each translation unit
After the `inline` keyword was extended to have the above meaning, it became acceptable for objects to be marked "inline".

Some properties of "inline" functions/objects
- Static objects declared within an inline function definition are shared across all translation units (i.e. they all refer to the same object which resides in a single translation unit)
- Types defined within an inline function are identical in all translation units
- Functions defined inside of a class/union (member and friend) are implicitly "inline"
- Deleted functions are implicitly "inline"
- `const` qualified inline objects at namespace scope have external linkage by default

## `constexpr`

The `constexpr` specifier can be prepended to the declaration of a function or object to declare that it is **possible** to evaluate the value of the function/object at compile-time. Such functions/objects can be used anywhere that a constant expression is expected (e.g. when the declaring the size of an array).

To be declared with `constexpr`, an object must:
- Have one of the following types:
  - Any primitive type
  - Array of any primitive type
  - Reference
  - Class with either:
    - No private/protected non-static data members, no virtual/private/protected base classes, no virtual member functions, and default constructor/destructor
    - All non-static data members have primitive/`constexpr` type, all base classes are `constexpr`, `constexpr` constructor/destructor
- Be initialized at declaration by a constant expression

Non-primitive objects declared `constexpr` do not generate machine-code instructions for destruction, even if the destructor is non-trivial.

To be declared with `constexpr`, a function must:
- Not be a coroutine
- Have a return type that can be used with `constexpr` (see above)
- Have each parameter be of a type that can be used with `constexpr` (see above)
- Not contain any of the following in the function body:
  - A `goto` statement
  - A labelled statement
  - Definition of an object which isn't/could not be declared with `constexpr`
  - Definition of an object with static or thread storage duration

Even though `try` blocks and inline assembly instructions are allowed in `constexpr` functions, throwing exceptions and executing assembly is disallowed.

Functions and static class members declared with `constexpr` are implicitly "inline". All other objects declared with `constexpr` are implicitly `const` qualified.

## `constinit`

The `constinit` specifier can be prepended to the declaration of an object to declare that it has static or thread storage duration and is initialized by a constant expression. Unlike an object declared with `constexpr`, an object declared with `constinit` is not necessarily `const`-qualified and does not necessarily have constant destruction.

## `consteval`

The `consteval` specifier can be prepended to the declaration of a function to declare that it **must** be evaluated at compile-time to produce a constant. The requirements on a function to be declared with `consteval` are identical to those required for `constexpr`. A function declared with `consteval` is implicitly `constexpr` and therefore also "inline".

## `noexcept`

The `noexcept` specifier can be appended to the declaration of a function to inform the compiler that the function does/does not throw exceptions. This allows the compiler to enable optimizations for non-throwing functions, and enables the `noexcept` operator.

## Placeholder Type Specifiers

Placeholder type specifiers can be used to tell the compiler that the type of an object, function, or template parameter should be deduced automatically. For objects, the type is deduced from the initializer. For functions, the return type is deduced from the return statement. For template parameters, the type is deduced from the argument.

### `decltype` Specifier

The `decltype` specifier returns the type of an input object or expression. It's useful for declaring types that are difficult, impossible, or cumbersome to declare using standard notation (e.g. lambda-function types, parameterized template types, etc.).

If the argument to the `decltype` specifier is an entity, its type is returned. If the argument to the `decltype` specifier is an expression with type `T`, then type returned depends on the value category of the expression:
- `T&&` for an xvalue
- `T&` for an lvalue
- `T` for a prvalue

## Attributes

Attributes are a C++ standard specified method for different compilers to introduce implementation-specific specifiers. Attributes can be used almost anywhere and applied to almost anything in C++: types, functions, objects, names, blocks, translation units, other attributes, etc. That isn't to say that each attribute can be applied to any language construct, but that any language construct can have an attribute be applied to it.

In general, attributes apply to the directly-preceding entity.

The following are all attributed specified by the C++ standard:
- `noreturn`: indicates that a function does not return
- `carries_dependency`: indicates that the dependency chain in release-consume memory order propagates in and out of the function
- `deprecated`: indicates that the use of a function/object is allowed but not recommended
- `fallthrough`: indicates that fall-through from a previous case statement is intended and should not issue a compiler warning
- `nodiscard`: indicates that the compiler should issue a warning if the return value of this function is discarded
- `maybe_unused`: indicates that the compiler should suppress warnings about unused entities
- `likely`/`unlikely`: indicates that the compiler should optimize for the case where some execution path through a statement is particularly likely/unlikely
- `no_unique_address`: indicates that a non-static data member does not need to have an address distinct from all of the other non-static data members in the class
- `optimize_for_synchronized`: indicates that the compiler should optimize a function for synchronized execution in a multi-threaded environment
