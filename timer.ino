#include <TM1637Display.h>  // Include the TM1637Display library

// Define the CLK and DIO pins for the TM1637 module
#define CLK 8
#define DIO 9
int seconds = 0;
unsigned long startTime, endTime, elapsedTime;

// Initialize the TM1637Display module
TM1637Display display(CLK, DIO);

void setup(){
  // Set the brightness of the display (0-7)
  display.setBrightness(0x0f);

  //save start time
  startTime = millis();
}

  
void loop() {
  //increment the seconds counter
  seconds++;

  //convert seconds to minutes and seconds
  int minutes = seconds / 60;
  int secondsDisplay = seconds % 60;

  //display time
  display.showNumberDecEx(minutes*100 + secondsDisplay, 0b01000000, true);
  
  //check if 10 minutes passed
  if (minutes == 10) {
    unsigned long endTime = millis(); // save the end time
    unsigned long elapsedTime = endTime - startTime; // calculate the elapsed time
    int timeDiff = elapsedTime - seconds; // calculate time difference
    display.showNumberDec(timeDiff);
    while (true) {} // stay in an infinite loop to stop the timer
  }
  //delay 1sec to loop again
  delay(1000);  
}
