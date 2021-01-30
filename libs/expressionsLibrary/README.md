# Expressions

This library documents C++ expressions.

C++ expressions are sequences of operators, conversions, memory allocations, and/or function calls which specify a computation. Expressions may produce a result and may generate side-effects.

## Types of Expressions

There are three types of expressions:
1. Primary Expressions
2. Unevaluated Expressions
3. Discarded-Value Expressions

### Primary Expressions

Primary expressions are expressions which are evaluated for their value. These are the expressions which are provided as arguments to functions and operators.

### Unevaluated Expressions

Unevaluated expressions are not evaluated at runtime, because their evaluations have meaning only at compile-time.

Example:
```
int n = sizeof(std::cout << "test");
```
The above line produces no console output. The value returned by the `sizeof` operator only has meaning during compile-time.

### Discarded-Value Expressions

Discarded-value expressions are evaluated for their side-effects only; any resulting value is discarded.

## Value Category

Every expression in C++ has two independent properties: type and value category. Value category determines what rules the compiler needs to follow when creating, copying, or moving the temporary values that result from evaluating an expression.

There are three fundamental value categories and two mixed value categories:

- Fundamental:
-- lvalue
-- prvalue
-- xvalue
- Mixed:
-- glvalue
-- rvalue

### glvalue

The name "glvalue" stands for "generalized lvalue". Both lvalue and xvalue expressions are glvalue expressions. They have the following properties:

- Can be implicitly converted to rvalue
- Can be polymorphic (can have a dynamic type which may or may not be the same as the static type)
- Can have incomplete type

### rvalue

The name "rvalue" is a layover from earlier languages, where such expressions always appeared as the right-hand operands of assignment operators. Both prvalue and xvalue expressions are rvalue expressions. They have the following properties:

- Cannot be used as input to the address-of operator (`&`)
- Cannot be the left-hand operand of an assignment or compound assignment operation
- Can be used to initialize a rvalue reference or immutable lvalue reference

### lvalue

The name "lvalue" is a layover from earlier languages, where such expressions always appeared as the left-hand operands of assignment operators. Expressions with lvalue category refer to an object whose address in memory is directly accessible by the program. In addition to the properties they inherit from glvalue expressions, they have the following properties:

- Can have their address taken by the address-of operator (`&`)
- Can be used to initialize a lvalue reference
- If mutable, can be the left-hand operand of all assignment and compound assignment operators

### prvalue

The name "prvalue" stands for "pure rvalue". Expressions with prvalue category refer to an object whose address in memory is not directly accessible by the program (i.e. literals). In addition to the properties they inherit from rvalue expressions, they have the following properties:

- Cannot have dynamic type
- Cannot have incomplete type
- Cannot have abstract class type
- Cannot be qualified

### xvalue

The name "xvalue" stands for "expiring value". Expressions with xvalue category refer to an object being used at the end of its lifetime, right before destruction. These expressions typically occur when a sub-expression returns a rvalue reference. They have no additional properties beyond what they inherit from glvalue and rvalue expressions.

### Exceptions

- Non-static member functions and pointers to them are classified as prvalue expressions, but cannot be used anywhere except by the function call operator.
- Function calls returning `void` and casts to `void` are classified as prvalue expressions, but can only be used in contexts where the result object is discarded (e.g. alone on a line, as the left-hand operand of the comma operator (`,`), in the `return` statement of a function returning `void`, etc.). This is because `void` expressions have no result object.
- Bit fields have a completely unique set of rules, displaying properties of both glvalue and rvalue expressions.

## Literals

Literals are constant values embedded into the source code of a program. Numbers, characters, strings of text, and booleans are all literal values. In addition, users can define their own literals, though this is more akin to renaming regular numeric literals with a special customized suffix.

### String Literals

String literals in particular have a few noteworthy properties:
- String literals have the null character (`\0`) automatically appended to the end. Thus, the storage for the string `"Hello"` would be of type `const char[6]`, and the individual characters (in order) `H`, `e`, `l`, `l`, `o`, `\0`. A string may contain multiple null characters, in which case the raw object is actually a character array containing multiple strings.
- Adjacent string literals with only whitespace separating them are automatically concatenated during phase six of translation. If one of the strings has an encoding prefix and the other does not, then the encoding prefix is used. If both of the strings have encoding prefixes which do not match, then the resolution is implementation-defined.
- String literals have static storage duration, and thus exist for the entire runtime of the program. They may be stored in read-only storage, therefore attempting to modify them is undefined behaviour.
- Some compilers can combine storage for equal or overlapping string literals.

## Operators

Operators are built-in, language-level functions which tell the compiler to perform a specific mathematical or logical operation.

### Types of Operators

C++ has 7 types of operator:
1. Assignment
2. Increment/Decrement
3. Arithmetic
4. Logical
5. Comparison
6. Access
7. Miscellaneous

