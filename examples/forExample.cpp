#include <omp.h>
#include <stdio.h>
int main() {
	#pragma omp for schedule(dynamic)
 	for(int n=0; n<10; ++n) printf(" %d\n", n);
}