#include "user.hpp"

User::User(string _email, string _username, Hash _password) : 
email(_email), username(_username), password(_password) {}

User::~User() {for (PlayList* playlist : playlists) {delete playlist;}}
