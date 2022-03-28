#ifndef __INTERFACE__
#define __INTERFACE__

#include <string>
#include <map>
#include "utunes.hpp"
#include "utils.hpp"
#include "song.hpp"
#include "options.hpp"
#include "command.hpp"
#include "errors.hpp"


using namespace std;

const string POST_CATEGORY_KEY = "POST";
const string GET_CATEGORY_KEY = "GET";
const string DELETE_CATEGORY_KEY = "DELETE";

const string SIGNUP_CMD = "signup";
const string LOGIN_CMD = "login";
const string LOGOUT_CMD = "logout";
const string SONGS_CMD = "songs";
const string LIKES_CMD = "likes";
const string PLAYLISTS_CMD = "playlists";
const string PLAYLISTS_SONGS_CMD = "playlists_songs";
const string USERS_CMD = "users";
const string FILTERS_CMD = "filters";
const string COMMENTS_CMD = "comments";

const string EMAIL_KEYWORD = "email";
const string USERNAME_KEYWORD = "username";
const string PASSWORD_KEYWORD = "password";
const string ID_KEYWORD = "id";
const string NAME_KEYWORD = "name";
const string PRIVACY_KEYWORD = "privacy";
const string PLAYLIST_ID_KEYWORD = "playlist_id";
const string SONG_ID_KEYWORD = "song_id";
const string ARTIST_KEYWORD = "artist";
const string MIN_YEAR_KEYWORD = "min_year";
const string MAX_YEAR_KEYWORD = "max_year";
const string MIN_LIKE_KEYWORD = "min_like";
const string MAX_LIKE_KEYWORD = "max_like";
const string TIME_KEYWORD = "time";
const string COMMENT_KEYWORD = "comment";
const string PUBLIC_KEYWORD = "public";
const string PRIVATE_KEYWORD = "private";

const char OPTIONS_SEPERATOR = '?';
const char OPTION_TOKENS_SEPERATOR = ' ';
const char COMMAND_SEPERATOR = ' ';

const string CONFIRM_INDICATOR = "OK";

const set<string> KEYWORDS = {EMAIL_KEYWORD, USERNAME_KEYWORD, PASSWORD_KEYWORD, 
							  ID_KEYWORD, NAME_KEYWORD, PRIVACY_KEYWORD, 
							  PLAYLIST_ID_KEYWORD, SONG_ID_KEYWORD, ARTIST_KEYWORD, 
							  MIN_YEAR_KEYWORD, MAX_YEAR_KEYWORD, MIN_LIKE_KEYWORD, 
							  MAX_LIKE_KEYWORD, TIME_KEYWORD, COMMENT_KEYWORD, 
							  PUBLIC_KEYWORD, PRIVATE_KEYWORD};


class Interface
{
public:
	Interface(Utunes* utunes);
	void run();
private:

	Utunes* utunes;
	LoggedInUser* logged_in_user;

	Command process_input_cmd(string cmd_str);
	string get_cmd_type(string cmd_str);
	string get_cmd_subject(string cmd_str);
	Options get_cmd_options(string cmd_str);
	map<string, string> extract_options(string options_str);
	void handle_cmd(Command cmd);
	void handle_post_cmds(Command cmd);
	void handle_post_cmds_for_user(Command cmd);
	void handle_get_cmds(Command cmd);
	void handle_delete_cmds(Command cmd);
	void signup (Options options);
	void login (Options options);
	void logout (Options options);
	void post_likes (Options options);
	void post_playlists (Options options);
	void post_playlist_song (Options options);
	void post_filters (Options options);
	void post_comments (Options options);
	void get_songs (Options options);
	void get_likes (Options options);
	void get_playlists (Options options);
	void get_playlist_songs (Options options);
	void get_users (Options options);
	void get_comments (Options options);
	void delete_likes (Options options);
	void delete_playlist_songs (Options options);
	void delete_filters (Options options);
	template<typename T> void print(const T& object) const {cout<<object;}
	void print_error(string error);
};

#endif