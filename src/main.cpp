#include <Arduino.h>
#include <LowPower.h>

namespace {
constexpr uint8_t kMotorPin = 12;
constexpr uint8_t kLedPin = 11;
constexpr int kFourHoursOfThirtyTwoSeconds = 4 * 3600 / 32;
}  // namespace


void setup() {
  pinMode(kLedPin, OUTPUT);
  digitalWrite(kLedPin, HIGH);
  pinMode(kMotorPin, OUTPUT);
  digitalWrite(kMotorPin, LOW);
}

void loop() {
  // Turn on the motor for 16 seconds.
  digitalWrite(kLedPin, HIGH);
  digitalWrite(kMotorPin, HIGH);
  LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
  LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
  digitalWrite(kMotorPin, LOW);
  digitalWrite(kLedPin, LOW);

  // Sleep for 4 hours.
  for (int i = 0; i < kFourHoursOfThirtyTwoSeconds; i++) {
    // 32 seconds of sleep
    for (int j = 0; j < 4; j++) {
      LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
    }
    
    // Toggle the LED on briefly to indicate power on.
    digitalWrite(kLedPin, HIGH);
    LowPower.powerDown(SLEEP_120MS, ADC_OFF, BOD_OFF);
    digitalWrite(kLedPin, LOW);
  }
}
