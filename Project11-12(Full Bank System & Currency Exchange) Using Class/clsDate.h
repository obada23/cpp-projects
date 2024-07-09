#pragma warning(disable : 4996)
#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <sstream>
using namespace std;
class clsDate
{
    private:
        short _Day=1;
        short _Month=1;
        short _Year=1900;

        static vector<string> splitString(string dateString,string seperator="/")
        {
            vector<string> vString;
            string word="";
            for(int i=0;i<dateString.length();i++)
            {
                if(dateString[i] != seperator[0])
                {
                    word+=dateString[i];
                }
                else
                {
                    vString.push_back(word);
                    word="";
                }

            }
            vString.push_back(word);
            return vString;
        }
        
        clsDate stringToDate(string dateString)
        {
            vector<string> vString = splitString(dateString);
            clsDate date;
        
            date._Day = stoi(vString[0]);
            date._Month = stoi(vString[1]);
            date._Year = stoi(vString[2]);
            return date;
        }

        static bool isEndOfWeek(string dayName)
        {
            return dayName == "Satarday";
        }

        static bool isWeekEnd(string dayName)
        {
            return dayName == "Friday"|| dayName == "Satarday";
        }

        static bool isBusinessDay(string dayName)
        {
            return dayName!="Friday";
        }

        static short daysUntilTheEndOfWeek(short day)
        {
            short count=0;
            for(int i=day;i<7;i++)
                count++;
            return count;
        }

    public:

        clsDate()
        {
            time_t t = time(0);
            tm* now = localtime(&t);
            this->_Day = now->tm_mday;
            this->_Month = now->tm_mon + 1;
            this->_Year = now->tm_year + 1900;
        }

        clsDate(string date)
        {
            clsDate Date = stringToDate(date);
            this->_Day = Date._Day;
            this->_Month = Date._Month;
            this->_Year = Date._Year;

        }

        clsDate(short day, short month, short year)
        {
            this->_Day = day;
            this->_Month = month;
            this->_Year = year;
        } 

        clsDate(short day, short year)
        {
            struct tm t = {0};
            t.tm_year = year - 1900;
            t.tm_mday = day;
            mktime(&t);

            this->_Day = t.tm_mday;
            this->_Month = t.tm_mon + 1;
            this->_Year = t.tm_year + 1900;
        } 

        void Print()
        {
            cout << this->_Day << "/" << this->_Month << "/" << this->_Year << endl;
        }

        void setDay(short day)
        {
            this->_Day = day;
        }

        short getDay()
        {
            return this->_Day;
        }

        void setMonth(short month)
        {
            this->_Month = month;
        }

        short getMonth()
        {
            return this->_Month;
        }

        void setYear(short year)
        {
            this->_Year = year;
        }

        short getYear()
        {
            return this->_Year;
        }

