# Name Lookup

"Name lookup" is the process by which a name encountered in a program is associated with the declaration which introduced it. For functions, multiple declarations can be associated with the same name due to overloaded and template functions. In this case, argument-dependent lookup and template argument deduction are used to determine exactly which function is referred to. For all other entities (e.g. objects, classes, namespaces, enumerations, etc.), name lookup must find exactly one declaration.

## Context

Prior to reading this document, reading the following documents is recommended to understand the exact meaning of the following terms:

* Namespaces
* Scope

## Types of Lookup

There are four different types of name lookup:

* Qualified name lookup
* Unqualified name lookup
* Argument-dependent lookup
* Template argument deduction

### Qualified Name Lookup

A "qualified name" is one that appears on the right-hand side of the scope resolution operator `::`. The name on the left-hand side of the scope resolution operator is the name of the scope in which to search for the qualified name. If the left-hand side is empty, then global namespace scope is implied.

Qualified names can refer to:
* Class members
* Namespace members
* Enumerators

Qualified name lookup can be used to access a base class member when it is hidden by a similarly named member in a derived class.

When a qualified name is used as a declarator, unqualified lookup of names following the qualified name in that same declarator use the same scope as the qualified name. However, this is not true for template arguments: names used in template arguments use the current scope unless qualified, regardless of if any preceding names were qualified.

When searching for a qualified name in a namespace, the following search order is used:
* First, search the specified namespace, including all inline namespace members (and their transitive inline namespace memebers)
* Then, search all namespaces introduced into the specified namespace through using directives
* Repeat this process recursively

It's okay if the same declaration is discovered more than once through multiple paths.
 
### Unqualified Name Lookup
 
An "unqualified name" is one that does not appear on the right-hand side of the scope resolution parameter `::`. Name lookup for an unqualified name begins in the current scope and proceeds through the scope stack until at least one declaration is found. If a declaration is found, no further scopes are examined. If multiple declarations are found then a compilation error occurs.

Unqualified name lookup for functions is handled by argument-dependent lookup (see below).
 
### Argument-Dependent Lookup

"Argument-dependent lookup" (also known as Koenig lookup) is the set of rules for finding declarations of unqualified function names and operators. In addition to the regular unqualified name lookup rules, function names are also searched for in the namespace scopes of their arguments.

Argument-dependent lookup (ADL) begins with unqualified name lookup. If any of the following are found, then ADL is stopped short:
* A declaration of a class member
* A declaration of a function defined in block scope (not via using declaration)
* Multiple declarations, at least one of which is not a function or function template

Otherwise, every argument to the function is examined. Depending on the type of the argument, additional scopes are searched for function declarations matching the given name using the following rules:
1. **Arguments of fundamental types:** No additional scopes are searched
2. **Arguments of enumeration type:** The innermost namespace or class scope enclosing the enumeration declaration
3. **Arguments of class type (including `union`):** 
    - The class scope
    - The class scopes of all direct and indirect base classes
    - If the class is a member of another class, then the class scope of the wrapping class
    - The innermost enclosing namespace scopes of the above classes
4. **Arguments of class template specialization:** 
    - All scopes from rule 2 above
    - The namespace scopes of all template arguments
    - If the template arguments are members of classes, then the class scope of the wrapping class
5. **Arguments of pointer type:**
    - This process is repeated for the type of the object to which the pointer points
    - If the pointer points to a member of a class, then the class scope of the wrapping class
6. **Arguments of function type:**
    - This process is repeated for the function parameter and return types
    - If the function is a member of a class, then the class scope of the wrapping class

If any namespace scope that's searched through ADL contains an inline namespace, the inline namespace is also searched. Conversely, if any namespace scope that's searched through ADL **is** an inline namespace, it's enclosing namespace is also searched. However, all using directives are ignored.
 
All declarations found through ADL that are not functions or function templates are ignored. For information regarding how the compiler chooses the appropriate function from the set of discovered declarations, see the "Overload Resolution" document.

### Template Argument Deduction

"Template argument deduction" is the set of rules for finding (and possibly instantiating) a function declaration for a given function template name. In order to instantiate a function template every template argument must be known, but not every template argument must be provided. Whenever possible, the compiler will attempt to deduce the missing template arguments from the function arguments.

Template argument deduction occurs after argument-dependent lookup if the only possibly viable result is a function template. It takes place before template argument substitution and overload resolution. It also takes place for class template instantiation, though that is not the focus of this documentation.

Template argument deduction is a very complex process with many rules. The primary point of this documentation is just to note that if argument-dependent lookup resolves to a function template, there is another step which takes place in the name lookup process to determine the exact function declaration for a name via template argument deduction.

## Overload resolution

During name lookup, argument-dependent lookup, and template argument deduction, more than one possible valid function may be discovered. If this occurs, the C++ compiler must perform overload resolution to determine which of the valid functions to use.

In general, the candidate function whose parameters most closely match the arguments is the one that is selected. More specifically, a candidate function F1 is selected over F2 if:
- The implicit conversion path from the arguments to the parameters for F1 is better than the implicit conversion path from the arguments to the parameters for F2 for at least one argument; OR
- The implicit conversion path from the return type of F1 to the type of the object being initialized is better than the implicit conversion path from the return type of F2 to the they of the object being initialized; OR
- The return type of F1 is the same type of reference as that of the reference being initialized and the return type of F2 is not; OR
  - F1 is not a template specialization and F2 is; OR
  - Both F1 and F2 are template specializations, but F1 is more specialized; OR
  - Both F1 and F2 are template specializations, but F1 has more constraints; OR
  - Both F1 and F2 are template specializations, but F1 is generated by a user-defined deduction-guide; OR
  - F2 is a constructor for a class B and F1 is a constructor for a class D which is derived from B; OR
  - F2 is a constructor for a templated class and F1 is a constructor for a non-templated class; OR

These comparisons are made between all candidate functions. If one function meets at least one of these criteria when compared against all of the other functions, that is the candidate function chosen by overload resolution. Otherwise, compilation fails.

### Ranking Implicit Conversions

An implicit conversion can have up to three ordered conversion steps:  standard conversion, user-defined conversion, standard conversion. There are also three ranks that a conversion step can hold:
1. Exact match:
    1. No conversion
    2. Lvalue-to-rvalue conversion
    3. Qualifier conversion
    4. Function pointer conversion
    5. User-defined conversion from class type to class type
2. Promotion
    1. Integer promotion
    2. Floating-point promotion
3. Conversion:
    1. Integer conversion
    2. Floating-point conversion
    3. Floating-point-to-integer conversion
    4. Pointer conversion
    5. Boolean conversion
    6. User-defined conversion from class type to base class type

The rank of an implicit conversion is the lowest of the individual ranks that make up the sequence.

When determining which implicit conversion path is better, conversion path C1 is better than conversion path C2 if:
- C1 is a subsequence of C2; OR
- C1 has higher rank than C2; OR
- C1 does not contain a user-defined conversion function and C2 does; OR
- C1 does not contain a variadic ellipses conversion and C2 does; OR
- C2 contains a pointer-to-bool conversion and C1 doesn’t; OR
- C1 has a better pointer conversion than C2 (In general, a “better” pointer conversion is one that is more specific. For example, if C derives from B derives from A, conversions of C to B and B to A are better than conversions of C to A or B* to void*); OR
- C1 and C2 only differ in qualification and C1 is less qualified than C2; OR
- C1 and C2 both result in another implicit conversion sequence, and the sequence caused by C1 is better than the sequence caused by C2; OR
- C1 and C2 both result in list-initialization, but C1 uses a std::initializer_list and C2 doesn’t 
