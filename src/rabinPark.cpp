#include <string>
#include <ctime>
#include <vector>
#include <omp.h>
#include "singleThreadRabinPark.cpp"

//omp_get_thread_num - number of thread
//omp_get_num_threads() - all threads count
int RabinKarp(std::string mainStr, std::string sub,int NUMBER_OF_THREADS) {
	int num = 0;
	int lastPlotSize = 0,lastThreadSize = 0;
	const clock_t begin_time = clock();
	const long desiredSubStrHash = hashFunc(sub);
	const int numberOfPlots = mainStr.size() / sub.size();

	(mainStr.size() % sub.size())  ?
			lastPlotSize = mainStr.size() % sub.size() + sub.size() :
			lastPlotSize = sub.size();

	#pragma omp parallel num_threads(NUMBER_OF_THREADS) 
	{	
		const int threadsDiap = numberOfPlots / omp_get_num_threads();

		(numberOfPlots % omp_get_num_threads()) ?
				lastThreadSize = threadsDiap + numberOfPlots % omp_get_num_threads() :
				lastThreadSize = threadsDiap;

		if (omp_get_num_threads() == 1) {
			num = singleThreadRabinPark(mainStr,sub);
		}
		else {
			#pragma parallel for reduction(+:num)
			for (int i = 0; i < sub.size() * threadsDiap ; i++)
			{
				long hs;
				if (!i) {
					hs = hashFunc(mainStr.substr(0,sub.size()) );
				}
				int startPos = sub.size() * threadsDiap * omp_get_thread_num() + i ;
				if ((hs == desiredSubStrHash )&&(mainStr.substr(startPos,sub.size()) == sub )){
			       	//#pragma omp atomic
			        num++;
			   	}
			   	hs = hashFunc(mainStr.substr(startPos+1,sub.size() ));	
			}
		}
	}
	printf("time =  %f sec\n" ,(float(clock () - begin_time ) / CLOCKS_PER_SEC)); 
	return num;
}
