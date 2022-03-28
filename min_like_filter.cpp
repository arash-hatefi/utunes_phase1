#include "min_like_filter.hpp"

MinLikeFilter::MinLikeFilter(unsigned int _min_like)  : min_like(_min_like) {}

bool MinLikeFilter::meet_criteria(Song* song) const {return (song->count_likes()>=min_like);}