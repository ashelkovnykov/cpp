# Scope

Each name that appears in the source code of a C++ program is valid in only part of the program. Furthermore, multiple entities may share the same name. The "scope" of an entity is the (possibly discontiguous) portion of the source code in which some entity can be referred to by its name. Outside of its scope, the name may be invalid or it may refer to another entity.

## Context

Prior to reading this document, reading the following documents is recommended to understand the exact meaning of the following terms:

* Statements

## Scope Rules

C++ uses "lexical" scoping, meaning that the scope of a name is determined by where it is defined. C++ uses a number of different scoping rules, each of which is explained in detail below.

### Block Scope

The scope of an entity introduced in a code block (compound statement) begins at declaration and ends at the end of the block.

The scope of objects declared in `if`, `switch`, `for`, and `while` initialization statements begins at declaration and ends at the end of the entire statement (including `else` blocks for `if` statements).

The scope of an exception caught inside of a `try` block begins at declaration and ends at the end of the exception handling statement (which may or may not be a compound statement). Therefore, the exception is not in scope in other exception handling blocks, nor in the enclosing block.

### Function Parameter Scope

The scope of a function parameter begins at declaration. If the function declaration is followed by the function body, then the scope of the parameter ends at the function body. Otherwise, it ends at the end of the function declarator.

### Function Scope

The scope of a label declared within a function begins at the beginning of the function body and ends at the end of the function body. Labels ignore nesting rules, so attempts to create a new label when one of the same name already exists in scope will result in a compiler error.

### Class Scope

The scope of an object declared inside of a class begins at declaration and is valid until the end of the class body, as well as in all function bodies (even if defined before declaration or outside of the class body), exception specifications, derived classes, and nested classes (if static).

Any time a class object is in scope, its members can be referred to using the `.`, `->`, and `::` operators.

### Enumeration Scope

The scope of an enumeration type begins at declaration and ends with the enclosing scope. If the enumeration is unscoped, then the scope of the enumerators begins at declaration and ends with the enclosing scope. Otherwise, the scope of the enumerators begins at declaration and ends at the end of the enumeration specifier.

While a scoped enumeration type is in scope, its enumerators can be referred to using the `::` operator.

### Template Parameter Scope

The scope of a template parameter begins at declaration and ends at the end of the smallest possible template in which it is declared. Template parameters follow regular nesting rules.

### Namespace Scope

Namespaces allow users to create custom named scopes and switch between them.

The scope of an entity declared in a named namespace block begins at declaration and extends through all similarly named namespace blocks (even if they are discontiguous). The `using` command can import all entities declared in a named namespace into the enclosing scope.

Entities declared within an unnamed or inlined namespace have scope which begins at declaration and ends with the enclosing scope.

### Global Namespace Scope

At the top level of a translation unit, there is a hidden, unnamed, top-most namespace known as the "global namespace" (e.g. where the `main` function is defined). The scope of entities in the global namespace begins at declaration and ends at the end of the translation unit.

## Nested Scopes

For all entities except labels, scopes are automatically nested. The innermost scope is always given priority, hiding the entity referred to by the other scope.

## Types of Entities

Scoping conflicts generally only occur between entities of the same type. For example, if some scope contains both an object named "A" and a class type "A", there will be no conflict. For more information, see the "Name Lookup" document.

## Point of Declaration

The point of declaration differs slightly for different kinds of entities.

For objects, the point of declaration is immediately after the declarator, prior to initialization (if any).

For classes and enumerations, the point of declaration is immediately after the identifier which names the class.

For enumerators and type aliases, the point of declaration is immediately after initialization.

For functions, the point of declaration is immediately before the function body.

For template parameters, the point of declaration is after the optional default argument.
