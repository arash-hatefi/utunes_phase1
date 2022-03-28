#ifndef __MAX_LIKE_FILTER__
#define __MAX_LIKE_FILTER__

#include <set>
#include "song.hpp"
#include "errors.hpp"
#include "filter.hpp"

const string MAX_LIKE_FILTER_TYPE = "max_like";

class MaxLikeFilter : public Filter
{
public:
	MaxLikeFilter(unsigned int _max_likes);
	bool meet_criteria(Song* song) const;
	string get_type() const {return MAX_LIKE_FILTER_TYPE;}
private:
	unsigned int max_like;	
};

#endif