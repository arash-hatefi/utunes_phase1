CC := g++ -std=c++11

BUILD_DIR=build

all: utunes.out

utunes.out:  $(BUILD_DIR)/main.o $(BUILD_DIR)/interface.o $(BUILD_DIR)/options.o $(BUILD_DIR)/command.o $(BUILD_DIR)/utunes.o $(BUILD_DIR)/logged_in_user.o $(BUILD_DIR)/combinatory_filter.o $(BUILD_DIR)/min_year_filter.o $(BUILD_DIR)/max_year_filter.o $(BUILD_DIR)/min_like_filter.o $(BUILD_DIR)/max_like_filter.o $(BUILD_DIR)/artist_filter.o $(BUILD_DIR)/no_filter.o $(BUILD_DIR)/filter.o $(BUILD_DIR)/utunes_db.o $(BUILD_DIR)/user.o $(BUILD_DIR)/playlist.o $(BUILD_DIR)/song_database.o $(BUILD_DIR)/song_list.o $(BUILD_DIR)/song.o $(BUILD_DIR)/song_info.o $(BUILD_DIR)/comment.o $(BUILD_DIR)/utils.o $(BUILD_DIR)/errors.o $(BUILD_DIR)/hash.o
	$(CC) $(BUILD_DIR)/main.o $(BUILD_DIR)/interface.o $(BUILD_DIR)/options.o $(BUILD_DIR)/command.o $(BUILD_DIR)/utunes.o $(BUILD_DIR)/logged_in_user.o $(BUILD_DIR)/combinatory_filter.o $(BUILD_DIR)/min_year_filter.o $(BUILD_DIR)/max_year_filter.o $(BUILD_DIR)/min_like_filter.o $(BUILD_DIR)/max_like_filter.o $(BUILD_DIR)/artist_filter.o $(BUILD_DIR)/no_filter.o $(BUILD_DIR)/filter.o $(BUILD_DIR)/utunes_db.o $(BUILD_DIR)/user.o $(BUILD_DIR)/playlist.o $(BUILD_DIR)/song_database.o $(BUILD_DIR)/song_list.o $(BUILD_DIR)/song.o $(BUILD_DIR)/song_info.o $(BUILD_DIR)/comment.o $(BUILD_DIR)/utils.o $(BUILD_DIR)/errors.o $(BUILD_DIR)/hash.o -o utunes.out

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/main.o: main.cpp
	$(CC) -c main.cpp -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/interface.o: interface.hpp interface.cpp
	$(CC) -c interface.cpp -o $(BUILD_DIR)/interface.o

$(BUILD_DIR)/options.o: options.hpp options.cpp
	$(CC) -c options.cpp -o $(BUILD_DIR)/options.o

$(BUILD_DIR)/command.o: command.hpp command.cpp
	$(CC) -c command.cpp -o $(BUILD_DIR)/command.o

$(BUILD_DIR)/utunes.o: utunes.hpp utunes.cpp
	$(CC) -c utunes.cpp -o $(BUILD_DIR)/utunes.o

$(BUILD_DIR)/logged_in_user.o: logged_in_user.hpp logged_in_user.cpp
	$(CC) -c logged_in_user.cpp -o $(BUILD_DIR)/logged_in_user.o

$(BUILD_DIR)/utunes_db.o: utunes_db.hpp utunes_db.cpp
	$(CC) -c utunes_db.cpp -o $(BUILD_DIR)/utunes_db.o

$(BUILD_DIR)/user.o: user.hpp user.cpp
	$(CC) -c user.cpp -o $(BUILD_DIR)/user.o

$(BUILD_DIR)/combinatory_filter.o: combinatory_filter.hpp combinatory_filter.cpp
	$(CC) -c combinatory_filter.cpp -o $(BUILD_DIR)/combinatory_filter.o

$(BUILD_DIR)/min_year_filter.o: min_year_filter.hpp min_year_filter.cpp
	$(CC) -c min_year_filter.cpp -o $(BUILD_DIR)/min_year_filter.o

$(BUILD_DIR)/max_year_filter.o: max_year_filter.hpp max_year_filter.cpp
	$(CC) -c max_year_filter.cpp -o $(BUILD_DIR)/max_year_filter.o

$(BUILD_DIR)/min_like_filter.o: min_like_filter.hpp min_like_filter.cpp
	$(CC) -c min_like_filter.cpp -o $(BUILD_DIR)/min_like_filter.o

$(BUILD_DIR)/max_like_filter.o: max_like_filter.hpp max_like_filter.cpp
	$(CC) -c max_like_filter.cpp -o $(BUILD_DIR)/max_like_filter.o

$(BUILD_DIR)/artist_filter.o: artist_filter.hpp artist_filter.cpp
	$(CC) -c artist_filter.cpp -o $(BUILD_DIR)/artist_filter.o

$(BUILD_DIR)/no_filter.o: no_filter.hpp no_filter.cpp
	$(CC) -c no_filter.cpp -o $(BUILD_DIR)/no_filter.o

$(BUILD_DIR)/filter.o: filter.hpp filter.cpp
	$(CC) -c filter.cpp -o $(BUILD_DIR)/filter.o






$(BUILD_DIR)/playlist.o: playlist.hpp playlist.cpp
	$(CC) -c playlist.cpp -o $(BUILD_DIR)/playlist.o

$(BUILD_DIR)/song_database.o: song_database.hpp song_database.cpp
	$(CC) -c song_database.cpp -o $(BUILD_DIR)/song_database.o

$(BUILD_DIR)/song_list.o: song_list.hpp song_list.cpp
	$(CC) -c song_list.cpp -o $(BUILD_DIR)/song_list.o

$(BUILD_DIR)/song.o: song.hpp song.cpp
	$(CC) -c song.cpp -o $(BUILD_DIR)/song.o

$(BUILD_DIR)/song_info.o: song_info.hpp song_info.cpp
	$(CC) -c song_info.cpp -o $(BUILD_DIR)/song_info.o

$(BUILD_DIR)/comment.o: comment.hpp comment.cpp
	$(CC) -c comment.cpp -o $(BUILD_DIR)/comment.o

$(BUILD_DIR)/utils.o: utils.hpp utils.cpp
	$(CC) -c utils.cpp -o $(BUILD_DIR)/utils.o

$(BUILD_DIR)/errors.o: errors.hpp errors.cpp
	$(CC) -c errors.cpp -o $(BUILD_DIR)/errors.o

$(BUILD_DIR)/hash.o: hash.hpp hash.cpp
	$(CC) -c hash.cpp -o $(BUILD_DIR)/hash.o


.PHONY: clean
clean:
	rm -r $(BUILD_DIR)/*.o