### Operator Precedence and Associativity

When a single expression contains multiple operators, there needs to be a system for determining which operator takes precedence (i.e. is evaluated first). Furthermore, there needs to be a system for determining input associativity for operators of equal precedence. Note that operator precedence is unrelated to the order of evaluation (see below). Operator precedence & associativity are compile-time concepts, whereas order of evaluation is a runtime concept. Furthermore, the C++ standard does not explicitly define operator precedence: it derives from the way that the standard defines operator behaviour.

When parsing an expression, an operator with higher precedence will be bound more tightly to its arguments than the operators of lower precedence (as if by parentheses). Operators with equal precedence will be bound to their arguments in the direction of their associativity: left-to-right or right-to-left. 

C++ has 16 levels of operator precedence. They are listed in order of descending precedence below. 
1. (left-to-right)
    - `::` (scope resolution)
2. (left-to-right)
    - `++` (postfix)
    - `--` (postfix)
    - `()` (functional cast)
    - `()` (function call)
    - `[]` (array subscript)
    - `.` (member access)
    - `->` (member access through pointer)
3. (right-to-left)
    - `++` (prefix)
    - `--` (prefix)
    - `+` (unary)
    - `-` (unary)
    - `!` (logical NOT)
    - `~` (bitwise NOT)
    - `()` (C style cast)
    - `*` (dereference)
    - `&` (address-of)
    - `sizeof`
    - `co_await`
    - `new`
    - `delete`
4. (left-to-right)
    - `*` (multiplication)
    - `/` (division)
    - `%` (modulo)
5. (left-to-right)
    - `+` (addition)
    - `-` (subtraction)
6. (left-to-right)
    - `<<` (bitwise left-shift)
    - `>>` (bitwise right-shift)
7. (left-to-right)
    - `<=>` (3-way comparison)
8. (left-to-right)
    - `<` (less-than)
    - `>` (greater-than)
    - `<=` (less-than or equal-to)
    - `>=` (greater-than or equal-to)
9. (left-to-right)
    - `==` (equal-to)
    - `!=` (not equal-to)
10. (left-to-right)
    - `&` (bitwise AND)
11. (left-to-right)
    - `^` (bitwise XOR)
12. (left-to-right)
    - `|` (bitwise OR)
13. (left-to-right)
    - `&&` (logical AND)
14. (left-to-right)
    - `||` (logical OR)
15. (right-to-left)
    - `?:` (ternary conditional)
    - `=` (assignment)
    - `+=` (sum compound assignment)
    - `-=` (difference compound assignment)
    - `*=` (product compound assignment)
    - `/=` (quotient compound assignment)
    - `%=` (remainder compound assignment)
    - `<<=` (bitwise left-shift compound assignment)
    - `>>=` (bitwise right-shift compound assignment)
    - `&=` (bitwise AND compound assignment)
    - `^=` (bitwise XOR compound assignment)
    - `|=` (bitwise OR compound assignment)
    - `throw`
    - `co_yield`
16. (left-to-right)
    - `,`

#### Examples

```
std::cout << a & b -> ((std::cout) << a) & b
*p++ -> *(p++)
a = b = c -> a = (b = c)
a + b - c -> (a + b) - c
delete++*p -> delete(++(*p))
a[1][2]++ -> ((a[1])[2])++
a.b++ -> (a.b)++
```

### Operator Overloading

By default, operators only accept built-in scalar types as input (e.g. `bool`, `char`, `int`, etc.). However, C++ allows the user to define new behaviour for operators so that they can accept user-defined types (i.e. class and enumeration types). This is called "operator overloading".

