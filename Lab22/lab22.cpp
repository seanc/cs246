#include <iostream>
#include <string>
#include "Node.h" 

int Tribonacci(int n)
{
	if (n <= 0) {
		return 0;
	} else if (n == 1 || n == 2) {
		return 1;
	} else if (n >= 3) {
		int series[n + 1];
		series[0] = 0;
		series[1] = 1;
		series[2] = 1;
		for (int i = 3; i <= n; i++) {
			series[i] = series[i - 1] + series[i - 2] + series[i - 3];
		}
		return series[n];
	}
}

int MissingSequentialMultiple(ds::dn::Node<int>* data,int n,int i)
{
	return 0;
}

int main()
{
	std::cout << Tribonacci(5);
	return 0;
}
