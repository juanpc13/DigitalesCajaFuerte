#include "LCDController.h"
LCDController lcdController;

#include <SPI.h>
#include "RFIDController.h"
RFIDController rfidContol;

#include "KeyPadController.h"
KeyPadController keypadControl;

#include "FingerPrintController.h"
FingerPrintController fingerController;

#include "Solenoid.h"
#define pinSolenoid A2
Solenoid solenoid(pinSolenoid);

#include "LlaveMaestra.h"
#define pinMKey 0
MasterKey masterKey(pinMKey);

boolean isRoot = false;
