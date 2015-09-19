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



class words {

public:

	//array-evi za upis rijeèi
	CString four[200]; //array za upis rijeèi velièine 4 slova
	CString five[200];
	CString six[200];
	CString seven[200];
	CString eight[200];
	CString nine[200];
	CString ten[200];

	words() {
		CString path;
		srand(time(NULL));
		std::string *temp; //varijabla se dinamièki alocira
		int max;
		int i = 0;


		path.LoadString(IDS_FOUR); // uèitava se .txt file
		std::ifstream file_four(path);
		std::istream_iterator<std::string> in4{ file_four }, end4;
		max = std::distance(in4, end4);	//broj rijeèi u .txt file-u
		temp = new std::string[max]; //dinamicka alokacija

		if (file_four.is_open())
		{
			file_four.clear();
			file_four.seekg(0, file_four.beg);
			for (i = 0; i < max; ++i) {
				file_four >> temp[i]; //u temp varijablu se stavljaju sve rijeèi iz file-a

			}


			for (i = 0; i < 200; ++i) {
				four[i] = temp[rand() % max].c_str(); //temp stavlja random 200 rijeèi u array
			}
			delete[]temp;
			file_four.close();
		}

		path.LoadString(IDS_FIVE);
		std::ifstream file_five(path);
		std::istream_iterator<std::string> in5{ file_five }, end5;
		max = std::distance(in5, end5);
		temp = new std::string[max];

		if (file_five.is_open())
		{
			file_five.clear();
			file_five.seekg(0, file_five.beg);
			for (i = 0; i < max; ++i) {
				file_five >> temp[i];

			}


			for (i = 0; i < 200; ++i) {
				five[i] = temp[rand() % max].c_str();
			}
			delete[]temp;
			file_five.close();
		}

		path.LoadString(IDS_SIX);
		std::ifstream file_six(path);
		std::istream_iterator<std::string> in6{ file_six }, end6;
		max = std::distance(in6, end6);
		temp = new std::string[max];

		if (file_six.is_open())
		{
			file_six.clear();
			file_six.seekg(0, file_six.beg);
			for (i = 0; i < max; ++i) {
				file_six >> temp[i];
			}


			for (i = 0; i < 200; ++i) {
				six[i] = temp[rand() % max].c_str();
			}
			delete[]temp;
			file_six.close();
		}

		path.LoadString(IDS_SEVEN);
		std::ifstream file_seven(path);
		std::istream_iterator<std::string> in7{ file_seven }, end7;
		max = std::distance(in7, end7);
		temp = new std::string[max];

		if (file_seven.is_open())
		{
			file_seven.clear();
			file_seven.seekg(0, file_seven.beg);
			for (i = 0; i < max; ++i) {
				file_seven >> temp[i];

			}


			for (i = 0; i < 200; ++i) {
				seven[i] = temp[rand() % max].c_str();
			}
			delete[]temp;
			file_seven.close();
		}

		path.LoadString(IDS_EIGHT);
		std::ifstream file_eight(path);
		std::istream_iterator<std::string> in8{ file_eight }, end8;
		max = std::distance(in8, end8);
		temp = new std::string[max];

		if (file_eight.is_open())
		{
			file_eight.clear();
			file_eight.seekg(0, file_eight.beg);
			for (i = 0; i < max; ++i) {
				file_eight >> temp[i];

			}


			for (i = 0; i < 200; ++i) {
				eight[i] = temp[rand() % max].c_str();
			}
			delete[]temp;
			file_eight.close();
		}

		path.LoadString(IDS_NINE);
		std::ifstream file_nine(path);
		std::istream_iterator<std::string> in9{ file_nine }, end9;
		max = std::distance(in9, end9);
		temp = new std::string[max];

		if (file_nine.is_open())
		{
			file_nine.clear();
			file_nine.seekg(0, file_nine.beg);
			for (i = 0; i < max; ++i) {
				file_nine >> temp[i];

			}


			for (i = 0; i < 200; ++i) {
				nine[i] = temp[rand() % max].c_str();
			}
			delete[]temp;
			file_nine.close();
		}


		path.LoadString(IDS_TEN);
		std::ifstream file_ten(path);
		std::istream_iterator<std::string> in1{ file_ten }, end1;
		max = std::distance(in1, end1);
		temp = new std::string[max];

		if (file_ten.is_open())
		{
			file_ten.clear();
			file_ten.seekg(0, file_ten.beg);
			for (i = 0; i < max; ++i) {
				file_ten >> temp[i];

			}


			for (i = 0; i < 200; ++i) {
				ten[i] = temp[rand() % max].c_str();
			}

			file_ten.close();
		}

		delete[]temp;
	}

};