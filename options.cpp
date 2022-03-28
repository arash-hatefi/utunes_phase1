#include "options.hpp"

Options::Options(map<string,string> _options) : options(_options) {}

string& Options::operator[](string key)
{
	try {return options.at(key);}
	catch(out_of_range& e) {throw(BadRequest());}
} 

unsigned int Options::count(string key) {return options.count(key);}
