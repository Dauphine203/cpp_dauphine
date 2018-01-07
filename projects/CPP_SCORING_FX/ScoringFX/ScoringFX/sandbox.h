/*
CURRENCY RANKING C++ MASTER 203 PROJECT

Date: 22/12/2017
File: Sandbox for testing
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>
#include <Eigen/Eigen>
#include <istream>
#include <Windows.h>
#include <wchar.h>


namespace sandbox {

	/// ALGORITHME DE TRI
	//  Create std::pair vector
	void MergeVectors_SD(const std::vector<std::string> C, const std::vector<double> S, std::vector<std::pair<std::string, double>> &vect)
	{
		vect.resize(C.size());

		for (int i = 0; i < C.size(); i++)
		{
			vect[i] = std::make_pair(C[i], S[i]);
		}
	}

	void MergeVectors_ID(const std::vector<int> C, const std::vector<double> S, std::vector<std::pair<int, double>> &vect)
	{
		vect.resize(C.size());

		for (int i = 0; i < C.size(); i++)
		{
			vect[i] = std::make_pair(C[i], S[i]);
		}
	}


	//	Rank currencies according to their score (PAIRED VECTOR CASE)
	void Tri_SD(std::vector<std::pair<std::string, double>> &vect)
	{
		for (int i = 0; i < vect.size() - 1; i++)
		{
			int minimum = i;
			for (int j = i + 1; j < vect.size(); j++)
			{
				if (vect[j].second < vect[minimum].second)
				{
					minimum = j;
				}
			}
			if (minimum != i)
			{
				std::string temp1;
				double temp2;
				temp1 = vect[i].first;
				temp2 = vect[i].second;
				vect[i].first = vect[minimum].first;
				vect[i].second = vect[minimum].second;
				vect[minimum].first = temp1;
				vect[minimum].second = temp2;
			}
		}
	}

	//	Rank currencies according to their score (PAIRED VECTOR CASE)
	void Tri_ID(std::vector<std::pair<int, double>> &vect)
	{
		for (int i = 0; i < vect.size() - 1; i++)
		{
			int minimum = i;
			for (int j = i + 1; j < vect.size(); j++)
			{
				if (vect[j].second < vect[minimum].second)
				{
					minimum = j;
				}
			}
			if (minimum != i)
			{
				int temp1;
				double temp2;
				temp1 = vect[i].first;
				temp2 = vect[i].second;
				vect[i].first = vect[minimum].first;
				vect[i].second = vect[minimum].second;
				vect[minimum].first = temp1;
				vect[minimum].second = temp2;
			}
		}
	}

	/// ARRONDIR
	double Arrondir(double a, int b) {
		int power;
		double result;
		power = pow(10, b);  // 10^b
		result = floor(a*power) / power;
		return result;
	}


	/// GET DATETIME STAMP
	void GetTimeTest() {
		SYSTEMTIME time;
		GetLocalTime(&time);
		wprintf(L"Datetime: %02d/%02d/%02d - %02d:%02d:%02d\n", time.wDay, time.wMonth, time.wYear,
												        	    time.wHour, time.wMinute, time.wSecond);
	}



}