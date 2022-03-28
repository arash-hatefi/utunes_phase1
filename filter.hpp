#ifndef __FILTER__
#define __FILTER__

#include <set>
#include "song.hpp"
#include "errors.hpp"

class Filter
{
public:
	set<Song*, cmpSongs> acceptable_songs(const set<Song*, cmpSongs>& songs) const;
	vector<Song*> acceptable_songs(const vector<Song*>& songs)const;
	virtual bool meet_criteria(Song* song) const {return true;};
	virtual string get_type() const = 0;
};

#endif