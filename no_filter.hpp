#ifndef __NO_FILTER__
#define __NO_FILTER__

#include <set>
#include "song.hpp"
#include "errors.hpp"
#include "filter.hpp"


const string NO_FILTER_TYPE = "none";

class NoFilter : public Filter
{
public:
	NoFilter();	
	bool meet_criteria(Song* song) const;
	string get_type() const {return NO_FILTER_TYPE;}
};

#endif