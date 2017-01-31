#ifndef CIMPARSER_HPP
#define CIMPARSER_HPP

#include <vector>
#include <string>
#include <unordered_map>

#include "BaseClass.h"

class CIMContentHandler;

class CIMParser
{
public:
	CIMParser();
	~CIMParser();

	void parse_file(std::string file);

	std::vector<BaseClass*> Objects;
private:
	std::unordered_map<std::string, BaseClass*> RDFMap;
	CIMContentHandler* ContentHandler;
};

#endif // CIMPARSER_HPP
