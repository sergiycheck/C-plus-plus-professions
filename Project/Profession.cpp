#include "stdafx.h"
#include "Profession.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

Profession::Profession()
{
	//profData.insert(pair<string, string>("HR", "Coach"));

	storeElements("Resource\\HR ,human resources services.txt", "HR, human resources services");//storying hr elements
	storeElements("Resource\\IT, computers and the Internet.txt", "IT, computers and the Internet");//storying it elements
	storeElements("Resource\\Aviation and space.txt", "Aviation and space");
	storeElements("Resource\\Humanitarian sciences.txt", "Humanitarian sciences");
	storeElements("Resource\\beauty and health.txt", "Beautiness and health");
	storeElements("Resource\\Natural sciences and research.txt", "Natural sciences and research");
	storeElements("Resource\\Culture, art, design.txt", "Culture, art, design");
	storeElements("Resource\\Agriculture and Water Management.txt", "Agriculture and Water Management");
	storeElements("Resource\\Education and Pedagogy.txt", "Education and Pedagogy");
	storeElements("Resource\\Finance, accounting, bank.txt", "Finance, accounting, bank");
	storeElements("Resource\\Fitness and Sports.txt", "Fitness and Sports");
	storeElements("Resource\\Marketing, Advertising and PR.txt", "Marketing, Advertising and PR");
	storeElements("Resource\\Mass-media, publishing house, polygraphy.txt", "Mass-media, publishing house, polygraphy");
	storeElements("Resource\\Medicine, pharmaceutics.txt", "Medicine, pharmaceutics");
	storeElements("Resource\\Real estate, construction, architecture.txt", "Real estate, construction, architecture");
	storeElements("Resource\\Restaurants, catering.txt", "Restaurants, catering");
	storeElements("Resource\\Secretariat, clerical work, ACO.txt", "Secretariat, clerical work, ACO");
	storeElements("Resource\\Security, Security, Police.txt", "Security, Security, Police");
	storeElements("Resource\\Service sector.txt", "Service sector");
	storeElements("Resource\\Show Business.txt", "Show Business");
	storeElements("Resource\\Working staff.txt", "Working staff");
	storeElements("Resource\\Telecommunications.txt", "Telecommunications");
	storeElements("Resource\\TLaw, Politics.txt", "TLaw, Politics");
	storeElements("Resource\\Tourism, Hospitality.txt", "Tourism, Hospitality");
	storeElements("Resource\\Trade, logistics, foreign trade activities.txt", "Trade, logistics, foreign trade activities");
	storeElements("Resource\\Transport, auto business.txt", "Transport, auto business");

	//ToStringAllElements(profData);//out put elements
}
void Profession::GetInfoAboutProfFromUser() 
{
	cout << "We have such types of professions " << endl;
	ToStringTypesOfProf(profData, beg);
	cout << "Enter the type of your profession. Choose one of the previous types " << endl;
	string type;
	getline(cin, type);
	outPutFromContainer(profData, type);
}
void Profession::TypesOfProf()
{
	ToStringTypesOfProf(profData, beg);
}
void Profession::storeElements(string fileName,string firstInContainer) 
{
	ifstream file;
	string line;

	file.open(fileName);
	if (file.is_open())
	{
		
		while (getline(file, line))
		{
			
			profData.insert(pair<string, string>(firstInContainer, line));//store elements
		}
		file.close();
	}
	else
	{
		cout << "Unable to open file";
	}

}

void Profession::ToStringTypesOfProf(multimap<string, string> container, multimap<string, string>::iterator iter)
{
	iter = container.begin();
	int i = 0;
	for (iter; iter != container.end();iter++)// loop througn all of elements
	{
		std::cout<<i<<" "<< (*iter).first << endl;//cout first element in pair multimap(type of profession)///second one is profession
		i++;
		int num = int(container.count((*iter).first));//cout elements with equal keys
		for (int i = 0; i < num-1; ++i)//skip cout equal keys
		{
			if (iter != container.end())//check if we are not at the end of multimap
			{
				iter++;//increase iterator of equal keys
			}
		}
		if (iter == container.end()) { break; }// if we are at the end we will break loop
		//std::cout<< (*iter).first << endl;//cout first element in pair multimap(type of profession)///second one is profession
	}
}


void Profession::outPutFromContainer(multimap<string, string> container, string firstInContainer)
{
	for (const auto &i : container)
	{
		if (i.first == firstInContainer)
		{
			cout << i.first << " - ";
			for (auto v : i.second) cout << v;
			cout << endl;
		}
	}
}
void Profession::ToStringAllElements(multimap<string, string> container)
{
	for (const auto &i : container)
	{
			cout << i.first << " - ";
			for (auto v : i.second) cout << v;
			cout << endl;
	}
}
void Profession::AddTypeAndProf(string type,string prof) 
{
	profData.insert(pair<string, string>(type, prof));
}


Profession::~Profession()
{
}
