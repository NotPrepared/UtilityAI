#pragma once
#include "Consideration.h"
class ConsiderationUtilitySCurve :
	public Consideration
{
public:
	ConsiderationUtilitySCurve(char name, bool ascening, bool ramp, float strength, KnowledgeFloat* knowledge, float max);
	~ConsiderationUtilitySCurve();
	float compute();

private:
	bool m_iascending;
	bool m_ramp;
	float m_strength;
	float m_maxvalue;

};

