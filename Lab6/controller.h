#pragma once
#include "repo.h"
#include "service.h"
#include "undo.h"
class controller {
	friend class entity;
	friend class repo;
	friend class service;
	friend class validator;
private:
	service pharmacy;
public:
	controller(service &l):pharmacy( l ) {};
	private:

		//prints every element from pharmacy
		void print_pharmacy();

		//prints menu
		void print_menu() const;
		
		//Validates and adds an entity to pharmacy
		void add_entity();

		// removes entity from pharmacy
		void remove_entity();

		//changes an entity from pharmacy
		void modify_entity();

		//finds an entity and prints it 
		void find();

		//prints the filtred data
		void filter_by_substance();

		//prints the filtred data
		void filter_by_price();

		//changes the order of element in pharmacy by name
		void sort_by_name();

		//changes the order of element in pharmacy by producer
		void sortare_producer();

		//add an entity in prescripsion
		void add_in_prescription();

		//adds a number of entitys from pharmacy, can duplicate
		void generate_prescription();

		//print the menu for prescription
		void print_prescription_menu();

		// print prescription
		void print_prescription();

		//exports the prescription to a file
		void export_prescription();

		// option controller for prescription menu
		void prescription_menu();

		//undo
		void undo();
	public:
		// option controller for main menu
		void meniu();

};