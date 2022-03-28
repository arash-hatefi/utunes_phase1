#include "playlist.hpp"

ostream& operator<<(ostream& os, const PlayListInfo& playlist_info)
{
    os << playlist_info.id << " " << playlist_info.name << " ";
    (playlist_info.publicity) ? (os << PUBLIC_INDICATOR) : (os << PRIVATE_INDICATOR);
    return os;
}

PlayListId str2playlistid(string input_string)
{
	if (!is_non_negative_int(input_string)) {throw(BadRequest());}
	return str2int(input_string);
}

unsigned int PlayList::total_made_lists = 0;

PlayList::PlayList(string _name, bool _public) : name(_name), publicity(_public) {set_id();}

void PlayList::add_song(Song* song)
{
	if (contains_song(song)) {throw(BadRequest());}
	songs.insert(song);
	song->increase_n_playlists();
}

PlayListId PlayList::get_id() {return id;}

bool PlayList::is_public() {return publicity;}

PlayListInfo PlayList::get_playlist_info() {return {id, name, publicity};}

void PlayList::set_id() {id = ++total_made_lists;}