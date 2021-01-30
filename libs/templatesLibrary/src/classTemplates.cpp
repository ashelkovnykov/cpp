#include "classTemplates.h"

void classTemplateDemonstration() {
  
  // Valid use of A: i uses default type int and default value 100
  auto a1 = T_A<>();
  // Valid use of A: i uses default value of 100
  auto a2 = T_A<short>();
  // Valid use of A: i set to 2
  auto a3 = T_A<short, 42>();
  // Valid use of A: 'b' can be converted to an short
  auto a4 = T_A<short, 'b'>();
  // Invalid use of A: cannot convert array of char to short
//  auto a5 = A<short, "ppp">();
  // Valid use of A: doesn't use deduction guide above since template parameter explicitly specified
  auto a6 = T_A<long>();
  // Valid use of A: uses deduction guide above
  auto a7 = T_A((long)36);
  
  auto b1 = T_B<T_A>();
  
}
