#pragma once
#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include <fstream>
#include <string>
#include <tchar.h>
#include <cstdio>
#include <iterator>
#include <vector>


using namespace std;

class words {

public:

	vector<std::string> list_words;

	words() {


		std::ifstream file("rijeci.txt");
		
		copy(istream_iterator<std::string>(file), istream_iterator<std::string>(), back_inserter(list_words));

	}

};