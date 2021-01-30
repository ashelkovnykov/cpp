# Standard Template Library

The C++ language contains several pre-produced macros, variables, classes, functions, and templates which are commonly used by software engineers. These objects are so vital or common that they are considered a core part of the language. However, since not all users may need them at all times, any program which wishes to make use of them must include their header files. Unlike including an external library, these headers do not need to be managed in the same way (often through external project management systems such as CMake): the headers and code are included in the compiler and can be accessed anytime from anywhere. The combined headers and source code for these objects is known as the "Standard Template Library" or STL.

## Concepts

The `<concepts>` header imports several default concepts, such as `same_as`, `unsigned_integral`, `copy_constructible`, etc.

## Coroutines

The `<coroutine>` header contains:
- classes to refer to suspended/awaiting coroutines
- comparators for coroutines
- hash support for coroutines
- trivial coroutine components

## Utilities

### Pure Utilitarian

#### `any`

- The box `any` class which can contain an object of any type which satisfies the constructor requirements.
- `make_any`: helper function to create `any` objects.
- `any_cast`: type-safe access to the object contained in an `any` object.

#### `bitset`

Introduces constant-length bit arrays, and operators to manage them.

#### `chrono`

Date and time library.

#### `compare`

Classes and objects for doing three-way comparisons. Supports partial, weak, and strong orderings.

#### `cstdlib`

- `std::div` types (store both the quotient and remainder from a division operation)
- `std::size_t` type (unsigned integer type that stores type size and alignment values)
- program execution exit status macros
- null pointer constant macro
- C-style memory allocation functions
- program process control functions
    - `abort`: cause abnormal program termination, without cleaning up
    - `exit`: cause normal program termination, with clean-up
    - `quick_exit`: cause normal program termination, with partial clean-up
    - `at_exit`: register a function to call on invocation of `exit`
    - `at_quick_exit`: register a function to call on invocation of `quick_exit`
    - `system`: call the host environment's command processor
    - `getenv`: access to the list of environment variables
- numeric string conversions
- wide string manipulation functions
- miscellaneous numeric functions:
    - `rand`: generate pseudo-random numbers 
    - `qsort`: quick sort algorithm
    - `bsearch`: binary search algorithm
    - `abs`: compute absolute value
    - `div`: compute both quotient and remainder for division

#### `csignal`

Signal macros and functions to raise/handle signals.

#### `csetjmp`

The `longjmp` function.

#### `cstdarg`

Macros necessary for handling variadic arguments.

#### `ctime`

C-Style date and time library

#### `functional`

- Arithmetic, logical, bitwise, and comparison operators as objects
- `hash` function

#### `initializer_list`

Contains the `initializer_list` class.

#### `optional`

- The box `optional` class which may or may not contain an object.
- `make_optional`: helper function to create `optional` objects.

#### `source_location`

A class containing information about the source code, such as file names, line numbers, and function names.

#### `tuple`

- Tuple class
- Helper classes for compile time info about tuple contents
- Tuple helper functions:
    - `make_tuple`: create a tuple object from individual objects
    - `tie`: unpack a tuple object into one or more individual objects
    - `tuple_cut`: concatenate multiple tuple objects into a single tuple
    - `get`: access a specific tuple element
    - `apply`: use the elements of a tuple as arguments to a function
    - `make_from_tuple`: use the elements of a tuple as arguments to the constructor of an object

#### `typeinfo`

Classes for results and exceptions from the `typeid` operator.

#### `type_traits`

Tools to check and modify object types using helper classes.

#### `utility`

