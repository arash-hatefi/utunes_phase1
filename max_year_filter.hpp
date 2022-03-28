#ifndef __MAX_YEAR_FILTER__
#define __MAX_YEAR_FILTER__

#include <set>
#include "song.hpp"
#include "errors.hpp"
#include "filter.hpp"

const string MAX_YEAR_FILTER_TYPE = "max_year";

class MaxYearFilter : public Filter
{
public:
	MaxYearFilter(unsigned int _max_year);
	bool meet_criteria(Song* song) const;
	string get_type() const {return MAX_YEAR_FILTER_TYPE;}

private:
	unsigned int max_year;
};

#endif