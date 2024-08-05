#include <iostream>
#include "RealUI.h"
#include "AllRequiredHeaders.h"

int main()
{
    User<int>();
    //int arr[5] = {1,2,3,4,0};
    //LinkedList<int> LL(arr,5);
    //MutableListSequence<int> List(LL);
    /*testDynamicArray();
    testLinkedList();
    testArraySequence();
    testListSequence();
    testOperators();
    testMapReduce();*/

    /*int userChoice = selectSequenceType();
    int type;
    if (userChoice != 0)
    {
        type = selectElementsType();
    }
    MutableListSequence<int> listInt;
    MutableArraySequence<int> arrayInt;
    MutableListSequence<double> listDouble;
    MutableArraySequence<double> arrayDouble;
    MutableListSequence<char> listChar;
    MutableArraySequence<char> arrayChar;
    MutableListSequence<MyString> listString;
    MutableArraySequence<MyString> arrayString;


    while (userChoice != 0)
    {
        switch (userChoice)
        {
            case 1:
                if (type == 1)
                {
                    setSequence(listInt);
                    sequenceInterface(listInt, userChoice);
                }
                else if (type == 2)
                {
                    setSequence(listDouble);
                    sequenceInterface(listDouble, userChoice);
                }
                else if (type == 3)
                {
                    setSequence(listChar);
                    sequenceInterface(listChar, userChoice);
                }
                else if (type == 4)
                {
                    setSequence(listString);
                    sequenceInterface(listString, userChoice);
                }
                break;
            case 2:
                if (type == 1)
                {
                    setSequence(arrayInt);
                    sequenceInterface(arrayInt, userChoice);
                }
                else if (type == 2)
                {
                    setSequence(arrayDouble);
                    sequenceInterface(arrayDouble, userChoice);
                }
                else if (type == 3)
                {
                    setSequence(arrayChar);
                    sequenceInterface(arrayChar, userChoice);
                }
                else if (type == 4)
                {
                    setSequence(arrayString);
                    sequenceInterface(arrayString, userChoice);
                }
                break;
        }
        userChoice = selectSequenceType();
        if (userChoice != 0)
        {
            type = selectElementsType();
        }
    }*/
    return 0;
}