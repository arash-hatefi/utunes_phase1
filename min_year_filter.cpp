#include "min_year_filter.hpp"

MinYearFilter::MinYearFilter(unsigned int _min_year)  : min_year(_min_year) {}

bool MinYearFilter::meet_criteria(Song* song) const {return (song->get_info().release_year>=min_year);}