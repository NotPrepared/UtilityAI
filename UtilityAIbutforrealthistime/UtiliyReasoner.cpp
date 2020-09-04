#include "stdafx.h"
#include "UtiliyReasoner.h"



UtiliyReasoner::UtiliyReasoner(vector<Decision*> decisions)
{
	m_decisions = decisions;
}

UtiliyReasoner::~UtiliyReasoner()
{
}

Decision * UtiliyReasoner::chooseBestDecision()
{
	float bestUtility = 0.0f;
	Decision* bestDecision = nullptr;
	for (int i = 0; i < 3; i++)
	{
		float utilityTemp = m_decisions[i]->computeConsiderations();
		if (utilityTemp >= bestUtility)
		{
			bestUtility = utilityTemp;
			bestDecision = m_decisions[i];
		}
	}
	return bestDecision;
}
