#include "interface.hpp"


Interface::Interface(Utunes* _utunes) : utunes(_utunes), logged_in_user(nullptr) {}

void Interface::run()
{
	string line;
	bool first_line = true;
	while (getline(cin, line))
	{
		if (first_line) {first_line=false;}
		else {print('\n');}
		if (line.empty()) {continue;}
		try {handle_cmd(process_input_cmd(line));}
		catch (exception& e) {print_error(e.what());}
	}
}

Command Interface::process_input_cmd(string cmd_str)
{
	cmd_str = remove_lead_trail_useless_chars(cmd_str);
	string category = get_cmd_type(cmd_str);
	string subject = get_cmd_subject(cmd_str);
	Options options = get_cmd_options(cmd_str);
	return {category, subject, options};
}

string Interface::get_cmd_type(string cmd_str)
{
	string cmd_type = get_token(cmd_str, 0, char2str(COMMAND_SEPERATOR));
	return cmd_type;
}

string Interface::get_cmd_subject(string cmd_str)
{
	string subject_with_type = get_token(cmd_str,0, char2str(OPTIONS_SEPERATOR));
	unsigned int seperator_idx = subject_with_type.find(COMMAND_SEPERATOR);
	if (seperator_idx>subject_with_type.size()) {return "";}
	string subject = subject_with_type.substr(seperator_idx+1);
	return remove_lead_trail_useless_chars(subject);
}

Options Interface::get_cmd_options(string cmd_str)
{
	string options_str = get_token(cmd_str, 1, char2str(OPTIONS_SEPERATOR));
	return Options(extract_options(options_str));
}

map<string, string> Interface::extract_options(string options_str)
{
	if (options_str.empty()) {return {};}
	options_str = remove_lead_trail_useless_chars(options_str, OPTION_TOKENS_SEPERATOR);
	for (const string keyword : KEYWORDS)
	{
		if (options_str.find(keyword+OPTION_TOKENS_SEPERATOR)==0)
		{
			options_str = options_str.substr(keyword.size());
			long unsigned int next_keyword_pos = options_str.size();
			for (const string next_keyword : KEYWORDS) 
			{next_keyword_pos = min(next_keyword_pos, options_str.find(OPTION_TOKENS_SEPERATOR+next_keyword+OPTION_TOKENS_SEPERATOR));}
			map<string, string> options = {{keyword, remove_lead_trail_useless_chars(options_str.substr(0,next_keyword_pos), OPTION_TOKENS_SEPERATOR)}};
			map<string, string> other_options = extract_options(options_str.substr(next_keyword_pos));
			options.insert(other_options.begin(), other_options.end());
			return options;
		}
	}
	throw(BadRequest());
}

void Interface::handle_cmd(Command cmd)
{
	if (cmd.category==POST_CATEGORY_KEY) {handle_post_cmds(cmd);}
	else if (cmd.category==GET_CATEGORY_KEY) {handle_get_cmds(cmd);}
	else if (cmd.category==DELETE_CATEGORY_KEY) {handle_delete_cmds(cmd);}
	else {throw(BadRequest());}
}

void Interface::handle_post_cmds(Command cmd)
{
	if (logged_in_user==nullptr)
	{
		if (cmd.subject==SIGNUP_CMD) {signup(cmd.options);}
		else if (cmd.subject==LOGIN_CMD) {login(cmd.options);}
		else {throw(PermissionDenied());}
	}
	else {handle_post_cmds_for_user(cmd);}
}

void Interface::handle_post_cmds_for_user(Command cmd)
{
	if (cmd.subject==SIGNUP_CMD || cmd.subject==LOGIN_CMD) {throw(BadRequest());}
	else if (cmd.subject==LOGOUT_CMD) {logout(cmd.options);}
	else if (cmd.subject==LIKES_CMD) {post_likes(cmd.options);}
	else if (cmd.subject==PLAYLISTS_CMD) {post_playlists(cmd.options);}
	else if (cmd.subject==PLAYLISTS_SONGS_CMD) {post_playlist_song(cmd.options);}
	else if (cmd.subject==FILTERS_CMD) {post_filters(cmd.options);}
	else if (cmd.subject==COMMENTS_CMD) {post_comments(cmd.options);}
	else {throw(NotFound());}
}

void Interface::handle_get_cmds(Command cmd)
{
	if (logged_in_user==nullptr) {throw(PermissionDenied());}
	if (cmd.subject==SONGS_CMD) {get_songs(cmd.options);}
	else if (cmd.subject==LIKES_CMD) {get_likes(cmd.options);}
	else if (cmd.subject==PLAYLISTS_CMD) {get_playlists(cmd.options);}
	else if (cmd.subject==PLAYLISTS_SONGS_CMD) {get_playlist_songs(cmd.options);}
	else if (cmd.subject==USERS_CMD) {get_users(cmd.options);}
	else if (cmd.subject==COMMENTS_CMD) {get_comments(cmd.options);}
	else {throw(NotFound());}
}

