# Classes

This library demonstrates C++ classes.

Classes are a combination of a user-defined type and a user-defined template for generating objects. They are a data structure for storing information and functionality: they logically group together objects, types, and functions.

When declaring a class, either of the keywords `struct` or `class` may be used. The only differences between these two keywords are the default access and inheritance modes of the declared class (struct = public, class = private).

There are many constructs that may go into the definition of a particular class, some of which are mandatory and some of which are optional. These constructs allow for very fine control over the exact behaviour of a class instance throughout its lifetime. The definition of any particular class could be very complicated. These constructs are outlined and elaborated upon below.

## Data Members

Classes may contain “data members”. These are objects that an instance of the class owns and contains within itself. Thus, a particular class object may have one or more sub-objects which are stored within the storage allocated for the class object.

In addition, the class definition may define “static data members”. Static data members are not owned by any one particular class instance; they are independent objects with static or thread storage duration. There is only one instance of a class static data member for the entire program (unless the static data member is thread local, in which case there is only one instance per thread). Static data members do not provide any new functionality: instead, their purpose is for logical convenience. They define objects of shared interest amongst all instances of a class in a manner that specifies this as their primary purpose.

Non-static data members may be initialized by a constructor, by a default member initializer, or may remain uninitialized (so long as they are initialized some time before access).

### Bit Fields

Integer class data members (`char`, `short`, `int`, `long`) can be constrained to a particular number of bits. Such a data member is known as a "bit field". The range of values which can be stored in a bit field are constrained by the smaller of the type or the number of bits available. For example, the bit field `unsigned char : 3` can hold values in the range `[0..7]`, and the bit field `unsigned char : 10` can hold values in the range `[0..256]`.

Multiple bit fields are often packed together to save space. For example, two bit fields declared back-to-back, one 2 bits in size and one 5 bits in size, would take up a single byte: the 7 bits of the two bit fields stored adjacently, and one bit left unused. Since a bit field may begin in the middle of a byte, the address of a bit field cannot be taken. Therefore, pointers and mutable references to bit fields are invalid.

## Member Functions

Classes may contain “function members”.  These are functions that may only be called through a reference to a particular class instance, often because their side effects and return value depend directly on the present state of the object.

In addition, the class definition may define “static member functions”. Static member functions do not operate on the data of any particular class object. Thus, the can only access static data members or other static function members. Their typical purpose is to setup internal class settings prior to the creation of any class instances (e.g. setup initial settings for a class factory).

Member functions can be “reference qualified”. This allows for member functions to be overloaded so that their behaviour is different when they are called for an lvalue class object vs. a rvalue class object.

## `this` Pointer

Within the scope of a class object, all class instances have access to the implicit pointer `this` which points to the object itself. If the object is qualified, so too then is the pointer.

## Nested Classes

A “nested class” is one which is defined within the scope of another class. A nested class can access all the same entities of the parent class that a data member of the parent class could, but is otherwise independent.

## Member Access

Every data member and member function of a class has an associated access level. Member access specifiers allow the author of a class to control which members are accessible to users of the class (the interface) and which members are for internal use only (the implementation).

To clarify, member access specifiers control which class members can be accessed from outside of the class scope. Within class scope, all members have access to all other members.

There are three levels of member access:
1. Public
2. Protected
3. Private
    
### Public Member Access

Public members form the interface of the class. They are accessible from anywhere outside of class scope.

### Protected Member Access

Protected members form the extended interface of the class to its derived classes. They are accessible to any derived class.

### Private Member Access

Private members form the implementation of the class. They are accessible only to the class itself.

### Friends

In the body of a class, external functions, classes, and templates can be declared “friends” of the class using the friend keyword. friendly function or class is allowed to access protected and private members of the class which grants them friendship.

When declaring friendship, unless the scope is explicitly specified, only the innermost non-class scope is checked. Friendship is not transitive: the friends of your friends are not your friends. Friendship is not inherited: the children of your friends are not your friends.

## Derived Classes

During definition, a class may be declared to “derive” from one or more “base” classes. If a class C derives from a class B which derives from a class A, then C is said to derive from both B and A: B is a direct base class of C, and A is an indirect base class of C. Each direct and indirect base class is present as an implicit base class sub-object within a derived class. These base class sub-objects need to be initialized just as any data member would, usually by a constructor.

