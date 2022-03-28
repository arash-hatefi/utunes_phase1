#include "combinatory_filter.hpp"

CombinatoryFilter::CombinatoryFilter() {filters.push_back(new NoFilter());}

CombinatoryFilter::~CombinatoryFilter() {reset();}

void CombinatoryFilter::add_filter(Filter* new_filter)
{
	for (unsigned int idx=0; idx<filters.size(); idx++)
	{
		if(filters[idx]->get_type()==new_filter->get_type())
		{
			delete filters[idx];
			filters.erase(filters.begin()+idx);
		}
	}
	filters.push_back(new_filter);
}

void CombinatoryFilter::reset()
{
	{for (Filter* filter : filters) {delete filter;}}
	filters.clear();
}

bool CombinatoryFilter::meet_criteria(Song* song) const
{
	for (Filter* filter : filters) {if(!filter->meet_criteria(song)) {return false;}}
	return true;
}