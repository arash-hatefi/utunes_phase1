#ifndef __USER__
#define __USER__

#include <vector>
#include "utils.hpp"
#include "hash.hpp"
#include "playlist.hpp"
#include "errors.hpp"

struct User
{
	User(string email, string username, Hash password);
	~User();
	string email, username;
	Hash password;
	SongList liked_songs;
	vector<PlayList*> playlists;
};


#endif