#include "image_processing.h"

namespace image_processing
{
	int readImage(std::string inputFileName, char data[])
	{
		std::ifstream file;
		size_t size = 0;
	
		file.open(inputFileName, std::ios::in | std::ios::binary | std::ios::ate);

		file.seekg(0, std::ios::end);
		size = file.tellg();
		file.seekg(0, std::ios::beg);

		file.read(data, size);
		data[size] = '\0';

		file.close();	

		return size;
	}

	void writeImage(std::string outputFileName, char data[], size_t size)
	{
		std::ofstream file(outputFileName, std::ios::binary);
		file.write(data, size - 8);
		file.close();
	}
}

