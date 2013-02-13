
#include "quaternion.h"

int main()
{
  Quaternion<int> h1;
  Quaternion<int> h2(4, 6, 1, 9);
  h1 = h2;
  Quaternion<int> h3(4, 6, 1, 9);
  h1 = h2 * h3;
  return 0;
}
