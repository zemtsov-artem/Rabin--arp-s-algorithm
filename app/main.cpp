#include <iostream>
#include "../src/rabinPark.cpp"

int main(int argc, char const *argv[])
{
	std::string ourSubString = " ";
	std::cout << "Enter your substring" << std::endl;
	std::cin >> ourSubString;
	int result = RabinKarp("Thesimplesentence,whereyoucanfindyoursubstring",ourSubString);
	if (result) {
		std::cout << result <<std::endl;
	}
	else {
		std::cout << "Not found" <<std::endl;
	}
	return 0;
}