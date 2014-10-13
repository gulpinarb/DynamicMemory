//
//  main.cpp
//  DynamicMemory
//
//  Created by Pınar on 04/10/14.
//  Copyright (c) 2014 Pınar. All rights reserved.
//

#include <iostream>
#include "diziislemleri.h"

#define MAXNAME 100


using namespace std;

typedef DynamicArray DataStructure;
DataStructure phoneBook;

void DrawMenu(void);
bool Process (char );
void AddRecord(void);
void ListRecords(void);
void RemoveRecord(void);


int main(int argc, const char * argv[])
{
    phoneBook.initArray();
    bool IsComplete =  false;
    char option;
    while(!IsComplete)
    {
        DrawMenu();
        cin>>option;
        IsComplete = Process(option);
    
    }
    
    return EXIT_SUCCESS;
}

void DrawMenu(void)
{
 cout<<"Enter Option add A: List L: ";

}

bool Process (char option)
{
    bool  IsComplete = false;

    switch(option)
    {
    case 'A':
    case 'a':
            AddRecord();
            break;
            
            case 'L':
            case 'l':
            ListRecords();
            break;
            case 'R':
            case 'r':
            RemoveRecord();
            break;
            case 'E':
            case 'e':
            cout<<  "Are you sure  that you want to terminate to program ? (Y/N):";
            cin >>option;
            if (option == 'y' || option == 'Y')
                IsComplete = true;
            break;
            
        default:
            cout<< "Invalid option, Pelease try again: {A L R E } :";
            cin>>option;
            IsComplete =Process(option);
            break;
    
    }
    
    return IsComplete;


}


void  AddRecord()
{
    char tempName[MAXNAME];
    memset(tempName,0,sizeof(char)*MAXNAME);
    
    cout<< "Please Enter Name:";
    cin.ignore(1000,'\n');
    cin>>tempName;
    PhoneRecord* newPhoneRec = new PhoneRecord;
    newPhoneRec->pName = new char[strlen(tempName) +1];
    memcpy(newPhoneRec->pName,tempName,(strlen(tempName))* sizeof(char));
    
    
    memset(tempName,0,sizeof(char)*MAXNAME);
    cout<< "Please Enter Surname:";
    cin.ignore(1000,'\n');
    cin>>tempName;
    newPhoneRec->pSurname= new char[strlen(tempName) +1];
    memcpy(newPhoneRec->pSurname,tempName,(strlen(tempName))* sizeof(char));
    phoneBook.add(newPhoneRec);

}

void  RemoveRecord()
{}

void ListRecords()
{
    phoneBook.list();

}
