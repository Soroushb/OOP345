/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 14/11/2020
WS7
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "SongCollection.h"

using namespace std;

namespace sdds {

	void printbar(std::ostream& out = std::cout)
	{
		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
	}

	std::ostream& operator<<(std::ostream& out, const Song& theSong) {
		out << "| " << left << setw(20) << theSong.m_title
			<< " | " << left << setw(15) << theSong.m_artist
			<< " | " << left << setw(20) << theSong.m_album
			<< " | " << right << setw(6) << (theSong.m_year > 0 ? to_string(theSong.m_year) : "")
			<< " | " << theSong.m_length / 60 << ":" << setw(2) << setfill('0') << theSong.m_length % 60
			<< " | " << fixed << setprecision(2) << theSong.m_price << " |"
			<< setfill(' ');
		return out;
	}

	SongCollection::SongCollection(std::string filename) {
		std::ifstream file(filename);
		if (!file)
			throw "Invalid filename!";

		while (file) {
			Song song;
			string buffer;
			getline(file, buffer);
			if (file) {
				trim(song.m_title = buffer.substr(0, 25));
				trim(song.m_artist = buffer.substr(25, 25));
				trim(song.m_album = buffer.substr(50, 25));
				try {
					song.m_year = stoi(buffer.substr(75, 5));
				}
				catch (...) {
					song.m_year = 0;
				}
				song.m_length = stoi(buffer.substr(80, 5));
				song.m_price = stod(buffer.substr(85));
				this->m_songs.push_back(song);
			}
		}
		file.close();
	}

	string& SongCollection::trim(string& token) {

		token.erase(token.find_last_not_of(' ') + 1);
		token.erase(0, token.find_first_not_of(' '));
		return token;
	}

	void SongCollection::display(std::ostream& out) const {
		std::for_each(m_songs.begin(), m_songs.end(), [&out](const Song& item) {out << item << endl; });
		
		auto total = std::accumulate(m_songs.begin(), m_songs.end(), 0u, [](const size_t& res, const Song& theSong) {return res + theSong.m_length; });

		printbar(out);
		string str = "Total Listening Time: ";
		str += to_string(total / 3600);
		str += ":";
		str += to_string((total %= 3600) / 60);
		str += ":";
		str += to_string(total % 60);
		out << "|" << right << setfill(' ') << setw(85) << str << " |" << endl;
	}

	void SongCollection::sort(string field)
	{
		if (field == "title")
			std::sort(m_songs.begin(), m_songs.end(), [](const Song& a, const Song& b) {return a.m_title < b.m_title; });
		else if (field == "album")
			std::sort(m_songs.begin(), m_songs.end(), [](const Song& a, const Song& b) {return a.m_album < b.m_album; });
		else if (field == "length")
			std::sort(m_songs.begin(), m_songs.end(), [](const Song& a, const Song& b) {return a.m_length < b.m_length; });
	}

	bool SongCollection::inCollection(string artist) const {
		auto res = std::find_if(m_songs.begin(), m_songs.end(), [&artist](const Song& aSong) {return aSong.m_artist == artist; });
		return res != m_songs.end();
	}

	std::list<Song> SongCollection::getSongsForArtist(string artist) const{
		auto cnt = std::count_if(m_songs.begin(), m_songs.end(), [&artist](const Song& aSong) {return aSong.m_artist == artist; });
		std::list<Song> songs(cnt);
		std::copy_if(m_songs.begin(), m_songs.end(), songs.begin(), [&artist](const Song& aSong) {return aSong.m_artist == artist; });
		return songs;
	}

	void SongCollection::cleanAlbum() {

		/*std::transform(m_songs.begin(), m_songs.end(), m_songs.begin(), [](Song song) {if (song.m_album == "[None]") song.m_album = ""; return song.m_album; });
		it gave me an error in Algorithm library. I couldn't figure it out.
		*/
			
		for (auto& value : m_songs) {
			if (value.m_album == "[None]") {
				value.m_album = "";
			}
		}	}

}