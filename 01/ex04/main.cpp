#include <sys/stat.h>
#include <cstdio>
#include <string>
#include <fstream>
#include <iostream>

namespace
{
	bool	isRegularFile(const char* filename)
	{
		struct stat path_stat;
		if (stat(filename, &path_stat) != 0)
		{
			perror(filename);
			return false;
		}
		if (!S_ISREG(path_stat.st_mode))
		{
			if (S_ISDIR(path_stat.st_mode))
				std::cerr << filename << ": Is a directory\n";
			else
				std::cerr << filename << ": Not a regular file\n";
			return false;
		}
		return true;
	}

	bool	openFile(const char* filename, std::ifstream& file)
	{
		if (!isRegularFile(filename))
			return false;
		file.open(filename);
		if (!file)
		{
			perror(filename);
			return false;
		}
		return true;
	}

	bool	openFile(const char* filename, std::ofstream& file)
	{
		// Truncates by default
		file.open(filename);
		if (!file)
		{
			perror(filename);
			return false;
		}
		return true;
	}

	void	replaceAll(std::string& str, const std::string& from, const std::string& to)
	{
		std::size_t	pos = 0;
		std::size_t	fromLen = from.length();
		std::size_t	toLen = to.length();

		while ((pos = str.find(from, pos)) != std::string::npos)
		{
			str.erase(pos, fromLen);
			str.insert(pos, to);
			pos += toLen;
		}
	}
}

int	main( int argc, char** argv )
{
	if (argc != 4)
	{
		std::cout << "Usage:\n\t./a.out file fromString toString\n";
		return 1;
	}

	std::string		inFileName(argv[1]);
	std::string		outFileName(inFileName + ".replace");
	std::ifstream	inFile;
	std::ofstream	outFile;
	if (!openFile(inFileName.c_str(), inFile)
		|| !openFile(outFileName.c_str(), outFile))
		return 1;

	std::string		from(argv[2]);
	std::string		to(argv[3]);
	std::string		line;

	while (std::getline(inFile, line))
	{
		if (!from.empty())
			replaceAll(line, from, to);
		outFile << line;
		if (!inFile.eof())
			outFile << '\n';
	}

	return 0;
}
