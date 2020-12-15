/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 14/11/2020
WS7
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <string>
#include <list>
#include <functional>


namespace sdds {

	struct Song {
		std::string m_artist{};
		std::string m_title{};
		std::string m_album{};
		double m_price{};
		int m_year{};
		size_t m_length{};
	};


	std::ostream& operator<<(std::ostream& out, const Song& theSong);

	class SongCollection {
		std::vector<sdds::Song> m_songs;
		std::string& trim(std::string& token);
	public:
		SongCollection(std::string filename);
		void display(std::ostream& out) const;
		void sort(std::string field);
		void cleanAlbum();
		bool inCollection(std::string artist) const;
		std::list<Song> getSongsForArtist(std::string artist) const;
	};
}

#endif