#include "stdafx.h"
#include "KnowledgeFloat.h"



KnowledgeFloat::KnowledgeFloat(char name, float value)
{
	m_name = name;
	m_value = value;
}


KnowledgeFloat::~KnowledgeFloat()
{
}

float KnowledgeFloat::getValue()
{
	return m_value;
}

void KnowledgeFloat::setValue(float newvalue)
{
	m_value = newvalue;
}

void KnowledgeFloat::increaseValue(float newvalue)
{
	m_value = m_value + newvalue;
	if (m_value <= 0) m_value = 0;
}

char KnowledgeFloat::getName()
{
	return m_name;
}
