//#ifndef CHANNEL_H
//#define CHANNEL_H
//
//#include <forward_list>
//#include <vector>
//#include <queue>
//#include <tuple>
//#include <string>
//
//#include "BMSUtils.h"
//
//class Channel
//{
//public:
//	Channel();
//	~Channel();
//
//	bool InitChannel(std::string channel_num);
//	bool AddNoteSeqInChannel(std::string channel_num, unsigned int measure, BMSUtils::Noteseq_t noteseq);
//
//	// Return type is wrapped with queue because the Channel can be duplicated like CH01(BGM)
//	std::queue<BMSUtils::Channel_t> GetChannel(std::string channel_num);
//	std::queue<BMSUtils::Noteseq_t> GetNoteSeqInChannel(std::string channel_num, unsigned int measure);
//private:
//	std::forward_list<BMSUtils::Channels_t> channels_;
//};
//
//Channel::Channel()
//{
//}
//
//Channel::~Channel()
//{
//}
//
//// Initialize Channel
//bool Channel::InitChannel(std::string channel_num)
//{
//	for (auto it = channels_.begin(); it != channels_.end(); ++it)
//	{
//		if (std::get<0>(*it) == channel_num)
//		{// The Channel already exists. So I'm gonna make duplicated Channel.
//
//			// Try to find largest unique number of certain Channel.
//			unsigned int largest_unique = 0;
//			for (auto it = channels_.cbegin(); it != channels_.cend(); ++it)
//			{
//				if ((std::get<0>(*it) == channel_num) && (std::get<1>(*it) > largest_unique))
//				{
//					largest_unique = std::get<1>(*it);
//				}
//			}
//			std::vector<BMSUtils::Channel_t> new_channel;
//			
//			unsigned int next_unique = largest_unique + 1;
//			BMSUtils::Channels_t new_channels = std::make_tuple(channel_num, next_unique, new_channel);
//			channels_.push_front(new_channels);
//		}
//		else
//		{// The Channel does not exit. So I'm gonna make new Channel.
//			std::vector<BMSUtils::Channel_t> new_channel;
//
//			BMSUtils::Channels_t new_channels = std::make_tuple(channel_num, 1, new_channel);
//			channels_.push_front(new_channels);
//		}
//	}
//}
//
//// Add Note sequence in certain Channel
//bool Channel::AddNoteSeqInChannel(std::string channel_num, unsigned int measure, BMSUtils::Noteseq_t noteseq)
//{
//	for (auto it = channels_.begin(); it != channels_.end(); ++it)
//	{
//		if (std::get<0>(*it) == channel_num)
//		{
//			// push noteseq
//		}
//		else
//		{
//			InitChannel(channel_num);
//			// push noteseq
//		}
//	}
//}
//
//// Please note that this method can return 0-size queue.
//std::queue<BMSUtils::Channel_t> Channel::GetChannel(std::string channel_num)
//{
//	std::queue<BMSUtils::Channel_t> channel;
//	for (auto it = channels_.begin(); it != channels_.end(); ++it)
//	{
//		if (std::get<0>(*it) == channel_num)
//		{
//			BMSUtils::Channel_t temp;
//			temp = *it;
//			channel.push(temp);
//		}
//	}
//
//	return channel;
//}
//
//// Please note that this method can return 0-size queue.
//std::queue<BMSUtils::Noteseq_t> Channel::GetNoteSeqInChannel(std::string channel_num, unsigned int measure)
//{
//
//}
//
//#endif // !Channel_H
