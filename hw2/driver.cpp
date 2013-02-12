
#include "quaternion.h"

int main()
{
	Quaternion<int> h;
	Quaternion<int> p(4, 6, 1, 9);
	h = p;
	return 0;
}
