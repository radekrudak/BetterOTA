#include "BetterOTA.h"
#include "terminal/Terminal.h"
#include <ArduinoOTA.h>
#include <utility>
#include <cstdarg>
BetterOTAClass BetterOTA = BetterOTAClass::getInstance();
OTACodeUploaderClass OTACodeUploader = OTACodeUploaderClass::getInstance();
OTATerminalClass OTATerminal = OTATerminalClass::getInstance();

BetterOTAClass BetterOTAClass::getInstance() {
    static BetterOTAClass instance;
    return instance;
}

OTACodeUploaderClass OTACodeUploaderClass::getInstance() {
    static OTACodeUploaderClass instance;
    return instance;
}

OTATerminalClass OTATerminalClass::getInstance() {
    static OTATerminalClass instance;
    return instance;
}

Terminal *terminal;

void BetterOTAClass::handle() {
    ArduinoOTA.handle();
    terminal->server.handleClient();
}

void OTACodeUploaderClass::begin() {
    ArduinoOTA.onStart([]() { if (terminal->hasStarted) terminal->server.close(); });
    ArduinoOTA.begin();
}

void OTATerminalClass::begin(int port) {
    terminal = new Terminal(port);
}

void OTATerminalClass::setHandler(std::function<void(String)> handler) {
    terminal->handler = std::move(handler);
}

void OTATerminalClass::print(const String& str) {
    terminal->outgoing += str;
}

void OTATerminalClass::println(const String& str) {
    terminal->outgoing += str + "\n";
}
String OTATerminalClass::format(String str...){


    va_list arg_list;
    va_start(arg_list,str);
    String ReturnString = str;
    for(int i=0; i< ReturnString.length(); i++)
    {
        if(ReturnString[i] == '%' )
        {
            String left, right;
            left = ReturnString.substring(0,i);
            right = ReturnString.substring(i+2,ReturnString.length());
            if(ReturnString[i+1] == 's' || ReturnString[i+1] == 'd')
            {

                ReturnString = left+va_arg(arg_list,String)+right;



            }
            else if (ReturnString[i+1] == 'i' )
            {

                ReturnString = left+String(va_arg(arg_list,int))+right;


            }
        }

    }
    va_end(arg_list);
    return ReturnString;
    
}
