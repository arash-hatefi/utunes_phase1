#ifndef __SONG_LIST__
#define __SONG_LIST__

#include <string>
#include <set>
#include "song.hpp"
#include "errors.hpp"
#include "combinatory_filter.hpp"
#include "min_year_filter.hpp"
#include "max_year_filter.hpp"
#include "min_like_filter.hpp"
#include "max_like_filter.hpp"
#include "artist_filter.hpp"
#include "no_filter.hpp"

struct SongsInfo {vector<SongInfo> info;};

ostream& operator<<(ostream& os, const SongsInfo& songs_info);

class SongList
{
public:
	virtual void add_song(Song* song);
	void remove_song (SongId song_id);
	SongInfo get_song_info(SongId id);
	SongsInfo get_songs_info(const Filter& filter=CombinatoryFilter());
	Song* get_song_using_id(SongId id);

protected:
	set<Song*, cmpSongs> songs;
	bool contains_song(Song* song);

private:
	
};


#endif