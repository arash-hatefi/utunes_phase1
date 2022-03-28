#include "song_database.hpp"

SongDB::SongDB() : SongList() {}

SongDB::SongDB(const string& csv_path) : SongList() {read_songs_form_csv(csv_path);}

SongDB::~SongDB() {for (Song* song : songs) delete song;}

void SongDB::read_songs_form_csv(const string& csv_path)
{
	try
	{
		Table<string> table = read_csv(csv_path);
		for (vector<string> row : table.content)
		{
			SongInfo new_song_info = {str2songid(row[table.column_keys[ID_KEY]]), 
									  row[table.column_keys[TITLE_KEY]],
									  row[table.column_keys[ARTIST_KEY]],
									  (unsigned int) str2int(row[table.column_keys[YEAR_KEY]]), 
							          row[table.column_keys[LINK_KEY]]};
			songs.insert(new Song(new_song_info));
		}
	}
	catch (...) {throw(CSVError(csv_path));}
}

void SongDB::set_id() {}