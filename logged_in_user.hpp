#ifndef __LOGGED_IN_USER__
#define __LOGGED_IN_USER__

#include <string>
#include <vector>
#include <bits/stdc++.h> 

#include "utunes_db.hpp"
#include "combinatory_filter.hpp"
#include "min_year_filter.hpp"
#include "max_year_filter.hpp"
#include "min_like_filter.hpp"
#include "max_like_filter.hpp"
#include "artist_filter.hpp"
#include "no_filter.hpp"
#include "errors.hpp"
#include "song_list.hpp"


class LoggedInUser
{
public:
	LoggedInUser(UtunesDB* _utunes_db, User* _user);
	~LoggedInUser();
	SongsInfo get_songs_info();
	SongInfo get_song_info(SongId song_id);
	string get_username();
	void like_song(SongId song_id);
	void unlike_song(SongId song_id);
	SongsInfo get_liked_songs();
	PlayListId make_playlist(string playlist_name, bool is_public);
	vector<PlayListInfo> get_playlists(string username);
	void add_to_playlist(PlayListId playlist_id, SongId song_id);
	void delete_playlist_song(PlayListId playlist_id, SongId song_id);
	SongsInfo get_playlist_songs(PlayListId playlist_id);
	vector<string> get_all_users();
	void add_artist_filter(string artist_name);
	void add_time_filter(int min_year, int max_year);
	void add_like_filter(int min_like, int max_like);
	void delete_filters();
	void add_comment(SongId song_id, int time, string comment);
	vector<string> get_comments_on_song(SongId song_id);

private:
	UtunesDB* utunes_db;
	User* user;
	CombinatoryFilter* song_filter;
	User* find_user(string username);
};

#endif