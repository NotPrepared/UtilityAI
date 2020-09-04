#include "stdafx.h"
#include "ConsiderationUtilityLinear.h"


ConsiderationUtilityLinear::ConsiderationUtilityLinear(char  name, bool ascending, KnowledgeFloat * aKnowledge, float maxvalue)
{
	m_name = name;
	m_iascending = ascending;
	m_knowledge = aKnowledge;
	m_maxvalue = maxvalue;
}

ConsiderationUtilityLinear::~ConsiderationUtilityLinear()
{
}

float ConsiderationUtilityLinear::compute()
{
	float valueTemp = m_knowledge->getValue();
	if (m_iascending==false) return (1 - valueTemp / m_maxvalue);
	else return (valueTemp / m_maxvalue);

}
