#include <string>
#include "hashFunc.cpp"
int RabinKarp(std::string s, std::string sub) {
		long substringHash = hashFunc(sub);
		long hsub = substringHash;

		long hs = hashFunc(s.substr(1,sub.size()) );
		for (int i = 1;i < (s.size()-sub.size()+1);i++){
	    	if (hs = hsub ){
	        	if (s.substr(i,i+sub.size()-1) == sub ){
	            	return i;
	        	}
	    	}
	    	hs = hashFunc(s.substr(i+1,i+sub.size() ));
	    }
		return 0;
	}
