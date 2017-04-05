#include <string>
#include "hashFunc.cpp"
int RabinKarp(std::string mainStr, std::string sub) {
	const int subLength = sub.size();
	long desiredSubStrHash = hashFunc(sub);
	long hs = hashFunc(mainStr.substr(0,sub.size()) );
	for (int i = 0;i < mainStr.size()-sub.size();i++){
	   	if (hs == desiredSubStrHash ){
	       	if (mainStr.substr(i,subLength) == sub ){
	           	return i;
	       	}
	   	}
	   	hs = hashFunc(mainStr.substr(i+1,subLength ));
	   }
return 0;
}
