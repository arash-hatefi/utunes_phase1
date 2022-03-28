#ifndef __COMMENT__
#define __COMMENT__

#include <string>
#include <iostream>

using namespace std;

class Comment
{

public:
	Comment(string _commenter_username, unsigned int _time, string _comment);
	string get_commenter_username();
	unsigned int get_time();
	friend ostream& operator<<(ostream& os, const Comment& comment);

private:
	string commenter_username;
	unsigned int time;
	string comment;
};

ostream& operator<<(ostream& os, const Comment& comment);

struct cmpComments { bool operator() (Comment* comment1, Comment* comment2) const; };


#endif