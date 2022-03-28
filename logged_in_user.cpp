#include "logged_in_user.hpp"

LoggedInUser::LoggedInUser(UtunesDB* _utunes_db, User* _user) : 
utunes_db(_utunes_db), user(_user) {song_filter = new CombinatoryFilter();}

LoggedInUser::~LoggedInUser() {delete song_filter;}

SongsInfo LoggedInUser::get_songs_info() {return utunes_db->song_database->get_songs_info(*song_filter);}

SongInfo LoggedInUser::get_song_info(SongId song_id) {return utunes_db->song_database->get_song_info(song_id);}

string LoggedInUser::get_username() {return user->username;}

void LoggedInUser::like_song(SongId song_id)
{
	Song* song = utunes_db->song_database->get_song_using_id(song_id);
	song->like(get_username());
	user->liked_songs.add_song(song);
}

void LoggedInUser::unlike_song(SongId song_id)
{
	Song* song = utunes_db->song_database->get_song_using_id(song_id);
	song->unlike(get_username());
	user->liked_songs.remove_song(song_id);
}

SongsInfo LoggedInUser::get_liked_songs() {return user->liked_songs.get_songs_info();}

PlayListId LoggedInUser::make_playlist(string playlist_name, bool is_public)
{
	PlayList* new_playlist = new PlayList(playlist_name, is_public);
	user->playlists.push_back(new_playlist);
	return new_playlist->get_id();
}

vector<PlayListInfo> LoggedInUser::get_playlists(string username)
{
	vector <PlayListInfo> playlists_info;
	User* wanted_user = find_user(username);
	for (PlayList* playlist : wanted_user->playlists)
	{if (playlist->is_public() || wanted_user==user) {playlists_info.push_back(playlist->get_playlist_info());}}
	return playlists_info;
}

void LoggedInUser::add_to_playlist(PlayListId playlist_id, SongId song_id)
{
	Song* song = utunes_db->song_database->get_song_using_id(song_id);
	for (PlayList* playlist : user->playlists)
	{
		if (playlist->get_id()==playlist_id)
		{
			playlist->add_song(song);
			return;
		}
	}
	throw(BadRequest());
}

void LoggedInUser::delete_playlist_song(PlayListId playlist_id, SongId song_id)
{
	for (PlayList* playlist : user->playlists)
	{
		if (playlist->get_id()==playlist_id)
		{
			playlist->remove_song(song_id);
			return;
		}
	}
	throw(BadRequest());
}

SongsInfo LoggedInUser::get_playlist_songs(PlayListId playlist_id)
{
	for (User* other_user : utunes_db->users)
	{
		for (PlayList* playlist : other_user->playlists)
		{
			if (playlist->get_id()==playlist_id)
			{
				if(other_user!=user && !playlist->is_public()) {throw(PermissionDenied());}
				return playlist->get_songs_info();
			}
		}
	}
	throw(NotFound());
}

vector<string> LoggedInUser::get_all_users()
{
	vector<string> usernames;
	for (User* other_user : utunes_db->users)
	{
		if(user!=other_user) {usernames.push_back(other_user->username);}
	}
	sort(usernames.begin(), usernames.end()); 
	return usernames;
}

void LoggedInUser::add_artist_filter(string artist_name)
{
	Filter* f = new ArtistFilter(artist_name);
	song_filter->add_filter(new ArtistFilter(artist_name));
}

void LoggedInUser::add_time_filter(int min_year, int max_year)
{
	if(min_year<0 || max_year<0 || (max_year<min_year)) {throw(BadRequest());}
	song_filter->add_filter(new MinYearFilter(min_year));
	song_filter->add_filter(new MaxYearFilter(max_year));
}

void LoggedInUser::add_like_filter(int min_like, int max_like)
{
	if(min_like<0 || max_like<0 || (max_like<min_like)) {throw(BadRequest());}
	song_filter->add_filter(new MinLikeFilter(min_like));
	song_filter->add_filter(new MaxLikeFilter(max_like));
}

void LoggedInUser::delete_filters() {song_filter->reset();}

void LoggedInUser::add_comment(SongId song_id, int time, string comment)
{
	if (time<0) {throw(BadRequest());}
	Song* song = utunes_db->song_database->get_song_using_id(song_id);
	song->add_comment(user->username, time, comment);
}

vector<string> LoggedInUser::get_comments_on_song(SongId song_id)
{
	Song* song = utunes_db->song_database->get_song_using_id(song_id);
	return song->get_comments();
}

User* LoggedInUser::find_user(string username)
{
	for (User* other_user : utunes_db->users) {if (other_user->username==username) {return other_user;}}
	throw(NotFound());
}