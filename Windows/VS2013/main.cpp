#include "main.h"

int main(void)
{
	std::string path("C:\\REPOSITORY\\BMSParser\\Resource\\test.bms");
	BMSParser parser;

	parser.Run(path);

	return 0;
}