#pragma once
#include <iostream>
using namespace std;
class clsString
{
    private:
        string _value;
        string _value2;

        static char invertingCharCase(char c)
        {
            return islower(c) ? toupper(c) : tolower(c);
        }

        static bool checkIsVowel(char c)
        {
            c = tolower(c);
            return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
            
        }

        static string lowerAllString(string s)
        {
            for(int i=0;i<s.length();i++)
                s[i] = tolower(s[i]);
            return s;
        }

    public:
        clsString()
        {
            this->_value = "";
        }

        clsString(string value)
        {
            this->_value = value;
        }

        void setValue(string value)
        {
            this->_value = value;
        }

        string getValue()
        {
            return this->_value;
        }

        void setValue2(string value)
        {
            this->_value2 = value;
        }

        string getValue2()
        {
            return this->_value2;
        }



        static void printFirstLetter(string s)
        {
            bool isFirstLetter = true;
            cout << "First letters of this string:" << endl;
            for(int i=0;i<s.length();i++)
            {
                if(s[i] != ' ' && isFirstLetter)
                    cout << s[i] << endl;
                isFirstLetter = (s[i]==' '? true : false);
            }
        }

        void printFirstLetter()
        {
            printFirstLetter(this->_value);
        }

        static string convertFirstLetterToUpper(string s)
        {
            bool isFirstLetter = true;
            for(int i=0;i<s.length();i++)
            {
                if(s[i]!=' '&& isFirstLetter)
                    s[i] = toupper(s[i]);
                isFirstLetter = (s[i] == ' ' ? true : false);
            }
            return s;
        }

        string convertFirstLetterToUpper()
        {
            return convertFirstLetterToUpper(this->_value);
        }

        static string convertFirstLetterToLowerCase(string n)
        {
            bool isFirstLetter = true;
            for(int i=0;i<n.length();i++)
            {
                if(isFirstLetter && n[i]!=' ')
                    n[i] = tolower(n[i]);
                isFirstLetter = (n[i] == ' ' ? true : false);

            }
            return n;
        }

        string convertFirstLetterToLowerCase()
        {
            return convertFirstLetterToLowerCase(this->_value);
        }

        static string convertLettersToUpperCase(string n)
        {
            for(int i=0;i<n.length();i++)
                n[i] = toupper(n[i]);  
            return n;
        }

        string convertLettersToUpperCase()
        {
            return convertLettersToUpperCase(this->_value);
        }

        static string convertLettersToLowerCase(string n)
        {
            for(int i=0;i<n.length();i++)
                n[i] = tolower(n[i]);  
            return n;
        }

        string convertLettersToLowerCase()
        {
            return convertLettersToLowerCase(this->_value);
        }


        static string invertAllLetterCase(string s)
        {
            for(int i=0;i<s.length();i++)
                s[i] = invertingCharCase(s[i]);
            return s;
        }

        string invertAllLetterCase()
        {
            return invertAllLetterCase(this->_value);
        }

        static int countCapitalLetters(string s) 
        {
            int count=0;
            for(int i=0;i<s.length();i++)
                if(isupper(s[i]))
                    count++;

            return count;
        }

        int countCapitalLetters()
        {
            return countCapitalLetters(this->_value);
        }


        static int countSmallLetters(string s)
        {
            int count=0;
            for(int i=0;i<s.length();i++)
                if(islower(s[i]))
                    count++;

            return count;
        }

        int countSmallLetters()
        {
            return countSmallLetters(this->_value);
        }

        static int countCharInTheString(string s,char c)
        {
            int count=0;
            for(int i=0;i<s.length();i++)
                if(s[i] == c)
                    count++;
            return count;
        }

        int countCharInTheString(char c)
        {
            return countCharInTheString(this->_value,c);
        }

        static int countLetterInTheString(string s,char c,bool matchCase=true)
        {
            int count=0;
            for(int i=0;i<s.length();i++)
            {
                if(matchCase==true)
                {
                    if(s[i]==c)
                        count++;
                }
                    
                else
                {
                    if(tolower(s[i])==tolower(c))
                        count++;
                }
            
                    
            }
            return count;
        }

        int countLetterInTheString(char c,bool matchCase=true)
        {
            return countLetterInTheString(this->_value,c,matchCase);
        }

