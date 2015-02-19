#ifndef MEASURE_H
#define MEASURE_H

#include <forward_list>
#include <queue>

#include "BMSUtils.h"

class Measure
{
public:
	Measure();
	~Measure();

	void AddNoteSeqOnMeasure(unsigned int measure_num, std::string channel, BMSUtils::Noteseq_t);
	BMSUtils::Measure_t GetMeasure(unsigned int measure_num);
	std::forward_list<BMSUtils::Measure_t> GetMeasures();

	void PrintMeasures();
	void PrintMeasure(unsigned int measure_num);

	void FinishedMeasure();
private:
	bool AddMeasure(unsigned int measure_num);
	void AddChannelInMeasure(unsigned int measure_num, BMSUtils::Channel_t channel);
	unsigned int LargestUnqNum(BMSUtils::Measure_t measure, std::string channel);

	std::forward_list<BMSUtils::Measure_t> measures_;
};

Measure::Measure()
{
}

Measure::~Measure()
{
}

// Please note that this method can return empty Measure
BMSUtils::Measure_t Measure::GetMeasure(unsigned int measure_num)
{
	BMSUtils::Measure_t measure;
	for (auto it = measures_.begin(); it != measures_.end(); ++it)
	{
		if ((*it).GetMeasureNum() == measure_num)
		{
			return *it;
		}
	}

	return measure; // The Measure does not exist
}

// Please note that this method can return empty Measures
std::forward_list<BMSUtils::Measure_t> Measure::GetMeasures()
{
	return measures_;
}

void Measure::PrintMeasures()
{
	for (auto it = measures_.begin(); it != measures_.end(); ++it)
	{
		(*it).PrintChannels();
	}
}

void Measure::PrintMeasure(unsigned int measure_num)
{
	for (auto it = measures_.begin(); it != measures_.end(); ++it)
	{
		if ((*it).GetMeasureNum() == measure_num)
		{
			(*it).PrintChannels();
		}
	}
}

// Need to reverse the order of the measure
void Measure::FinishedMeasure()
{
	measures_.reverse();
}

void Measure::AddNoteSeqOnMeasure(unsigned int measure_num, std::string channel, BMSUtils::Noteseq_t noteseq)
{
	if (std::distance(measures_.begin(), measures_.end()) == 0)
	{// Initial push
		BMSUtils::Channel_t new_channel(channel, 1, noteseq);
		AddChannelInMeasure(measure_num, new_channel);
	}
	else
	{
		for (auto it = measures_.begin(); it != measures_.end(); ++it)
		{
			if ((*it).GetMeasureNum() == measure_num)
			{// The measure already exists
				unsigned int next_unq = LargestUnqNum(*it, channel) + 1;
				BMSUtils::Channel_t new_channel(channel, next_unq, noteseq);
			
				AddChannelInMeasure(measure_num, new_channel);
				break;
			}
			else
			{
				BMSUtils::Channel_t new_channel(channel, measure_num, noteseq);
				AddChannelInMeasure(measure_num, new_channel);
				break;
			}
		}
	}
}

bool Measure::AddMeasure(unsigned int measure_num)
{
	for (auto it = measures_.begin(); it != measures_.end(); ++it)
	{
		if ((*it).GetMeasureNum() == measure_num)
		{
			return false;
		}
		else
		{
			BMSUtils::Measure_t new_measure(measure_num);
			measures_.push_front(new_measure);
			return true;
		}
	}
	return false;
}

void Measure::AddChannelInMeasure(unsigned int measure_num, BMSUtils::Channel_t new_channel)
{
	if (std::distance(measures_.begin(), measures_.end()) == 0)
	{
		BMSUtils::Measure_t new_measure(measure_num, new_channel);
		measures_.push_front(new_measure);
	}
	else
	{
		for (auto it = measures_.begin(); it != measures_.end(); ++it)
		{
			if ((*it).GetMeasureNum() == measure_num)
			{
				(*it).AddChannel(new_channel);
				break;
			}
		}
		BMSUtils::Measure_t new_measure(measure_num, new_channel);
		measures_.push_front(new_measure);
	}
}

unsigned int Measure::LargestUnqNum(BMSUtils::Measure_t measure, std::string channel)
{
	std::queue<BMSUtils::Channel_t> channels = measure.GetChannels();
	unsigned int largest_unq = 0;
	for (unsigned int i = 0; i < channels.size(); ++i)
	{
		if ((channels.front().GetChannelNum() == channel) && (channels.front().GetUniqueNum() > largest_unq))
		{
			largest_unq = channels.front().GetUniqueNum();
		}
		channels.pop();
	}
	return largest_unq;
}

#endif // !MEASURE_H
