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

	template <typename T>
	static bool IsNumberBetween(T Number, T From, T To)
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

	template <typename T>
	static int ReadIntNumberBetween(T From, T To, string ErrorMessage="Number is not within range, Enter again:\n")
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

	static bool IsValideDate(clsDate Date)
	{
		//return	clsDate::isvalidte(Date);
	}

};

