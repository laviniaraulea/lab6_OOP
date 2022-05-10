#include "controller.h"
#include "validare.h"


int compare_by_name(entity e1, entity e2)
{
	return e1.get_name().compare(e2.get_name());
}
int compare_by_producer(entity e1, entity e2) noexcept
{
	return e1.get_producer().compare(e2.get_producer());
}
int compare_by_producer_and_price(entity e1, entity e2) noexcept
{
	if (e1.get_producer().compare(e2.get_producer()) == 0)
		if (e1.get_price() > e2.get_price())
			return 0;
		else
			return 1;

	return 1;
}
bool return_true(entity e) noexcept
{
	return true;
}
void controller::print_pharmacy()
{
	for (auto& i : this->pharmacy.get_list_medicine()->return_vector())
	{
		cout << i<<endl;
	}

}
void controller::print_menu() const
{
	cout << "\n1.adauga entitate || 2.afiseaza entitati || 3.sterge entitate ||  4. modifica entitate || 5.cauta entitate" << endl;
	cout << "6.filtreaza dupa substanta activa || 7.filtreaza dupa pret || 8.sortare denumire || 9.sortare producator" << endl;
	cout << "10. sortare substanta activa + pret || 11.Undo || 12.MENIU RETETA" << endl;
}
void controller::remove_entity()
{
	std::string n;
	cout << "Nume entitate care sa se elimine: ";
	getline(cin, n);
	try {
		this->pharmacy.delete_entity_from_list_medicine(n);
	}
	catch (Exception exp)
	{
		cout <<exp.getMessage() << endl;
	}
	
}
void controller::modify_entity()
{
	std::string pro,n;
	int pret;
	cout << "Producator entitatii care sa se modifice: ";
	getline(cin, pro);
	cout << "Denumire: ";
	getline(cin, n);
	cout << "Pret: ";
	cin >> pret;
	try {
		this->pharmacy.modify_enity_from_list_medicine(pro, n, pret);
	}
	catch (Exception exp)
	{
		cout << exp.getMessage() << endl;
	}
	cout << endl;

}
void controller::add_entity()
{
	std::string pro, n, s, p;
	std::string pr;
	int pret;
	validator v;
	cout << "Nume entitate: ";
	getline (cin, n);
	cout << "Producator entitate: ";
	getline(cin, pro);
	cout << "Substanta activa entitate: ";
	getline(cin, s);
	cout << "Pret entitate: ";
	getline(cin, pr);
	entity e;
	try {
		if (v.price(pr) == 1)
		{
			pret = stoi(pr);
			e.create_entity(n, pret, pro, s);
			this->pharmacy.add_in_list_medicine(e);
		}
	}
	catch (Exception& ex)
	{
		std::cout << ex.getMessage() << endl;
	}

}
void controller::find()
{
	std::string  n;
	cout << "Nume entitate care sa se caute: ";
	getline(cin, n);
	try {
		const size_t i = this->pharmacy.find_entity_from_list_medicine(n);
		entity f = this->pharmacy.get_entity_from_list_medicine(i);
		cout << f;
	}
	catch (Exception& ex)
	{
		std::cout << ex.getMessage() << endl;
	}
	cout << endl;
}
void controller::filter_by_substance()
{
	std::string s;
	cout << "Substanta activa dupa care sa se filtreze: ";
	cin >> s;
	vector<entity> l=this->pharmacy.filter_after_active_substance(s);
	for (int i = 0; i < l.size(); i++)
	{
		entity e = l.at(i);
		cout << e;
		cout << endl;
	}
}
void controller::filter_by_price()
{
	std::string p;
	validator v;
	cout << "Pretul dupa care sa se filtreze: ";
	cin >> p;
	try {
		if (v.price(p) == 1)
		{
			const int pret = stoi(p);
			vector<entity> l=this->pharmacy.filter_after_price(pret);
			for (int i = 0; i < l.size(); i++)
			{
				entity e = l.at(i);
				cout << "Denumire: " << e.get_name();
				cout << "/ Pret: " << e.get_price();
				cout << "/ Producator: " << e.get_producer();
				cout << "/ Substanta Activa: " << e.get_activ_substance();
				cout << endl;
			}
		}
	}
	catch (Exception& ex)
	{
		std::cout << ex.getMessage() << endl;
	}
}
void controller::sort_by_name()
{
	this->pharmacy.sort_after_function(compare_by_name);
}
void controller::sortare_producer()
{
	this->pharmacy.sort_after_function(compare_by_producer);
}

void controller::add_in_prescription()
{
	std::string n;
	cout << "Numele entitatii care sa se adauge in reteta: ";
	getline(cin, n);
	try {
		this->pharmacy.add_in_prescription(n);
		cout << "Entitatea a fost adaugata cu succes!!"<<endl;
	}
	catch (Exception& ex)
	{
		std::cout << ex.getMessage() << endl;
	}
}
void controller::generate_prescription()
{
	int n;
	cout << "Numarul de medicamente care sa se adauge: "<<endl;
	cin >> n;
	this->pharmacy.add_random(n);

}
void controller::print_prescription_menu()
{
	cout << "1.goleste reteta || 2.adauga entitate dupa denumire || 3.genereaza reteta||  4. export || 5.afiseaza reteta "<< endl;
	
}
void controller::print_prescription()
{
	for (auto& i : this->pharmacy.get_prescription().return_vector())
	{
		cout << i << endl;
	}
}
void controller::export_prescription()
{
	std::string n;
	cout << "Numele fisierului: ";
	getline(cin, n);
	this->pharmacy.export_in_file_from_prescription(n);
}
void controller::prescription_menu()
{
	int n;
	while (true)
	{
		print_prescription_menu();
		cout << "Lungime: " << this->pharmacy.count_entity_after_function(return_true)<<endl;
		cout << "Optiunea este: ";
		cin >> n;
		cin.get();
		if (n == 1)
			this->pharmacy.free_prescription();
		else if (n == 2)
			this->add_in_prescription(); 
		else if (n == 3)
			this->generate_prescription();
		else if (n == 0)
			break;
		else if (n == 5)
			this->print_prescription();
		else if (n == 4)
			this->export_prescription();
		else
			cout << "Optiunea nu este corecta!!"<<endl;
	}
}
void controller::meniu()
{
	int n;
	while (true)
	{
		print_menu();
		cout << "\nOptiunea este: ";
		cin >> n;
		cin.get();
		if (n == 1)
			this->add_entity();
		else if (n == 2)
			this->print_pharmacy();
		else if (n == 3)
			this->remove_entity();
		else if (n == 4)
			this->modify_entity();
		else if (n == 5)
			this->find();
		else if (n == 6)
			this->filter_by_substance();
		else if (n == 7)
			this->filter_by_price();
		else if (n == 8)
			this->sort_by_name();
		else if (n == 9)
			this->sortare_producer();
		else if (n == 10)
			this->pharmacy.sort_after_function(compare_by_producer_and_price);
		else if (n == 11)
		{
			try {
				this->pharmacy.undo();
			}
			catch (Exception ex)
			{
				cout << ex.getMessage();
			}
		}
		else if (n == 12)
			this->prescription_menu();
		else if (n == 0)
			break;
		else
			cout << "Optiunea nu este corecta!!";
	}
}
