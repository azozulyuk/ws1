
/* Citation and Sources...
-----------------------------------------------------------
Workshop 1
Module: 1
Filename: cstr.cpp
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

#define _CRT_SECURE_NO_WARNINGS//make sure that to extra unneccessary errors appear 
#include "cstr.h"//include the header file so the program knows where are the prototypes

  namespace seneca {//open seneca namespace 

   //makes sure there is enough space for the result + connects src to the end of des 
    char* strcat(char* des, const char* src) {
          size_t len = strlen(des);
       size_t i = 0;
             while (des && src && src[i]) {
               des[i + len] = src[i];
         i++;//iterate after
   }
            des[i + len] = char(0);
             return des;
     }

    
    //change the upper to lowercase + if ch is lower then unchanged 
     char tolower(char ch) {
           if (ch >= 'A' && ch <= 'Z') {
        ch += ('a' - 'A');
          }
      return ch;
     }

              //change all char to lowercase in src
          char* tolower(char* des, const char* src) {
      size_t i = 0;
           for (; des && src && src[i]; i++) {
        des[i] = tolower(src[i]);
           }
      des[i] = char(0);
        return des;
       }

 
          //change all characters to lowercase in string + return the same pointer 
           char* tolower(char* str) {
          for (size_t i = 0; str && str[i]; i++) {
                str[i] = tolower(str[i]); // Uses the char version of tolower()
      }
           return str;
         }

  
                    //compare 2 strings , gives back 0 if equal 
                int strcmp(const char* s1, const char* s2) {
                        size_t i{};
                     for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
        return s1[i] - s2[i];
                 }

   

     //compares characters up to the len of 2 strings ( size) + =0 if they are equal 
              int strcmp(const char* s1, const char* s2, size_t len) {
     size_t i{};
   while (i < len - 1 && s1[i] && s2[i] && s1[i] == s2[i]) {
             i++;//iterate
       }
       return s1[i] - s2[i];
         }

  
            //src is being copied to des  
              //return des 
         char* strcpy(char* des, const char* src) {
                  size_t i;
     for (i = 0; src[i]; i++) des[i] = src[i];
                   des[i] = char(0);
            return des;
      }

  
         //copies the max of len chracters to des 
         char* strcpy(char* des, const char* src, size_t len) {
            size_t i;
         for (i = 0; i < len && src[i]; i++) {
         des[i] = src[i];
           }
      des[i] = 0; 
          return des;//return des back 
         }

  
         //copies max of len characters from src to des and bring back des at the end 
      char* strncpy(char* des, const char* src, size_t len) {
             size_t i = 0;
           while (i < len - 1 && src[i]) {
                des[i] = src[i];
            i++;//keep the iteration going  
          }
           des[i] = src[i];//last char copied here or nullterm.
           return des;
          }

    
        size_t strlen(const char* str) {//return the length so count the char size untill hit the null terminator 
            size_t len{};
            for (len = 0; str && str[len]; len++);
           return len;
       }
 
        //looks for the 1st appearence of the sunstring (toFind) in str
         //returns a pointer 
      const char* strstr(const char* str, const char* toFind) {
         const char* faddress = nullptr;
              size_t
              i,
             flen = strlen(toFind),
         slen = strlen(str);
                   for (i = 0; flen <= slen && i <= slen - flen && strcmp(&str[i], toFind, flen); i++);
                     if (flen <= slen && i <= slen - flen) {
          faddress = &str[i];
             }
         return faddress;
       }

     //introduce the boolean func where if characters are a-z or A-Z = true, anything else returns = false
     bool isalpha(char ch) {
           return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    
         }

    //introduce the boolean func where if characters are true = need to be whitespace 
         bool isspace(char ch) {
      return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
        }

    
}//namespace seneca
