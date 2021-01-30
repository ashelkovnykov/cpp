# Concepts Library

This library demonstrates some of the core C++ concepts. Some of these concepts are so crucial that their documentation is found in the root documentation folder.

## `main` Function

The designated entry point to a program that is executed in a hosted environment (i.e. within an OS) is the `main` function (freestanding programs \[e.g. bootloaders, OS kernels, etc.\] have implementation-defined entry points).

There are 2 common forms that the `main` function declaration takes:
```
int main()                          // No input to the program
int main(int argc, char *argv[])    // Command line input to program; argc is the number of arguments and argv are the arguments as C-style strings
```
Often times, an additional global variable `char *environ[]` is declared to access execution environment variables.

The `main` function has a few special properties:
* The name "main" is reserved for a function in the global namespace
* It cannot be overloaded
* It cannot be called recursively
* Its address cannot be taken
* Its return type cannot be deduced
* It cannot be declared with modifiers
* It does not need a return statement (default return value of `0`)
* There is an implicit call to `std::exit` after it returns a result

## Comments

"Comments" are little notes left in the source code to help explain what the program is doing in plain, human-readable language. Comments are removed from the source code early in the translation process. Thus, they do not affect the compiled executables. 

## Declarations & Definitions

Declarations are commands which introduce (or re-introduce) a name into the C++ program to refer to an entity. A declaration announces that an entity of some type exists, and that it has a particular name. However, this is not sufficient to use the entity in the program. The entity also requires a definition. A definition fully describes the nature of the entity (e.g. the contents of a class, the behaviour or a function, etc.). Every definition is a declaration, but not every declaration is a definition.

### One-Definition Rule

Only one definition of any object, function, class, enumeration, template, or concept is allowed per translation unit. Technically, multiple definitions of the listed entities are allowed for a program. However, the set of criteria to do so is so restrictive that it's effectively a single definition, and the program will operate as if it were.

#### ODR-use

An object is "odr-used" if it's used in a way which requires a definition to be present in the program. It's possible for objects to not be odr-used in a program, meaning that the program can compile and be used if it is linked with another file which provides the definition.

Informally, an object is "odr-used" if:
- its value is read
- its value is written
- its address is taken
- a reference is bound to it

Informally, a reference is "odr-used" if it's used and its referent isn't known at compile time.

Informally, a function is "odr-used" if:
- it's called
- its address is taken

There must be exactly one definition of each "odr-used" object and function in a program.

There must be a definition of each "odr-used" inline object and inline function in each translation unit.

## Initialization

"Initialization" of an object provides it with a value at the time of construction (i.e. declaration).

### Order of Initialization

Objects with automatic storage duration are initialized whenever program execution enters their scope. Objects with dynamic storage duration are initialized explicitly by the user. Objects with static storage duration are initialized as a part of the program startup, before the execution of the `main` function begins. Objects with thread storage duration are initialized as a part of thread launch, before the execution of the thread begins.

The initialization of objects with static or thread storage duration occurs in two distinct phases, which also have their own sub-phases:
1. Static Initialization
2. Dynamic Initialization

#### Static Initialization

Objects which are statically initialized are either constant initialized or zero initialized.

Constant initialization occurs during compile time. The compiler will search for objects which have fully deterministic values. These pre-computed object representations are stored as a part of the program so that their values are intrinsically loaded during program execution.

If an object cannot be constant initialized, it is instead zero initialized during this phase. These objects are then dynamically initialized.

#### Dynamic Initialization

After static initialization occurs, dynamic initialization using one of the initialization types detailed below occurs for all objects with static or thread storage duration that were not constant initialized.

Most such objects have their initializations sequenced in the exact order that their definitions appear within a single translation unit (objects have no sequencing between translation units). Some inline objects or objects created through a templated class may be sequenced earlier or later.
 
### Types of Initialization

There are eight types of initialization in C++:
1. Zero Initialization
2. Default Initialization
3. Value Initialization
4. Direct Initialization
5. Copy Initialization
6. Aggregate Initialization
7. Reference Initialization
8. List Initialization

#### Zero Initialization

Zero initialization has no syntax of its own. Instead, zero initialization occurs under certain circumstances when performing another kind of initialization. Default, value, aggregate, and list initialization may result in zero initialization.

Objects with non-union class type have all base classes and non-static data members zero initialized. Constructors are ignored and all padding is initialized to zero bits.

Objects with union type have the first non-static member zero initialized and all padding is initialized to zero bits.

Objects of array type have all elements zero initialized.

Objects of primitive type are initialized by the integer `0` converted to the appropriate type.

#### Default Initialization

