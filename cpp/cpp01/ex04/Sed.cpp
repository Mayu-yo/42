#include "Sed.hpp"

Sed::Sed(std::string filename, std::string s1, std::string s2)
{
	_filename = filename;
	_before_string = s1;
	_after_string = s2;
}

Sed::~Sed(void)
{
}

int Sed::replace() {
	size_t pos = 0;
	std::string line;
	std::string new_filename;
	std::ifstream ifs;
	std::ofstream ofs;

	ifs.open(_filename.c_str());
	if (!ifs) {
		std::cerr << "Error: could not open file" << std::endl;
		return 1;
	}
	new_filename = _filename + ".replace";
	ofs.open(new_filename.c_str());
	if (!ofs) {
		std::cerr << "Error: could not create file" << std::endl;
		return 1;
	}
	while (std::getline(ifs, line)) {
		while ((pos = line.find(_before_string,pos)) != std::string::npos) {
			line.erase(pos, _before_string.length());
			line.insert(pos, _after_string);
		}
		ofs << line << std::endl;
		pos = 0;
	}
	ifs.close();
	ofs.close();
	return 0;
}