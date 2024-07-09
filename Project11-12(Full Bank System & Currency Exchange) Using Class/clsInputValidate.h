//ProgrammingAdivces.com
//Mohammed Abu-Hadhoud

#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"

class clsInputValidate
{

public:

	static bool IsNumberBetween(short Number, short From, short To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(int Number , int From, int To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;

	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		//Date>=From && Date<=To
		if ((clsDate::checkIsDate1AfterThanDate2(Date, From) || clsDate::checkIsDate1EqualsToDate2(Date, From)) 
			&&
			(clsDate::checkIsDate1LessThanDate2(Date, To) || clsDate::checkIsDate1EqualsToDate2(Date, To))
		  )
		{
			return true;
		}
		
		//Date>=To && Date<=From
		if ((clsDate::checkIsDate1AfterThanDate2(Date, To) || clsDate::checkIsDate1EqualsToDate2(Date, To)) 
			&&
			(clsDate::checkIsDate1LessThanDate2(Date, From) || clsDate::checkIsDate1EqualsToDate2(Date, From))
		   )
		{
			return true;
		}

		return false;
	}

	static int ReadIntNumber(string ErrorMessage="Invalid Number, Enter again\n")
	{
		int Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage ;
		}
		return Number;
	}

	static string ReadString(string message)
	{
		string name;
		cout << message;
		getline(cin>>ws,name);
		return name;
	}

	static float ReadFloatNumber(string message)
	{
		float number;
		cout << message;
		cin >> number;
		return number;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage="Number is not within range, Enter again:\n")
	{
		int Number=ReadIntNumber();

		while (!IsNumberBetween(Number,From,To)) 
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}

	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		double Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		double Number = ReadDblNumber();

		while (!IsNumberBetween(Number, From, To)) {
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}
		return Number;
	}
	

	/* static bool IsValideDate(clsDate Date)
	{
		return	clsDate::isValidDate(Date);
	} */

};

