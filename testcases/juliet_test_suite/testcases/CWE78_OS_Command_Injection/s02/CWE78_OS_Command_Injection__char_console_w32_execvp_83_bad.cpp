/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_console_w32_execvp_83_bad.cpp
Label Definition File: CWE78_OS_Command_Injection.strings.label.xml
Template File: sources-sink-83_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: console Read input from the console
 * GoodSource: Fixed string
 * Sinks: w32_execvp
 *    BadSink : execute command with execvp
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITBAD

#include "std_testcase.h"
#include "CWE78_OS_Command_Injection__char_console_w32_execvp_83.h"

#include <process.h>
#define EXECVP _execvp

namespace CWE78_OS_Command_Injection__char_console_w32_execvp_83
{
CWE78_OS_Command_Injection__char_console_w32_execvp_83_bad::CWE78_OS_Command_Injection__char_console_w32_execvp_83_bad(char * dataCopy)
{
    data = dataCopy;
    {
        /* Read input from the console */
        size_t dataLen = strlen(data);
        /* if there is room in data, read into it from the console */
        if (100-dataLen > 1)
        {
            /* POTENTIAL FLAW: Read data from the console */
            if (fgets(data+dataLen, (int)(100-dataLen), stdin) != NULL)
            {
                /* The next few lines remove the carriage return from the string that is
                 * inserted by fgets() */
                dataLen = strlen(data);
                if (dataLen > 0 && data[dataLen-1] == '\n')
                {
                    data[dataLen-1] = '\0';
                }
            }
            else
            {
                printLine("fgets() failed");
                /* Restore NUL terminator if fgets fails */
                data[dataLen] = '\0';
            }
        }
    }
}

CWE78_OS_Command_Injection__char_console_w32_execvp_83_bad::~CWE78_OS_Command_Injection__char_console_w32_execvp_83_bad()
{
    {
        char *args[] = {COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG2, COMMAND_ARG3, NULL};
        /* execvp - searches for the location of the command among
         * the directories specified by the PATH environment variable */
        /* POTENTIAL FLAW: Execute command without validating input possibly leading to command injection */
        EXECVP(COMMAND_INT, args);
    }
}
}
#endif /* OMITBAD */
