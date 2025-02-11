# Subtle NullPointerException with Nullable Ints in Hack

This repository demonstrates a subtle bug that can occur in Hack when using nullable integer types (`?int`). The bug arises from the implicit behavior of the `+` operator with nullable types.  If a nullable int is null, the addition will throw a runtime exception, which can be hard to debug.

## Bug Description
The bug is showcased in the `bug.hh` file.  Initially, the code uses standard ints. However, changing to nullable ints introduces the possibility of a runtime error if a null value propagates through the function calls.

## Solution
The solution, found in `bugSolution.hh`, addresses this issue by explicitly checking for null values before performing the addition.

## How to Reproduce
1. Clone this repository.
2. Compile and run the `bug.hh` file.  The initial version with non-nullable ints will work.
3. Modify the type hints to use nullable ints (`?int`). Recompile and run. The code will now throw an exception if a null value is encountered.
4. Compare to the solution provided in `bugSolution.hh` which demonstrates safe handling of nullable ints. 