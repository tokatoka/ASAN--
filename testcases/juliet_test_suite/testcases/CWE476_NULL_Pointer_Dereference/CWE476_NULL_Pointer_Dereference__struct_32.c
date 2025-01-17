/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__struct_32.c
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sinks-32.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Check for NULL before attempting to print data
 *    BadSink : Print data
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE476_NULL_Pointer_Dereference__struct_32_bad()
{
    twoIntsStruct * data;
    twoIntsStruct * *dataPtr1 = &data;
    twoIntsStruct * *dataPtr2 = &data;
    {
        twoIntsStruct * data = *dataPtr1;
        /* POTENTIAL FLAW: Set data to NULL */
        data = NULL;
        *dataPtr1 = data;
    }
    {
        twoIntsStruct * data = *dataPtr2;
        /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
        printIntLine(data->intOne);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    twoIntsStruct * data;
    twoIntsStruct * *dataPtr1 = &data;
    twoIntsStruct * *dataPtr2 = &data;
    {
        twoIntsStruct * data = *dataPtr1;
        /* FIX: Initialize data */
        {
            twoIntsStruct tmpData;
            tmpData.intOne = 0;
            tmpData.intTwo = 0;
            data = &tmpData;
        }
        *dataPtr1 = data;
    }
    {
        twoIntsStruct * data = *dataPtr2;
        /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
        printIntLine(data->intOne);
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    twoIntsStruct * data;
    twoIntsStruct * *dataPtr1 = &data;
    twoIntsStruct * *dataPtr2 = &data;
    {
        twoIntsStruct * data = *dataPtr1;
        /* POTENTIAL FLAW: Set data to NULL */
        data = NULL;
        *dataPtr1 = data;
    }
    {
        twoIntsStruct * data = *dataPtr2;
        /* FIX: Check for NULL before attempting to print data */
        if (data != NULL)
        {
            printIntLine(data->intOne);
        }
        else
        {
            printLine("data is NULL");
        }
    }
}

void CWE476_NULL_Pointer_Dereference__struct_32_good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */
#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE476_NULL_Pointer_Dereference__struct_32_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE476_NULL_Pointer_Dereference__struct_32_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
