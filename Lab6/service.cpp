#include "service.h"
#include <random>


void service::add_in_prescription(const std::string &n)
{
    const size_t i = this->find_entity_from_list_medicine(n);
    this->prescription.add(this->get_entity_from_list_medicine(i));
}
void service::free_prescription() noexcept
{
    this->prescription.free();
}
void service::add_random(const int &n)
{
    std::mt19937 mt{ std::random_device{}() };
    std::uniform_int_distribution<>const dist(0, (int)this->list_medicine->get_length() - 1);
    for (int i = 0; i < n; i++)
    {
        const size_t rndNr = dist(mt);
        this->prescription.add(this->get_entity_from_list_medicine(rndNr));
    }

}
entity service::get_entity_from_prescription(const size_t& i) const
{
    return this->prescription.get_entity(i);
}
void service::sort_after_function(int (*comparare)(entity e1, entity e2)) {
    
    for (int i = 0; i < list_medicine->get_length(); i++)
        for (int j = 0; j < list_medicine->get_length(); j++)
        {
                if (comparare(list_medicine->get_entity(i), list_medicine->get_entity(j)) > 0)
                    list_medicine->swap(i, j);
        }
}
size_t service::get_lenght_prescription() const noexcept
{
    return this->prescription.get_length();
}

void service::export_in_file_from_prescription(std::string fisier)
{
    std::ofstream f(fisier);
    for (int i = 0; i < this->get_lenght_prescription(); i++)
    {
        entity it = this->get_entity_from_prescription(i);
        f << it.get_name() << "," << it.get_price() << "," << it.get_producer() << "," << it.get_activ_substance() << endl;
    }
  //  std::for_each(lst.begin(), lst.end(), [&](auto it) {    f <<it.get_name() << "," << it.get_price() << "," << it.get_producer() << "," << it.get_activ_substance() << endl;
 //       });
    f.close();

}

size_t service::get_lenght_list_medicine() const noexcept
{
    return this->list_medicine->get_length();
}

abstract_repo* service::get_list_medicine()
{
    return this->list_medicine;
}

repo service::get_prescription()
{
    return this->prescription;
}

entity service::get_entity_from_list_medicine(const size_t& i) const
{
    if (i<0 || i>this->get_lenght_list_medicine())  throw Exception("Indexul nu e valid!!");
    return this->list_medicine->get_entity(i);
}

void service::add_in_list_medicine(const entity &e)
{
    this->list_medicine->add(e);
    this->undo_list.push_back(new add_undo{this->list_medicine,e });
}

void service::delete_entity_from_list_medicine(const std::string &n)
{
   const size_t i = this->find_entity_from_list_medicine(n);
   entity f = this->get_entity_from_list_medicine(i);
   this->undo_list.push_back(new remove_undo{this->list_medicine,f});
   this->list_medicine->remove(n);
}

void service::modify_enity_from_list_medicine(const std::string &pro,const std::string &n,const int &p)
{
    entity f1;
    f1 = this->list_medicine->find_by_producer(pro);
    this->list_medicine->modify_name_and_price(pro, n, p);
    entity f2 = this->get_entity_from_list_medicine(this->find_entity_from_list_medicine(n));
     this->undo_list.push_back(new modify_undo{ this->list_medicine, f2,f1 });
}

size_t service::find_entity_from_list_medicine(const std::string &n) const
{
    const size_t i= this->list_medicine->find_by_name(n);
    return i;
}

vector<entity> service::filter_after_active_substance(const std::string& substance)
{
    vector<entity> l;
    vector<entity> sursa= this->list_medicine->return_vector();
    copy_if(sursa.begin(), sursa.end(), std::back_inserter(l), [&substance](const entity &e) {return e.get_activ_substance() == substance; });
    return l;
}

vector<entity> service::filter_after_price(const int price)
{
    vector<entity> l;
    vector<entity> sursa = this->list_medicine->return_vector();
    copy_if(sursa.begin(), sursa.end(), std::back_inserter(l), [&price](const entity& e) {return e.get_price() == price; });
    return l;
}

int service::count_entity_after_function(bool (*compare)(entity e))
{
    std::vector<entity> v = this->prescription.return_vector();
    return (int)count_if(v.begin(), v.end(), compare);
}

void service::undo()
{
    if (this->undo_list.empty())      throw Exception("Nu se poate efectua undo!!");
    else
    {
        base_undo* und = this->undo_list.back();
        und->doUndo();
        this->undo_list.pop_back();
        delete und;
    }
}

