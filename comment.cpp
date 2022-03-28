#include "comment.hpp"

Comment::Comment(string _commenter_username, unsigned int _time, string _comment) :
commenter_username(_commenter_username), time(_time), comment(_comment) {}

string Comment::get_commenter_username() {return commenter_username;}

unsigned int Comment::get_time() {return time;}

ostream& operator<<(ostream& os, const Comment& comment)
{
    os << comment.time << " " << comment.commenter_username<< ": " << comment.comment;
    return os;
}

bool cmpComments::operator() (Comment* comment1, Comment* comment2) const
{
	if (comment1->get_time() == comment2->get_time())
	{
		return (comment1->get_commenter_username() <= comment2->get_commenter_username());
	}
	return (comment1->get_time() < comment2->get_time());
}