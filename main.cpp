#include <iostream>
#include <fstream> 
#include <stdio.h>
#include <string>
#include <math.h>
#include <ctime>
#include <vector>
#include <omp.h>
#define pathToTheFile "WP.txt"
#define NUMBER_OF_THR 4

long hashFunc(const std::string _inputString) {
	long sum = 0;
	for (int i = 0; i < _inputString.size(); ++i) {
		sum += (int)_inputString.at(i) * pow(101, _inputString.size() - i - 1);
	}
	return sum;
}

int RabinKarp(const std::string mainStr, const std::string sub, const int NUMBER_OF_THREADS) {
	int num = 0;
	const clock_t begin_time = clock();
	long desiredSubStrHash = hashFunc(sub);

#pragma omp parallel num_threads(NUMBER_OF_THREADS)  reduction(+:num) firstprivate(desiredSubStrHash) 
	{
#pragma omp for nowait
		for (int diapIter = 0; diapIter < mainStr.size(); diapIter++)
		{
			long _hs;
			if (diapIter == 0) {
				_hs = hashFunc(mainStr.substr(0, sub.size()));
			}
			if ((_hs == desiredSubStrHash) && (mainStr.substr(diapIter, sub.size()) == sub))
			{
				num++;
			}
			_hs = hashFunc(mainStr.substr(diapIter + 1, sub.size()));
		}
	}
	printf("time =  %f sec\n", (float(clock() - begin_time) / CLOCKS_PER_SEC));
	return num;
}

int main(int argc, char const *argv[]){
	std::string str,strTotal,ourSubString;
	std::ifstream in;
	in.open(pathToTheFile);
	while ( in ) {
		getline(in,str);
 	  	strTotal += str;
	}
	in.close();

	printf("Enter your substring\n");
	std::cin >> ourSubString;
	int result = RabinKarp(strTotal,ourSubString,NUMBER_OF_THR);

	printf("%d\n",result );
	return 0;
}