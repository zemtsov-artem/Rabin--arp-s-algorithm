#include <iostream>
#include <fstream> 
#include "../src/rabinPark.cpp"
#define pathToTheFile "../filesToRead/WP.txt"
#define NUMBER_OF_THR 2


int main(int argc, char const *argv[]){
	std::string str,strTotal,ourSubString;
	std::ifstream in;
	std::string tempStr = "firstsecondfirstthirdfourth";
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