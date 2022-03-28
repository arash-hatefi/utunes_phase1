#ifndef __UTILS__
#define __UTILS__

#include <string>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

const string CSV_DELIMITER = ",";
const string EMPTY_INDICATOR = "Empty";

string char2str(char c);

template<typename T> ostream& operator<<(ostream& os, const vector<T>& vec)
{
	if (vec.empty()) {os << EMPTY_INDICATOR;}
	else
	{
		for (unsigned int idx=0; idx<vec.size()-1; idx++) {os << vec[idx] <<endl;}
		os << vec[vec.size()-1];
	}
	return os;
}

template<typename T> bool exist_in_vec(const T& val, const vector<T>& vec)
{
	for (unsigned int idx=0; idx<vec.size(); idx++) {if(vec[idx]==val) {return true;}}
	return false;
}

template<typename T> int get_idx_in_vec(const T& val, const vector<T>& vec)
{
	for (unsigned int idx=0; idx<vec.size(); idx++) {if(vec[idx]==val) {return idx;}}
	return -1;
}

bool is_non_negative_int(const string& input_string);

int str2int(const string &input_string);

template<typename T> struct Table
{
	vector<vector<T>> content;
	map<string, unsigned int> column_keys;
	map<string, unsigned int> row_keys;
};

vector<string> split(string input_string, const string& delimiter=" ");

string get_token(const string& input_string, unsigned int token_idx, const string& delimiter=" ");

string remove_lead_trail_useless_chars(string input_string, char useless_char=' ');

string format(const string& format, ...);

Table<string> read_csv(const string &file_path);



#endif