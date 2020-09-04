#pragma once
#include "Consideration.h"
class ConsiderationUtilityLinear:
	public Consideration
{
public:
	ConsiderationUtilityLinear(char name, bool ascending, KnowledgeFloat* aKnowledge, float maxValue);
	~ConsiderationUtilityLinear();
	float compute();
private:
	float m_maxvalue;
	bool m_iascending;
};

