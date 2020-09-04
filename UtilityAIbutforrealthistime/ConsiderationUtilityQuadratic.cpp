#include "stdafx.h"
#include "ConsiderationUtilityQuadratic.h"


ConsiderationUtilityQuadratic::ConsiderationUtilityQuadratic(char name, bool ascending, bool konkav, float strength, KnowledgeFloat * knowledge, float maxvalue)
{
	m_name = name;
	m_iascending = ascending;
	m_konkav = konkav;
	m_strength = strength;
	m_knowledge = knowledge;
	m_maxvalue = maxvalue;
}

ConsiderationUtilityQuadratic::~ConsiderationUtilityQuadratic()
{
}

float ConsiderationUtilityQuadratic::compute()
{
	float valueTemp = m_knowledge->getValue()/m_maxvalue;
	
	if (m_iascending == true)
	{
		if (m_konkav == true)
		{
			valueTemp = pow (valueTemp, 1/m_strength);
		}
		else
		{
			valueTemp = pow(valueTemp, m_strength);
		}
	}
	else
	{
		if (m_konkav == true)
		{
			valueTemp = 1 - pow(valueTemp, 1 / m_strength);
		}
		else
		{
			valueTemp = 1 - pow(valueTemp, m_strength);
		}
	}
	return valueTemp;
}
