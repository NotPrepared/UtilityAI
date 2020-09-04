#pragma once
#include "KnowledgeFloat.h"
#include <string>

class Consideration
{
public:
	Consideration();
	Consideration(char name, KnowledgeFloat* aKnowledge);
	~Consideration();
	KnowledgeFloat* getKnowledge();
	char getName();
	virtual float compute()= 0;

protected:
	KnowledgeFloat * m_knowledge;
	char m_name;

private:

};
