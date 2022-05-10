#pragma once
#include <vector>
#include "Domain.h"
#include "vector_template.h"
#include <algorithm> 
#include <unordered_map>
#include <random>


class abstract_repo {
	
	friend class entity;
public:

	virtual vector<entity> return_vector() = 0;
	/*
	* remove all contents from repository
	*/
	virtual void free() noexcept =0;

	/*
	* out: size_t number of elements
	*/
	virtual size_t get_length() const noexcept =0;

	/*
	* throws exception if i not in range
	* in: size_t i - the index of the entity
	* out entity
	*/
	virtual entity get_entity(const size_t& i) const =0;

	/*
	* add an entity to the back of the repository
	* in: entity e - element that needs to be added
	* out: -
	*/
	virtual void add(const entity& e) =0;

	/*
	* finds an entity by name and removes it from repo
	* throws exception if not find
	* in: string n: name
	*/
	virtual void remove(const std::string& n) =0;

	/*
	* finds an entity after producer and change its name and price
	* throws exception if not find
	* in: string pro - producer, string n - name, int p - price
	*
	*/
	virtual void modify_name_and_price(const std::string& pro, const std::string& n, const int& p) =0;

	/*
	* find an entity from repo
	* throws exception if not find
	* in: string n - the name
	* out: size_t index
	*/
	virtual size_t find_by_name(const std::string& n) const =0;

	/*
	* find an entity from repo
	* throws exception if not find
	* in: string n - the producer
	* out: entity
	*/
	virtual entity find_by_producer(const std::string& n) const =0;

	/*
	* swap the element from poz i to poz j
	* throws exception if i or j not valid
	*/
	virtual void swap(int i, int j) =0;
};

class repo : public abstract_repo{
	friend class Exception;
protected:
	vector <entity> lista_entitati;
public:

	/*
	* remove all contents from repository
	*/
	void free() noexcept;

	/*
	* out: size_t number of elements
	*/
	size_t get_length() const noexcept override;

	/*
	* throws exception if i not in range
	* in: size_t i - the index of the entity
	* out entity
	*/
	entity get_entity(const size_t& i) const override;

	/*
	* add an entity to the back of the repository
	* in: entity e - element that needs to be added
	* out: -
	*/
	void add(const entity& e) override;

	/*
	* finds an entity by name and removes it from repo
	* throws exception if not find
	* in: string n: name
	*/
	void remove(const std::string& n) override;

	/*
	* finds an entity after producer and change its name and price
	* throws exception if not find
	* in: string pro - producer, string n - name, int p - price
	*
	*/
	void modify_name_and_price(const std::string& pro, const std::string& n, const int& p) override;

	/*
	* find an entity from repo
	* throws exception if not find
	* in: string n - the name
	* out: size_t index
	*/

	size_t find_by_name(const std::string& n) const override;

	/*
	* find an entity from repo
	* throws exception if not find
	* in: string n - the producer
	* out: entity
	*/
	entity find_by_producer(const std::string& n) const override;

	/*
	* swap the element from poz i to poz j
	* throws exception if i or j not valid
	*/
	void swap(int i, int j) override;

	vector<entity> return_vector() override;

};

class repo_pro : public abstract_repo {
	friend class entity;
protected:
	unordered_map <size_t, entity> lista_entitati;
	float probability=0;
public:

	void  throw_p() const;

	float get_probbaility() const noexcept;

	void set_probability(const float& p)noexcept;

	/*
	* remove all contents from repository
	*/
	void free() noexcept;

	/*
	* out: size_t number of elements
	*/
	size_t get_length() const noexcept override;

	/*
	* throws exception if i not in range
	* in: size_t i - the index of the entity
	* out entity
	*/
	entity get_entity(const size_t&i) const override;

	/*
	* add an entity to the back of the repository
	* in: entity e - element that needs to be added
	* out: - 
	*/
	void add(const entity &e) override;

	/*
	* finds an entity by name and removes it from repo
	* throws exception if not find
	* in: string n: name
	*/
	void remove(const std::string &n) override;

	/*
	* finds an entity after producer and change its name and price
	* throws exception if not find
	* in: string pro - producer, string n - name, int p - price
	* 
	*/
	void modify_name_and_price(const std::string &pro,const std::string &n, const int &p) override;

	/*
	* find an entity from repo
	* throws exception if not find
	* in: string n - the name
	* out: size_t index
	*/
	size_t find_by_name(const std::string &n) const override;
	
	/*
	* find an entity from repo
	* throws exception if not find
	* in: string n - the producer
	* out: entity
	*/
	entity find_by_producer(const std::string& n) const override;

	/*
	* swap the element from poz i to poz j
	* throws exception if i or j not valid
	*/
	void swap(int i, int j) override;
	vector<entity> return_vector() override;
};
