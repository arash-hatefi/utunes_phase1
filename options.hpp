#ifndef __OPTIONS__
#define __OPTIONS__

#include <map>
#include <string>
#include "errors.hpp"

using namespace std;

class Options 
{ 
public: 
	Options(map<string,string> _options); 
	string& operator[](string key);
	unsigned int count(string key);
private:  
	map<string, string> options;
};

#endif