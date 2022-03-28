#include "max_year_filter.hpp"

MaxYearFilter::MaxYearFilter(unsigned int _max_year)  : max_year(_max_year) {}

bool MaxYearFilter::meet_criteria(Song* song) const {return (song->get_info().release_year<=max_year);}