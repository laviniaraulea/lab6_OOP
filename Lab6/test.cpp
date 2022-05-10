#include "test.h"
#include "validare.h"
#include <iostream>
#include <sstream>
bool lungime(entity e) noexcept
{
	return true;
}
int comp(entity e1, entity e2) noexcept
{
	return e1.get_price()>e2.get_price();
}
void test_adauga()
{
	repo_pro* r = new repo_pro;
	r->set_probability(0);
	service s{r};
	entity e;
	string n{ "nume1" };
	string n1{ "producator1" };
	string n2{ "substantaactiva1" };
	stringstream out;
	int constexpr nr = 43;
	assert(r->get_probbaility() == 0);
	e.create_entity(n, nr, n1, n2);
	out << e;
	assert(" Denumire: nume1 Producator: producator1 Substanta Activa: substantaactiva1 Pret: 43"== out.str());
	bool p = lungime(e);
	p = false;
	s.add_in_list_medicine(e);
	assert(s.get_entity_from_list_medicine(0).get_name() == n);

	out << s.get_list_medicine();

	assert(s.find_entity_from_list_medicine(n)==0);
	
	n.replace(0, n.size(), "modificare1");
	s.modify_enity_from_list_medicine(n1, n, 12);
	assert(s.get_entity_from_list_medicine(0).get_name() == n);

	s.delete_entity_from_list_medicine(n);
	
	assert(s.get_lenght_list_medicine() == 0);
	validator v;
	try {
		v.price("-123");
	}
	catch (Exception e)
	{

	}
	try {
		v.price("12");
		v.price("daf");
	}
	catch (Exception e)
	{

	}
	try
	{
		s.delete_entity_from_list_medicine("1daf");
	}
	catch (Exception e)
	{

	}
	e.modify_entity("modificare", 123);

	repo* r1 = new repo;
	service s1{ r1 };
	entity e1;
	string n21{ "nume1" };
	string n11{ "producator1" };
	string n12{ "substantaactiva1" };
	stringstream out1;
	int constexpr nr1 = 43;
	e1.create_entity(n21, nr1, n11, n12);
	out1 << e1;
	assert(" Denumire: nume1 Producator: producator1 Substanta Activa: substantaactiva1 Pret: 43");
	bool p1 = lungime(e1);
	p1 = false;
	s1.add_in_list_medicine(e1);
	assert(s1.get_entity_from_list_medicine(0).get_name() == n21);

	out << s1.get_list_medicine();

	assert(s1.find_entity_from_list_medicine(n21) == 0);

	n1.replace(0, n21.size(), "modificare1");
	s1.modify_enity_from_list_medicine(n11, n21, 12);
	assert(s1.get_entity_from_list_medicine(0).get_name() == n21);

	s1.delete_entity_from_list_medicine(n21);

	assert(s1.get_lenght_list_medicine() == 0);
	delete r1;
	delete r;
}
void test_sortare()
{
	repo_pro* r = new repo_pro;
	service s{ r };
	repo h = s.get_prescription();
	entity e,f,g;
	string n{ "nume1" };
	string n1{ "producator1" };
	string n2{ "substantaactiva1" };
	int constexpr nr = 12;
	e.create_entity(n, nr, n1, n2);
	s.add_in_list_medicine(e);
	f.create_entity("nume2", 134, "producator2", "substantaactiva2");
	s.add_in_list_medicine(f);
	g.create_entity("nume3", 12, "producator3", "substantaactiva2");
	s.add_in_list_medicine(g);

	vector<entity> filtru;
	filtru = s.filter_after_price(12);
	assert(filtru.size() == 2);

	filtru = s.filter_after_active_substance("substantaactiva2");
	assert(filtru.size() == 2);

	assert(s.count_entity_after_function(lungime) == 0);

	s.sort_after_function(comp);
	assert(s.get_entity_from_list_medicine(0).get_price() == 134);

	assert(s.get_lenght_prescription() == 0);
	s.add_random(3);

	s.add_in_prescription("nume2");

	e=s.get_entity_from_prescription(0);
	s.export_in_file_from_prescription("test");
	s.free_prescription();

	repo* r1 = new repo;
	service s1{ r1 };
	repo h1 = s1.get_prescription();
	entity e1, f1, g1;
	string n21{ "nume1" };
	string n11{ "producator1" };
	string n12{ "substantaactiva1" };
	int constexpr nr1 = 12;
	e1.create_entity(n21, nr1, n11, n12);
	s1.add_in_list_medicine(e1);
	f1.create_entity("nume2", 134, "producator2", "substantaactiva2");
	s1.add_in_list_medicine(f1);
	g1.create_entity("nume3", 12, "producator3", "substantaactiva2");
	s1.add_in_list_medicine(g1);

	vector<entity> filtru1;
	filtru1 = s1.filter_after_price(12);
	assert(filtru1.size() == 2);

	filtru1 = s1.filter_after_active_substance("substantaactiva2");
	assert(filtru1.size() == 2);

	assert(s1.count_entity_after_function(lungime) == 0);

	s1.sort_after_function(comp);
	assert(s1.get_entity_from_list_medicine(0).get_price() == 134);

	assert(s1.get_lenght_prescription() == 0);
	s1.add_random(3);

	s1.add_in_prescription("nume2");

	e1 = s1.get_entity_from_prescription(0);
	s1.export_in_file_from_prescription("test");
	s1.free_prescription();
	delete r1;
	delete r;
	
}
void test_undo()
{
	repo_pro* r = new repo_pro;
	r->free();
	service s{ r };
	abstract_repo* l = s.get_list_medicine();
	l->get_length();
	entity e, f, g;
	string n{ "nume1" };
	string n1{ "producator1" };
	string n2{ "substantaactiva1" };
	int constexpr nr = 12;
	e.create_entity(n, nr, n1, n2);
	s.add_in_list_medicine(e);
	f.create_entity("nume2", 134, "producator2", "substantaactiva2");
	s.add_in_list_medicine(f);
	g.create_entity("nume3", 12, "producator3", "substantaactiva2");
	s.add_in_list_medicine(g);

	s.undo();
	assert(s.get_lenght_list_medicine() == 2);

	n.replace(0, n.size(), "modificare1");
	s.modify_enity_from_list_medicine(n1, n, 12);
	assert(s.get_entity_from_list_medicine(0).get_name() == n);
	s.undo();
	assert(s.get_entity_from_list_medicine(0).get_name() == "nume1");

	s.delete_entity_from_list_medicine("nume1");
	s.undo();
	assert(s.get_lenght_list_medicine() == 1);

	repo* r1 = new repo;
	service s1{ r1 };
	abstract_repo* l1 = s1.get_list_medicine();
	l1->get_length();
	entity e1, f1, g1;
	string n21{ "nume1" };
	string n11{ "producator1" };
	string n12{ "substantaactiva1" };
	int constexpr nr1 = 12;
	e1.create_entity(n21, nr1, n11, n12);
	s1.add_in_list_medicine(e1);
	f1.create_entity("nume2", 134, "producator2", "substantaactiva2");
	s1.add_in_list_medicine(f1);
	g1.create_entity("nume3", 12, "producator3", "substantaactiva2");
	s1.add_in_list_medicine(g1);

	s1.undo();
	assert(s1.get_lenght_list_medicine() == 2);

	n21.replace(0, n1.size(), "modificare1");
	s1.modify_enity_from_list_medicine(n11, n21, 12);
	assert(s1.get_entity_from_list_medicine(0).get_name() == n21);
	s1.undo();
	assert(s1.get_entity_from_list_medicine(0).get_name() == "nume1");

	s1.delete_entity_from_list_medicine("nume1");
	s1.undo();
	assert(s1.get_lenght_list_medicine() == 2);
	delete r1;
	delete r;
}
void test_all()
{
	test_adauga();
	test_sortare();
	test_undo();
}
