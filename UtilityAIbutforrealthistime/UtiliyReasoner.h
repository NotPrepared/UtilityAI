#pragma once
#include <vector>
#include "Decision.h"
#include "ConsiderationUtilityLinear.h"
#include "ConsiderationUtilityQuadratic.h"
#include "KnowledgeFloat.h"
using namespace std;

class UtiliyReasoner
{
public:
	UtiliyReasoner(vector<Decision*> decisions);
	~UtiliyReasoner();
	Decision* chooseBestDecision();
private:
	vector<Decision*> m_decisions;
	float m_averageUtility;
};

