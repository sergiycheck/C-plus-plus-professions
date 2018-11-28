#include "stdafx.h"
#include "ProfInfo.h"


using namespace std;

ProfInfo::ProfInfo()
{
	cout << "Constructor **********************************************************" << endl;

}
void ProfInfo::WhatToSet(string SettinStr)
{
	Set(skills, "Resource\\"+SettinStr+"\\Skills.txt");
	Set(Education, "Resource\\" + SettinStr + "\\Education.txt");
	Set(whatWillYouDo, "Resource\\" + SettinStr + "\\WhatWillYouDo.txt");
	profession = SettinStr;
}
void ProfInfo::StoreFileNames()
{
	string pathToFile = "Resource\\1Names of folders\\Names of folders.txt";
	ifstream file;
	string line;

	file.open(pathToFile);
	if (file.is_open())
	{

		while (getline(file, line))
		{

			fileNames.push_back(line);//store elements
		}
		file.close();
	}
	else
	{
		cout << "Unable to open file";
	}
	cout << endl;
	cout << "Folder names : " << endl;
	vector<string >::iterator iter;
	int i = 0;
	for (iter = fileNames.begin(); iter != fileNames.end(); iter++) 
	{
		cout<<i<<" - " << *(iter) << endl;
		i++;
	}
	
}
void ProfInfo::Set(vector<string>& vectStr, string fileName)
{
	
	fstream file;
	string line;
	file.open(fileName);
	if (file.is_open()) 
	{
		while (getline(file, line))
		{
			vectStr.push_back(line);
			
		}
	}
	else 
	{
		cout << "Unable to open file" << endl;
	}

}
void ProfInfo::GetSkills()
{
	cout << endl;
	cout << profession +" skills "<<"*************************************************"<< endl;
	cout << endl;
	vector<string>::iterator iter;
	for (iter = skills.begin(); iter != skills.end(); iter++) cout << *(iter) << endl;
	erase(skills);
}
void ProfInfo::GetEducation()
{
	cout << endl;
	cout << profession + " education " << "*************************************************" << endl;
	cout << endl;
	vector<string>::iterator iter;
	for (iter = Education.begin(); iter != Education.end(); iter++) cout << *(iter) << endl;
	erase(Education);
}
void ProfInfo::GetWhatWillYouDo()
{
	cout << endl;
	cout << profession + " main work " << "*************************************************" << endl;
	cout << endl;
	vector<string>::iterator iter;
	for (iter = whatWillYouDo.begin(); iter != whatWillYouDo.end(); iter++) cout << *(iter) << endl;
	erase(whatWillYouDo);
}
void ProfInfo::erase(vector<string>& vectStr)
{
	vector<string>::iterator iter;
	while (!vectStr.empty())
	{
		vectStr.pop_back();
	}
}
void ProfInfo::ToStringAllInfo()
{
	GetSkills();
	GetEducation();
	GetWhatWillYouDo();
}

ProfInfo::~ProfInfo()
{
	cout << endl;
	cout << "Destructor *************************************" << endl;
}
