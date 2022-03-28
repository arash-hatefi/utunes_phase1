#ifndef __ARTIST_FILTER__
#define __ARTIST_FILTER__

#include <set>
#include "song.hpp"
#include "errors.hpp"
#include "filter.hpp"

const string ARTIST_FILTER_TYPE = "artist";

class ArtistFilter : public Filter
{
public:
	ArtistFilter(string _artist);
	bool meet_criteria(Song* song) const;
	string get_type() const {return ARTIST_FILTER_TYPE;}
private:
	string artist;	
};

#endif