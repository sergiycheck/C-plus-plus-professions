#pragma once
#include <map>

using namespace std;
class Profession
{
public:
	Profession();
	void storeElements(string fileName, string firstInContainer);
	void ToStringAllElements(multimap<string, string> container);
	void ToStringTypesOfProf(multimap<string, string> container, multimap<string, string>::iterator iter);
	void outPutFromContainer(multimap<string, string>, string firstInContainer);
	//////////////////New 
	void AddTypeAndProf(string type,string prof);
	void GetInfoAboutProfFromUser();
	void TypesOfProf();

	void DelTypeAndProf();
	void DelProf();
	void TestToDefProf();
	void DefProfFromWrite();

	//data base
	void GetInfoFromDaTa();
	void SetInfoToDaTa();

	~Profession();
private:
	multimap<string, string> profData;
	multimap<string,string>::iterator beg;

};

