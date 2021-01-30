# Entities

A C++ program accomplishes its computational task using several conceptual entities:

- Objects
- Values
- References
- Functions
- Enumerations
- Types
- Templates
- Namespaces

## Objects

Objects are the primary building block of a C++ program. Objects are created to store values and manipulated through functions/expressions.

### Properties

All objects have the following properties:

- Type
- Size
- Alignment
- Value
- Storage Location
- Storage Duration
- Lifetime
- Name (optional)

#### Type

Type is a semantic interpretation of what the raw data of the object represents. It also restricts the operations which may be performed on the object.

#### Size

The size of an object is the number of bytes in memory which are used to store its value. An object inherits this property from its type.

#### Alignment

The alignment of an object is the minimum number of bytes which must separate two successive addresses referring to objects of the same type. Alignment is always a power of 2. An object inherits this property from its type.

#### Value

The value of an object is the raw data that it holds. This could be a number, a word, a memory address, or something else entirely.

#### Storage Location

The storage location is a memory address which holds the value of the object. This memory location may or may not be accessible to the program.

#### Storage Duration

See the "Storage Duration" document.

#### Lifetime

See the "Storage Duration" document.

#### Name

An object may or may not have a name which the program uses to refer to it. For more information on names in C++, see the "Identifiers" document.

### Object Creation

Objects can be created explicitly using memory allocation functions or implicitly if such functions are not used. Objects which are created explicitly need to be destroyed explicitly as well, whereas objects which are created implicitly will be managed entirely by the compiler.

### Sub-objects

Class and array objects may have sub-objects: unique objects that live within the memory of another object.

## Values

Values are literals that have intrinsic meaning (e.g. `42`, `"text"`, `'a'`, `0xaeff9008`, etc.). They are assigned to objects and passed as input to functions/operators.

## References

References are aliases to existing objects. They allow multiple names to refer to the same object.

## Functions

Functions are subroutines of sequenced expressions that perform a specific task. These expressions are packaged as a named unit so that they may be reused.

## Enumerations

Enumerations are a distinct type whose possible values are restricted to a finite set of options. These options are usually explicitly named constants called "enumerators".

## Types

Types are named semantic interpretations of raw data. They provide meaning to otherwise arbitrary sequences of bits. C++ has several built-in types, but additional types are created when users define new classes.

## Templates

Templates are C++ entities that define families of classes, functions, types, variables, or concepts. They are parameterized by one or more parameters. When arguments are provided/deduced for a template parameter, an appropriately specialized member of the family is substituted.

## Namespaces

Namespaces are named scopes which allow users to explicitly group objects so that objects with the same name do not interfere with each other.
