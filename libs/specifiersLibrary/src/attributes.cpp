#include "attributes.h"

int attributeExample [[deprecated]] (int x) {
  switch (x) {
    case 99: [[fallthrough]];
    case 100: [[unlikely]];
      return 0;
    default: [[likely]];
      return (x - 1);
  }
}
