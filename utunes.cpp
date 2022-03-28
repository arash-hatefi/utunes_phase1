#include "utunes.hpp"

Utunes::Utunes() : utunes_db(new UtunesDB()) {}

Utunes::~Utunes() {delete utunes_db;}

void Utunes::import_songs_form_csv(const string& file_path) {utunes_db->song_database->read_songs_form_csv(file_path);}

LoggedInUser* Utunes::signup(string email, string username, string password) 
{
	for (User* user : utunes_db->users) {if (user->email==email || user->username==username) {throw(BadRequest());}}
	User* new_user = new User(email, username, myhash(password));
	utunes_db->users.push_back(new_user);
	return user_login(new_user);
}

LoggedInUser* Utunes::login(string email, string password)
{
	User* user = find_user(email, password);
	return user_login(user);
}

void Utunes::logout(string username)
{
	for (unsigned int idx=0; idx<logged_in_users.size(); idx++)
	{
		if (logged_in_users[idx]->get_username()==username)
		{
			delete logged_in_users[idx];
			logged_in_users.erase(logged_in_users.begin()+idx);
			return;
		}
	}
	throw(PermissionDenied());
}

User* Utunes::find_user(string email, string password)
{
	Hash hashed_password = myhash(password);
	for(User* user : utunes_db->users) {if(email==user->email && hashed_password==user->password) return user;}
	throw(BadRequest());
}

LoggedInUser* Utunes::user_login(User* user)
{
	LoggedInUser* new_logged_in_user = new LoggedInUser(utunes_db, user);
	logged_in_users.push_back(new_logged_in_user);
	return new_logged_in_user;
}