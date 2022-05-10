#pragma once
#include <iostream>
#include <string>

using namespace std;

class entity {
private:
	std::string name;
	int price = -1;
	std::string producer;
	std::string activ_substance;

public:
	entity(std::string d, int p, std::string pro, std::string sub) :name{ d }, price{ p }, producer{ pro }, activ_substance{ sub }{};
	entity() noexcept {};
	/*
	in: name, price, producer, activ subtstance
	* out: new entity
	*/
	void create_entity(const std::string& d, const int& p, const std::string& pro, const std::string& sub);

	std::string get_name() const;
	int get_price() const noexcept;
	std::string get_producer() const noexcept;
	std::string get_activ_substance() const noexcept;

	/*
	* sets the entity's name with the string value
	* in: string
	* out: -
	*/
	void set_name(const std::string& new_name) noexcept;
	/*
	* sets the entity's price with the int value
	* in: int
	* out: -
	*/
	void set_price(const int& p) noexcept;

	/*
	* modifies the name and the price of an entity
	* in: string d - new name and int p - new price
	* out: -
	*/
	void modify_entity(const std::string& d, const int& p)  noexcept;

	friend ostream& operator<<(ostream& output, const entity& e) {
		output << " Denumire: " << e.get_name() << " Producator: " << e.get_producer() << " Substanta Activa: " << e.get_activ_substance() << " Pret: " << e.get_price();
		return output;
	}
};