        static short countVowel(string s)
        {
            short count=0;
            for(int i=0;i<s.length();i++)
            {
                if(checkIsVowel(s[i]))
                    count++;
            }
            return count;
        }

        short countVowel()
        {
            return countVowel(this->_value);
        }

        static void printVowel(string s)
        {

            for(int i=0;i<s.length();i++)
            {
                if(checkIsVowel(s[i]))
                    cout << s[i] << "   ";
            }
            cout << endl << endl ;
        }

        void printVowel()
        {
           printVowel(this->_value); 
        }

        static void printEachWord(string s)
        {
            cout << "\nYour string words are:\n";
            int i=0;
            string word="";
            while(i<s.length())
            {
                if(s[i]!=' ')
                {
                    word += s[i];
                    i++;
                }
                else
                {
                    cout << word << endl;
                    i++;
                    word = "";
                }
            }
            cout << word << endl << endl;
            word="";
            
            
        }

        void printEachWord()
        {
            printEachWord(this->_value);
        }

        static short countWords(string s)
        {
            
            int i=0;
            short count=0;
            while(i<s.length())
            {
                if(s[i]!=' ')
                    i++;
                
                else
                {
                    count++;
                    i++;
                }
                    
            }
        
            count++;
            return count;
        }

        short countWords()
        {
            return countWords(this->_value);
        }

        static vector<string> splitString(string s, string c)
        {
            string word = "";
            vector<string> vString;
            int i=0;
            while(i<s.length())
            {
                if(s[i]!=c[0])
                {
                    word += s[i];
                    i++;
                }
                
                else
                {
                    vString.push_back(word);
                    word="";
                    i+=c.length();
                }
                    
            }
            vString.push_back(word);
            word="";
            return vString;
        
        }

        vector<string> splitString()
        {
            return splitString(this->_value,this->_value2);
        }

        static string trimLeft(string n)
        {
            for(short i=0; i<n.length(); i++)
                if(n[i]!=' ')
                    return n.substr(i,n.length()-i);
            return "";

        }

        string trimLeft()
        {
            return trimLeft(this->_value);
        }

        static string trimRight(string n)
        {
            for(short i=n.length()-1; i>=0; i--)
                if(n[i]!=' ')
                    return n.substr(0,i+1);
            return "";
        }

        string trimRight()
        {
            return trimRight(this->_value);
        }

        static string trim(string n)
        {
            return trimLeft(trimRight(n)); 
        }

        string trim()
        {
            return trim(this->_value);
        }

        static string joinString(vector<string> vName, string delim)
        {
            string name="";
            for(int i=0;i<vName.size();i++)
            {
                name+=vName.at(i) + delim;
            }
            
            return name.substr(0,name.length()-delim.length());
        
        }
        string joinString(vector<string> vName)
        {
            return joinString(vName,",,&,,");
        }

        static string reverseString(string s) 
        {
            string temp = "";
            string result = "";
            for(int i=0;i<s.length();i++)
            {
                if(s[i]!=' ')
                {
                    temp += s[i]; 
                }
                else
                {
                    result = temp + " " + result;  
                    temp = "";
                }
            }
            result = temp + " " + result; 
            return result.substr(0,result.length()-1);
        }

        string reverseString()
        {
            return reverseString(this->_value);
        }

        static string replaceWords(string s1 , string country1, string country2)
        {
            string result = "";
            string word = "";
            for(int i=0;i<s1.length();i++)
            {
                if(s1[i]!=' ')
                    word += s1[i];
                
                else
                {
                    if(word==country1)  
                        result += country2 + " ";
                    
                    else
                        result += word + " ";

                    word = "";
                    
                }
            }
            if(word == country1)
                result += country2;
            else 
                result += word;
            
            return result;
        }

        string replaceWords(string country1, string country2)
        {
            return replaceWords(this->_value,country1,country2);
        }

        static string removePauncuations(string name)
        {
            
            string name2 = "";
            for(int i=0;i<name.length();i++)
            {
                if(!ispunct(name[i]))
                    name2+=name[i];
                    
            }
            return name2;

        }

        string removePauncuations()
        {
            return removePauncuations(this->_value);
        }

      
};