### Virtual Base Classes

Consider the case that there exist the classes A, B, C, and D. D derives from B and C, and both B and C derive from A. In such a case, any instance of D will contain two unique base class sub-objects of type A, one from each of B and C. Clearly, in some cases this behaviour is undesirable. To prevent such behaviour, the keyword virtual must be used.

If class B and C are specified to derive from a virtual class A, this means that the most derived object which derives from B and/or C may have only one base class sub-object of type A.

All virtual base class sub-objects are initialized before any non-virtual base class sub-objects.

### Inheritance

When classes derive from one another, they form an inheritance hierarchy, known as such because the derived class inherits the members of the base classes. There are three types of inheritance that a class can declare when it derives from a base class: public, protected, and private.

#### Public Inheritance

When one class derives from another using public inheritance, all public members of the base class are accessible as public members of the derived class and all protected members of the base class are accessible as protected members of the derived class. Public inheritance captures the “is-a” relationship between classes: a bus is a car, a circle is a shape, a box is a cube, etc. References and pointers to such derived objects are expected to be usable by any code that expects a pointer or reference to one of its public bases.

#### Protected Inheritance

When one class derives from another using protected inheritance, all public and protected members of the base class are accessible as protected members of the derived class. Protected inheritance enforces a more controlled polymorphism: the “is-a” relationship is only valid within the body of the derived class.

#### Private Inheritance

When one class derives from another using private inheritance, all public and protected members of the base class are accessible as private members of the derived class. Private inheritance enforces an even more controlled polymorphism than protected inheritance: the “is-a” relationship is only valid within the body of the derived class, and not any further derived classes. Typically, the polymorphism relationship enforced by private inheritance is so strict that it would be better to use a data member. However, in some cases private inheritance is preferable (e.g. some aspect of the base behaviour needs to be overridden).

### Virtual Functions

“Virtual functions” are functions whose behaviour can be overridden within derived classes. To override a virtual function, the definition in the derived class must have:
- The same name
- The same parameter list
- The same qualifiers
- Covariant return type
    
Otherwise, the definition hides the existing function from the base class within the scope of the derived class. Obviously, only non-static member functions can be virtual.

A virtual function doesn’t need to be visible or accessible to be overridden. The behaviour of a virtual function is preserved, no matter what type of pointer or reference is used to refer to the object.

#### override

The override specifier denotes that the preceding function is virtual and that the following function definition overrides any existing definitions inherited from one or more base classes.

#### final

The final specifier locks the definition of a function for all future derived classes: they can no longer override the existing definition.

Virtual functions called during object construction or destruction are considered final: more-derived classes are considered to not exist.

### final

Just like virtual functions, classes can be declared final too. A class that is declared with the final specifier cannot have another class derive from it.

### Empty Base Optimization

If a base class contains no non-static data members, often times the compiler will optimize the base class sub-object out of any derived classes.

## Abstract Classes

An “abstract class” is one which cannot be instantiated, but can be used as a base class. Any class that defines or inherits a virtual function which has a “pure virtual” definition (ex. f() = 0) is considered abstract. These classes are used to represent general concepts which need to be made concrete through further definition.

No instance of an abstract class can exist. Abstract classes cannot be used as parameter types, return types, or conversion types; however, pointers and references to abstract classes are valid.

## Local Classes

Class definitions may appear inside the body of a function. If they do so, they are known as “local classes”. Local class types exist only within the function scope and are not accessible from without. In addition, local classes have a subset of the functionality of full classes:
- No static data members
- Cannot use templates
- Cannot use friend templates
- Cannot have friend functions
- Member functions have no linkage
- Member functions must be defined entirely within the class body

## Constructors

A constructor is a special non-static member function that's used to initialize instances of the class type. The arguments passed to the parameter list of a constructor are used to initialize direct bases, virtual bases, and non-static data members.

Constructors have no names and cannot be invoked directly: they are invoked during initialization. If more than one constructor is available, the compiler selects 

