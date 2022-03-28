#include "filter.hpp"

set<Song*, cmpSongs> Filter::acceptable_songs(const set<Song*, cmpSongs>& songs) const
{
	set<Song*, cmpSongs> accepted_songs;
	for (Song* song : songs) {if (meet_criteria(song)) {accepted_songs.insert(song);}}
	return accepted_songs;
}

vector<Song*> Filter::acceptable_songs(const vector<Song*>& songs) const
{
	vector<Song*> accepted_songs;
	for (Song* song : songs) {if (meet_criteria(song)) {accepted_songs.push_back(song);}}
	return accepted_songs;
}