#ifndef BMSUTILS_H
#define BMSUTILS_H

namespace BMSUtils
{
	/* Custom types */

	//typedef std::tuple<std::string, std::string, std::string> File_t;
	//typedef std::tuple<std::string, std::string> Command_t;
	//typedef std::tuple<std::string, unsigned int, Noteseq_t> Channel_t;
	//typedef std::tuple<unsigned int, Channel_t> Measure_t;
	
	// <File number: std::string, File name: std::string, Extension: std::string>
	class File_t
	{
	public:
		File_t()
		{
		}
		File_t(std::string file_num, std::string file_name, std::string extension)
		{
			SetFileNum(file_num);
			SetFileName(file_name);
			SetExtension(extension);
		}

		std::string GetFileNum() { return filenum_; }
		std::string GetFileName() { return filename_; }
		std::string GetExtension() { return extension_; }

		~File_t()
		{
		}

	private:
		void SetFileNum(std::string input) { filenum_ = input; }
		void SetFileName(std::string input) { filename_ = input; }
		void SetExtension(std::string input) { extension_ = input; }

		std::string filenum_ = "";
		std::string filename_ = "";
		std::string extension_ = "";
	};
	
	// <Command number: std::string, Command data: std::string>
	class Command_t
	{
	public:
		Command_t()
		{
		}
		Command_t(std::string command_num, std::string command_data)
		{
			SetCommandNum(command_num);
			SetCommandData(command_data);
		}

		std::string GetCommandNum() { return command_num_; }
		std::string GetCommandData() { return command_data_; }

		~Command_t()
		{
		}

	private:
		void SetCommandNum(std::string input) { command_num_ = input; }
		void SetCommandData(std::string input) { command_data_ = input; }

		std::string command_num_ = "";
		std::string command_data_ = "";
	};

	// <Note number: std::string>
	typedef std::string Noteseq_t;
	
	// <Channel number: std::string, Unique Channel number: unsigned int, Note sequence: Noteseq_t>
	class Channel_t
	{
	public:
		Channel_t()
		{
		}
		Channel_t(std::string channel_num, unsigned int unique_num, Noteseq_t noteseq)
		{
			SetChannelNum(channel_num);
			SetUniqueNum(unique_num);
			SetNoteSeq(noteseq);
		}

		void SetChannelNum(std::string input) { channel_num_ = input; }
		void SetUniqueNum(unsigned int input) { unique_num_ = input; }
		void SetNoteSeq(Noteseq_t input) { noteseq_ = input; }

		std::string GetChannelNum() { return channel_num_; }
		unsigned int GetUniqueNum() { return unique_num_; }
		Noteseq_t GetNoteSeq() { return noteseq_; }

		~Channel_t()
		{
		}

	private:
		std::string channel_num_ = "";
		unsigned int unique_num_ = 0;
		Noteseq_t noteseq_;
	};
	
	// <Measure number(000~999): unsigned int, Channels: queue<Channel_t>>
	class Measure_t
	{
	public:
		Measure_t()
		{
		}
		Measure_t(unsigned int measure_num)
		{
			SetMeasureNum(measure_num);
		}
		Measure_t(unsigned int measure_num, Channel_t channel)
		{
			SetMeasureNum(measure_num);
			AddChannel(channel);
		}

		void AddChannel(Channel_t input) { channels.push(input); }

		unsigned int GetMeasureNum() { return measure_num; }
		std::queue<Channel_t> GetChannels() { return channels; }
		void PrintChannels()
		{
			std::queue<Channel_t> temp = channels;
			for (unsigned int i = 0; i < temp.size(); ++i)
			{
				std::cout << "#" << GetMeasureNum();
				std::cout<< temp.front().GetChannelNum() << " (" << temp.front().GetUniqueNum() << ")";
				std::cout << " " << temp.front().GetNoteSeq() << std::endl;
				temp.pop();
			}
		}

		~Measure_t()
		{
		}

	private:
		void SetMeasureNum(unsigned int input) { measure_num = input; }
		
		unsigned int measure_num = 0;
		std::queue<Channel_t> channels;
	};

	// Use AddLongNoteNum() & GetLongNoteList when the BMS uses LNOBJ
	class LongNote_t
	{
	public:
		LongNote_t() {}

		void SetType(std::string input) { type_ = input; }
		void AddLongNoteNum(std::string notenum) { longnotes_.push_front(notenum); }

		std::string GetType() { return type_; }
		std::forward_list<std::string> GetLongNoteList() { return longnotes_; }
	private:
		std::string type_ = "";
		std::forward_list<std::string> longnotes_;
	};

	/* Functions on here should be static */

}

#endif // !BMSUTILS_H
