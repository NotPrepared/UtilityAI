#pragma once
#include "Knowledge.h"
class KnowledgeFloat :
	public Knowledge
{
public:
	KnowledgeFloat(char name, float value);
	~KnowledgeFloat();
	float getValue();
	void setValue(float newvalue);
	void increaseValue(float newvalue);
	char getName();

protected:
	float m_value;
	char m_name;


};
