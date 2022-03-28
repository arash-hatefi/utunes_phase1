#ifndef __UTUNES__
#define __UTUNES__

#include <string>
#include <bits/stdc++.h> 

#include "user.hpp"
#include "song_database.hpp"
#include "hash.hpp"
#include "errors.hpp"
#include "song_list.hpp"
#include "logged_in_user.hpp"



class Utunes
{
public:
	Utunes();
	~Utunes();
	void import_songs_form_csv(const string& file_path);
	LoggedInUser* signup(string email, string username, string password);
	LoggedInUser* login(string email, string password);
	void logout(string username);

private:
	UtunesDB* utunes_db;
	vector<LoggedInUser*> logged_in_users;
	User* find_user(string email, string password);
	LoggedInUser* user_login(User* user);
};



#endif