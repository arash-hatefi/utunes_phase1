#include "hash.hpp"

Hash myhash(string input_string) {return hash<string>{}(input_string);}

template<typename T> Hash myhash(T input)
{
	string input_string = to_string(input);
	return myhash(input_string);
}

template Hash myhash<int>(int input);
template Hash myhash<long>(long input);
template Hash myhash<long long>(long long input);
template Hash myhash<unsigned long>(unsigned long input);
template Hash myhash<unsigned long long>(unsigned long long input);
template Hash myhash<double>(double input);
template Hash myhash<long double>(long double input);
template Hash myhash<float>(float input);
template Hash myhash<char>(char input);