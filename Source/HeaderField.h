#ifndef HEADERFIELD_H
#define HEADERFIELD_H

#include <string>
#include <deque>
#include <tuple>
#include <forward_list>

#include "BMSUtils.h"

class HeaderField
{
public:
	HeaderField();
	~HeaderField();
	void SetPlayer(int input);
	void SetGenre(std::string input);
	void SetTitle(std::string input);
	void SetArtist(std::string input);
	void SetBPM(int input);
	void SetPlayLevel(int input);
	void SetRank(int input);
	void SetTotal(int input);
	void SetVolWav(int input);
	void SetStageFile(std::string input);

	void AddWAVFile(std::string str_num, std::string path, std::string extension);
	void AddBMPFile(std::string str_num, std::string path, std::string extension);

	void AddSTOPCmd(std::string str_num, std::string str_data);
	void AddBPMCmd(std::string str_num, std::string str_bpm);

	void SetLongNoteType(std::string type);
	void AddLongNote(std::string note_num);

	int GetPlayer();
	std::string GetGenre();
	std::string GetTitle();
	std::string GetArtist();
	int GetBPM();
	int GetPlayLevel();
	int GetRank();
	int GetTotal();
	int GetVolWav();
	std::string GetStageFile();

	std::deque <BMSUtils::File_t> GetWAVFileList();
	void PrintWAVFileList();

	std::deque <BMSUtils::File_t> GetBMPFileList();
	void PrintBMPFileList();

	std::deque <BMSUtils::Command_t> GetSTOPList();
	void PrintSTOPList();

	std::deque <BMSUtils::Command_t> GetBPMList();
	void PrintBPMList();

	std::string GetLongNoteType();
	std::forward_list <std::string> GetLongNoteList();
	void PrintLongNoteList();
private:
	/* BMS HEADER FIELD */
	int Player = 0;
	std::string Genre = "";
	std::string Title = "";
	std::string Artist = "";
	int BPM = 0;
	int PlayLevel = 0;
	int Rank = 0;
	int Total = 0;
	int VolumeWav = 0;
	std::string StageFile = "";
	BMSUtils::LongNote_t LongNotes;

	std::deque <BMSUtils::File_t> dq_WAV;
	std::deque <BMSUtils::File_t> dq_BMP;
	std::deque <BMSUtils::Command_t> dq_STOP;
	std::deque <BMSUtils::Command_t> dq_BPM;
};

HeaderField::HeaderField()
{
}

HeaderField::~HeaderField()
{
}

/* HEADER FIELD */
void HeaderField::SetPlayer(int input)
{
	Player = input;
}

void HeaderField::SetGenre(std::string input)
{
	Genre = input;
}

void HeaderField::SetTitle(std::string input)
{
	Title = input;
}

void HeaderField::SetArtist(std::string input)
{
	Artist = input;
}

void HeaderField::SetBPM(int input)
{
	BPM = input;
}

void HeaderField::SetPlayLevel(int input)
{
	PlayLevel = input;
}

void HeaderField::SetRank(int input)
{
	Rank = input;
}

void HeaderField::SetTotal(int input)
{
	Total = input;
}

void HeaderField::SetVolWav(int input)
{
	VolumeWav = input;
}

void HeaderField::SetStageFile(std::string input)
{
	StageFile = input;
}

void HeaderField::AddWAVFile(std::string str_num, std::string path, std::string extension)
{
	BMSUtils::File_t data(str_num, path, extension);
	dq_WAV.push_back(data);
}

void HeaderField::AddBMPFile(std::string str_num, std::string path, std::string extension)
{
	BMSUtils::File_t data(str_num, path, extension);
	dq_BMP.push_back(data);
}

void HeaderField::AddSTOPCmd(std::string str_num, std::string str_data)
{
	BMSUtils::Command_t data(str_num, str_data);
	dq_STOP.push_back(data);
}

void HeaderField::AddBPMCmd(std::string str_num, std::string str_bpm)
{
	BMSUtils::Command_t data(str_num, str_bpm);
	dq_BPM.push_back(data);
}

void HeaderField::SetLongNoteType(std::string type)
{
	LongNotes.SetType(type);
}

void HeaderField::AddLongNote(std::string note_num)
{
	LongNotes.AddLongNoteNum(note_num);
}

int HeaderField::GetPlayer()
{
	return Player;
}

std::string HeaderField::GetGenre()
{
	return Genre;
}

std::string HeaderField::GetTitle()
{
	return Title;
}

std::string HeaderField::GetArtist()
{
	return Artist;
}

int HeaderField::GetBPM()
{
	return BPM;
}

int HeaderField::GetPlayLevel()
{
	return PlayLevel;
}

int HeaderField::GetRank()
{
	return Rank;
}

int HeaderField::GetTotal()
{
	return Total;
}

int HeaderField::GetVolWav()
{
	return VolumeWav;
}

std::string HeaderField::GetStageFile()
{
	return StageFile;
}

std::deque<BMSUtils::File_t> HeaderField::GetWAVFileList()
{
	return dq_WAV;
}

void HeaderField::PrintWAVFileList()
{
	for (unsigned int i = 0; i < dq_WAV.size(); i++)
	{
		std::cout << "WAV" << dq_WAV.at(i).GetFileNum() << ": " << dq_WAV.at(i).GetFileName();
		std::cout << "\t Extension: " << dq_WAV.at(i).GetExtension() << std::endl;
	}
}

std::deque<BMSUtils::File_t> HeaderField::GetBMPFileList()
{
	return dq_BMP;
}

void HeaderField::PrintBMPFileList()
{
	for (unsigned int i = 0; i < dq_BMP.size(); i++)
	{
		std::cout << "BMP" << dq_BMP.at(i).GetFileNum() << ": " << dq_BMP.at(i).GetFileName();
		std::cout << "\t Extension: " << dq_BMP.at(i).GetExtension() << std::endl;
	}
}

std::deque<BMSUtils::Command_t> HeaderField::GetSTOPList()
{
	return dq_STOP;
}

void HeaderField::PrintSTOPList()
{
	for (unsigned int i = 0; i < dq_STOP.size(); i++)
	{
		std::cout << "STOP" << dq_STOP.at(i).GetCommandNum() << ": " << dq_STOP.at(i).GetCommandData() << std::endl;
	}
}

std::deque<BMSUtils::Command_t> HeaderField::GetBPMList()
{
	return dq_BPM;
}

void HeaderField::PrintBPMList()
{
	for (unsigned int i = 0; i < dq_BPM.size(); i++)
	{
		std::cout << "STOP" << dq_BPM.at(i).GetCommandNum() << ": " << dq_BPM.at(i).GetCommandData() << std::endl;
	}
}

std::string HeaderField::GetLongNoteType()
{
	return LongNotes.GetType();
}

std::forward_list <std::string> HeaderField::GetLongNoteList()
{
	return LongNotes.GetLongNoteList();
}

void HeaderField::PrintLongNoteList()
{
	if (LongNotes.GetType() == "1" || LongNotes.GetType() == "2")
	{
		std::cout << "The BMS uses LNTYPE " << LongNotes.GetType() << std::endl;
	}
	else if (LongNotes.GetType() == "LNOBJ")
	{
		auto itlist = LongNotes.GetLongNoteList();
		for (auto it = itlist.begin(); it != itlist.end(); ++it)
		{
			std::cout << "LNOBJ " << *it << std::endl;
		}
	}
	else
	{
		std::cout << "It seems that the BMS don't uses longnote" << std::endl;
	}
}

#endif // !HEADERFIELD_H
