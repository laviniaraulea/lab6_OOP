#pragma once
#include "validare.h"
#include "erori.h"
#include <iostream>

int validator::price(std::string pret)
{
	for (int i = 0; i < pret.size(); i++)
		if (isalpha(pret.at(i)))	throw Exception("Pretul trebuie sa contina doar cifre!!");
	if (stoi(pret)<0)
		throw Exception("Pretul trebuie sa fie pozitiv!!");
	return 1;
}
