# ARMwatch
The ARMwatch is a smart watch based off of the RFduino (ARM Cortex M0 with BLE).

After setting up the board files for the RFduino with the Boards Manager and the link provided in RFduino's quick start up guide, replace platform.txt under C:\Users\<YourUserHere>\AppData\Local\Arduino15\packages\RFduino\hardware\RFduino\2.3.1 with the one on their GitHub: https://github.com/RFduino/RFduino/blob/master/platform.txt (as of version 2.3.1 of RFduino files). This stops the compiler from complaining about deprecated directories and stuff in the platform.txt.
