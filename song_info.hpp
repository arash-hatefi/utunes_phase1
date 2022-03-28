#ifndef __SONG_INFO__
#define __SONG_INFO__

#include <string>
#include "utils.hpp"
#include "errors.hpp"

using namespace std;


const string LIKES_COUNTER_INDICATOR = "#likes: ";
const string COMMENTS_COUNTER_INDICATOR = "#comments: ";
const string PLAYLIST_COUNTER_INDICATOR = "#playlists: ";

typedef unsigned int SongId;

SongId str2songid(string input_string);


struct SongInfo
{
	SongInfo(SongId _id, string _title, string _artist, unsigned int _release_year, string _link);
	SongId id;
	string title;
	string artist;
	unsigned int release_year;
	string link;
	unsigned int n_likes;
	unsigned int n_comments;
	unsigned int n_playlists;
};

ostream& operator<<(ostream& os, const SongInfo& song_info);

#endif
