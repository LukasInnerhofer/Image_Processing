#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include <iostream>
#include <fstream>
#include <cstddef>
#include <string>


namespace image_processing
{
	int readImage(std::string, char []);
	void writeImage(std::string, char [], size_t);
}

#endif //IMAGE_PROCESSING_H
