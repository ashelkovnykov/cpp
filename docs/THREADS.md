# Threads

A "thread" is a component of a "process" (i.e. program). It is the smallest logical grouping of instructions which are carried out by the processor on which the process is running. C++ offers the ability to write multi-threaded programs, meaning that a C++ program can perform multiple concurrent tasks while sharing resources (e.g. memory).

The purpose of this document is not the documentation of multi-threading programming, but rather the particulars of multi-threading in C++. Therefore, familiarity with multi-threading concepts is assumed on the part of the user.

## Forward Progress

Every valid C++ program makes the guarantee that every thread will eventually perform one of the following actions:
* Terminate
* Make a call to an I/O library function
* Perform an access through a volatile glvalue
* Perform an atomic operation
* Perform a synchronization operation

No thread is allowed to execute indefinitely without performing one of the above actions. Doing so is undefined behaviour, and therefore the compiler is allowed to remove any loops with no observable behaviour, without proof that they would or would not terminate eventually.

A thread is said to be "making forward progress" if it performs one of the above actions, blocks while calling a standard library function, or calls an atomic lock-free function which does not complete because of a unblocked concurrent thread.

### Concurrent Forward Progress

A thread guarantees "concurrent forward progress" if it makes progress (as defined above) in a finite amount of time, while it has not terminated, regardless of if any other thread is making progress. Ideally, all threads would make this guarantee.

Ex. A thread which performs its own task independent of all other threads.

### Parallel Forward Progress

A thread guarantees "parallel forward progress" if it does not guarantee that it will make progress (as defined above), but if it does then it guarantees concurrent forward progress from then on.

Ex. A thread sitting in a thread pool with several other threads, each of which are independent and executed in arbitrary order.

### Weak Parallel Forward Progress

A thread guarantees "weak parallel forward progress" if it does not guarantee that it will make forward progress whether other threads make progress or not.

Ex. A thread which blocks on the execution of a pool of other threads.

## Obstruction

When a single unblocked thread executes a lock-free atomic function, it is guaranteed to succeed. When one or more unblocked threads execute a lock-free atomic function, at least one of them is guaranteed to succeed. It is the responsibility of the C++ programmer to ensure that a live-lock does not occur.

## Sequencing

Expression evaluations within the same thread have the asymmetric, transitive, pair-wise relationship of "sequencing". This relationship can be defined as follows:
* If A is sequenced before B, then the evaluation of A will complete before the evaluation of B begins.
* If A and B are un-sequenced, then evaluations may be performed in any order and may overlap
* If A amd B are indeterminately sequenced, then their evaluations may be performed in any order but may not overlap

Exact sequencing rules for the evaluation of expressiosn can be found in [the C++ standard](https://en.cppreference.com/w/cpp/language/eval_order). 
