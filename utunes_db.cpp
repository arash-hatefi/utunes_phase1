#include "utunes_db.hpp"

UtunesDB::UtunesDB() {song_database = new SongDB;}

UtunesDB::~UtunesDB()
{
	for (User* user : users) {delete user;}
	if(song_database!=nullptr) {delete song_database;}
}