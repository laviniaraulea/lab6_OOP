#pragma once
#include "repo.h"
#include "domain.h"
#include "undo.h"
#include <fstream> 
class service {
	friend class entity;
	friend class repo;
	friend class validator;
private:
	abstract_repo* list_medicine;
	repo prescription;
	vector <base_undo*> undo_list;

public:
	service(abstract_repo* l) noexcept:list_medicine( l ){};
	service(){};
	
	~service() {
		for (auto& e : this->undo_list)
			delete e;
	};

	size_t get_lenght_list_medicine()const noexcept;

	abstract_repo* get_list_medicine();

	repo get_prescription();

	size_t get_lenght_prescription() const noexcept;

	/*
    * Emptys the prescription list
    */
	void free_prescription() noexcept;

	/*
	* Finds and adds an entity in precription from list_medicine after name
	* throws exception if entity not found
	* in: string n - the name of the entity
	* out: - 
	*/
	void add_in_prescription(const std::string& n);

	/*
	* Adds random entitis from list_medicine in prescription
	* int: the number of entitis that will pe added
	* out: - 
	*/
	void add_random(const int& n);

	/*
	* throws exception if i is not in range
	* in: size_t the index of entity
	* out: entity
	*/
	entity get_entity_from_prescription(const size_t& i) const;

	/*
	* throws exception if i is not in range
	* in: size_t the index of entity
	* out: entity
	*/
	entity get_entity_from_list_medicine(const size_t& i) const;

	/*
	* Creates a file and exports the entitis from prescription
	* in: string file - the name of te file
	* out:  - 
	*/
	void export_in_file_from_prescription(std::string file);

	/*
	* Adds an entity at the end
	* in: entity
	* out: - 
	*/
	void add_in_list_medicine(const entity &e);

	/*Finds an element after name and removes it from the pharmacy
	* throws exception if element not find
	* return true if succes
	* return false 
	*/
	void delete_entity_from_list_medicine(const std::string &n);

	/*
	* Finds an entity after producer and change its name and price
	*throws exception if element not find
	* in: string pro - producer, string n - new name, int p - price 
	* return true if find
	* return false else
	*/
	void modify_enity_from_list_medicine(const std::string &pro,const std::string &n, const int &p);

	/*
	* Finds entity after name
	* throws exception if not find
	* in: string n - the entity names
	* out: index 
	*/
	size_t find_entity_from_list_medicine(const std::string &n) const;

	/*creats a vector with the entitys that have the same active substance 
	* in: string substance 
	* out: std vector
	*/
	vector<entity> filter_after_active_substance(const std::string& substance);

	/*creats a vector with the entitys that have the same price
	* in: int price
	* out: std vector
	*/
	vector<entity> filter_after_price(const int price);

	/*
	* Sort pharmacy after the given function
	* in: function(entity1, entity2)
	*/
	void sort_after_function(int(*compare)(entity e1, entity e2));

	/*
	* Counts the entiys from list_medicine after a given function
	* int: function( entity1)
	* out: the number of entitys
	*/
	int count_entity_after_function(bool(*functie)(entity e));

	/*
	* Undo the last change in list_medicine
	*/
	void undo();

	/*
	* frees the memory used in undo
	*/
	void free_undo() noexcept;

	
};