        static string dayName(short d)
        {
            string days[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thirsday", "Friday", "Satarday" };
            return days[d];
        }

		static string dateToString(clsDate date,string dilm="/")
		{
			string dateString="";
			dateString = to_string(date._Day) + dilm;
			dateString += to_string(date._Month) + dilm;
			dateString += to_string(date._Year);
			return dateString;
		}

		string dateToString(string dilm="/")
		{
			return dateToString(*this,dilm);
		}

        static bool isLeapYear(short year)
        {
            return (year%400==0) || (year%4==0 && year%100!=0); 
        }

        bool isLeapYear()
        {
            return isLeapYear(this->_Year);
        }

        static short numberOfDaysInYear(short year)
        {
            return (isLeapYear(year)) ? 366 : 365;
        }

        short numberOfDaysInYear()
        {
            return numberOfDaysInYear(this->_Year);
        }

        static int numberOfHoursInYear(short year)
        {
            return (isLeapYear(year)) ? 366*24 : 365*24;
        }

        int numberOfHoursInYear()
        {
            return numberOfHoursInYear(this->_Year);
        }

        static int numberOfMinutesInYear(short year)
        {
            return (isLeapYear(year)) ? 366*24*60 : 365*24*60;
        }

		static void SwapDates(clsDate& A, clsDate& B)
		{
			// Swap _Day
			short tempDay = A._Day;
			A._Day = B._Day;
			B._Day = tempDay;

			// Swap _Month
			short tempMonth = A._Month;
			A._Month = B._Month;
			B._Month = tempMonth;

			// Swap _Year
			short tempYear = A._Year;
			A._Year = B._Year;
			B._Year = tempYear;
		}

        int numberOfMinutesInYear()
        {
            return numberOfMinutesInYear(this->_Year);
        }

        static int numberOfSecondsInYear(short year)
        {
            return (isLeapYear(year)) ? 366*24*60*60 : 365*24*60*60;
        }

        int numberOfSecondsInYear()
        {
            return numberOfSecondsInYear(this->_Year);
        }

        static short numberOfDaysInMonth(short year, short month)
        {   
            if (month<1||month>12)
                return 0;
            
            short numberOfDays[] = {31,0,31,30,31,30,31,31,30,31,30,31};
            return (month==2) ? (isLeapYear(year) ? 29 : 28) : numberOfDays[month-1];
        }

        short numberOfDaysInMonth()
        {
            return numberOfDaysInMonth(this->_Year,this->_Month);
        }

        static int numberOfHoursInMonth(short year, short month)
        {
            return numberOfDaysInMonth(year,month)*24;
        }

        int numberOfHoursInMonth()
        {
            return numberOfHoursInMonth(this->_Year,this->_Month);
        }


        static int numberOfMinutesInMonth(short year, short month)
        {
            return numberOfDaysInMonth(year,month)*24*60;
        }

        int numberOfMinutesInMonth()
        {
            return numberOfMinutesInMonth(this->_Year,this->_Month);
        }

        static int numberOfSecondsInMonth(short year, short month)
        {
            return numberOfDaysInMonth(year,month)*24*60*60;
        }

        int numberOfSecondsInMonth()
        {
            return numberOfSecondsInMonth(this->_Year,this->_Month);
        }

        static short dayOrderInWeaks(short year, short month, short day)
        {

            short a = ((14-month)/12);
            short y = year - a;
            short m = month + 12*a - 2;
            short d = (day+y+(y/4)-(y/100)+(y/400)+((31*m)/12))%7;

            return d;
        }

        short dayOrderInWeaks()
        {
            return dayOrderInWeaks(this->_Year,this->_Month,this->_Day);
        }

        static short dayOrderInWeaks(clsDate date)
        {

            short a = ((14-date._Month)/12);
            short y = date._Year - a;
            short m = date._Month + 12*a - 2;
            short d = (date._Day+y+(y/4)-(y/100)+(y/400)+((31*m)/12))%7;

            return d;
        }

        short dayOrderInWeaks() const
        {   
            return dayOrderInWeaks(*this);
        }


        static void calender(short year, short month)
        {
            string months[13] = { "","Jan", "Feb", "Mar", "May","Apr", "Jun", "Jul", "Aug", "Sep","Oct", "Nov", "Dec" };

        
            cout << "______________________" << months[month] << "__________________________\n" << endl;
            cout << "Sun\tMon\tTue\tWed\tThu\tFri\tSat\n";
            int numberOfDays = numberOfDaysInMonth(year,month);
            int current = dayOrderInWeaks(year,month,1);
        
            int i;
            for(i=0;i<current;i++)
                cout << "\t";
            for(int j=1;j<=numberOfDays;j++)
            {
                cout << j << "\t";
                if(++i==7)
                {
                    i=0;
                    cout << endl;
                }
            }
            cout << "\n___________________________________________________\n\n\n\n";
        
        }

        void calender()
        {
            calender(this->_Year,this->_Month);
        }

        static void calenderYear(short year)
        {
            string months[13] = { "","Jan", "Feb", "Mar","Apr", "May", "Jun", "Jul", "Aug", "Sep","Oct", "Nov", "Dec" };

            cout << "___________________________________________________" << endl << endl;
            cout << "\t\t  Calender - " << year << endl;
            cout << "___________________________________________________" << endl << endl;

            for(int month=1;month<=12;month++)
            {
                cout << "______________________" << months[month] << "__________________________\n" << endl;
                cout << "Sun\tMon\tTue\tWed\tThu\tFri\tSat\n";
                int numberOfDays = numberOfDaysInMonth(year,month);
                int current = dayOrderInWeaks(year,month,1);
        
                int i;
                for(i=0;i<current;i++)
                    cout << "\t";
                for(int j=1;j<=numberOfDays;j++)
                {
                    cout << j << "\t";
                    if(++i==7)
                    {
                        i=0;
                        cout << endl;
                    }
                }
                cout << "\n___________________________________________________\n\n\n\n";
            }

        }

        void calenderYear()
        {
            calenderYear(this->_Year);
        }

        static short numberOfDaysFromTheBeginingOfTheYear(short year, short month, short day)
        {
            short totalDays = 0;
            for(int i=1;i<month;i++)
            {
                totalDays+=numberOfDaysInMonth(year,i);
            }
            totalDays+=day;
            return totalDays;
        
        }

        short numberOfDaysFromTheBeginingOfTheYear()
        {
            return numberOfDaysFromTheBeginingOfTheYear(this->_Year,this->_Month,this->_Day);
        }

        static clsDate dateAddDays(short days,clsDate date)
        {
            short remainingDays = days + numberOfDaysFromTheBeginingOfTheYear(date._Year,date._Month,date._Day);
            short monthDays = 0;
            date._Month = 1;
            while(true)
            {
                monthDays = numberOfDaysInMonth(date._Year,date._Month);
                if(remainingDays > monthDays)
                {
                    remainingDays -= monthDays;
                    date._Month++;
                    if(date._Month > 12)
                    {
                        date._Month = 1;
                        date._Year++;
                    }
                }
                else
                    break;
            
            }
            date._Day = remainingDays;
            return date;
        }

        clsDate dateAddDays(short days) const
        {
            return dateAddDays(days,*this);
        }

        static bool checkIsDate1LessThanDate2(clsDate date1,clsDate date2)
        {
            return date1._Year<date2._Year ? true
            : (date1._Year==date2._Year ? date1._Month < date2._Month ? true
            : (date1._Month==date2._Month ? date1._Day < date2._Day ? true
            : false : false) : false);
        }
        bool checkIsDate1LessThanDate2(clsDate date2) const
        {
            return checkIsDate1LessThanDate2(*this,date2);
        }

        static bool checkIsDate1EqualsToDate2(clsDate date1,clsDate date2)
        {
            return date1._Year==date2._Year && date1._Month == date2._Month && date1._Day == date2._Day;
        }

        bool checkIsDate1EqualsToDate2(clsDate date2) const
        {
            return checkIsDate1EqualsToDate2(*this,date2);
        }

        static bool isLastDayInMonth(clsDate date)
        {
            return numberOfDaysInMonth(date._Year,date._Month) == date._Day;
        }

        bool isLastDayInMonth()
        {
            return isLastDayInMonth(*this);
        }

        static bool isLastMonthInYear(clsDate date)
        {
            return date._Month == 12;
        }

        bool isLastMonthInYear()
        {
            return isLastMonthInYear(*this);
        }

        static clsDate increaseDateByOneDay(clsDate date)
        {
            if(isLastDayInMonth(date))
            {
                if(isLastMonthInYear(date))
                {
                    date._Year++;
                    date._Month=1;
                    date._Day=1;

                }
            else
            {
                date._Day=1;
                date._Month++;
            }
        }
            else
                date._Day++;
            return date;
        }

        clsDate increaseDateByOneDay()
        {
            return increaseDateByOneDay(*this);
        }


        static clsDate getSystemDate()
        {
            clsDate date;
            time_t t = time(0);
            tm* now = localtime(&t);
            date._Year = now->tm_year + 1900;
            date._Month = now->tm_mon + 1;
            date._Day = now->tm_mday;
            return date;
        
        }

        static int getDifferenceInDays(clsDate date1, clsDate date2, bool includeEndDays = false)
        {
            bool check;
            if(checkIsDate1LessThanDate2(date1,date2))
                check = true;
            else
                check = false;

            int result = 0;
            while (true)
            {
                if(date1._Year < date2._Year)
                {
                    for(int month=1;month<=12;month++)
                    {
                        result += numberOfDaysInMonth(date1._Year,month);
                    }
                    date1._Year++;
                
                }
                if(date2._Year < date1._Year)
                {
                    for(int month=1;month<=12;month++)
                    {
                        result += numberOfDaysInMonth(date2._Year,month);
                    }
                    date2._Year++;
                
                }
                else if(date1._Year == date2._Year)
                {
                    result+= numberOfDaysFromTheBeginingOfTheYear(date2._Year,date2._Month,date2._Day) - numberOfDaysFromTheBeginingOfTheYear(date1._Year,date1._Month,date1._Day);
                    break;
                }
                
            }
            if(check)
                return includeEndDays==true ? result+1 : result;
            else
                return includeEndDays==true ? -1*(result+1) : -1*result; 
        }

        int getDifferenceInDays(clsDate date2, bool includeEndDays = false)
        {
            return getDifferenceInDays(*this,date2,includeEndDays);
        }
        

        static clsDate increaseDateByOneWeak(clsDate date)
        {
            for(short i=1;i<=7;i++)
            {
                date = increaseDateByOneDay(date);  
            }
            return date;
        }

        clsDate increaseDateByOneWeak()
        {
            return increaseDateByOneWeak(*this);
        }

        static clsDate increaseDateByXWeeks(clsDate date,short weeks)
        {
            for(short i=1;i<=weeks;i++)
            {
                date = increaseDateByOneWeak(date);
            }
            return date;
        }

        clsDate increaseDateByXWeeks(short weeks)
        {
            return increaseDateByXWeeks(*this,weeks);
        }

        static clsDate increaseDateByOneMonth(clsDate date)
        {

            short days = numberOfDaysInMonth(date._Year,date._Month);

            for(short i=1;i<=days;i++)
            {
                date = increaseDateByOneDay(date);
            }
            return date;
        }

        clsDate increaseDateByOneMonth()
        {
            return increaseDateByOneMonth(*this);
        }

        static clsDate increaseDateByXMonths(clsDate date,short months)
        {
        
            for(short i=1;i<=months;i++)
            {
                date = increaseDateByOneMonth(date);
            }
            return date;
        }

        clsDate increaseDateByXMonths(short months)
        {
            return increaseDateByXMonths(*this,months);
        }

        static clsDate increaseDateByOneYear(clsDate date)
        {
            date._Year++;
            return date;
        }

        clsDate increaseDateByOneYear()
        {
            return increaseDateByOneYear(*this);
        }

        static clsDate increaseDateByXYears(clsDate date,short years)
        {
            for(short i=1;i<=years;i++)
                date = increaseDateByOneYear(date);
            return date;
        }

        clsDate increaseDateByXYears(short years)
        {
            return increaseDateByXYears(*this,years);
        }

        static clsDate increaseDateByXYearsFaster(clsDate date,short years)
        {
            date._Year += years;
            return date;
        }

        clsDate increaseDateByXYearsFaster(short years)
        {
            return increaseDateByXYearsFaster(*this,years);
        }

        static clsDate increaseDateByOneDecade(clsDate date)
        {
            date._Year += 10;
            return date;
        }

        clsDate increaseDateByOneDecade()
        {
            return increaseDateByOneDecade(*this);
        }

        static clsDate increaseDateByXDecade(clsDate date,short decade)
        {
            for(int i=1;i<=decade;i++)
                date = increaseDateByOneDecade(date);
            return date;
        }

        clsDate increaseDateByXDecade(short decade)
        {
            return increaseDateByXDecade(*this,decade);
        }

        static clsDate increaseDateByXDecadeFaster(clsDate date,short decade)
        {
            date._Year += 10*decade;
            return date;
        }

        clsDate increaseDateByXDecadeFaster(short decade)
        {
            return increaseDateByXDecadeFaster(*this,decade);
        }

        static clsDate increaseDateByOneCentury(clsDate date)
        {
            date._Year += 100;
            return date;
        }

        clsDate increaseDateByOneCentury()
        {
            return increaseDateByOneCentury(*this);
        }

        static clsDate increaseDateByOneMillennium(clsDate date)
        {
            date._Year += 1000;
            return date;    
        }

        clsDate increaseDateByOneMillennium()
        {
            return increaseDateByOneMillennium(*this);
        }


        static bool isFirstDayInMonth(clsDate date)
        {
            return date._Day=1;
        }

        bool isFirstDayInMonth()
        {
            return isFirstDayInMonth(*this);
        }

        static bool isFirstMonthInYear(clsDate date)
        {
            return date._Month==1;
        }

        bool isFirstMonthInYear()
        {
            return isFirstMonthInYear(*this);
        }



        static clsDate decreaseDateByOneDay(clsDate date)
        {
            if(isFirstDayInMonth(date))
            {
                if(isFirstMonthInYear(date))
                {
                    date._Year--;
                    date._Month=12;
                    date._Day=numberOfDaysInMonth(date._Year,date._Month);

                }
                else
                {

                    date._Month--;
                    date._Day=numberOfDaysInMonth(date._Year,date._Month);
                
                }
            }
                else
                    date._Day--;
                return date;
        }

        clsDate decreaseDateByOneDay()
        {
            return decreaseDateByOneDay(*this);
        }

        static clsDate decreaseDateByXDays(clsDate date,short days)
        {
            for(short i=1;i<=days;i++)
            {
                date = decreaseDateByOneDay(date);
            }
            return date;
        }

        clsDate decreaseDateByXDays(short days)
        {
            return decreaseDateByXDays(*this,days);
        }

        static clsDate decreaseDateByOneWeak(clsDate date)
        {
            for(short i=1;i<=7;i++)
            {
                date = decreaseDateByOneDay(date);  
            }
            return date;
        }

        clsDate decreaseDateByOneWeak()
        {
            return decreaseDateByOneWeak(*this);
        }

        static clsDate decreaseDateByXWeeks(clsDate date,short weeks)
        {
            for(short i=1;i<=weeks;i++)
            {
                date = decreaseDateByOneWeak(date);
            }
            return date;
        }

        clsDate decreaseDateByXWeeks(short weeks)
        {
            return decreaseDateByXWeeks(*this,weeks);
        }


        static clsDate decreaseDateByOneMonth(clsDate date)
        {
            if(date._Month==1)
            {
                date._Month=12;
                date._Year--;
            }
            else
                date._Month--;

            short days = numberOfDaysInMonth(date._Year,date._Month);

            if(date._Day > days )
                date._Day = days;
            return date;
        }

        clsDate decreaseDateByOneMonth()
        {
            return decreaseDateByOneMonth(*this);
        }

        static clsDate decreaseDateByXMonths(clsDate date,short months)
        {
        
            for(short i=1;i<=months;i++)
            {
                date = decreaseDateByOneMonth(date);
            }
            return date;
        }

        clsDate decreaseDateByXMonths(short months)
        {
            return decreaseDateByXMonths(*this,months);
        }

        static clsDate decreaseDateByOneYear(clsDate date)
        {
            date._Year--;
            return date;
        }

        clsDate decreaseDateByOneYear()
        {
            return decreaseDateByOneYear(*this);
        }

        static clsDate decreaseDateByXYears(clsDate date,short years)
        {
            for(short i=1;i<=years;i++)
                date = decreaseDateByOneYear(date);
            return date;
        }

        clsDate decreaseDateByXYears(short years)
        {
            return decreaseDateByXYears(*this,years);
        }

        static clsDate decreaseDateByXYearsFaster(clsDate date,short years)
        {
            date._Year -= years;
            return date;
        }

        clsDate decreaseDateByXYearsFaster(short years)
        {
            return decreaseDateByXYearsFaster(*this,years);
        }

        static clsDate decreaseDateByOneDecade(clsDate date)
        {
            date._Year -= 10;
            return date;
        }

        clsDate decreaseDateByOneDecade()
        {
            return decreaseDateByOneDecade(*this);
        }

        static clsDate decreaseDateByXDecade(clsDate date,short decade)
        {
            for(int i=1;i<=decade;i++)
                date = decreaseDateByOneDecade(date);
            return date;
        }

        clsDate decreaseDateByXDecade(short decade)
        {
            return decreaseDateByXDecade(*this,decade);
        }

        static clsDate decreaseDateByXDecadeFaster(clsDate date,short decade)
        {
            date._Year -= 10*decade;
            return date;
        }

        clsDate decreaseDateByXDecadeFaster(short decade)
        {
            return decreaseDateByXDecadeFaster(*this,decade);
        }

        static clsDate decreaseDateByOneCentury(clsDate date)
        {
            date._Year -= 100;
            return date;
        }

        clsDate decreaseDateByOneCentury()
        {
            return decreaseDateByOneCentury(*this);
        }

        static clsDate decreaseDateByOneMillennium(clsDate date)
        {
            date._Year -= 1000;
            return date;
        }

        clsDate decreaseDateByOneMillennium()
        {
            return decreaseDateByOneMillennium(*this);
        }


        static short daysUntilTheEndOfMonth(clsDate date)
        {
            short count=0;
            short daysInCurrentMonth = numberOfDaysInMonth(date._Year,date._Month);
            for(short i=date._Day;i<=daysInCurrentMonth;i++)
                count++;    
            return count;   
        }

        short daysUntilTheEndOfMonth()
        {
            return daysUntilTheEndOfMonth(*this);
        }

        static short daysUntilTheEndOfYear(clsDate date)
        {
            short sumOfTheDays=0;
            for(int i=date._Month;i<=12;i++)
                sumOfTheDays += numberOfDaysInMonth(date._Year,date._Month);
            return sumOfTheDays-date._Day;
        
        }

        short daysUntilTheEndOfYear()
        {
            return daysUntilTheEndOfYear(*this);
        }


        static bool checkIsDate1AfterThanDate2(clsDate date1, clsDate date2)
        {
            return (!checkIsDate1LessThanDate2(date1,date2) && !checkIsDate1EqualsToDate2(date1,date2));
        } 

        bool checkIsDate1AfterThanDate2(clsDate date2)
        {
            return checkIsDate1AfterThanDate2(*this,date2);
        }   

        static short actucalVacationDays(clsDate dateStart,clsDate dateEnd)
        {
            short days=0;
            while(checkIsDate1LessThanDate2(dateStart,dateEnd))
            {
                if(!isWeekEnd(dayName(dayOrderInWeaks(dateStart))))
                    days++;
                dateStart = increaseDateByOneDay(dateStart);
            }
            return days;

        } 

        short actucalVacationDays(clsDate dateEnd)
        {
            return actucalVacationDays(*this,dateEnd);
        }

        enum enDateCompare{ Before = -1, Equal = 0, After = 1 };

        static enDateCompare dateCompare(clsDate date1,clsDate date2)
        {
            if(checkIsDate1LessThanDate2(date1,date2))
                return Before;
            else if(checkIsDate1EqualsToDate2(date1,date2))
                return Equal;
            else
                return After;
        }

        enDateCompare dateCompare(clsDate date2)
        {
            return dateCompare(*this,date2);
        }

        static string getSystemTime()
        {
            auto now = chrono::system_clock::now();
            time_t currentTime = chrono::system_clock::to_time_t(now);

            // Convert to a tm structure
            tm *localTime = localtime(&currentTime);

            // Create a string stream to format the output
            ostringstream oss;
            oss << put_time(localTime, "%H:%M:%S");

            // Output the formatted time
            string currentTimeStr = oss.str();
            return currentTimeStr;
        }



    };

