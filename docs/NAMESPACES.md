# Namespaces

Namespaces provide a method to prevent name conflicts. In a large project, there may exist multiple entities with the same name: types, objects, labels, etc. The compiler can usually tell which entity is being referred to. For example, based on the context, the compiler can tell whether it's a type or an object which is being referred to. If the entities are both objects, then the ambiguity is resolved through nested scopes. However, this isn't always possible. Namespaces allow the user to create their own named scopes in which to define entities for the purpose of organizing the project and preventing naming conflicts.

## Context

Prior to reading this document, reading the following documents is recommended to understand the exact meaning of the following terms:

* Linkage
* Statements
* Scope

## Overview

Namespaces can only be defined in global or namespace scope. Namespaces can be nested.

### Named Namespaces

"Named namespaces" are the most common type. They create a named scope in which entities can be defined. All namespace blocks with the same name refer to the same scope; entities can be declared in the same namespace in multiple discontinuous blocks. Namespace members can also be referenced and modified outside of the namespace block, but this can only be done: after the namespace members have been declared; only in namespace scope; only if the current namespace encloses the namespace whose member is being modified.

### Inline Namespaces

"Inline namespaces" have the transitive property that their members can also be treated as members of the enclosing namespace. The enclosing namespace has an implicit `using namespace [inline namespace name]` directive inserted. When a namespace is added to the set of associated namespaces, all of its member inline namespaces are added as well. If a inline namespace is added to the set of associated namespaces, its enclosing namespace is added as well. Members of the inline namespace can be referred to in many ways: they can be fully qualified or partially qualified by just the enclosing namespace name or just the inline namespace name.

### Unnamed Namespaces

"Unnamed namespaces" create a namespace with a unique name which is unknown to the user and implicitly add a `using` directive to refer to the contents of this namespace in the enclosing namespace. Unnamed namespaces can also be inline namespaces, although in practical terms there is no difference. All members of unnamed namespaces can have only internal linkage.
