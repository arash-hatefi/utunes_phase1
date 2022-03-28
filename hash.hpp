#ifndef __HASH__
#define __HASH__

#include <string>
#include <functional> 

using namespace std;

typedef int Hash;

Hash myhash(string input_string);

template<typename T> Hash myhash(T input);

#endif