Default initialization occurs when an object is constructed without an initializer. This occurs in the following situations:
- An object with automatic, static, or thread storage duration is declared without an initializer
- An object with dynamic storage duration is created by a `new` expression without an initializer
- A base class or non-static data member is not mentioned in the constructor

Objects with class type are subjected to overload resolution against an empty parameter list, and the selected constructor is called to provide an initial value for the new object.

Objects with array type have each element independently default initialized.

Objects with primitive type are initialized to indeterminate values: they keep whatever data happens to be in the storage location assigned for the object.

Objects which are `const`-qualified cannot be default initialized unless they are of class type and have a user-defined default constructor.

#### Value Initialization

Value initialization occurs when an object is constructed with an empty initializer. This occurs in the following situations:
- A nameless temporary object is created with an empty initializer
- An object with automatic, static, or thread storage duration is declared with an empty initializer
- An object with dynamic storage duration is created by a `new` expression with an empty initializer
- A non-static data member is initialized by an empty initializer

Objects with class type with no default constructor or a user-defined default constructor are default initialized. Objects with class type and an implicit default constructor are zero initialized, then default initialized.

Objects with array type have each element independently value initialized.

Objects with primitive type are zero initialized.

#### Direct Initialization

Direct initialization occurs when an object is constructed with an explicit set of construction arguments. This occurs in the following situations:
- A nameless temporary object is created with a non-empty initializer
- A nameless temporary object is created by a functional or static cast
- A primitive object with automatic, static, or thread storage duration is declared with a single brace-enclosed initialization value
- An object with automatic, static, or thread storage duration is declared with a non-empty initializer
- An object with dynamic storage duration is created by a `new` expression with a non-empty initializer
- A base class or non-static data member is initialized by a non-empty initializer

Objects initialized through direct initialization receive the explicit value provided, except for in the following situations:
- Elements of array objects without initializers are value initialized
- Objects with class type use the appropriate constructor, as opposed to the raw initialization arguments provided
- If the type of the initialization value does not match the type of the object, either the appropriate conversion will occur or an error will occur during compilation

#### Copy Initialization

Copy initialization occurs when an object is constructed from another object. This occurs in the following situations:
- An object with automatic, static, or thread storage duration is declared with an initializer following an equals sign (`=`)
- An argument is passed to a function by value
- A function returns an object by value
- An exception is thrown/caught by value
- As a part of aggregate initialization, when initializing multiple elements using a single object

Objects of class type select the appropriate constructor, likely the special copy constructor. All other types of objects copy their value from the given object, which may or may not need to undergo conversion first.

##### Copy Elision

