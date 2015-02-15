#ifndef BMSPARSER_H
#define BMSPARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <queue>

#include "BMS.h"
#include "BMSUtils.h"

class BMSParser
{
public:
	BMSParser();
	~BMSParser();

	bool Run();
private:
	bool OpenFile(std::string filePath);
	bool ReadFile(std::ifstream &file);
	BMS ParseData();

	std::queue<std::string> q_data;
};

BMSParser::BMSParser()
{
}

BMSParser::~BMSParser()
{
}

bool BMSParser::Run()
{
	std::string path;
	path = "C:\\REPOSITORY\\BMSParser\\Resource\\test.bms";
	//path = "C:\\REPOSITORY\\BMSParser\\Resource\\05.bon_voyage_7hyper.bme";

	if (OpenFile(path)) {
		ParseData();
		return true;
	}

	return false;
}

bool BMSParser::OpenFile(std::string filePath)
{
	std::ifstream file(filePath);

	if (file.is_open()) {
		ReadFile(file);
		return true;
	}
	else {
		std::cout << "Failed to open the file" << std::endl;
		return false;
	}
}

bool BMSParser::ReadFile(std::ifstream &file)
{
	std::string line;
	while (std::getline(file, line)) {
		//std::cout << line << std::endl;
		q_data.push(line);
	}
	file.close();

	return true;
}

BMS BMSParser::ParseData()
{
	BMS bms;

	std::cout << "Data in queue" << std::endl << std::endl;

	while (!q_data.empty()) {
		//std::cout << q_data.front() << std::endl;
		if (q_data.front() == "*----------------------HEADER FIELD")
		{
			std::cout << "Entered Header Field" << std::endl;
		}
		else if (q_data.front().substr(0, 7) == "#PLAYER")
		{
			int length = q_data.front().length() - 8;	// 7 + 1(=blank) = 8
			bms.SetPlayer(std::stoi(q_data.front().substr(8, length)));
			std::cout << "Player: " << bms.GetPlayer() << std::endl;
		}
		else if (q_data.front().substr(0, 6) == "#GENRE")
		{
			int length = q_data.front().length() - 7;
			bms.SetGenre(q_data.front().substr(7, length));
			std::cout << "Genre: " << bms.GetGenre() << std::endl;
		}
		else if (q_data.front().substr(0, 6) == "#TITLE")
		{
			int length = q_data.front().length() - 7;
			bms.SetTitle(q_data.front().substr(7, length));
			std::cout << "Title: " << bms.GetTitle() << std::endl;
		}
		else if (q_data.front().substr(0, 7) == "#ARTIST")
		{
			int length = q_data.front().length() - 8;
			bms.SetArtist(q_data.front().substr(8, length));
			std::cout << "Artist: " << bms.GetArtist() << std::endl;
		}
		else if (q_data.front().substr(0, 4) == "#BPM")
		{
			int length = q_data.front().length() - 5;
			bms.SetBPM(std::stoi(q_data.front().substr(5, length)));
			std::cout << "BPM: " << bms.GetBPM() << std::endl;
		}
		else if (q_data.front().substr(0, 10) == "#PLAYLEVEL")
		{
			int length = q_data.front().length() - 11;
			bms.SetPlayLevel(std::stoi(q_data.front().substr(11, length)));
			std::cout << "Play Level: " << bms.GetPlayLevel() << std::endl;
		}
		else if (q_data.front().substr(0, 5) == "#RANK")
		{
			int length = q_data.front().length() - 6;
			bms.SetRank(std::stoi(q_data.front().substr(6, length)));
			std::cout << "Rank: " << bms.GetRank() << std::endl;
		}
		else if (q_data.front().substr(0, 6) == "#TOTAL")
		{
			int length = q_data.front().length() - 7;
			bms.SetTotal(std::stoi(q_data.front().substr(7, length)));
			std::cout << "Total: " << bms.GetTotal() << std::endl;
		}
		else if (q_data.front().substr(0, 7) == "#VOLWAV")
		{
			int length = q_data.front().length() - 8;
			bms.SetVolWav(std::stoi(q_data.front().substr(8, length)));
			std::cout << "Volume: " << bms.GetVolWav() << std::endl;
		}
		else if (q_data.front().substr(0, 10) == "#STAGEFILE")
		{
			int length = q_data.front().length() - 11;
			bms.SetStageFile(q_data.front().substr(11, length));
			std::cout << "Stage File: " << bms.GetStageFile() << std::endl;
		}
		else if (q_data.front().substr(0, 4) == "#WAV")
		{// Sound files
			/* Example: #WAV01 BRUM_BD.ogg */
			std::string str_num = q_data.front().substr(4, 2);
			std::string filename = "";
			std::string extension = "";

			int length = q_data.front().length() - 7;
			filename = q_data.front().substr(8, length);
			extension = q_data.front().substr(q_data.front().length() - 3, 3);
			bms.AddWAVFile(str_num, filename, extension);
		}
		else if (q_data.front().substr(0, 4) == "#BMP")
		{// Image, Video files
			/* Example: #BMP01 background.jpg */
			std::string str_num = q_data.front().substr(4, 2);
			std::string filename = "";
			std::string extension = "";

			int length = q_data.front().length() - 7;
			filename = q_data.front().substr(8, length);
			extension = q_data.front().substr(q_data.front().length() - 3, 3);
			bms.AddBMPFile(str_num, filename, extension);
		}

		q_data.pop();
	}

	bms.PrintWAVFileList();
	bms.PrintBMPFileList();

	return bms;
}

#endif // !BMSPARSER_H
