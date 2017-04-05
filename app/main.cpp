#include <iostream>
#include <fstream> 
#include "../src/rabinPark.cpp"
#define pathToTheFile "../filesToRead/WP.txt"


int main(int argc, char const *argv[]){
	std::string ourSubString,str,strTotal;
	std::ifstream in;
	in.open(pathToTheFile);
	while ( in ) {
		getline(in,str);
 	  	strTotal += str;
	}

	std::cout <<"You work with War and Peace" << std::endl 
			  << "Enter desired substring" << std::endl;
	std::cin >> ourSubString;
	int result = RabinKarp(strTotal,ourSubString);
	(result != 0) ? std::cout << result <<std::endl  : std::cout << "Not found" <<std::endl;
	return 0;
}