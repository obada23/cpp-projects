#pragma once
#include <iostream>
#include "clsQueue.h"
#include "clsDate.h"
#include "clsClock.h"
using namespace std;

class clsQueueLine
{

    private:
        struct stTicketInfo
        {
            string _CurrentTime;
            short _ClientNumber;
            short _EstimatedTime;
            short _ServedClient;
            short _WatingClient;
        };

        short _TotalTicket;
        string _Prefex;
        short _Time;
        stTicketInfo _QueueLine;
        clsQueue<stTicketInfo> _Queue;

    public:
        clsQueueLine(string prefex, short time)
        {
            this->_TotalTicket = 0;
            this->_Prefex = prefex;
            this->_Time = time;
            this->_QueueLine._ClientNumber = 0;
            this->_QueueLine._EstimatedTime = 0;
            this->_QueueLine._ServedClient = 0;
            this->_QueueLine._WatingClient = 0;

        }

        void IssueTicket()
        {
            _TotalTicket++;
            _QueueLine._ClientNumber++;
            _QueueLine._CurrentTime = clsDate::dateToString(clsDate::getSystemDate()) + "  -  " +  clsClock::clockToString(clsClock::getSystemTime());        
            _Queue.push(_QueueLine);
            _QueueLine._WatingClient++;
            _QueueLine._EstimatedTime+=_Time;
            
        }

        void PrintInfo()
        {
            cout << "\n\t\t-----------------------------\n";
            cout << "\t\t\t Queue Info \n";
            cout << "\t\t-----------------------------\n\n";
            cout << "\t\t   Prefix           = " << this->_Prefex << endl;
            cout << "\t\t   Total Tickets    = " << this->_TotalTicket << endl;
            cout << "\t\t   Served CLients   = " << this->_QueueLine._ServedClient << endl;
            cout << "\t\t   Wating Clients   = " << this->_QueueLine._WatingClient << endl;
            cout << "\n\t\t-----------------------------\n\n";
        }

        void PrintTicketsLineRTL()
        {
            cout << "Tickets: ";
            
            for(int i=0;i<_Queue.Size();i++)
            {
                stTicketInfo Queue = _Queue.GetItem(i);
                cout << _Prefex << Queue._ClientNumber << "  <---  ";
            }
            cout << endl << endl;
        }

        void PrintTicketsLineLTR()
        {
            cout << "Tickets: ";
            _Queue.Reverse();
            stTicketInfo Queue;
            for(int i=0;i<_Queue.Size();i++)
            {
                Queue = _Queue.GetItem(i);
                cout << _Prefex << Queue._ClientNumber << "  --->  ";
            }
            _Queue.Reverse();
            cout << endl << endl;
        }

        void PrintAllTickets()
        {
            cout << "\t\t\t Tickets" << endl;
            for(int i=0;i<_Queue.Size();i++)
            {
                cout << "\t\t_____________________________\n\n";
                stTicketInfo Queue = _Queue.GetItem(i);
                cout << "\t\t\t   " << _Prefex << Queue._ClientNumber << endl << endl;
                cout << "\t\t    " <<  Queue._CurrentTime << endl;
                cout << "\t\t    " << "Waiting Clients = " << Queue._WatingClient << endl;
                cout << "\t\t    " << "   Serve Time In " << endl;
                cout << "\t\t    " << "    " << Queue._EstimatedTime << " Minutes." << endl;
                cout << "\n\t\t-----------------------------\n\n";
            }

            
        }

        void ServeNextClient()
        {
            _Queue.pop();
            _QueueLine._WatingClient--;
            _QueueLine._ServedClient++;
            _QueueLine._EstimatedTime -= 10;

        }

};
