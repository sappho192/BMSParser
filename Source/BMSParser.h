﻿#ifndef BMSPARSER_H
#define BMSPARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <regex>

#include "BMS.h"
#include "BMSUtils.h"

class BMSParser
{
public:
	BMSParser();
	~BMSParser();

	bool Run(std::string path);
	void Print();
	BMS GetBMS();
private:
	bool OpenFile(std::string filePath);
	bool ReadFile(std::ifstream &file);
	void ParseData();
	void HasFinished();
	bool IsFinished();

	std::queue<std::string> q_data;
	bool finished = false;

	BMS bms;
};

BMSParser::BMSParser()
{
}

BMSParser::~BMSParser()
{
}

bool BMSParser::Run(std::string path)
{
	//std::string path;
	//path = "C:\\REPOSITORY\\BMSParser\\Resource\\test.bms";
	//path = "C:\\REPOSITORY\\BMSParser\\Resource\\05.bon_voyage_7hyper.bme";

	if (OpenFile(path)) {
		ParseData();
		return true;
	}

	return false;
}

void BMSParser::Print()
{
	if (finished)
	{
		std::cout << "Title: " << bms.GetTitle() << std::endl;
		std::cout << "Artist: " << bms.GetArtist() << std::endl;
		std::cout << "Genre: " << bms.GetGenre() << std::endl;
		std::cout << "BPM: " << bms.GetBPM() << std::endl;
		std::cout << "Play Level: " << bms.GetPlayLevel() << std::endl;
		std::cout << "Rank: " << bms.GetRank() << std::endl;
		std::cout << "Total: " << bms.GetTotal() << std::endl;
		std::cout << "Volume: " << bms.GetVolWav() << std::endl;
		std::cout << "Stage File: " << bms.GetStageFile() << std::endl;
		std::cout << "Player: " << bms.GetPlayer() << std::endl;
		bms.PrintWAVFileList();
		bms.PrintBMPFileList();
		bms.PrintSTOPList();
		bms.PrintBPMList();
		bms.PrintLongNoteList();

		bms.PrintMeasures();
	}
	else
	{
		std::cout << "The parsing process did not finised." << std::endl;
	}
}

BMS BMSParser::GetBMS()
{
	if (IsFinished())
	{
		return bms;
	}
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

void BMSParser::ParseData()
{
	//BMS bms;

	//std::cout << "Data in queue" << std::endl << std::endl;

	bool header_fin = false;
	while (!q_data.empty()) {
		//std::cout << q_data.front() << std::endl;
		if (header_fin == false)
		{
			if (q_data.front() == "*---------------------- HEADER FIELD")
			{
				//std::cout << "Entered HEADER FIELD" << std::endl;
			}
			else if (q_data.front().substr(0, 7) == "#PLAYER")
			{
				int length = q_data.front().length() - 8;	// 7 + 1(=blank) = 8
				bms.SetPlayer(std::stoi(q_data.front().substr(8, length)));
			}
			else if (q_data.front().substr(0, 6) == "#GENRE")
			{
				int length = q_data.front().length() - 7;
				bms.SetGenre(q_data.front().substr(7, length));
			}
			else if (q_data.front().substr(0, 6) == "#TITLE")
			{
				int length = q_data.front().length() - 7;
				bms.SetTitle(q_data.front().substr(7, length));
			}
			else if (q_data.front().substr(0, 7) == "#ARTIST")
			{
				int length = q_data.front().length() - 8;
				bms.SetArtist(q_data.front().substr(8, length));
			}
			else if (q_data.front().substr(0, 4) == "#BPM")
			{
				int length = q_data.front().length() - 5;
				bms.SetBPM(std::stoi(q_data.front().substr(5, length)));
			}
			else if (q_data.front().substr(0, 10) == "#PLAYLEVEL")
			{
				int length = q_data.front().length() - 11;
				bms.SetPlayLevel(std::stoi(q_data.front().substr(11, length)));
			}
			else if (q_data.front().substr(0, 5) == "#RANK")
			{
				int length = q_data.front().length() - 6;
				bms.SetRank(std::stoi(q_data.front().substr(6, length)));
			}
			else if (q_data.front().substr(0, 6) == "#TOTAL")
			{
				int length = q_data.front().length() - 7;
				bms.SetTotal(std::stoi(q_data.front().substr(7, length)));
			}
			else if (q_data.front().substr(0, 7) == "#VOLWAV")
			{
				int length = q_data.front().length() - 8;
				bms.SetVolWav(std::stoi(q_data.front().substr(8, length)));
			}
			else if (q_data.front().substr(0, 10) == "#STAGEFILE")
			{
				int length = q_data.front().length() - 11;
				bms.SetStageFile(q_data.front().substr(11, length));
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
			else if (q_data.front().substr(0, 5) == "#STOP")
			{
				std::string str_num = q_data.front().substr(5, 2);
				std::string str_data = "";

				int length = q_data.front().length() - 7;
				str_data = q_data.front().substr(8, length);
				bms.AddSTOPCmd(str_num, str_data);
			}
			else if (std::regex_search(q_data.front(), std::regex("^(#BPM)[0-9,A-Z]{2}")))
			{// #BPMxx
				std::string str_num = "";
				std::string str_bpm = "";

				str_num = q_data.front().substr(4, 2);

				int length = q_data.front().length() - 5;
				str_bpm = q_data.front().substr(6, length);

				bms.AddBPMCmd(str_num, str_bpm);
			}
			else if (q_data.front().substr(0, 7) == "#LNTYPE")
			{
				bms.SetLongNoteType(q_data.front().substr(8, 1));
			}
			else if (q_data.front().substr(0, 6) == "#LNOBJ")
			{
				bms.SetLongNoteType("LNOBJ");
				bms.AddLongNote(q_data.front().substr(7, 2));
			}
		}

		if (q_data.front() == "*---------------------- MAIN DATA FIELD")
		{
			header_fin = true;
			//std::cout << "Entered MAIN DATA FIELD" << std::endl;
		}
		/* RegEx time! */
		else if (std::regex_search(q_data.front(), std::regex("^(#)[0-9]{5}(:)")))
		{
			//std::cout << "Channel data" << std::endl;

			/* Example: #00204:F3F2F1F0FEFDFCFBFAF9F8F7F6F5F4F3 */
			unsigned int measure = std::stoi(q_data.front().substr(1,3));
			std::string channel = q_data.front().substr(4, 2);
			
			BMSUtils::Noteseq_t noteseq;
			int length = q_data.front().length() - 6;
			noteseq = q_data.front().substr(7, length);

			bms.AddNoteSeqOnMeasure(measure, channel, noteseq);
		}

		q_data.pop();
	}

	HasFinished();
}

void BMSParser::HasFinished()
{
	bms.FinishedMeasure();
	finished = true;
}

bool BMSParser::IsFinished()
{
	return finished;
}

#endif // !BMSPARSER_H
