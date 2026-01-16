/* Citation and Sources...
-----------------------------------------------------------
Workshop 1
Module: 1
Filename: io.cpp
-----------------------------------------------------------
Author: Anastasiya Zozulyuk
Student number: 139,230,247
Email: azozulyuk@myseneca.ca
Subject: BTP200NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.7    2025/01/15  Completing code
V0.8    2025/01/15  Debugged DMA
V0.9    -         Asked prof for help for XYZ
V1.0    2026/01/16  Ready for submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function main,ect.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS//make sure there is no unexpected errors appear 
#include <iostream>//for count
#include <iomanip>//formattinf of num 
#include <cstdio>//make sure useafe of file is possible 
#include "io.h"//headet file with prototypes included
#include "cstr.h"//include string functions 

using namespace std;//lets more options for programming to exist in code ( cout/std::cout) 

   namespace seneca {//open the seneca namespace
      void read(char* name) {//read the name from the input ( user ) 
           cout << "name>\n ";
    cin >> name;//assume 0 spaces in the name
       }

    //outputs a long long number --> thats the format (999) 999-9999
    void print(long long phone) {
        int area = (int)(phone / 10000000LL);//first 3 digits
        int prefix = (int)((phone / 10000LL) % 1000LL);//middle 3 digits
        int line = (int)(phone % 10000LL);//last 4 digits

             cout << '(' << area << ") ";
            cout << setw(3) << setfill('0') << prefix;//make sure preserving 0 in all of the sections 
         cout << '-';
           cout << setw(4) << setfill('0') << line;
        cout << setfill(' ');//restart fill char + there is no affect on other functions 
    }
        //outputs the PhoneRec with rownum, and any chosen setting ( visual) 
           void print(const PhoneRec& rec, size_t& row, const char* filter) {
        bool match = true;
                   //if filter chosen, check all the user initials by strstr
              if (filter && filter[0] != '\0') {
                       if (!strstr(rec.m_name, filter) && !strstr(rec.m_lastName, filter)) {
                  match = false;
                    }
       }

                if (match) {
        cout << row << ": " << rec.m_name << ' ' << rec.m_lastName << ' ';
                     print(rec.m_phoneNumber);//phone prints the function
                         cout << '\n';
                     row++;
                  }
         }

        //reads PhoneRec using teh FILE and gives back T if 3 fields are successfully read 
         bool read(PhoneRec& rec, FILE* fptr) {
           //names and phone:(tabs or spaces)
        int rv = fscanf(fptr, "%30s %30s %lld",
            rec.m_name,
              rec.m_lastName,
                 &rec.m_phoneNumber);
             return rv == 3;
       }
           //prints PhoneRec data from an array
             void print(PhoneRec* recs[], size_t size, const char* filter) {
              size_t row = 1;
                for (size_t i = 0; i < size; i++) {
         if (recs[i]) {
                print(*recs[i], row, filter);
                 }
             }
           }

          //set the array of pointers regarding the elements in PhoneRec
        void setPointers(PhoneRec* ptrs[], PhoneRec recs[], size_t size) {
        for (size_t i = 0; i < size; i++) {
               ptrs[i] = &recs[i];
        }
               }

    
              void sort(PhoneRec* ptrs[], size_t size, bool sortByLastName) {//sort everything by first and last name regarding the data taken from PhoneRec
                for (size_t i = 0; i + 1 < size; i++) {
          for (size_t j = i + 1; j < size; j++) {

                   const char* left = sortByLastName
                       ? ptrs[i]->m_lastName
                       : ptrs[i]->m_name;

         const char* right = sortByLastName
                        ? ptrs[j]->m_lastName
                : ptrs[j]->m_name;

           //strcmp from cstr
          if (strcmp(left, right) > 0) {
                 PhoneRec* temp = ptrs[i];
               ptrs[i] = ptrs[j];
                 ptrs[j] = temp;
                     }
          }
            }
  }

   }//namespace seneca

