#include <iostream>
#include <fstream>
#include <cstddef>

#define INPUT_FILENAME "image.png"

int main()
{
	std::ifstream file;
	size_t size = 0;

	std::cout << "Attempting to open " << INPUT_FILENAME << std::endl;
	
	file.open(INPUT_FILENAME, std::ios::in | std::ios::binary | std::ios::ate);
	char *data = 0;

	file.seekg(0, std::ios::end);
	size = file.tellg();
	std::cout << "File size: " << size << std::endl;
	file.seekg(0, std::ios::beg);

	data = new char[size - 8 + 1];
	file.read(data, size);
	data[size] = '\0';
	std::cout << "Data size: " << file.tellg() << std::endl;

	std::cout << std::endl;
	for(unsigned int iterator = 0; iterator < size; ++iterator)
	{
		std::cout << std::endl << "#" << std::dec << iterator << ": " << std::hex << static_cast<short>(data[iterator]);
	}
	file.close();	

	std::ofstream out("out.png", std::ios::binary);
	out.write(data, size - 8);
	out.close();

	std::cin.get();
	return 0;
}



