#ifndef __MIN_LIKE_FILTER__
#define __MIN_LIKE_FILTER__

#include <set>
#include "song.hpp"
#include "errors.hpp"
#include "filter.hpp"

const string MIN_LIKE_FILTER_TYPE = "min_like";

class MinLikeFilter : public Filter
{
public:
	MinLikeFilter(unsigned int _min_likes);
	bool meet_criteria(Song* song) const;
	string get_type() const {return MIN_LIKE_FILTER_TYPE;}
private:
	unsigned int min_like;	
};

#endif