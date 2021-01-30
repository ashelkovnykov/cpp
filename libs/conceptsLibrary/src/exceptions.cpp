#include <stdexcept>

#include "exceptions.h"

using namespace exceptionsExample;

void alwaysThrows(Colour c) {
  if (c == red) {
    throw std::logic_error("");
  } else if (c == blue) {
    throw std::runtime_error("");
  } else if (c == green) {
    throw std::exception();
  } else {
    throw 'z';
  }
}

/**
 * This class demonstrates the function-try-block. This block allows the user to catch exceptions in the function body (and the member initializer
 * list, if used for a constructor).
 *
 * Every catch statement in a function-try-block implicitly ends with a throw command, meaning that an external try-block is necessary. The following
 * are the purposes of a function-try-block:
 * - Catch errors in member initializer lists
 * - Log an exception and rethrow
 * - Modify a thrown exception
 * - Change what type of exception is thrown
 * - Early program termination
 */
struct AlwaysFailsToBuild {
  
  explicit AlwaysFailsToBuild(Colour c) try {
    alwaysThrows(c);
  } catch(const std::runtime_error& e) {
    throw std::logic_error("");
  }
};

/**
 * If an exception is not caught by an enclosing try-catch block, stack unwinding will continue until either program termination or a suitable catch
 * block is found.
 */
void exceptionCatcher() {
  
  try {
    try {
      try {
        AlwaysFailsToBuild A(red);
        AlwaysFailsToBuild B(blue);
        AlwaysFailsToBuild C(green);
        AlwaysFailsToBuild D(yellow);
      } catch (const std::logic_error& e) {
        // This is where red is caught
      } catch (const std::runtime_error& e) {
        // Never activated - blue is always converted to a logic_error by AlwaysFailsToBuild
      }
    } catch (const std::logic_error& e) {
      // Never activated - red is always caught by the inner catch block
    } catch (const std::exception& e) {
      // This is where green is caught
    } catch (...) {
      // This catch statement is implicitly appended to each try-catch block (it's how the stack unwinding is implemented): catch the exception, then
      // throw it up another level
      throw;
    }
  } catch (...) {
    // This is where yellow is caught
  }
  
}
