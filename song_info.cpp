#include "song_info.hpp"

ostream& operator<<(ostream& os, const SongInfo& song_info)
{
    os << song_info.id <<endl
       << song_info.title << endl
       << song_info.artist<< endl
       << song_info.release_year << endl
       << LIKES_COUNTER_INDICATOR << song_info.n_likes << endl
       << COMMENTS_COUNTER_INDICATOR << song_info.n_comments << endl
       << PLAYLIST_COUNTER_INDICATOR << song_info.n_playlists;
    return os;
}

SongId str2songid(string input_string) 
{
	if (!is_non_negative_int(input_string)) {throw(BadRequest());}
	return str2int(input_string);
}