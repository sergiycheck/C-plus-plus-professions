#pragma once
#include "Profession.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
class AbstractInfoProf
{
public:
	AbstractInfoProf();
	virtual void Set(vector<string>& vectStr, string fileName) = 0;
	virtual void GetSkills() = 0;
	virtual void GetEducation() = 0;
	virtual void GetWhatWillYouDo() = 0;
	virtual void ToStringAllInfo() = 0;
	virtual void StoreFileNames() = 0;
	virtual void WhatToSet(string SettinStr) = 0;
	virtual void erase(vector<string>& vectStr) = 0;

	~AbstractInfoProf();
private:
	vector<string> skills;
	vector<string>	Education;
	vector<string>	whatWillYouDo;
};

