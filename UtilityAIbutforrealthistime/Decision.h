#pragma once
#include "Consideration.h"
#include <vector>
using namespace std;
class Decision
{
public:
	Decision(char name, vector<Consideration*> considerations, int optnmr, int consamount);
	~Decision();
	float computeConsiderations();
	int getOptnmr();
	void addConsideration(Consideration* cons);

private:
	int m_optnmr; //Ersetzt Option der Einfachkeit halber
	std::vector<Consideration*> m_considerations;
	char m_name;
	int m_considerationAmount;
};

