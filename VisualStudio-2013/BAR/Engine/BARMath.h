#ifndef MATH_H
#define MATH_H

namespace Mathf
{
	//returns the minimum of two ints
	inline int Min(int x, int y)
	{
		int a = x - y;
		return (x - (a & ~(a >> 31)));
	}

	//returns the maximum of two ints
	inline int Max(int x, int y)
	{
		int a = x - y;
		return (x - (a & (a >> 31)));
	}
}

#endif