Constructors have a very specific syntax: `[class name] [parameter list] [member initializer list] [constructor body]`
- Class name: The name of the constructor function is exactly the same as the name of the class type (case sensitive).
- Parameter list: A regular function parameter list.
- Member initializer list: Takes the form `: [non-static data member or base name]([initializer list]), ...`. All direct bases, virtual bases, and non-static data members are initialized by the end of the member initializer list, even if they are not specified.
- Constructor body: A regular function body which may perform additional actions (note that all direct bases, virtual bases, and non-static data members are initialized before the constructor body begins execution).

Base and non-static member initialization occurs in the following order, regardless of the order of the member initializer list:
1. Virtual bases in depth-first, left-to-right declaration traversal
2. Direct bases in left-to-right declaration traversal
3. Non-static data members in order of declaration

If a non-static data member both has a default member initializer and appears in the member initializer list of a constructor, the constructor takes precedence. 

A constructor cannot be a coroutine. A constructor cannot be `const`, `volatile`, or reference qualified.

### Delegating Constructor

A constructor can replace the bases and members in a member initializer list with a constructor call (to another constructor: recursion is not allowed). Such a constructor is called a "delegating constructor" because it delegates initialization to another constructor. Delegating constructors are useful for classes that can be initialized through many different combinations of arguments, but the initialization logic is identical and relies mostly on default parameter values.

### Default Constructor

The "default constructor" is a constructor which can be called with no arguments, either because it doesn't require any or because all parameters have default arguments.

If a user-defined constructor is not declared for a class, the compiler will automatically declare a default constructor (the user can also force the compiler to declare a default constructor, even if he/she has defined a constructor). The compiler-declared default constructor is defined with empty member initializer list and empty body. Note that a user-defined empty default constructor and a compiler defined default constructor may behave differently in certain situations (depending on the compiler implementation).

An automatically declared default constructor is defined as deleted if one or more of the following conditions is true:
- The class has a member of reference type without a default initializer
- The class has a `const` member without a default initializer
- The class has a member without a default initializer whose default constructor is deleted, ambiguous, or inaccessible
- The class has a direct or virtual base whose default constructor is deleted, ambiguous, or inaccessible
- The class has a direct or virtual base whose destructor is deleted or inaccessible

### Copy Constructor

A copy constructor is a constructor which is called when an object of class type is initialized from an lvalue object of the same class type (either by direct initialization, pass-by-value function argument, or function return value). A copy constructor takes only one parameter: a (possibly-qualified) reference to an object of the same class type. A class can have multiple copy constructors (e.g. `T::T(&T)` and `T::T(const &T)`).

If a user-defined copy constructor is not declared for a class, the compiler will automatically declare a copy constructor (the user can also force the compiler to declare a copy constructor, even if he/she has defined a copy constructor). The definition for an automatically-defined copy constructor will copy all class bases and non-static data members in their initialization order using direct initialization.

An automatically declared copy constructor is defined as deleted if one or more of the following conditions is true:
- The class has a user-defined move constructor or move assignment operator
- The class has a non-static data member of rvalue reference type
- The class has a non-static data member whose copy constructor is deleted, ambiguous, or inaccessible
- The class has a direct or virtual base whose copy constructor is deleted, ambiguous, or inaccessible
- The class has a direct or virtual base whose destructor is deleted or inaccessible

### Move Constructor

A move constructor is a constructor which is called when an object of class type is initialized from an xvalue object of the same class type (either by direct initialization, pass-by-value function argument, or function return value). A move constructor takes only one parameter: a (possibly-qualified) rvalue reference to an object of the same class type. Move constructors "steal" the resources held by the argument rather than make copies of them, leaving the argument in a valid but indeterminate state. A class can have multiple move constructors (e.g. `T::T(&&T)` and `T::T(const &&T)`).

If a class has no user-defined copy constructor, destructor, copy assignment operator, or move assignment operator then the compiler will automatically declare a move constructor (the user can also force the compiler to declare a move constructor, even if he/she has defined a move constructor). The definition for an automatically-defined move constructor will perform member-wise move operations for all class bases and non-static data members in their initialization order using direction initialization with an xvalue argument.

An automatically declared move constructor is defined as deleted if one or more of the following conditions is true:
- The class has a non-static data member whose move constructor is deleted, ambiguous, or inaccessible
- The class has a direct or virtual base whose move constructor is deleted, ambiguous, or inaccessible
- The class has a direct or virtual base whose destructor is deleted or inaccessible

### Converting Constructor

