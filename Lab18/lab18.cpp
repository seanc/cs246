#include <iostream>
#include <string>
#include "Array.h"
#include "Node.h"
#include "Iterator.h"
#include "List.h"
#include "Queue.h"
#include "Set.h"
#include "Stack.h"
#include "Deque.h"
#include <math.h>

int ToInteger(std::string num)
{
	int MIN = -2147483648;
	int MAX = 2147483647;

	int sum = 0;
	int sign = num[0] == '-' ? -1 : 1;
	ds::da::Stack<int> digits;
 
	if (num[0] == '-') {
		num = num.substr(1, num.length());
	}

	for (char digit : num) {
		if (digit >= '0' && digit <= '9') {
			digits.Push(digit - '0');
		} else {
			return MIN;
		}
	}

	int i = 0;
	while (!digits.IsEmpty()) {
		sum += pow(10, i) * digits.Top();
		digits.Pop();
		i++;
	}

	sum *= sign;

	if (sum < MIN || sum > MAX) {
		return MIN;
	}

	return sum;
}

// std::string ABStringWithExceptions(int m,int n)
// {
// 	int length = m + n;
// 	std::string out;
// 	if (m == n) {
// 		while (m > 0 || n > 0) {
// 			if (m > 0) {
// 				out += "A";
// 			}
// 			if (n > 0) {
// 				out += "B";
// 			}
// 			m--;
// 			n--;
// 		}
// 	} else if (abs(m - n) > length) {
// 		return "";
// 	} else {
// 		bool A = true;
// 		int cnt = 0; 
// 		while (m >= 0 || n >= 0) {
// 			std::cout << m << " " << n << " " << out << " - ";
// 			if (m > 0 && A) {
// 				if (cnt < 3) {
// 					out += "A";

// 					cnt++;
// 					m--;
// 				} else {
// 					A = false;
// 					cnt = 0;
// 				}
// 			} else if (n > 0 && !A) {
// 				if (cnt < 3) {
// 					out += "B";
// 					cnt++;
// 					n--;

// 				} else {
// 					A = true;
// 					cnt = 0;
// 				}
// 			}

// 			if (m == 0 && n > 0 || n == 0 && m > 0) {
// 				return "";
// 			}
// 		}
// 	}
// 	return out;
// }

int main()
{
	std::cout << ToInteger("-12323") << "\n";
	// std::cout << ABStringWithExceptions(7, 10);
	return 0;
}
