// hash func transform string to value
// key is 101
// simple example hi = 104 * 101^1 + 105 * 101^0  (ANSII code h-104,i-105)
#include <stdio.h>
#include "string"
#include <math.h>
long hashFunc(std::string _inputValue) {
	int stringSize = _inputValue.size();
	long sum = 0;
	#pragma parallel for reduction(+:sum)
	for (int i = 0; i < stringSize; ++i) {
		sum += (int)_inputValue.at(i) * pow(101,stringSize - i -1);
	}
	return sum;
}

