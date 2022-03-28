# Utunes Project - Phase#1
Project for the advanced programming undergraduate course, University of Tehran. (Finish date: 18-12-2020)

## Description
Utunes is a simple music platform where users can find their favorite music, make playlists, like songs, and add comments to them. 
In phase 1 of the project, the basic command-line interface of Utunes was implemented.

## Running the Code
- Complete the song database in ```./inputs/songs.csv```
- Compile the code and run ```./utunes.out ./inputs/songs.csv```

## Sample Commands
```
POST signup ? email <email> username <username> password <password>
POST login ? email <email> password <password>
POST logout
GET song
GET songs ? id <id>
POST likes ? id <id> 
GET likes
DELETE likes ? id <id>
POST playlists ? name <name> privacy <public/private>
GET playlists ? username <username>
POST playlists_songs ? playlist_id <playlist_id> song_id <song_id>
ET playlists_songs ? playlist_id <playlist_id>
DELETE playlists_songs ? playlist_id <playlist_id> song_id <song_id>
GET users
POST filters ? artist <artist>
POST filters ? min_year <min_year> max_year
POST filters ? min_like <min_like> max_like <max_like>
DELETE filters 
POST comments ? song_id <song_id> time <time> comment <comment>
GET comments ? song_id <song_id>
```

