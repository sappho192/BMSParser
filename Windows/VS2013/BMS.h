#ifndef BMS_H
#define BMS_H

#include <string>
#include <tuple>
#include <deque>

typedef std::tuple<std::string, std::string, std::string> File_t;

class BMS
{
public:
	BMS();
	~BMS();

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

	std::deque <File_t> GetWAVFileList();
	void PrintWAVFileList();

	std::deque <File_t> GetBMPFileList();
	void PrintBMPFileList();
private:
	/* BMS HEADER FIELD */
	int Player				= 0;
	std::string Genre		= "";
	std::string Title		= "";
	std::string Artist		= "";
	int BPM					= 0;
	int PlayLevel			= 0;
	int Rank				= 0;
	int Total				= 0;
	int VolumeWav			= 0;
	std::string StageFile	= "";

	std::deque <File_t> dq_WAV;
	std::deque <File_t> dq_BMP;
};

BMS::BMS()
{
}

BMS::~BMS()
{
}

/* HEADER FIELD */
void BMS::SetPlayer(int input)
{
	Player = input;
}

void BMS::SetGenre(std::string input)
{
	Genre = input;
}

void BMS::SetTitle(std::string input)
{
	Title = input;
}

void BMS::SetArtist(std::string input)
{
	Artist = input;
}

void BMS::SetBPM(int input)
{
	BPM = input;
}

void BMS::SetPlayLevel(int input)
{
	PlayLevel = input;
}

void BMS::SetRank(int input)
{
	Rank = input;
}

void BMS::SetTotal(int input)
{
	Total = input;
}

void BMS::SetVolWav(int input)
{
	VolumeWav = input;
}

void BMS::SetStageFile(std::string input)
{
	StageFile = input;
}

void BMS::AddWAVFile(std::string str_num, std::string path, std::string extension)
{
	File_t data (str_num, path, extension);
	dq_WAV.push_back(data);
}

void BMS::AddBMPFile(std::string str_num, std::string path, std::string extension)
{
	File_t data(str_num, path, extension);
	dq_BMP.push_back(data);
}


int BMS::GetPlayer()
{
	return Player;
}

std::string BMS::GetGenre()
{
	return Genre;
}

std::string BMS::GetTitle()
{
	return Title;
}

std::string BMS::GetArtist()
{
	return Artist;
}

int BMS::GetBPM()
{
	return BPM;
}

int BMS::GetPlayLevel()
{
	return PlayLevel;
}

int BMS::GetRank()
{
	return Rank;
}

int BMS::GetTotal()
{
	return Total;
}

int BMS::GetVolWav()
{
	return VolumeWav;
}

std::string BMS::GetStageFile()
{
	return StageFile;
}

std::deque<File_t> BMS::GetWAVFileList()
{
	return dq_WAV;
}

void BMS::PrintWAVFileList()
{
	for (unsigned int i = 0; i < dq_WAV.size(); i++)
	{
		std::cout << "WAV" << std::get<0>(dq_WAV.at(i)) << ": " << std::get<1>(dq_WAV.at(i));
		std::cout << "\t Extension: " << std::get<2>(dq_WAV.at(i)) << std::endl;
	}
}

std::deque<File_t> BMS::GetBMPFileList()
{
	return dq_BMP;
}

void BMS::PrintBMPFileList()
{
	for (unsigned int i = 0; i < dq_BMP.size(); i++)
	{
		std::cout << "BMP" << std::get<0>(dq_BMP.at(i)) << ": " << std::get<1>(dq_BMP.at(i));
		std::cout << "\t Extension: " << std::get<2>(dq_BMP.at(i)) << std::endl;
	}
}

#endif // !BMS_H
