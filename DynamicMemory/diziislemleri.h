//
//  diziislemleri.h
//  DynamicMemory
//
//  Created by Pınar on 04/10/14.
//  Copyright (c) 2014 Pınar. All rights reserved.
//

#ifndef DynamicMemory_diziislemleri_h
#define DynamicMemory_diziislemleri_h


#include <stdio.h>
#include "record.h"


struct DynamicArray{

    PhoneRecord* PhoneBookArray;
    void initArray();
    void terminateArray();
    void add(PhoneRecord* newPhoneRecord);
    void IncreaseArraySize();
    void list();
    void remove(int recordNum);
    void search( char []);
    void update( int recordNum, PhoneRecord* newPhoneRecord);
    int iRecordNumber;
    int iArrayCapacity;
    int* aintIndex;

};


#endif
