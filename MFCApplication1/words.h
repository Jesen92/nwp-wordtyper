#pragma once
#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include <fstream>
#include <string>
#include <tchar.h>



class words {

public:

	CString four[400];
	CString five[400];
	CString six[400];
	CString seven[400];
	CString eight[400];
	CString nine[400];
	CString ten[400];

	words() {
		std::ifstream file_four("G://Rijeci//cetiri.txt");
		std::ifstream file_five("G://Rijeci//pet.txt");
		std::ifstream file_six("G://Rijeci//sest.txt");
		std::ifstream file_seven("G://Rijeci//sedam.txt");
		std::ifstream file_eight("G://Rijeci//osam.txt");
		std::ifstream file_nine("G://Rijeci//devet.txt");
		std::ifstream file_ten("G://Rijeci//deset.txt");

		std::string temp;
		if (file_four.is_open())
		{
			for (int i = 0; i < 400; ++i) {
				file_four >> temp;
				four[i] = temp.c_str();
			}
			file_four.close();
		}

		if (file_five.is_open())
		{
			for (int i = 0; i < 400; ++i) {
				file_five >> temp;
				five[i] = temp.c_str();
			}
			file_five.close();
		}

		if (file_six.is_open())
		{
			for (int i = 0; i < 400; ++i) {
				file_six >> temp;
				six[i] = temp.c_str();
			}
			file_six.close();
		}

		if (file_seven.is_open())
		{
			for (int i = 0; i < 400; ++i) {
				file_seven >> temp;
				seven[i] = temp.c_str();
			}
			file_seven.close();
		}

		if (file_eight.is_open())
		{
			for (int i = 0; i < 400; ++i) {
				file_eight >> temp;
				eight[i] = temp.c_str();
			}
			file_eight.close();
		}

		if (file_nine.is_open())
		{
			for (int i = 0; i < 400; ++i) {
				file_nine >> temp;
				nine[i] = temp.c_str();
			}
			file_nine.close();
		}

		if (file_ten.is_open())
		{
			for (int i = 0; i < 400; ++i) {
				file_ten >> temp;
				ten[i] = temp.c_str();
			}
			file_ten.close();
		}
	}


};