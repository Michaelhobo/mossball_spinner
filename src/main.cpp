#include <Arduino.h>
#include <LowPower.h>

namespace {
constexpr uint8_t kMotorPin = 12;
constexpr uint8_t kLedPin = 11;
constexpr int kFourHoursOfEightSeconds = 4 * 3600 / 8;
}  // namespace


void setup() {
  pinMode(kMotorPin, OUTPUT);
  digitalWrite(kMotorPin, LOW);
  pinMode(kLedPin, OUTPUT);
  digitalWrite(kLedPin, LOW);
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
  for (int i = 0; i < kFourHoursOfEightSeconds; i++) {
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
  }
}
