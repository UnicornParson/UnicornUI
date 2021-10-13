// proxy functions gor internal logging

import QtQuick 2.0

Item
{
    id: root
    function logDebug()
    {
        if(!globals)
            return

        var message = ""
        for (var i = 0; i < arguments.length; i++)
        {
            message += String(arguments[i]) + " "
        }
        globals.uDebug(message)
    }

    function logTrace()
    {
        if(!globals)
            return

        var message = ""
        for (var i = 0; i < arguments.length; i++)
        {
            message += String(arguments[i]) + " "
        }
        globals.uTrace(message)
    }

    function logWarning()
    {
        if(!globals)
            return

        var message = ""
        for (var i = 0; i < arguments.length; i++)
        {
            message += String(arguments[i]) + " "
        }
        globals.uWarning(message)
    }

    function logError()
    {
        if(!globals)
            return

        var message = ""
        for (var i = 0; i < arguments.length; i++)
        {
            message += String(arguments[i]) + " "
        }
        globals.uError(message)
    }

    function logCritical()
    {
        if(!globals)
            return

        var message = ""
        for (var i = 0; i < arguments.length; i++)
        {
            message += String(arguments[i]) + " "
        }
        globals.uCritical(message)
    }

    function logFatal()
    {
        if(!globals)
            return

        var message = ""
        for (var i = 0; i < arguments.length; i++)
        {
            message += String(arguments[i]) + " "
        }
        globals.uFatal(message)
    }
}
