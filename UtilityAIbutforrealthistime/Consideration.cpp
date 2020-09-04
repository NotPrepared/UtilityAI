#include "stdafx.h"
#include "Consideration.h"
#include <string>




Consideration::Consideration()
{
}

Consideration::Consideration(char name, KnowledgeFloat * aKnowledge)
{
	m_name = name;
	m_knowledge = aKnowledge;
}

Consideration::~Consideration()
{
}

KnowledgeFloat * Consideration::getKnowledge()
{
	return m_knowledge;
}

char Consideration::getName()
{
	return m_name;
}