Copy elision omits copy and move constructors for class objects in certain situations, resulting in zero-copy pass-by-value semantics. In such an event, the object is constructed directly into its storage. When copy elision occurs, the target object is treated as another way to refer to the same object. Destruction of the object occurs at the later of the two times when the object may be destroyed (depending on the storage duration of the two identifiers). Multiple instances of copy elision may be chained together. In certain circumstances, copy elision is mandatory according to the C++ standard. In other cases, it is an implementation-defined optional optimization. For more information, see [the C++ standard](https://en.cppreference.com/w/cpp/language/copy_elision).

#### Aggregate Initialization

Aggregate initialization occurs when an object with aggregate type is initialized from a brace-enclosed list of one or more construction arguments. A type is an aggregate if:
- It's an array; OR
- It's a class; AND
  - It has no private/protected non-static members
  - It has no user-defined or inherited constructors
  - It has no virtual, private, or protected base classes
  - It has no virtual member functions
  
Each array element (if the object is an array) or direct public base/non-static data member (if the object is a class) is copy initialized in order from the corresponding clause of the initializer list (Static data members and unnamed bit-fields are skipped). Implicit conversions are allowed. The initializer list can contain nested initializer lists (e.g. when initializing a base class of a class). If the object being initialized is an array of unspecified size, the number of clauses in the initializer list determines the size of the array. The number of clauses in the initializer list may not exceed the number of elements/members that need to be initialized. If the number of clauses is insufficient, the remaining elements/members are initialized by their default member initializers, otherwise they're initialized by empty initializer lists. Arrays of regular and wide characters can be initialized from string literals.

#### Reference Initialization

Reference initialization occurs when a reference to an object is bound. The rules are very specific, but quite intuitive. For more information, see [the C++ standard](https://en.cppreference.com/w/cpp/language/reference_initialization).

#### List Initialization

List initialization occurs when an object of non-aggregate type is initialized from a brace-enclosed list of construction arguments. List initialization always degenerates to another type of initialization. The specific rules governing it are very convoluted, though mostly intuitive. For more information, see [the C++ standard](https://en.cppreference.com/w/cpp/language/list_initialization).

## The `using` Command

The `using` command has two uses, called the "using declaration" and the "using directive".

### Using Declaration

The `using` command can be used to introduce names that are defined elsewhere into the current declarative region. When this is done, it's called a "using declaration". It has three uses:

* Introduce namespace members into the current namespace or block scope
* Introduce enumerators into namespace, block, or class scope
* Introduce base class members into derived class definitions

#### Introducing Namespace Members and/or Enumerators

Each declarator in the "using declaration" introduces one name at a time (e.g. if a "using declaration" introduces a enumeration, it does not introduce each of the enumerations enumerators into the present scope).

Names introduced into a namespace, block, or class scope by a "using declaration" can be used just like any other names, including qualified lookup from other scopes. All regular restrictions on declarations apply (e.g. a "using declaration" cannot introduce a namespace member and entity type as an existing member of the current scope). Undefined members introduced this way cannot be defined in the current scope. Introducing a function or function template with the same name, return type, and parameter list is ill-formed behaviour.

Note: if a "using" declaration is used to introduce a namespace member, and that namespace is later extended to include additional members with the same name, it does not affect which member was introduced.

#### Introducing Base Class Members

A "using declaration" can be used to introduce base class members into a derived class definition. For example, this can be done to expose a protected member of a base class as a public member of a derived class. If the derived class already has a member with the same name, parameter list, and/or qualifications, then the derived class member overwrites the introduced base class member. If the introduced base class member is an overloaded function, then all base class member functions with that name are introduced.

A "using declaration" can refer to base class constructors and assignment operators, but not destructors or member template specializations.

### Using Directive

The `using` command can be used to make all of the members of a namespace available in the current namespace or block scope. When this is done, it's called a "using directive". From the point of view of unqualified name lookup, every name from the introduced namespace is treated as if it were declared in the nearest namespace scope which encloses both the current namespace/block and the namespace being imported.

Unlike the "using declaration", the "using directive" does not add any names into the current declarative region. Therefore, the introduced names do not cause naming conflicts, as all conflicts are automatically resolved by nesting scopes.

"Using directives" are transitive: if a "using directive" introduces a namespace A which itself contains a "using directive" for some other namespace B, then the effect is as if the "using directive" from namespace A is present in the current scope.

If a namespace that is imported using a "using directive" is later extended to include new members, they **are visible** in the current scope (unlike a "using declaration").

## Exceptions

Exception handling and exceptions provide a way to transfer control and information (respectively) when an error occurs (technically, that's not the only purpose for which they can be used, but it's C++ convention that this is their intended/valid use-case). Exceptions are "thrown" (generated) up the call stack and need to be "caught" (processed), or else the program will terminate with an "uncaught exception" error.

Exceptions are generated by the `throw` command and caught by `try-catch` blocks. There are numerous classes of exception which encapsulate various data used to process them within a `catch` block.

Functions and programs as a whole can make various exception guarantees:
- Nofail: The function always succeeds
- Nothrow: The function never throws exceptions (i.e. errors are either reported through other means or concealed)
- Strong exception guarantee: If the function throws an exception, the program will return to the state directly before the function call
- Weak exception guarantee: If the function throws an exception, the program will be left in a valid state
- No exception guarantee: If the function throws an exception, the program may be in an invalid state (e.g. resource leaks, memory leaks, memory corruption, etc.)

## Undefined Behaviour

The C++ standard precisely defines the observable behaviour of every C++ program, except for five kinds of program.

### Ill-Formed Programs

Ill-formed programs have syntax or diagnosable semantic errors. A C++ compiler is required to issue a diagnostic warning/error, even if it's capable of assigning meaning to the code.

### Ill-Formed Programs (No Diagnostic Necessary)

Ill-formed programs with undiagnosable semantic errors do not require the C++ compiler to issue a diagnostic.

### Implementation-Defined Behaviour

The behaviour of the program varies between compiler implementations. The compiler is required to document this behaviour (e.g. number of bits in a byte).

### Unspecified Behaviour

The behaviour of the program varies between compiler implementations. The compiler is not required to document this behaviour (e.g. order of evaluation of function arguments).

### Undefined Behaviour

There are no restrictions on the behaviour of such a program. The C++ compiler is not required to diagnose undefined behaviour and the program is not required to do anything meaningful.

There are several actions which can cause undefined behaviour.
* Signed overflow
* Access out of bounds
* Uninitialized scalars
* Forced casts
* Null pointer dereference
* Access to a pointer passed to `realloc`
* Infinite loop without side-effects