void Interface::handle_delete_cmds(Command cmd)
{
	if (logged_in_user==nullptr) {throw(PermissionDenied());}
	if (cmd.subject==LIKES_CMD) {delete_likes(cmd.options);}
	else if (cmd.subject==PLAYLISTS_SONGS_CMD) {delete_playlist_songs(cmd.options);}
	else if (cmd.subject==FILTERS_CMD) {delete_filters(cmd.options);}
	else {throw(NotFound());}
}

void Interface::signup (Options options)
{
	string email = options[EMAIL_KEYWORD];
	string username = options[USERNAME_KEYWORD];
	string password = options[PASSWORD_KEYWORD];
	logged_in_user = utunes -> signup(email, username, password);
	print(CONFIRM_INDICATOR);
}

void Interface::login (Options options)
{
	string email = options[EMAIL_KEYWORD];
	string password = options[PASSWORD_KEYWORD];
	logged_in_user = utunes -> login(email, password);
	print(CONFIRM_INDICATOR);
}

void Interface::logout (Options options)
{
	utunes -> logout(logged_in_user->get_username());
	logged_in_user = nullptr;
	print(CONFIRM_INDICATOR);
}

void Interface::post_likes (Options options)
{
	SongId song_id = str2songid(options[ID_KEYWORD]);
	logged_in_user->like_song(song_id);
	print(CONFIRM_INDICATOR);
}

void Interface::post_playlists (Options options)
{	
	string name = options[NAME_KEYWORD];
	string privacy = options[PRIVACY_KEYWORD];
	bool is_public;
	if (privacy==PRIVATE_KEYWORD) {is_public=false;}
	else if (privacy==PUBLIC_KEYWORD) {is_public=true;}
	else {throw(BadRequest());}
	PlayListId id = logged_in_user->make_playlist(name, is_public);
	print(id);
}

void Interface::post_playlist_song (Options options)
{
	PlayListId playlist_id = str2playlistid(options[PLAYLIST_ID_KEYWORD]);
	SongId song_id = str2songid(options[SONG_ID_KEYWORD]);
	logged_in_user->add_to_playlist(playlist_id, song_id);
	print(CONFIRM_INDICATOR);
}

void Interface::post_filters (Options options)
{
	if (options.count(ARTIST_KEYWORD))
	{
		string artist = options[ARTIST_KEYWORD];
		logged_in_user->add_artist_filter(artist);
	}
	else if (options.count(MIN_YEAR_KEYWORD) && options.count(MAX_YEAR_KEYWORD))
	{
		string min_year = options[MIN_YEAR_KEYWORD];
		string max_year = options[MAX_YEAR_KEYWORD];
		logged_in_user->add_time_filter(str2int(min_year), str2int(max_year));
	}
	else if (options.count(MIN_LIKE_KEYWORD) && options.count(MAX_LIKE_KEYWORD))
	{
		string min_likes = options[MIN_LIKE_KEYWORD];
		string max_likes = options[MAX_LIKE_KEYWORD];
		logged_in_user->add_like_filter(str2int(min_likes), str2int(min_likes));
	}
	else {throw(BadRequest());}
	print(CONFIRM_INDICATOR);
}

void Interface::post_comments (Options options)
{
	string song_id = options[SONG_ID_KEYWORD];
	string time = options[TIME_KEYWORD];
	string comment = options[COMMENT_KEYWORD];
	if (!is_non_negative_int(song_id) || !is_non_negative_int(time)) {throw(BadRequest());}
	logged_in_user->add_comment(str2songid(song_id), str2int(time), comment);
	print(CONFIRM_INDICATOR);
}

void Interface::get_songs (Options options)
{
	if (options.count(ID_KEYWORD))
	{
		SongId song_id = str2songid(options[ID_KEYWORD]);
		print(logged_in_user -> get_song_info(song_id));
	}
	else {print(logged_in_user -> get_songs_info());}
}

void Interface::get_likes (Options options) {print(logged_in_user -> get_liked_songs());}

void Interface::get_playlists (Options options)
{
	string username = options[USERNAME_KEYWORD];
	print(logged_in_user -> get_playlists(username));
}

void Interface::get_playlist_songs (Options options)
{
	string playlist_id = options[PLAYLIST_ID_KEYWORD];
	print(logged_in_user -> get_playlist_songs(str2playlistid(playlist_id)));
}

void Interface::get_users (Options options) {print(logged_in_user -> get_all_users());}

void Interface::get_comments (Options options)
{
	string song_id = options[SONG_ID_KEYWORD];
	print(logged_in_user -> get_comments_on_song(str2songid(song_id)));
}

void Interface::delete_likes (Options options)
{
	string song_id_str = options[ID_KEYWORD];
	logged_in_user->unlike_song(str2songid(song_id_str));
	print(CONFIRM_INDICATOR);
}

void Interface::delete_playlist_songs (Options options)
{
	string playlist_id = options[PLAYLIST_ID_KEYWORD];
	string song_id = options[SONG_ID_KEYWORD];
	logged_in_user->delete_playlist_song(str2playlistid(playlist_id), str2songid(song_id));
	print(CONFIRM_INDICATOR);
}

void Interface::delete_filters (Options options)
{
	logged_in_user->delete_filters();
	print(CONFIRM_INDICATOR);
}

void Interface::print_error(string error) {cout<<error;}