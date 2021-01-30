#ifndef TYPES_REFERENCES_H
#define TYPES_REFERENCES_H

/**
 * References are aliases to existing objects or functions. The type of the reference is the type of the object or function to which it refers
 * (therefore there can be no references of type 'void'). Since references are not themselves objects, there can be no arrays of references, pointers
 * to references, or references to references.
 *
 * Since a reference is not an object, it usually does not occupy storage. However, the compiler may choose to allocate storage for a reference to
 * implement desired semantics (e.g. class contains non-static reference member).
 *
 * There are two types of references: lvalue references and rvalue references. A lvalue reference refers to an object residing in memory; this is the
 * classic C++ reference. A rvalue reference refers to an object without storage location (e.g. a character or number literal); this is a newer type
 * of reference which is used to extend the lifetime of a temporary object.
 *
 * Functions can be overloaded for values, pointers, lvalue references, or rvalue references. This allows functions to modify their behaviour when
 * operating on references to objects, or to literals. In addition, template functions have access to "forward references". This is a reference which
 * may be either an lvalue or rvalue reference, which preserves its type when used, and which can have its type preserved when passed to other
 * functions using the std::forward() function.
 *
 * As mentioned above, it is not possible to have a reference to a reference. Such a situation is a little convoluted to set up, however in the event
 * that it occurs the references undergo "reference collapse". A rvalue reference to a rvalue reference collapses to a rvalue reference. All other
 * reference combinations collapse to a lvalue reference.
 */
struct ReferenceTypes {

  int i;
  int& r1 = i; // lvalue reference to int i; anywhere r1 is used, the value of i will be substituted
  int&& r2 = 3; // rvalue reference to the number 3; anywhere r2 is used, 3 will be substituted
  
};

#endif // TYPES_REFERENCES_H
