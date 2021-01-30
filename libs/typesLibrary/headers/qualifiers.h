#ifndef TYPES_QUALIFIERS_H
#define TYPES_QUALIFIERS_H

/**
 * All objects can have their type qualified as one of:
 * - const
 * - volatile
 * - const volatile
 * - mutable
 * - mutable volatile
 *
 * The 'const' qualifier means that an object is considered immutable. Attempting to modify the object directly results in a compile time error, and
 * attempting to modify it indirectly results in undefined behaviour.
 *
 * The 'volatile' qualifier means that all accesses to an object are treated as side-effects by the compiler, meaning that they cannot be optimized
 * out or reordered. This is useful for multi-threading purposes.
 *
 * The 'const volatile' qualifier means that an object has the properties of both the 'const' and 'volatile' qualifiers.
 *
 * Technically, 'mutable' is a storage class specifier, not a qualifier. However, it does not affect storage class or linkage; it behaves more like
 * a qualifier.
 *
 * The 'mutable' specifier means that an object can be modified even if it is contained within a 'const' qualified object. This qualifier is
 * reserved for non-static class member objects. It can be combined with the 'volatile' qualifier to apply the properties of both.
 */
struct QualifierTypes {
  
  int i1; // regular int
  const int i2; // immutable int
  volatile int i3; // volatile int
  const volatile int i4; // immutable and volatile int
  mutable int i5; // this int is mutable, even if its enclosing 'QualifierTypes' object is immutable
  mutable volatile int i6; // this int is both volatile, and mutable even if its enclosing 'QualifierTypes' object is immutable
  
  /**
   * There exists a hierarchy between the qualifiers. Lower level qualifiers can be implicitly converted to higher level qualifiers. Higher level
   * qualifiers can only be converted to lower level qualifiers through explicit casts. The hierarchy looks like so:
   * 0: unqualified
   * 1: const, volatile
   * 2: const volatile
   */
   const int &a;
   volatile int &b;
   const volatile int &c;
   
   // Valid:
   // a = i1;
   // b = i1;
   // c = i1;
   // a = i2;
   // c = i2;
   // b = i3;
   // c = i3;
   // c = i4;
   
   // Invalid:
   // b = i2;
   // a = i3;
   // a = i4;
   // b = i4;
  
};

#endif // TYPES_QUALIFIERS_H
