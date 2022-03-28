#ifndef __SONG_DB__
#define __SONG_DB__

#include <vector>
#include <string>
#include "song.hpp"
#include "utils.hpp"
#include "errors.hpp"
#include "song_list.hpp"

const string ID_KEY = "id";
const string TITLE_KEY = "title";
const string ARTIST_KEY = "artist";
const string YEAR_KEY = "release_year";
const string LINK_KEY = "link";


class SongDB : public SongList
{
public:
	SongDB();
	SongDB(const string& csv_path);
	~SongDB();
	void read_songs_form_csv(const string& csv_path);
private:
	void set_id();

};

#endif