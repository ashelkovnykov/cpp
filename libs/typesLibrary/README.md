# Type Library

This library demonstrates the C++ type property and type specifiers.

"Type" is a property of C++ object, references, functions, and expressions. "Type" is a semantic interpretation of what the raw data stored, referenced, or returned represents. Furthermore, it restricts the type of operations which may be performed (e.g. cannot do addition with words).

## Static Type

The "static type" of a C++ entity is determined through analysis during compile-time. The static type does not change while the program is executing. Most entities have only static type.

## Dynamic Type

Polymorphic objects and the expressions which reference them have a "dynamic type": the most-derived type that can correctly refer to the object/expression. For example, consider the following code:
```
struct B { };
struct D: B {};

int main() {
    D d;
    B* ptr = &d;

    ...
}
```
The static type of `*ptr` is `B`, but the dynamic type is `D`.

## Incomplete Type

A type can be incomplete if the size and layout information for the type are not available to the compiler. The following are incomplete types:

- `void` (though it is a special case)
- Any class which has been declared but not defined
- Enumerations are incomplete from declaration until their underlying type is specified/inferred
- Arrays of unknown size
- Arrays of objects of incomplete type

In most use cases, a complete type is necessary (the full list is available in the C++ standard). If an incomplete type is used in such a case, it must be completed within the same translation unit.
