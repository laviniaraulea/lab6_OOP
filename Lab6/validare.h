#pragma once
#include <string>

class validator {

public:
	/*verify if the price is valid
	* throws exception if not
	*/
	int price(std::string pret);
};