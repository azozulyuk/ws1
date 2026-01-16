/* Citation and Sources...
-----------------------------------------------------------
Workshop 1
Module: 1
Filename: cstr.h
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
#ifndef SENECA_CSTR_H
#define SENECA_CSTR_H

#include <cstddef>//include the standart library for legnth and sizes

namespace seneca {//to group the functions 

    //add srt string at the very end of des 
    char* strcat(char* des, const char* src);

    //change the uppercase to lower if nedeed
    char tolower(char ch);

    char* tolower(char* des, const char* src);
    char* tolower(char* str);

    //string comparison
    int strcmp(const char* s1, const char* s2);

    int strcmp(const char* s1, const char* s2, size_t len);

    //copy src into des
    char* strcpy(char* des, const char* src);
    char* strcpy(char* des, const char* src, size_t len);
    char* strncpy(char* des, const char* src, size_t len);

    //give back the length of the string
    size_t strlen(const char* str);

    //first appearence ( occurance) of the string
    const char* strstr(const char* str, const char* toFind);

    //character check boolean t/f
    bool isalpha(char ch);//true is a-z/ A-Z
    bool isspace(char ch);//true if has whitespace 

}

#endif//SENECA_CSTR_H
