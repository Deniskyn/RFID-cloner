
#include "MenuOrganizer.h"
MenuOrganizer menuOrganizer;

#include "GUI.h"
GUI gui; 
/*
  [OLED -> NodeMCU]
    SDA -> D1 
    SCL -> D2
 */

#include "Rfid.h"
Rfid rfid;
/*
  [RC522 -> NodeMCU]
     RST -> D3
     SDA -> D8
    MOSI -> D7
    MISO -> D6
    SCK  -> D5
 */

#include "Buttons.h"
Buttons buttons;

/*
Button connections:
NodeMCU 3.3.V pin connection goes TWICE to the following 2 legs of buttons:
// Resistors are connected in series (to each other) and to 1 leg of each button.
// Starting at 3.3V and going through: 4.7k -> 2.2K -> 1K -> 680 -> 470 -> 220 -> A0 -> 1k -> GND.
// Other leg of each button is connected directly to 3.3V in parallel. This way different
// voltage is provided                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
NodeMCU A0 pin connection
1k - ground
*/

#include "NamePicker.h"
NamePicker namePicker;

#include "Notification.h"
Notification notification;

#include "Files.h"
Files files;

void setup() {
  Serial.begin(115200);
  //delay(10000);
  Serial.println("Starting");
  
  files.Init();
  //files.Format();
  //files.DumpDirToSerial("/");
  //files.DumpDirToSerial("/rfid");
  //files.RemoveDir("/rfid");
  files.SetTemporaryLastReadFileName("%Last_read%");
  
  gui.Init();
  rfid.Init();
  notification.Init();
}

void loop() {
  buttons.Update();
  gui.Update();
  rfid.Update();
  
  /*
  gui.HandleControls();
  
  if(gui.WasSelected()){
    int choice = gui.GetSelection();
    gui.ResetSelection();
    if(choice != CANCELLED){
      mainMenu[choice].function();
    }
  }
  gui.Draw();
  */
}





















