#include<iostream>
#include "interface.hpp"
#include "utunes.hpp"

using namespace std;

#include "utils.hpp"

int main(int argc, char *argv[])
{
	string file_path = argv[1];
	Utunes utunes;
	utunes.import_songs_form_csv(file_path);
	Interface interface(&utunes);
	interface.run();
	return 0;
}