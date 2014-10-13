//
//  diziislemleri.cpp
//  DynamicMemory
//
//  Created by Pınar on 04/10/14.
//  Copyright (c) 2014 Pınar. All rights reserved.
//

#include "diziislemleri.h"
#include <cstring>
#include <iostream>

using namespace  std;



void DynamicArray::initArray()
{
    iArrayCapacity = 5; //Initial size it will be increased logharitmic when it is full
    PhoneBookArray = new PhoneRecord[iArrayCapacity];
    aintIndex = new int[iArrayCapacity];
    iRecordNumber  = 0;
    aintIndex[0] = 0;
    
}
void DynamicArray::terminateArray()
{
    delete [] PhoneBookArray;
}
void DynamicArray::add(PhoneRecord* newPhoneRecord)
{
    if (iRecordNumber + 1 == iArrayCapacity)
    {
        IncreaseArraySize();
    }
    
    PhoneRecord stRecInArray;
    int tmp1, tmp2;
    int counter =0;
    for (int i =0;i<iRecordNumber ;i++)
    {
        stRecInArray = PhoneBookArray[i];
       if(strcmp(stRecInArray.pName,newPhoneRecord->pName)<0)
          counter++;
       else
          break;
    
    }
    PhoneBookArray[counter] = *newPhoneRecord;
    iRecordNumber++;
    tmp1 = aintIndex[counter];
    aintIndex[counter] = iRecordNumber -1;
    counter++;
    while(counter <= iRecordNumber)
    {
        tmp2 = aintIndex[counter];
        aintIndex [counter]= tmp1;
        tmp1 = tmp2;
        counter++;
    
    }
    
    
}
void DynamicArray::IncreaseArraySize()
{

    iArrayCapacity *= 2;
    PhoneRecord* tmpPhoneBookArray = new PhoneRecord[iArrayCapacity];
    int* tmpaintIndex = new int[iArrayCapacity];
    memcpy (tmpPhoneBookArray, PhoneBookArray, sizeof(PhoneBookArray)*iArrayCapacity);
    memcpy (tmpaintIndex, aintIndex, iArrayCapacity* sizeof(int));
    delete []PhoneBookArray;
    PhoneBookArray = tmpPhoneBookArray;
    delete [] aintIndex;
    aintIndex = tmpaintIndex;

}
void DynamicArray::list()
{
    for(int i =0; i< iRecordNumber; i++)
    {
        cout<< aintIndex[i] +1<<"."<<PhoneBookArray[i].pName<<" "<<PhoneBookArray[i].pSurname<<endl;
    }
}
void DynamicArray::remove(int recordNum)
{
    PhoneRecord* tmpBook = new PhoneRecord[iRecordNumber-1];
    int iNewRecNum =0;
    for (int i=0; i<iRecordNumber; i++)
    {
        if (i!= recordNum){
            tmpBook [iNewRecNum] = PhoneBookArray[i];
            ++iNewRecNum;
        }
        
        iRecordNumber = iNewRecNum;
        delete [] PhoneBookArray;
        PhoneBookArray = tmpBook;
        delete []tmpBook;
     }
}
void DynamicArray::search( char [])
{
}
void DynamicArray::update( int recordNum, PhoneRecord* newPhoneRecord)
{
}
