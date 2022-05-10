#pragma once
#include "Domain.h"
#include "repo.h"

class base_undo {
public:
	virtual void doUndo() = 0;
	virtual ~base_undo(){};
};
class add_undo : public base_undo {
	entity ent;
	abstract_repo* rep;
public:
	add_undo(abstract_repo*rep,const entity& e): rep{rep}, ent{e}{}
	void doUndo() override {
		rep->remove(ent.get_name());
	}
};
class remove_undo : public base_undo {
	abstract_repo* rep;
	entity ent;
public:
	remove_undo(abstract_repo* rep, const entity& e): rep{rep}, ent{e}{}
	void doUndo() override {
		rep->add(ent);
	}
};

class modify_undo : public base_undo {
	abstract_repo* rep;
	entity ent1;
	entity ent2;
public:
	modify_undo(abstract_repo* rep, const entity& e1, entity& e2) : rep{ rep }, ent1{ e1 }, ent2{ e2 }{}
	void doUndo() override {
		rep->modify_name_and_price(ent1.get_producer(), ent2.get_name(), ent2.get_price());
	}
};
