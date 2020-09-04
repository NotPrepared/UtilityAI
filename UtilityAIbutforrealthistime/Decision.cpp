#include "stdafx.h"
#include "Decision.h"



Decision::Decision(char name, vector<Consideration*> considerations, int optnmr, int consamount)
{
	m_considerations = considerations;
	m_name = name;
	m_optnmr = optnmr;
	m_considerationAmount = consamount;
}

Decision::~Decision()
{
}

float Decision::computeConsiderations()
{
	float tempValue = 0.0f;
	for (int i = 0; i < m_considerationAmount; i++)
	{
		tempValue += m_considerations[i]->compute();
	}
	tempValue = tempValue / m_considerationAmount;
	return tempValue;
}

int Decision::getOptnmr()
{
	return m_optnmr;
}

void Decision::addConsideration(Consideration * cons)
{
	m_considerations.push_back(cons);
}
