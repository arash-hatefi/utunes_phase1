#include "utils.hpp"


string char2str(char c) 
{
    string s(1, c); 
    return s;    
}

bool is_non_negative_int(const string& input_string)
{
    for (char c : input_string) {if(!isdigit(c)) {return false;}}
    return true;
}

int str2int(const string &input_string) {return stoi(input_string);}


vector<string> split(string input_string, const string& delimiter)
{
	vector<string> result;	
	size_t pos = 0;
	string token;
	while ((pos = input_string.find(delimiter)) != string::npos)
	{
		token = input_string.substr(0, pos);
	    if (token.size()>0) {result.push_back(token);}
	    input_string.erase(0, pos + delimiter.length());
	}
	if (!input_string.empty()) {result.push_back(input_string);}
	return result;
}

string get_token(const string& input_string, unsigned int token_idx, const string& delimiter)
{
	vector<string> tokens = split(input_string, delimiter);
	return (token_idx>=tokens.size()) ? "" : tokens[token_idx];
}

string remove_lead_trail_useless_chars(string input_string, char useless_char)
{
	while(*input_string.begin()==useless_char) {input_string.erase(input_string.begin());}
	while(*(input_string.end()-1)==useless_char) {input_string.erase(input_string.end()-1);}
	return input_string;
}

string format(const string& format, ...)
{
    va_list args;
    va_start (args, format);
    size_t len = vsnprintf(NULL, 0, format.c_str(), args);
    va_end (args);
    vector<char> vec(len + 1);
    va_start (args, format);
    vsnprintf(&vec[0], len + 1, format.c_str(), args);
    va_end (args);
    return &vec[0];
}

Table<string> read_csv(const string &file_path)
{
	fstream file;
	file.open(file_path);

	vector<vector<string>> content;
	map<string, unsigned int> column_keys;
	string line;

	getline(file, line);
	unsigned int idx = 0;
	for (string column_title : split(line, CSV_DELIMITER)) {column_keys[column_title] = (idx++);}

	while(getline(file, line)) {content.push_back(split(line, CSV_DELIMITER));}

	Table<string> table;
	table.content = content;
	table.column_keys = column_keys;
	return table;
}