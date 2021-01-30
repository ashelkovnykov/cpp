# Translation Unit

During translation, C++ compilers operate on discrete units of data for the first 10 phases. These discrete units of source code are called translation units. The final phase of translation links the machine code generated from the units into a single executable.

A translation unit is all of the code in a single source file, after preprocessing. Therefore, it is all of the code in a single source file after:
* `#include` directives have imported code
* `ifdef`/`ifndef` directives have included or excluded code
* All macros have been expanded
* Code has been analyzed for correct syntax and semantics

Clearly, during translation there will be one translation unit per source file.

## Instantiation Unit

Some compilers may produce "instantiation units". These are blocks of code produced by instantiating class and function templates for a particular set of types. Instantiation units are compiled just like translation units, assembled just like translation units, and linked just like translation units.
