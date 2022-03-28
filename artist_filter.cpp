#include "artist_filter.hpp"

ArtistFilter::ArtistFilter(string _artist) : artist(_artist) {}

bool ArtistFilter::meet_criteria(Song* song) const {return (song->get_info().artist==artist);}