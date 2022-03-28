#include "song_list.hpp"

ostream& operator<<(ostream& os, const SongsInfo& songs_info)
{
    vector<string> songs_info_vec;
	for (SongInfo song_info : songs_info.info)
    {
    	stringstream temp;
	    temp << song_info.id << " " << song_info.title << " " 
	    << song_info.artist << " " << song_info.release_year;
	    songs_info_vec.push_back(temp.str());
    }
    os << songs_info_vec;
    return os;
}

void SongList::add_song(Song* song) {songs.insert(song);}

void SongList::remove_song (SongId song_id)
{
	Song* song = get_song_using_id(song_id);
	songs.erase(song);
}

SongInfo SongList::get_song_info(SongId id) {return get_song_using_id(id)->get_info();}

SongsInfo SongList::get_songs_info(const Filter& filter)
{
	SongsInfo songs_info;
	for (Song* song : filter.acceptable_songs(songs)) {songs_info.info.push_back(song->get_info());}
	return songs_info;
}

Song* SongList::get_song_using_id(SongId id)
{
	for (Song* song : songs) {if (id==song->get_id()) {return song;}}
	throw (NotFound());
}

bool SongList::contains_song(Song* song) {return (songs.find(song) != songs.end());}
