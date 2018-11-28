#pragma once
#include "AbstractInfoProf.h"
#include <fstream>
#include <string>
class ProfInfo :
	private AbstractInfoProf
{
public:
	ProfInfo();
	void Set(vector<string>&vectStr, string fileName);
	void GetSkills();
	void GetEducation();
	void GetWhatWillYouDo();
	void StoreFileNames();

	void WhatToSet(string SettinStr);
	void ToStringAllInfo();
	void erase(vector<string>& vectStr);
	~ProfInfo();
private:
	string profession;
	vector<string> skills;
	vector<string>	Education;
	vector<string>	whatWillYouDo;
	vector<string>  fileNames;
};

