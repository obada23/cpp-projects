#pragma once
#include <iostream>
#include <fstream>
#include "clsString.h"
using namespace std;

class clsCurrency
{
    private:
        string _Country;
        string _Code;
        string _Name;
        float _Rate;

        static clsCurrency _ConvertLineToCurrencyObject(string line, string seprator = "#//#")
        {
            vector<string> vCurrency = clsString::splitString(line,seprator);
            return clsCurrency(vCurrency.at(0),vCurrency.at(1),vCurrency.at(2),stof(vCurrency.at(3)));
        }

        static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string dilm = "#//#")
        {
            string line = "";
            line += Currency.getCountry() + dilm;
            line += Currency.getCode() + dilm;
            line += Currency.getName() + dilm;
            line += to_string(Currency.getRate());
            return line;
        }

        static vector<clsCurrency> _LoadCurrencyDataFormFile()
        {
            vector<clsCurrency> vCurrency;
            fstream myFile;
            myFile.open("Currencies.txt", ios::in);
            if(myFile.is_open())
            {
                string line;
                while(getline(myFile,line))
                {
                    clsCurrency Currency = _ConvertLineToCurrencyObject(line);
                    vCurrency.push_back(Currency);
                }
                myFile.close();
            }
            return vCurrency;

        }

        static clsCurrency _GetEmptyCurrencyObject()
        {
            return clsCurrency("","","",0);
        }

        void _SaveCurrenciesDataToFile(vector<clsCurrency> vCurrency)
        {
            fstream myFile;
            myFile.open("Currencies.txt", ios::out);
            if(myFile.is_open())
            {
                string dataLine;
                for(clsCurrency &C : vCurrency)
                {
                    dataLine = _ConvertCurrencyObjectToLine(C);
                    myFile << dataLine << endl;
                }
                myFile.close();
            }
        }

    public:
        clsCurrency(string Country, string Code, string Name, float Rate)
        {
            this->_Country = Country;
            this->_Code = Code;
            this->_Name = Name;
            this->_Rate = Rate;
        }

        void setCountry(string Country)
        {
            this->_Country = Country;
        }

        string getCountry()
        {
            return this->_Country;
        }

        void setCode(string Code)
        {
            this->_Code = Code;
        }

        string getCode()
        {
            return this->_Code;
        }

        void setName(string Name)
        {
            this->_Name = Name;
        }

        string getName()
        {
            return this->_Name;
        }

        void setRate(float Rate)
        {
            this->_Rate = Rate;
        }

        float getRate()
        {
            return this->_Rate;
        }

        static vector<clsCurrency> GetCurrenciesList()
        {
            return _LoadCurrencyDataFormFile();
        }

        static clsCurrency FindCode(string Code)
        {
            vector <clsCurrency> vCurrency;
            fstream myFile;
            myFile.open("Currencies.txt", ios::in);
            if(myFile.is_open())
            {
                string line;
                while(getline(myFile,line))
                {
                    clsCurrency Currency = _ConvertLineToCurrencyObject(line);
                    if(Currency._Code == Code)
                    {
                        myFile.close();
                        return Currency;
                    }
                }
                myFile.close();
            }
            return _GetEmptyCurrencyObject();
        }

        static clsCurrency FindCountry(string Country)
        {
            vector <clsCurrency> vCurrency;
            fstream myFile;
            myFile.open("Currencies.txt", ios::in);
            if(myFile.is_open())
            {
                string line;
                while(getline(myFile,line))
                {
                    clsCurrency Currency = _ConvertLineToCurrencyObject(line);
                    if(Currency._Country == Country)
                    {
                        myFile.close();
                        return Currency;
                    }
                }
                myFile.close();
            }
            return _GetEmptyCurrencyObject();
        }

        bool isEmptyCode(string Code)
        {
            return (_Code != Code);
        }

        static bool IsCurrencyCodeExist(string Code)
        {
            clsCurrency Currency = FindCode(Code);
            return (!Currency.isEmptyCode(Code));
        }

        bool isEmptyCountry(string Country)
        {
            return (_Country != Country);
        }

        static bool IsCurrencyCountryExist(string Country)
        {
            clsCurrency Currency = FindCountry(Country);
            return (!Currency.isEmptyCountry(Country));
        }

        void Update()
        {
            vector<clsCurrency> vCurrency = _LoadCurrencyDataFormFile();
            for(clsCurrency &C : vCurrency)
            {
                if(C.getCode() == getCode())
                {
                    C = *this;
                    break;
                }
            }
            _SaveCurrenciesDataToFile(vCurrency);
        }

        

};
