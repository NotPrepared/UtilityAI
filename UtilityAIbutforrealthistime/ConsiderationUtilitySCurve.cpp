#include "stdafx.h"
#include "ConsiderationUtilitySCurve.h"



ConsiderationUtilitySCurve::ConsiderationUtilitySCurve(char name, bool ascening, bool ramp, float strength, KnowledgeFloat * knowledge, float max)
{
	m_name = name;
	m_iascending = ascening;
	m_ramp = ramp;
	m_strength = strength;
	m_knowledge = knowledge;
	m_maxvalue = max;
}

ConsiderationUtilitySCurve::~ConsiderationUtilitySCurve()
{
}

float ConsiderationUtilitySCurve::compute()
{
	float x = m_knowledge->getValue() / m_maxvalue;
	float tempValue = 0;
	if (m_iascending == true)
	{

		tempValue = 10 * pow(x, 3) - 15 * pow(x, 4) + 6 * pow(x, 5);
	}
	else
	{
		tempValue = 1 - (10 * pow(x, 3) - 15 * pow(x, 4) + 6 * pow(x, 5));
	}
	
	return tempValue;

}
