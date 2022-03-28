#ifndef __PLAYLIST__
#define __PLAYLIST__


#include <string>
#include "song_list.hpp"

using namespace std;

const string PUBLIC_INDICATOR = "public";
const string PRIVATE_INDICATOR = "private";

typedef unsigned int PlayListId;

PlayListId str2playlistid(string input_string);

struct PlayListInfo
{
	PlayListId id;
	string name;
	bool publicity;
};

ostream& operator<<(ostream& os, const PlayListInfo& playlist_info);

class PlayList : public SongList
{
public:
	PlayList(string _name, bool _public);
	void add_song(Song* song);
	PlayListId get_id();
	bool is_public();
	PlayListInfo get_playlist_info();

private:
	PlayListId id;
	string name;
	bool publicity;
	static unsigned int total_made_lists;
	void set_id();
};

#endif