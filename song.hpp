#ifndef __SONG__
#define __SONG__

#include <vector>
#include <set>
#include <string>
#include <iostream>
#include "errors.hpp"
#include "utils.hpp"
#include "song_info.hpp"
#include "comment.hpp"

using namespace std;

class Song
{

public:
	Song(SongInfo _info);
	~Song();
	void like(string username);
	void unlike(string username);
	unsigned int count_likes();
	void increase_n_playlists();
	void add_comment(string commenter_username, unsigned int time, string comment);
	vector<string> get_comments();
	SongId get_id();
	SongInfo get_info();
	
private:
	SongInfo info;
	vector<string> liked_by;
	set<Comment*, cmpComments> comments;

};

struct cmpSongs { bool operator() (Song* song1, Song* song2) const; };


#endif