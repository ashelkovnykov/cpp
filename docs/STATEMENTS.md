# Statement

A C++ program is a sequence of commands executed in order. Statements are the commands which comprise the program. There are 7 types of statement:

1. Expression statement
2. Selection statement
3. Iteration statement
4. Jump statement
5. Declaration statement
6. Compound statement
7. Try block

## Expression Statement

The most common type of statement. Variable assignment, function calls, operations, and null statements are all expression statements.

## Selection Statement

A selection statement evaluates an expression to determine which of several statements should be executed. `if` and `switch` statements are selection statements.

## Iteration Statement

An iteration statement executes another statement multiple times (the exact number of which may be determined by an expression). `do`, `for`, "range" `for`, and `while` statements are iteration statements.

## Jump Statement

A jump statement modifies the flow of the program. `break`, `continue`, `return` and `goto` statements are jump statements.

## Declaration Statement

A declaration statement introduces one or more identifiers. `int i;` is an example of a declaration statement.

## Compound Statement

A compound statement groups multiple statements and declarations into a single unit which can be used anywhere where a single statement is expected. A compound statement is denoted by wrapping the component statements with braces (`{}`) to form what is called a "block" of code.

## Try Block

A try block is a special type of wrapper around a statement which has the ability to catch runtime exceptions. Though they can be large and complex, a try block is treated just like a compound statement.

## Labels

Any statement can be "labelled" by preceding it with an identifier followed by a colon. The provided identifier is the "label" for the statement and can be used as the input to `goto` to directly control program flow. The same statement can have multiple labels.
