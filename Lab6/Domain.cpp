#include "Domain.h"


void entity::create_entity(const std::string &d,const int &p,const std::string &pro,const std::string &sub)
{
	this->set_price(p);
	this->set_name(d);
	(this->activ_substance).assign(sub);
	(this->producer).assign(pro);
}

std::string entity::get_name() const
{
	return this->name;
}

int entity::get_price() const noexcept
{
	return this->price;
}

std::string entity::get_producer() const noexcept
{
	return this->producer;
}

std::string entity::get_activ_substance() const noexcept
{
	return this->activ_substance;
}

void entity::set_name(const std::string &new_name) noexcept
{
	(this->name).assign(new_name);
}

void entity::set_price(const int &p) noexcept
{
	this->price = p;
}

void entity::modify_entity(const std::string &d,const int &p) noexcept
{
	this->set_name(d);
	this->set_price(p);
}