By default, all constructors are "converting constructors": the constructors are considered during both direct initialization and copy initialization (as part of a user-defined conversion sequence). However, by prefacing the constructor declaration with the `explicit` keyword, the constructor becomes an "explicit constructor" which is only considered for direct initialization.

The above only applies to regular constructors; all move and copy constructors are converting constructors.

## Destructor

A destructor is a special class member function that is called when the lifetime of an object ends (e.g. program termination, thread exit, end of scope, delete expression, end of expression, etc.). The purpose of the destructor is to free the resources that an object may have acquired during its lifetime. After the body of the destructor is executed, the compiler calls the destructors for all non-static, non-variant members of the class in reverse order of declaration, followed by the destructors of all direct, non-virtual bases, followed by the destructors of all virtual bases.

A destructor cannot be a coroutine. Deleting a derived object through a pointer to one of its base classes is undefined behaviour unless the destructor is virtual. For this reason, it's a common rule that a destructor should be either virtual and public, or non-virtual and protected.

If a class has no user-defined destructor, then the compiler will automatically declare a destructor. The definition for an automatically-defined destructor has an empty body.

An automatically declared destructor is defined as deleted if one or more of the following conditions is true:
- The class has a non-static data member with a deleted or inaccessible destructor
- The class has a direct or virtual base with a deleted or inaccessible destructor
- The class has a virtual destructor (because the base class has a virtual destructor) an the lookup for the de-allocation function results in a call to a deleted, ambiguous, or inaccessible function.

## Assignment Operators

Copy and move constructors are used when a new object is initialized from an existing object, meaning that a new block of memory is created. In contrast, class assignment operators are used to assign the value of one object to another object of the same type, both of which already exist.

There are two types of assignment operators: copy and move. If both are provided, then one is selected based on the right-hand argument to the assignment operator: copy assignment for lvalues and move assignment for rvalues. If only the copy assignment operator is available, then it is used by all argument categories (i.e. copy assignment is the fall-back for move assignment).

### Copy Assignment Operator

The copy assignment operator is called when a class object appears on the left-hand side of an assignment operator, and the object on the right-hand side is an lvalue of the same type (or implicitly convertible to the same type). A class copy assignment operator has the form `T& T::operator=(T)` or `T& T::operator=(T&)`. A class may have multiple copy assignment operators.

If a class has no user-defined copy assignment operator, then the compiler will automatically declare a copy assignment operator (the user can also force the compiler to declare a copy assignment operator, even if he/she has defined a copy assignment operator). The definition for an automatically-defined copy assignment operator will perform member-wise copy assignment of the object's bases and non-static data members in their initialization order using built-in assignment for primitive types and copy assignment for class types. 

An automatically declared copy assignment operator is defined as deleted if one or more of the following conditions is true:
- The class has a user-defined move constructor
- The class has a user-defined move assignment operator
- The class has a `const` qualified non-static data member of primitive type
- The class has a non-static data member of reference type
- The class has a non-static data member whose copy assignment operator is deleted, ambiguous, or inaccessible
- The class has a direct or virtual base whose copy assignment operator is deleted, ambiguous, or inaccessible

### Move Assignment Operator

The move assignment operator is called when a class object appears on the left-hand side of an assignment operator, and the object on the right-hand side is an rvalue of the same type (or implicitly convertible to the same type). A class move assignment operator has the form `T& T::operator=(T&&)`. Move assignment operators "steal" the resources held by the argument rather than make copies of them, leaving the argument in a valid but indeterminate state. A class may have multiple move assignment operators.

If a class has no user-defined copy constructor, move constructor, destructor, copy assignment operator, or move assignment operator, then the compiler will automatically declare a move assignment operator (the user can also force the compiler to declare a move assignment operator, even if he/she has defined a move assignment operator). The definition for an automatically-defined move assignment operator will perform member-wise move assignment of the objects direct bases and non-static data members in order of declaration using built-in assignment for primitive types and move assignment for class types.

An automatically declare move assignment operator is defined as deleted if one or more of the following conditions is true:
- The class has a `const` qualified non-static data member
- The class has a non-static data member of reference type
- The class has a non-static data member whose move assignment operator is deleted, ambiguous, or inaccessible
- The class has a direct or virtual base whose move assignment operator is deleted, ambiguous, or inaccessible
