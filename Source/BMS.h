#ifndef BMS_H
#define BMS_H

#include <string>
#include <tuple>
#include <deque>

#include "HeaderField.h"
#include "Measure.h"
#include "BMSUtils.h"

typedef std::tuple<std::string, std::string, std::string> File_t;

class BMS : public HeaderField, public Measure
{
public:
	BMS();
	~BMS();
private:
};

BMS::BMS()
{
}

BMS::~BMS()
{
}


#endif // !BMS_H
