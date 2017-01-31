#include <iostream>
#include "CIMModel.hpp"
#include "IEC61970.h"

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		std::cout << "Usage: example <cim file> [additional cim files]" << std::endl;
		std::cout << "Provide at least one cim file" << std::endl;
		return 1;
	}

	CIMModel someModel;

	for(int i = 1; i < argc; i++)
	{
		someModel.addCIMFile(argv[i]);
	}

	someModel.parseFiles();

	for (BaseClass* Object : someModel.Objects)
	{
		if(IEC61970::Base::Core::IdentifiedObject* IdObj = dynamic_cast<IEC61970::Base::Core::IdentifiedObject*>(Object))
		{
			if(!IdObj->name.empty())
				std::cout << IdObj->name << std::endl;
		}
	}
	return 0;
}
