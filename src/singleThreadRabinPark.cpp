#include <string>
#include "hashFunc.cpp"
int singleThreadRabinPark(std::string mainStr, std::string sub) {
	int result = 0;
	long desiredSubStrHash = hashFunc(sub);
	long hs = hashFunc(mainStr.substr(0,sub.size()) );
	for (int i = 0; i < mainStr.size()-sub.size();i++){
	   	if ((hs == desiredSubStrHash ) && (mainStr.substr(i,sub.size()) == sub )){
			result++;
	   	}

	   	hs = hashFunc(mainStr.substr(i+1,sub.size() ));
	   }
	return result;
}