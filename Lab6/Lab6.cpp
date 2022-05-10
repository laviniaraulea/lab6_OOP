#include <iostream>
#include "controller.h"
#include "repo.h"
#include "service.h"
#include "test.h"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h> 
using namespace std;

void set_probability_to_fail()
{
	repo_pro* r = new repo_pro;
	float p;
	cout << "Probabilitatea este: ";
	cin >> p;
	r->set_probability(p);
	service s{ r };
	controller c{ s };
	c.meniu();
	delete r;

}
void not_probability()
{
	repo_pro* r = new repo_pro;
	service s{ r };
	controller c{ s };
	c.meniu();
	delete r;
}
int main()
{
    {
        test_all();
		set_probability_to_fail();
		//not_probability();
    }
    _CrtDumpMemoryLeaks(); 
}


