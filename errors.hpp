#ifndef __ERRORS__
#define __ERRORS__

#include <bits/stdc++.h> 
#include "utils.hpp"
  
using namespace std; 

const string BAD_REQUEST_ERROR = "Bad Request";
const string NOT_FOUND_ERROR = "Not Found";
const string PERMISION_DENIED_ERROR = "Permission Denied";
const string CSV_ERROR = "Error occured while reading";

struct BadRequest : exception 
{ 
    const char* what() const noexcept {return BAD_REQUEST_ERROR.c_str();} 
};

struct NotFound : exception 
{ 
    const char* what() const noexcept {return NOT_FOUND_ERROR.c_str();} 
};

struct PermissionDenied : exception 
{ 
    const char* what() const noexcept {return PERMISION_DENIED_ERROR.c_str();} 
};

class CSVError : exception 
{ 
public:
    CSVError(string _csv_path) : csv_path(_csv_path) {}
    const char* what() const noexcept {return format(CSV_ERROR, csv_path).c_str();} 
    
private: 
    string csv_path;
};


#endif
 