// UtilityAIbutforrealthistime.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "UtiliyReasoner.h"
#include "KnowledgeFloat.h"
#include "ConsiderationUtilityLinear.h"
#include "ConsiderationUtilityQuadratic.h"
#include "ConsiderationUtilitySCurve.h"
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
	
	//Knowledges
	KnowledgeFloat* distance = new KnowledgeFloat('d', 8.7f); //Max 10
	KnowledgeFloat* healthSelf = new KnowledgeFloat('h', 7.9f); //Max 10
	KnowledgeFloat* healthEnemy = new KnowledgeFloat('e', 4.6f); //Max 10
	KnowledgeFloat* ammo = new KnowledgeFloat('a', 1.2f); //Max 10
	KnowledgeFloat* ammoEnemy = new KnowledgeFloat('f', 2.1f); //Max 10

	//Considerations für Granate
	ConsiderationUtilityLinear* distancefornade = new ConsiderationUtilityLinear('d', true, distance, 10.0f);
	ConsiderationUtilityLinear* healthselffornade = new ConsiderationUtilityLinear('h', false, healthSelf, 10.0f);
	ConsiderationUtilityQuadratic* healthenemyfornade = new ConsiderationUtilityQuadratic('e', true, false, 2, healthEnemy, 10.0f);
	ConsiderationUtilityLinear* ammofornade = new ConsiderationUtilityLinear('a', true, ammo, 10.0f);
	ConsiderationUtilityQuadratic* ammoenemyfornade = new ConsiderationUtilityQuadratic('f', true, true, 2, healthEnemy, 10.0f);

	vector<Consideration*> considerationsfornade;
	considerationsfornade.push_back(distancefornade);
	considerationsfornade.push_back(healthselffornade);
	considerationsfornade.push_back(healthenemyfornade);
	considerationsfornade.push_back(ammofornade);
	considerationsfornade.push_back(ammoenemyfornade);

	Decision* grenade = new Decision('g', considerationsfornade, 1, 5);


	//Pistol
	ConsiderationUtilitySCurve* distanceforpistol = new ConsiderationUtilitySCurve('a', false, true, 2, distance, 10.0f);
	ConsiderationUtilityQuadratic* ammoforpistol = new ConsiderationUtilityQuadratic('a', true, true, 2, ammo, 10.0f);
	ConsiderationUtilityQuadratic* ammoenemyforpistol = new ConsiderationUtilityQuadratic('a', false, true, 2, ammoEnemy, 10.0f);
	vector<Consideration*> considerationsforpistol;
	considerationsforpistol.push_back(distanceforpistol);
	considerationsforpistol.push_back(ammoforpistol);
	considerationsforpistol.push_back(ammoenemyforpistol);

	Decision* pistol = new Decision('p', considerationsforpistol, 2, 3);

	//Faust
	ConsiderationUtilitySCurve* distanceforfist = new ConsiderationUtilitySCurve('a', false, true, 2, distance, 10.0f);
	ConsiderationUtilityQuadratic* healthforfist = new ConsiderationUtilityQuadratic('a', true, true, 2, healthSelf, 10.0f);
	ConsiderationUtilityLinear* healthenemyforfist = new ConsiderationUtilityLinear('a', false, healthEnemy, 10.0f);
	ConsiderationUtilityLinear* ammoforfist = new ConsiderationUtilityLinear('a', false, ammo, 10.0f);
	ConsiderationUtilityQuadratic* ammoenemyforfist = new ConsiderationUtilityQuadratic('a', false, true, 2, ammoEnemy, 10.0f);
	vector<Consideration*> considerationsforfist;
	considerationsforfist.push_back(distanceforfist);
	considerationsforfist.push_back(healthforfist);
	considerationsforfist.push_back(healthenemyforfist);
	considerationsforfist.push_back(ammoforfist);
	considerationsforfist.push_back(ammoenemyforfist);

	Decision* fist = new Decision('f', considerationsforfist, 3, 5);

	//UtiliyReasoner
	vector<Decision*> decisions;
	decisions.push_back(grenade);
	decisions.push_back(pistol);
	decisions.push_back(fist);

	UtiliyReasoner* utilityReasoner = new UtiliyReasoner(decisions);

	while (true)
	{
		Decision* decisionMade = utilityReasoner->chooseBestDecision();

		switch (decisionMade->getOptnmr())
		{
		case 1:
			cout << "Nade used" << endl;
			ammo->increaseValue(-0.2f);
			distance->increaseValue(+0.2f);
			break;
		case 2:
			cout << "Sniper" << endl;
			ammo->increaseValue(-0.2f);
			distance->increaseValue(+0.2f);
			break;
		case 3:
			cout << "Fistfight" << endl;
			ammo->increaseValue(0.2f);
			distance->increaseValue(-0.2f);
			break;
		default:
			break;
		}
	}
	

	return 0;
}

