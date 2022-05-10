#include "repo.h"
#include <algorithm>
#include <random>



void repo::free() noexcept
{
	this->lista_entitati.clear();
}

size_t repo::get_length() const noexcept
{
	return lista_entitati.size();
}

entity repo::get_entity(const size_t&i) const{

	if (i<0 || i>this->get_length())	throw Exception("Indexul nu e valid!!");
	return lista_entitati.at(i);
}

void repo::remove(const std::string &n)
{
	this->lista_entitati.erase(this->lista_entitati.begin()+this->find_by_name(n));
}
void repo::modify_name_and_price(const std::string &pro,const std::string &n,const int &p)
{
	int ok = 0;
	for (auto& i : this->lista_entitati)
	{
		if (!i.get_producer().compare(pro))
		{
			i.set_price(p);
			i.set_name(n);
			ok = 1;
		}
	}
	if (ok==0)	throw Exception("Elementul nu a fost gasit!!");
}
void repo::add(const entity &e)
{
	lista_entitati.push_back(e);
}	

entity repo::find_by_producer(const std::string& n) const
{
	for (auto& i : this->lista_entitati)
	{
		if (!i.get_producer().compare(n))
		{
			return i;	}	}	throw Exception("Elementul nu a fost gasit!!");
}

void repo::swap(int i, int j)
{
	if (i<0 || j<0 || i>this->get_length() || j>this->get_length())	throw Exception("Indexul nu e valid!!!");
	entity e = lista_entitati.at(i);
	lista_entitati.at(i) = lista_entitati.at(j);
	lista_entitati.at(j) = e;
}

vector<entity> repo::return_vector()
{
	return this->lista_entitati;
}

size_t repo::find_by_name(const std::string &n) const
{
	size_t j = 0;
	for (auto& i : this->lista_entitati)
	{
		if (i.get_name()== n)
		{
			return j;
		}
		j++; }	throw Exception("Elementul nu a fost gasit!!");
	
}

void repo_pro::throw_p() const
{
	std::mt19937 mt{ std::random_device{}() };
	std::uniform_int_distribution<> dist(0, 100);
	int r = dist(mt);
//	const float r = (float)rand() / (float)RAND_MAX;
	if (r < this->probability)	throw Exception("Nu s a putut efectua operatia!!");
	}

float repo_pro::get_probbaility()const noexcept
{
	return this->probability;
}

void repo_pro::set_probability(const float& p)  noexcept
{
	this->probability = p;
}

void repo_pro::free() noexcept
{
	this->lista_entitati.clear();
}

size_t repo_pro::get_length() const noexcept
{
	return lista_entitati.size();
}

entity repo_pro::get_entity(const size_t& i) const {

	this->throw_p();
	if (i<0 || i>this->get_length())	throw Exception("Indexul nu e valid!!");
	return this->lista_entitati.at(i);
}

void repo_pro::remove(const std::string& n)
{
	this->throw_p();
	for (int i = 0; i < this->get_length(); i++)
		if (this->lista_entitati.at(i).get_name() == n)
			this->lista_entitati.erase(i);
}
void repo_pro::modify_name_and_price(const std::string& pro, const std::string& n, const int& p)
{
	this->throw_p();
	int ok = 0;
	for (auto& i : this->lista_entitati)
	{
		if (!i.second.get_producer().compare(pro))
		{
			i.second.set_price(p);
			i.second.set_name(n);
			ok = 1;
		}
	}
	if (ok == 0)	throw Exception("Elementul nu a fost gasit!!");
}
void repo_pro::add(const entity& e)
{
	this->throw_p();
	lista_entitati.insert({this->get_length(),e});
}

entity repo_pro::find_by_producer(const std::string& n) const
{
		for (auto& i : this->lista_entitati)
		{
			if (!i.second.get_producer().compare(n))
			{
				return i.second;}}		throw Exception("Elementul nu a fost gasit!!");
}

void repo_pro::swap(int i, int j)
{
	if (i<0 || j<0 || i>this->get_length() || j>this->get_length())	throw Exception("Indexul nu e valid!!!");
	entity e = lista_entitati.at(i);
	lista_entitati.at(i) = lista_entitati.at(j);
	lista_entitati.at(j) = e;
}

vector<entity> repo_pro::return_vector()
{
	vector <entity> v;
	for (auto& i : this->lista_entitati)
	{
		v.push_back(i.second);
	}
	return v;
}

size_t repo_pro::find_by_name(const std::string& n) const
{
	this->throw_p();
	size_t j = 0;
	for (auto& i : this->lista_entitati)
	{
		if (i.second.get_name() == n)
		{
			return j;}	j++;	}
	throw Exception("Elementul nu a fost gasit!!");

}