#include "functionTemplates.h"

// Explicit instantiation of function template echo specialization for type double
template void echo<double>(double);
// Explicit instantiation of function template echo specialization for type char (template argument deduced)
template void echo<>(char);
// Explicit instantiation of function template echo specialization for type int (template argument deduced)
template void echo(int);
