#include "song.hpp"

SongInfo::SongInfo(SongId _id, string _title, string _artist, unsigned int _release_year, string _link) :
id(_id), title(_title), artist(_artist), release_year(_release_year), link(_link), n_likes(0), n_comments(0), n_playlists(0) {}

Song::Song(SongInfo _info) : info(_info) {}

Song::~Song() {for (Comment* comment : comments) {delete comment;}}

void Song::like(string username)
{
	if(exist_in_vec<string>(username, liked_by)) {throw(BadRequest());}
	liked_by.push_back(username);
	info.n_likes++;
}

void Song::unlike(string username)
{
	int idx = get_idx_in_vec<string>(username, liked_by);
	if (idx<0) {throw(BadRequest());}
	liked_by.erase(liked_by.begin()+idx);
	info.n_likes--;
}

unsigned int Song::count_likes() {return liked_by.size();}

void Song::increase_n_playlists() {info.n_playlists++;}

void Song::add_comment(string commenter_username, unsigned int time, string comment)
{
	comments.insert(new Comment(commenter_username, time, comment));
	info.n_comments++;
}

vector<string> Song::get_comments()
{
	vector<string> str_comments;
	for (Comment* comment : comments)
	{
		ostringstream os;
		os << *comment;
		str_comments.push_back(os.str());
	}
	return str_comments;
}

SongId Song::get_id() {return info.id;}

SongInfo Song::get_info() {return info;}

bool cmpSongs::operator() (Song* song1, Song* song2) const {return (song1->get_id() < song2->get_id());}

