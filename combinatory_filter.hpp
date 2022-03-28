#ifndef __COMBINAROTY_FILTER__
#define __COMBINAROTY_FILTER__

#include <set>
#include "song.hpp"
#include "errors.hpp"
#include "filter.hpp"
#include "no_filter.hpp"

const string COMBINATORY_FILTER_TYPE = "combinatory";

class CombinatoryFilter : public Filter
{
public:
	CombinatoryFilter();
	~CombinatoryFilter();
	void add_filter(Filter* filter);
	bool meet_criteria(Song* song) const;
	void reset();
	string get_type() const {return COMBINATORY_FILTER_TYPE;}
private:
	vector<Filter*> filters;
};

#endif