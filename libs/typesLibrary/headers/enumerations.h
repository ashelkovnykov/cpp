#ifndef TYPES_ENUMERATIONS_H
#define TYPES_ENUMERATIONS_H

/**
 * An enumeration is a distinct type whose possible values are restricted to a finite set of options. These options are usually explicitly named
 * constants called "enumerators".
 *
 * All enumeration types have an underlying type. The underlying type is an integral type which must be able to represent all of the enumerator
 * values. An underlying type can be explicitly fixed during declaration. If the underlying type is not explicitly fixed during declaration, the
 * underlying type will be the smallest type from the following list which is able to hold all of the enumerator values: int, unsigned int, long,
 * unsigned long. If an enumerator initialization list is not provided as part of the declaration, an underlying type must be explicitly provided. In
 * such a case, the enumeration will be considered to have complete type but incomplete definition.
 *
 * Each enumerator can be defined by an initializer. Any enumerator without an initializer will be given the value (previous enumerator + 1). If the
 * first enumerator does not have an initializer, it is given the value 0. If the enumerator initialization list is provided but empty, the
 * enumeration is treated as if it had a single enumerator with value 0.
 *
 * There are two types of enumerations: scoped and unscoped. Scoped enumerations have their enumerators converted to named constants of the
 * enumeration's type, available in the enumeration's scope, and accessible through the scope resolution operator. Scoped enumerators cannot be
 * implicitly converted to integral values. Unscoped enumerations have their enumerators converted to named constants of th enumeration's type,
 * available in the enclosing scope. Unscoped enumerators can be implicitly converted to integral values.
 */
 
// Scoped enumeration; red = 0, blue = 1, green = 2
enum class Colour_1 { red, blue, green };
// Scoped enumeration; red = 1, blue = 2, green = 3
enum class Colour_2 { red = 1, blue, green };
// Scoped enumeration; red = 0, blue = 20, green = 21
enum class Colour_3 { red, blue = 20, green };
// Unscoped enumeration; only introduces the enumerators as constants into the current scope
enum { red, blue, green };
// Unscoped enumeration with explicitly set underlying type; introduces enumerators into the current scope; need to use new colours and red, blue, and
// green were added by the above enumeration
enum Colour_5 : char { cyan, yellow, magenta };

#endif // TYPES_ENUMERATIONS_H
