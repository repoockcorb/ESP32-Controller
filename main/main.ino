// main.ino
// #include "GamepadController.h"
// #include "AudioPlayer.h"
// void setup() {
//     setupGamepadController();
//     setupAudio();
// }

// void loop() {
//     loopGamepadController();
//     loopAudio();

// }


// main.ino
#include "GamepadController.h"
#include "AudioPlayer.h"

void setup() {
  setupGamepadController();
  setupAudio();
}

void loop() {
  loopGamepadController();

  // Check if the gamepad is connected and valid
  if (myGamepad) {
    // Check specific buttons
    if (myGamepad->a()) {
      Serial.println("A button is pressed");
      loopAudio();  // Call loopAudio only if A button is pressed
    } else {
      // Serial.println("A button is not pressed");
    }

    //     // You can also check other buttons like this
    //     if (myGamepad->b()) {
    //         Serial.println("B button is pressed");
    //     }
    //     if (myGamepad->x()) {
    //         Serial.println("X button is pressed");
    //     }
    //     if (myGamepad->y()) {
    //         Serial.println("Y button is pressed");
    //     }
    //     // Add other button checks as needed
    // } else {
    //     Serial.println("Gamepad is not connected");
  }
}
