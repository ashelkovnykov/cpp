# Linkage

During the final phase of C++ translation (see the Translation documentation), individual translation units are joined together to form a cohesive program. At this time, the compiler will "link" names between different translation units which refer to the same entity. To do so, it needs to know when a name in one translation unit refers to the same entity in another translation unit. For example, the compiler needs to know that a name of a declared, but not defined, function in one translation unit refers to a defined function of the same name in another translation unit. To accomplish this, each entity has an property known as "linkage".

## Types of Linkage

There are four types of linkage:
1. No linkage
2. Internal linkage
3. External linkage
4. Module linkage

### No Linkage

"No linkage" means that the entity can only be referred to from its present scope. All entities declared in block scope have no linkage, except for objects explicitly declared with external linkage.

### Internal Linkage

"Internal linkage" means that the entity can be referred to from any scope within the current translation unit. Entities in namespace scope can be explicitly declared to have internal linkage. Non-volatile, non-inline, const objects which aren't exported have internal linkage by default. Data members of anonymous unions and all entities declared in an unnamed namespace always have internal linkage (even if explicitly declared to have external linkage).

### External Linkage

"External linkage" means that the entity can be referred to from any scope in any translation unit. The following entities have external linkage (unless explicitly declared otherwise):
* Namespace-scope non-const objects
* Namespace-scope functions
* Namespace-scope classes
* Enumerations
* Templates

### Module Linkage

"Module linkage" means that the entity can be referred to from any scope in the same module unit (which may span multiple translation units). All names which would ordinarily have external linkage instead have module linkage if they are declared in a module and are not exported.