- Pair class
- Utility functions:
    - `swap`: swaps values of two objects
    - `exchange`: replaces an objects value with a new one and returns the old one
    - `forward`: allows perfect forwarding of arguments taken as rvalue references to deduced types in templates
    - `move`: used to indicate that an object may be "moved from" (i.e. transfer it's value/resources to another object)
    - `as_const`: obtains a reference to const of the input argument
    - `declval`: converts any type T to a reference type, making it possible to use member functions in expressions without needing to generate an object using a constructor
    - `in_range`: checks if an integer is within the range set by two other integers
    - `make_pair`: creates a pair object
    - `get`: access an element of a pair
    - functions to compare integer values without conversion to the exact same type

#### `version`

Macros containing information about the compiler implementation.

### Dynamic Memory

#### `memory`

High-level memory management tools:
- Smart pointers:
    - `unique_ptr`: owns and manages an object through a pointer, and disposes of the object either when it goes out of scope or is assigned a new value.
    - `shared_ptr`: shares ownership of an object through a pointer with other `shared_ptr` objects. Tracks the number of `shared_ptr` objects referring to the same object, and disposes of that object when the final `shared_ptr` is deleted or assigned a new value.
    - `weak_ptr`: holds a non-owning reference to an object managed by one or more `shared_ptr` objects. Models temporary ownership of an object which may be deleted at any time and should only be accessed if it exists.
    - `auto_ptr`: manages an object created by a `new` expression and deletes it when the `auto_ptr` is destroyed.
- Allocator: every `std` library component that uses storage does so through an object which manages access/addressing, allocation/de-allocation, and construction/destruction of objects.
- Basic garbage collection
- Functions to convert smart pointers to regular pointers
- Functions to generate smart pointers for objects
- Smart pointer comparison operators
- Smart pointer casting operators

### Numeric

#### `cfloat`

Macros of various useful values for floating point types (e.g. minimums, maximums, epsilons, etc).

#### `cinttypes`

- Functions for the types in `<cstdint>`:
    - `abs`: compute absolute value of an integer
    - `div`: compute quotient and remainder for integer division
    - `strtoimax`: convert byte string to integer
    - `wcstoimax`: convert wide string to integer
- Macro constants for reading/writing integer types from `<cstdint>` using `std::fprintf` and `std::fscanf`

#### `climits`

Macros of the minimum/maximum values for all integer types.

#### `cstdint`

Implementation-independent integer types (i.e. guaranteed to use a certain number of bits) and macros for their minimum/maximum values.

### Error Handling

#### `cassert`

`assert` function.

#### `cerrno`

Macros for C-style error codes.

#### `exception`

- Classes for exception handling:
    - `exception`: base class for all exceptions
    - `nested_exception`: a mixin type to capture multiple exceptions
    - `exception_ptr`: shared pointer for handling exception objects
- Functions for throwing and handling exceptions:
    - `uncaught_exceptions`: checks if exception handling is in progress
    - `make_exception_ptr`: create an `exception_ptr` from an exception object
    - `current_exception`: capture the current exception in an `exception_ptr`
    - `rethrow_exception`: throw an exception from an `exception_ptr`
    - `terminate`: function called when exception handling fails

#### `stdexcept`

Some common exceptions for the most frequently-occurring errors.

#### `system_error`

Classes and functions for handling error codes.

## Strings

### `cctpye`

Functions for checking if individual character objects are lowercase, uppercase, alphanumeric, etc. Also, functions for converting characters between cases.

### `cstring`

C-style string and character array manipulation functions.

### `cwchar`

C-style wide character library.

### `cwctype`

Same as `<cctype>` but for wide characters.
    
### `format`

Classes and functions to format strings inside of other strings.

### `string`

String manipulation library:
- Classes to support regular, wide, and unicode strings
- I/O operators
- Comparison operators
- Numeric conversion functions
- Iterator/range access functions
- Hash functions

### `string_view`

Extension of the `<string>` library to provide "views" for strings. A view is like a reference to an object which would otherwise be impossible to refer to (for example, a reference to an array is not enough since we also need to know the size of the array). Many uses of strings don't require ownership of the string, only the ability to inspect the characters of the string and use them to create sub-strings.

## Containers

STL contains several data structure templates in individual header files:
- `array`
- `deque`
- `forward_list`
- `list`
- `map`
- `queue`
- `set`
- `span`
- `stack`
- `unordered_map`
- `unordered_set`
- `vector`

In addition, the STL contains iterators, adaptors, views, and concepts for managing the above containers in the following header files:
- `iterator`
- `ranges`

## Algorithm

The `<algorithm>` header file contains many common algorithm function templates. In addition, the `<execution>` header file contains execution policies which specify how those algorithm functions should execute with regards to multi-threading. 

### Non-modifying Sequence Operations

- `adjacent_find`: find the first two adjacent elements in a range which satisfy a given predicate
- `all_of`: checks if a predicate is true for all elements in a range
- `any_of`: checks if a predicate is true for any elements in a range
- `count`: returns the number of elements in a range
- `count_if`: returns the number of elements in a range which satisfy a predicate
- `find`: finds the first element in a range which matches a given value
- `find_if`: finds the first element in a range which satisfies a predicate
- `find_if_not`: finds the first element in a range which does not satisfy a predicate
- `find_end`: find the last occurrence of sequence in a range
- `find_first_of`: find the first element in a range from a given set of elements
- `for_each`: applies a function to a range of elements
- `for_each_n`: applies a function to the first n elements of a sequence
- `mismatch`: finds the first position where two ranges differ
- `none_of`: checks if a predicate is true for no elements in a range
- `search`: find the first occurrence of a sequence in a range
- `search_n`: find n consecutive copies of an element in a range

### Modifying Sequence Operations:

- `copy`: copy a range of elements to a new location
- `copy_backward`: copy a range of elements to a new location in reverse order
- `copy_if`: copy a range of elements which satisfy a predicate to a new location
- `copy_n`: copy a number of elements from a range to a new location
- `fill`: assign a given value to every element in a range
- `fill_n`: assign a given value to n elements in a range
- `generate`: assign a value to every element in a range by repeatedly calling a given function
- `generate_n`: assign a value to n elements in a range by repeatedly calling a given function
- `iter_swap`: swap teh values of two elements in a range which are pointed to by iterators
- `move`: move a range of elements to a new location
- `move_backward`: move a range of elements to a new location in reverse order
- `remove`: remove all elements from a range that match a given value
- `remove_copy`: copy a range of elements to a new location, omitting those that match a given value
- `remove_copy_if`: copy a range of elements to a new location, omitting those that satisfy a predicate
- `remove_if`: remove all elements from a range that satisfy a predicate
- `replace`: replace all elements in a range of a given value with another value
- `replace_copy`: copy a range of elements to a new location, replacing those that match a given value with another value
- `replace_copy_if`: copy a range of elements to a new location, replacing those that satisfy a predicate with another value
- `replace_if`: replace all elements in a range which satisfy a predicate with another value
- `reverse`: reverse the order of elements in a range
- `reverse_copy`: copy a range of elements to a new location, in reverse order
- `rotate`: rotate the order of elements in a range to the left
- `rotate_copy`: copy a range of elements to a new location, rotating the order to the left
- `sample`: select n elements from a sequence at random (without replacement)
- `shift_left`: shift elements in a range n spots towards the beginning of the list (Note: does NOT rotate elements)
- `shift_right`: shift elements in a range n spots towards the end of the list (Note: does NOT rotate elements)
- `shuffle`: randomly re-order elements in a range
- `swap`: swap the values of two objects
- `swap_ranges`: swap the values of two ranges
- `transform`: applies a function to a range of elements, storing the results to another destination
- `unique`: remove consecutive duplicate elements in a range
- `unique_copy`: copy a range of elements to a new location, omitting consecutive duplicate elements

### Partitioning Operations

- `is_partitioned`: determines if a range is partitioned by a predicate (all elements that satisfy the predicate appear before all elements that don't)
- `partition`: partition a range by a predicate (reorder elements so that all elements that satisfy the predicate appear before all elements that don't)
- `partition_copy`: copy a range of elements to a new location, while also partitioning them using a predicate
- `partition_point`: locates the partition point in a partitioned range
- `stable_partition`: partition a range by a predicate, preserving the relative order of elements

### Sorting Operations

- `is_sorted`: checks whether a range is sorted into ascending order
- `is_sorted_until`: finds the largest sub-range that is sorted into ascending order
- `nth_element`: quick-select algorithm
- `partial_sort`: sorts the first n elements of a range into ascending order
- `partial_sort_copy`: copy a sub-range of elements from a range to a new location, sorting them into ascending order
- `sort`: sort a range of elements into ascending order
- `stable_sort`: sort a range of elements into ascending order, preserving the relative order of elements

### Search Operations

- `binary_search`: binary search algorithm
- `equal_range`: returns all elements that match a given value in a sorted range
- `lower_bound`: returns an iterator to the first element equal to or lesser than a given value within a sorted range
- `upper_bound`: returns an iterator to the first element greater than a given value within a sorted range

### Merge Operations

- `merge`: merge two sorted ranges
- `inplace_merge`: merge two sorted sub-ranges within one range in-place

### Set Operations

- `includes`: checks if one sorted range is a sub-range of another sorted range
- `set_difference`: find the elements in one range which are not in a second range and copy them to a third range
- `set_intersection`: find the elements in one range which are also in a second range and copy them to a third range
- `set_symmetric_difference`: find the different elements between two ranges and copy them to a third range
- `set_union`: find the union of two ranges and copy them to a third range

### Heap Operations

- `is_heap`: checks if a range is a max-heap
- `is_heap_until`: finds the largest sub-range that is a max-heap
- `make_heap`: heapify a range into a max-heap
- `pop_heap`: remove the top element from a max-heap
- `push_heap`: add an element to a max-heap
- `sort_heap`: re-order the elements of a max-heap into a list of elements sorted in ascending order

### Min/Max Operations

- `clamp`: round a given value to a range
- `max`: return the greater of two values
- `max_element`: return the largest element in a range
- `min`: return the lesser of two values
- `min_element`: returns the smallest element in a range
- `minmax`: return the lesser and greater of two values
- `minmax_element`: return the smallest and largest values in a range

### Comparison Operations

- `equal`: checks if two ranges of elements are equal
- `lexicographical_compare`: returns true if one range is lexicographically less than another (like string comparison)
- `lexicographical_compare_three_way`: three-way lexicographical comparison

### Permutation Operations

- `is_permutation`: checks if one range is a permutation of another range

## Numerics

### `cmath`

Contains the following common mathematical functions:
- absolute value
- beta function
- ceiling
- elliptic integrals
    - complete/incomplete
    - first, second, third kind
- error function (erf)
- exponential (base e)
- exponential (base 2)
- exponential (e^x - 1)
- floating-point remainder
- floor
- fused multiplication-addition
- gamma function
- gamma function logarithm
- Hermite polynomials
- Laguerre polynomials
- Legendre polynomials
- linear interpolation
- logarithm (base e)
- logarithm (base 2)
- logarithm (base 10)
- logarithm (ln(1 + x))
- power equations
- Riemann zeta function
- roots (square and cubic)
- round
- spherical functions
    - Bessel
    - Legendre
    - Neumann
- sum of squares
- trigonometric functions
    - sine, arc sine, hyperbolic sine, inverse hyperbolic sine
    - cosine, arc cosine, hyperbolic cosine, inverse hyperbolic cosine
    - tangent, arc tangent, hyperbolic tangent, inverse hyperbolic tangent
- truncate

### `complex`

Complex number implementation and extensions to many of the functions from `<cmath>` to handle complex numbers.

### `random`

- random number engines
    - linear congruential algorithm
    - Mersenne twister algorithm
    - lagged Fibonacci algorithm
- various pre-defined random number generators
- various distributions
    - discrete uniform distribution
    - continuous uniform distribution
    - Bernoulli distribution
    - binomial distribution
    - negative binomial distribution
    - geometric distribution
    - Poisson distribution
    - exponential distribution
    - gamma distribution
    - Weibull distribution
    - extreme value distribution
    - Gaussian distribution
    - log-normal distribution
    - chi-squared distribution
    - Cauchy distribution
    - Fisher's F-distribution
    - Student's T-distribution

### `ratio`

Class to represent exact rational fractions and functions to perform basic comparison/mathematical operations on them.

### `cfenv`

Floating-point environment access functions.

### `bit`

Bit manipulation functions:
- check for power of 2
- rounding to power of 2
- counting bits
- counting consecutive bits

### `numbers`

Various mathematical constants as variable templates:
- e
- log_2 e
- log_10 e
- pi
- inverse pi
- inverse root pi
- ln 2
- ln 10
- root 2
- root 3
- inverse root 3
- Euler's constant
- phi (golden ratio)

## Localization

The `<locale>` header contains classes to store polymorphic differences between cultures/locales (e.g. time, money, punctuation, etc.).

## Input/Output

### `iosfwd`

Forward declaration of the classes in the other I/O headers.

### `ios`

Base header for C++ I/O. Contains classes for managing arbitrary stream buffers, formatting flags, I/O exceptions, file/stream positions, and file/stream buffers. Also contains functions to control various output options:
- textual/numeric boolean representations
- show/hide numeric bases
- basic/scientific notation
- show/hide decimal points in floating-point numbers
- show/hide positive sign for positive numbers
- skip/include leading whitespace
- use/ignore uppercase
- placement of fill characters
- numeric base (decimal, octal, hexadecimal)

### `istream`

Specialization of `<ios>` constructs for input streams.

### `ostream`

Specialization of `<ios>` constructs for output streams.

### `iostream`

Combination of `<istream>`, `<ostream>`, and `<streambuf>` which defines `cin`, `cout`, and `cerr` buffers.

### `fstream`

Specialization of `<ios>` constructs for input/output streaming operations from/to files.

### `sstream`

Specialization of `<ios>` constructs for input/output streaming operations from/to strings.

### `syncstream`

Specialization of `<ostream>` for synchronized output to an output stream.

### `iomanip`

Helper functions to control I/O options of streams introduced by `<ios>`.

### `streambuf`

Abstracts a raw buffer for input/output streams.

### `cstdio`

C-style I/O.

## Filesystem

The `<filesystem>` header contains support for accessing the OS filesystem through C++. Contains classes and functions for managing:
- Paths
- Directories
- File types
- File permissions
- File info (e.g. creation date, last modified date, size, etc.)
- Symbolic links
- Used/free space

## Regular Expressions

The `<regex>` header contains classes and functions to manage regular expressions.

## Atomic Operations

The `<atomic>` header contains class specializations for atomic booleans, integers, and pointers. It also contains the `atomic_ref` class for atomic references to/operations on non-atomic objects. In addition, it contains the following atomic functions:
- store/load values to/from atomic objects
- swap values between atomic and non-atomic objects
- atomic addition, subtraction, bitwise AND, bitwise OR, and bitwise XOR operations
- atomic thread operations

## Multi-threading Support

### `thread`

Introduces the code for threads some basic thread functions: `yield`, `sleep_for`, and `sleep_until`.

### `stop_token`

Interfaces for querying/registering cancellation call-backs for auto-joining threads.

### `mutex`

Introduces code for locks and mutual exclusion blocks.

### `shared_mutex`

Extends `<mutex>` code to include shared locks and shared mutual exclusion blocks.

### `future`

Introduces primitives for asynchronous computation.

### `condition_variables`

Introduces code for condition variables.

### `semaphore`

Introduces code for counting and binary semaphores.

### `latch`

Introduces code for latches (atomic downward counters which are used to synchronize threads).

### `barrier`

Introduces code for barriers (specialized thread-coordination mechanism that blocks up to a set maximum number of threads until the expected number of threads arrive at the barrier).
