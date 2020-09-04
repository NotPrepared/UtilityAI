#pragma once
#include "Consideration.h"
class ConsiderationUtilityQuadratic :
	public Consideration
{
public:
	ConsiderationUtilityQuadratic(char name, bool ascending, bool konkav, float strength, KnowledgeFloat* knowledge, float maxvalue);
	~ConsiderationUtilityQuadratic();
	float compute();

private:
	bool m_iascending;
	bool m_konkav;
	float m_strength;
	float m_maxvalue;
};

