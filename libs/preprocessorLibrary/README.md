# Preprocessor

This library demonstrates C++ preprocessing.

The preprocessor is run as the fourth phase of translation. Preprocessing directives allow the user to control what code is compiled during later stages of translation using preprocessing directives. These directives grant the following controls:
* Conditional inclusion
* Replacing text macros
* Source file inclusion
* Line and filename aliasing
* Error generation
* Implementation Defined Behaviour

## Conditional Inclusion

Conditional inclusion allows the preprocessor to include or exclude entire chunks of source code based on the evaluation of conditional expressions.

## Replacing Text Macros

The C++ preprocessor supports defining object-like and function-like macros. Once defined, all instances of a name matching the name of a defined macro will be replaced with the defined value.

### Feature Testing

The C++ language and the STL define many preprocessor macros which correspond to features introduced into the C++ language. The value of these macros is the year and month that they were introduced into the working draft of the language. The full list of these macros is available [here](https://en.cppreference.com/w/cpp/feature_test).

## Source File Inclusion

Other source files can have their entire contents injected into the current source file, at the point of the directive.

## Line and Filename Aliasing

Allows renaming how the filename and line information is reported by the compiler. This is often useful for machine-generated source files and for tests.

## Error Generation

Manually throw errors during preprocessing.

## Implementation Defined Behaviour

Allows changes to settings which control how the compiler handles evaluation of mathematical formulas, the floating point environment, repeated source file inclusion, and class/union member alignment.
