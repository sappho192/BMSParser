#include "main.h"

int main(void)
{
	std::string path("C:\\REPOSITORY\\BMSParser\\Resource\\test.bms");
	BMSParser parser;

	if (parser.Run(path))
	{
		parser.Print();
		BMS bms = parser.GetBMS();
	}

	return 0;
}