/* Citation and Sources...
-----------------------------------------------------------
Workshop 1
Module: 1
Filename: io.h
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
#pragma once//prevents the file from being included twice
#ifndef SENECA_IO_H//checks if seneca_io_h is alreday defined
#define SENECA_IO_H//file can be processed only once

#include <cstddef>//gives acess to the size_t
#include <cstdio>//lets the usage of files and do different manipulations 

    namespace seneca {//for function grouping 

    struct PhoneRec {//define struct
      char m_name[31];//first name 30 visible characters plus 1 '\0'
      char m_lastName[31];//last name 30 visible characters plus 1 '\0'
        long long m_phoneNumber{};//add phone number
      };
     
    

    
   void read(char* name);//works for reading the keybord name input ( of a user) 
   
    
  void print(long long phone);//print a phone number in a spesific format ((999) 999-9999)

   //prints one record + num + spesific visual setting ( filter) 
    void print(const PhoneRec& rec, size_t& row, const char* filter = nullptr);

         bool read(PhoneRec& rec, FILE* fptr);//reads i single record from a file ( datafile) 

   void print(PhoneRec* recs[], size_t size, const char* filter = nullptr);//brings out ann array of different pointers to the existing records 
    void setPointers(PhoneRec* ptrs[], PhoneRec recs[], size_t size);//pointers[i] id being set to a single record (data)

    
 void sort(PhoneRec* ptrs[], size_t size, bool sortByLastName);//organizes the array pointers by first / last name

   }

#endif//SENECA_IO_H
