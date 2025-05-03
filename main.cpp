#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
    DigitalIn gasDetect(D2);
    DigitalIn overTempDetector(D3);
    DigitalIn alarmOffButton(BUTTON1);

    DigitalOut alarmLed(LED2);

    gasDetect.mode(PullDown);
    overTempDetector.mode(PullDown);

    alarmLed = OFF;

    bool alarmState = OFF;

    while (true) {

        if (gasDetect || overTempDetector) {
            alarmState = ON;
        }

        alarmLed = alarmState;

        if (alarmOffButton) {
            alarmState = OFF;
        }
    }
}