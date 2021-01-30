#ifndef TYPES_TYPES_H
#define TYPES_TYPES_H

namespace types {
  
  enum Type {A, B, C};
  
  // The 'typedef' expression allows the user to create aliases for type names. These aliases can be used anywhere the type name would be and refer to
  // exactly the same type.
  typedef Type alias;
  
  struct Node {
    Node *Node; // next node
    alias Type;  // type of current node
    
    // The identifier "Node" is ambiguous, referring to both a type and an object. Thus, references to the "Node" type must be "elaborated type
    // specifiers". This is done by prefacing the type name with the keyword used during the declaration of the type: 'class', 'struct', 'enum', or
    // 'union'.
    struct Node* next();
    
    // This function does not run into the ambiguity described above because it uses an alias to refer to the same type.
    alias value();
  };
  
}

#endif // TYPES_TYPES_H
