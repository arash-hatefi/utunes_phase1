#ifndef __MIN_YEAR_FILTER__
#define __MIN_YEAR_FILTER__

#include <set>
#include "song.hpp"
#include "errors.hpp"
#include "filter.hpp"


const string MIN_YEAR_FILTER_TYPE = "min_year";


class MinYearFilter : public Filter
{
public:
	MinYearFilter(unsigned int _min_year);
	bool meet_criteria(Song* song) const;
	string get_type() const {return MIN_YEAR_FILTER_TYPE;}
private:
	unsigned int min_year;
};

#endif