#ifndef WINDOWDISPLAY_H
#define WINDOWDISPLAY_H

#include <Windows.h>
#include <string>
#include <iostream>
#include "Object.h"

enum eCommand {
   ConfigureAnalogOnly  = 0,
   ConfigureDigitalOnly = 1,
   ConfigureBoth = 2,
   SetValueAnalogOnly = 3,
   SetValueDigitalOnly = 4,
   SetValueBoth = 5
};

struct DataPacket {
   eCommand command;
   unsigned int value;
};

class WindowsDisplay : public Object {
public:
   WindowsDisplay(std::string const& pipeName);
   ~WindowsDisplay();

   bool SendValue(unsigned int value);

protected:
   WindowsDisplay(WindowsDisplay const&);
   WindowsDisplay& operator=(WindowsDisplay const&);

private:
   HANDLE mhPipe;

   void Init(std::string const& pipeName);
   bool Send(unsigned int value);
};



class DigitalDisplay: public WindowsDisplay {
public:
   DigitalDisplay(): WindowsDisplay("SDP_DigitalDisplay") {
   }
};


class AnalogDisplay: public WindowsDisplay {
public:
   AnalogDisplay(): WindowsDisplay("SDP_AnalogDisplay") {
   }
};

#endif //WINDOWDISPLAY_H