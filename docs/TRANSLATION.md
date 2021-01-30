# Translation

This document summarizes the phases that C++ source files go through during translation from source files to an executable program.

**NOTE:** Translation occurs *as if* each of these phases took place independently. The exact compiler behaviour is implementation specific and may differ slightly.

## Phase 1: Map Bytes to Source Character Set

Source files may differ in how the characters are represented or which characters are present depending on the operating system and editor used. This phase translates the wide range of possible characters to a standard set, oftentimes ASCII.

The only requirement for the source character set is that it must at a minimum contain 96 core characters:
* The 26 lower case English letters
* The 26 upper case English letters
* The 10 digits
* The following 29 punctuation characters:
  * `_ { } [ ] # ( ) < > % : ; . ? * + - / ^ & | ~ ! = , \ " '`
* The following 5 whitespace characters:
  * Space, horizontal tab, vertical tab, form feed, new line

### 1.1: Map Individual Bytes

The individual characters of the source code (usually encoded using a multibyte system such as UTF-8) are converted to single-byte characters from the source character set. Any character that cannot be mapped to a character in the source character set is replaced by its escaped unicode character name (`\u` or `\U`). 

### 1.2: Map Trigraphs

Trigraph sequences are replaced by their corresponding single-character representations.

## Phase 2: Merge Source Lines

All lines that end with a backslash (`\ `) followed by a newline character have both the backslash and newline character deleted, merging the current line of source code with the following one. If the resulting code produces an escaped unicode character name, the compiler behaviour is undefined. If after this phase the source file does not end with a newline character, one is automatically inserted by the compiler.

## Phase 3: Tokenization

During this phase, the source file is decomposed from a single block of continuous text into discrete tokens. Tokens are formed using the "maximal munch" rule (a greedy algorithm): the next token is formed by taking the longest sequence of characters which could constitute another preprocessing token.

### 3.1 Form Tokens

The source file is decomposed into a sequence of tokens. The possible types of tokens are:
* Whitespace sequence
* Comment block
* Preprocessing token
  * Header names (e.g. `<stdio.h>`, `"myHeader.h"`, etc.)
  * Preprocessing numbers
    * Integer constants (e.g. `36`, `044u`, `0x24ll`, etc.)
    * Floating-point constants (e.g. `1.0`, `.1`, `1.`, `1.8e1`, `0x1.2p4`, etc.)
  * Character constants (e.g. `'a'`, `'!'`, `'\n'`, etc.)
  * String literals (e.g. `"abc"`, `"\x1a = 26"`, `"猫🍌"`, etc.)
  * User-defined literals (e.g. `12_km`, `90_deg`, etc.)
  * Operators (e.g. `+`, `-`, `<=`, `?`, `<<`, etc.)
  * Punctuators (e.g. `=`, `[`, `]`, `,`, `#`, `##`, etc.)
  * Identifiers (e.g. `int`, `my_val`, `_CONSTANT`, `🐱`, etc.)
  * Any single non-whitespace character which does not fit into the above categories

### 3.2 Revert Raw String Literals

Any changes made during phases 1 and 2 to the contents of a raw string literal are reverted.

### 3.3 Replace Comments

All comment blocks are replaced by a single space character (` `).

### 3.4 Condense whitespace

Compilers may choose to replace each whitespace sequence token with a single space character (` `). Newline characters are always kept.

## Phase 4: Preprocessing

The preprocessor executes each preprocessing directive one at a time. Afterwards, no more preprocessing directives remain in the source code.

Any new code introduced using the `include` directive goes through phases 1-4 recursively.

## Phase 5: Map Escape Sequences to Execution Character Set

All characters in character and string literals are converted to characters in the execution character set. The execution character set can differ be any character set, so long as it contains the 96 characters of the source character set as single-byte representations.

If an escaped sequence or universal character does not exist in the execution character set, it is up to the compiler what character to convert to. However, the resultant character is guaranteed to not be null.

## Phase 6: Concatenate Strings

Adjacent string literals and those separated only by a whitespace sequence are concatenated.

## Phase 7: Prepare Translation Units

The remaining tokens are analyzed for correct syntax and semantics. The result is a translation unit (see translation unit documentation for more details).

## Phase 8: Template Instantiation

Each translation unit is examined to produce a list of required template instantiations. The template definitions are located and the instantiations are performed, producing instantiation units (see translation unit documentation for more details).

Note: Some compilers do not produce instantiation units, and instead inject the instantiations into the translation units.

## Phase 9: Compilation

The translation and instantiation units (if any) are converted into assembly instructions for the specific processor architecture that the program will run on.

### The "as-if" Rule

The C++ compiler is allowed to perform any changes to the program during compilation, as long as they do not affect the observable behaviour of the program. Specifically, any changes may be performed so long as the following conditions hold true:
1. Accesses to volatile objects are not reordered with respect to each other within the same thread.
2. At program termination, the data written to files or output is exactly as if the program was executed as written.
3. Prompting text sent to a terminal will always arrive before the program waits for input.

The "as-if" rule only applies to the defined behaviour of a program. If a program contains undefined behaviour, the compiler is by definition unable to follow this rule.

There are ___ exceptions to the "as-if" rule:
1. move-constructors of temporary objects may be removed, even if it affects program output
2. copy-constructors of temporary objects may be removed, even if it affects program output
3. destructors of temporary objects may be removed, even if it affects program output
4. calls to replaceable allocation functions may be removed, even if it affects program output

## Phase 10: Assembly

The machine instructions generated by the compilation phase are converted into actual machine code instructions for the intended processor.

## Phase 11: Linking

The output of the assembly phase is multiple "object" files which contain the machine instructions for the translation and instantiation units. These files need to be "linked" (along with external libraries) into a single file which contains all of the code in one self-contained program. This is the final phase of translation.