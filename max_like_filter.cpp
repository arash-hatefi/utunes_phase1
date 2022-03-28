#include "max_like_filter.hpp"

MaxLikeFilter::MaxLikeFilter(unsigned int _max_like)  : max_like(_max_like) {}

bool MaxLikeFilter::meet_criteria(Song* song) const {return (song->count_likes()<=max_like);}