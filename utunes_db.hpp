#ifndef __UTUNES_DB__
#define __UTUNES_DB__

#include <vector>
#include "user.hpp"
#include "song_database.hpp"

struct UtunesDB
{
	UtunesDB();
	vector<User*> users;
	SongDB* song_database;
	~UtunesDB();
};

#endif