Though the standard does not make any restrictions on what the behaviour of an overloaded operator should be, a series of best-practices and unwritten expectations do exist and are documented in [the C++ standard](https://en.cppreference.com/w/cpp/language/operators).

Note: overloading operators does not affect their precedence or associativity.

#### Overloadable Operators

All operators except for the following can be overloaded:
- `::` (scope resolution)
- `.` (member access)
- `?:` (ternary conditional)
- `sizeof`
- `throw`
- `co_yield`

## Conversions

In C++ it is possible to convert objects of one type to objects of another type. This may happen implicitly (when an expression of one type is used in a context where an expression of another type is expected) or explicitly (when the user converts from one type to another using a conversion function).

### Implicit Conversions

An implicit conversion from some type T1 to T2 occurs in the following situations:
- When calling a function that expects T2 as input with T1 as an argument
- When calling an operator that expects T2 as input with T1 as an operand
- When initializing a new object of type T2 from T1
- When T1 is not an integer, but is used as the conditional for a `switch` statement
- When T1 is not a boolean, but is used as the conditional for an `if` statement

#### Numeric Promotion

In certain situations, smaller numeric types may be converted to larger numeric types while preserving the value (e.g. when performing an arithmetic operation on an object smaller than `int` \[all arithmetic operators do not take arguments smaller than `int`\]). The following are all valid numeric promotions:
- `bool`, `char`, `unsigned char`, `wchar_t`, `char8_t`, `char16_t1`, `short`, `unsigned short` -> `int`
- `char32_t` -> `unsigned int`
- An unscoped enumeration can be converted to its underlying type, which can then be promoted
- bit field -> `int` (if it can fit the entire value range of the bit field)
- bit field -> `unsigned int` (if it can fit the entire value range of the bit field)
- `float` -> `double`

#### Numeric Conversions

Unlike promotions, conversions may or may not change the value.

A boolean can be converted to any integer type. The literal `false` is converted to `0` and the literal `true` is converted to `1`.

Any integer type can be converted to any other integer type. If the value of the source object can be represented in the destination type, then it does not change. Otherwise, the new value is equivalent to the source value module 2^n, where n is the number of bits used to represent the destination type.

Any floating-point type can be converted to any other floating-point type. If the value of the source object can be represented in the destination type, then it does not change. If the value of the source object is between two values that are representable in the destination type, then the result is one of those two values (implementation-defined behaviour). Otherwise, the result is undefined behaviour.

An integer type can be converted to a floating point type. If the value of the integer can be directly represented as a floating point value, it is. If the value of the integer cannot be directly represented, either the closest lower or higher value is selected (implementation-defined behaviour).

A floating-point type can be converted to an integer type. The fractional part is discarded, and the remainder becomes the destination value. If the destination type cannot fit the value, the behaviour is undefined.

Any integer, floating-point, unscoped enumeration, or pointer type can be converted to boolean type. `0` becomes `false`, any other value becomes `true`.

The null pointer of any type can be converted to the null pointer of any other type. Any type of pointer can be converted to a pointer to `void`. A pointer to some derived class type can be converted to a pointer to its base class type. A pointer of any type can be cast to a more-qualified version of the same type (e.g. `char` -> `const char`, `const char` -> `volatile const char`, etc.). A pointer to non-throwing function can be converted to a pointer to a throwing function.

### `static_cast` Conversion

The exact conversion rules for `static_cast` are very specific. They are documented in full in [the C++ standard](https://en.cppreference.com/w/cpp/language/static_cast). In general, `static_cast` is a compile-time cast used for the following purposes:
- Down-casting classes
- Up-casting classes
- Converting to/from `void`
- Converting to/from `void*`
- Converting between enumerations

The resulting object of a conversion via `static_cast` will have a different bit representation than the source object. 

### `reinterpret_cast` Conversion

he exact conversion rules for `reinterpret_cast` are very specific. They are documented in full in [the C++ standard](https://en.cppreference.com/w/cpp/language/reinterpret_cast). In general, `reinterpret_cast` is a compile-time cast used when one wishes to perform a `static_cast` without modifying the underlying bit representation of the source object.

### `dynamic_cast` Conversion

The exact conversion rules for `dynamic_cast` are very specific. They are documented in full in [the C++ standard](https://en.cppreference.com/w/cpp/language/dynamic_cast). In general, `dynamic_cast` is a runtime cast used to convert up, down, or sideways along an inheritance hierarchy.

### C-style Conversion

It's possible in C++ to use C syntax for performing a conversion (i.e. `(new_type)expression`). When such a cast is encountered, the compiler will attempt to make one of the following five casts, in order of preference:
1. `const_cast<new_type>(expression)`
2. `static_cast<new_type>(expression)`
3. `const_cast<new_type>(static_cast<qualified_new_type>(expression))`
4. `reinterpret_cast<new_type>(expression)`
5. `const_cast<new_type>(reinterpret_cast<qualified_new_type>(expression))`
The first choice which satisfies the requirements of the cast operator is selected, even if it results in a compilation error.

### User-defined Conversion

Users can define their own conversion functions in C++ which can be used by the compiler for implicit conversions and calls to `static_cast`. 

## Evaluation

There are two components to evaluation of an expression: value computation (i.e. resolving the expression to a singular value) and side effect realization (e.g. I/O operations, accessing volatile glvalues, assignment, etc.).

### Order of Evaluation

Certain expressions are guaranteed to be evaluated before others (see the Sequencing section of the Threads documentation, or [the C++ standard](https://en.cppreference.com/w/cpp/language/eval_order)). However, there are many situations in which there is no specified order in which expressions are evaluated. The most common such situation is the order of evaluation of arguments to a function or operator. Consider the following example:
```
f1(f2(f3() + f4()), f5())
```

There are several possible orders in which the function calls may be evaluated, and this order may change between executions:
- `f5, f4, f3, f2, f1`
- `f5, f3, f4, f2, f1`
- `f4, f3, f5, f2, f1`
- `f3, f4, f5, f2, f1`
- `f4, f3, f2, f5, f1`
- `f3, f4, f2, f5, f1`
