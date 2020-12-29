/*
 * PlexFx Arduino Example with FastLED
 * Requires FastLED
 * 
 * Copyright (c) 2020 Daniel Tierney <dtierne2@binghamton.edu>
 * This document should have been distributed with a license.
 * 
 * For addressable LEDs. Sets all LEDs to purple, and then slowly fades
 * half of them to dark. Repeats the effect.
 */

#include <PlexFx.h>
#include <FastLED.h>

#define NUM_LEDS 50
CRGB leds[NUM_LEDS];

PlexFx::LinkedController ec;
bool resetLights = true;

/*
 * This function is called on our Effect whenever LinkedController::run is called (every 50ms here)
 * For each LED targeted by the effect, it subtracts some from the brightness until it is off
 * When each LED is off, the effect will end (returns false)
 */
bool constFade(PlexFx::Effect& effect) {
  bool foundNonZero = false;  // End the effect if they are all off

  // We use an iterator to apply our effect to every LED targeted.
  // You can also use a traditional for loop as so:
  // for (PlexFx::Index i = 0; i < effect.targets->size(); ++i) { ... }
  // This is useful if the index will be involved in the function (like making a rainbow)
  for (auto it = effect.targets->begin(); it != effect.targets->end(); ++it) {

    // The step size is stored in our effect data
    // Data is whatever we allocate it as (void*). In this example, it was created as a byte, so we access it as such
    // If there's no data, use a step size of 5.
    byte incr = effect.data ? *(byte*)(effect.data) : 5;

    // Apply it to each channel until it reaches zero
    if (leds[*it][0] > incr) {
      leds[*it][0] -= incr;
      foundNonZero = true;
    } else {
      leds[*it][0] = 0;
    }
    if (leds[*it][1] > incr) {
      leds[*it][1] -= incr;
      foundNonZero = true;
    } else {
      leds[*it][1] = 0;
    }
    if (leds[*it][2] > incr) {
      leds[*it][2] -= incr;
      foundNonZero = true;
    } else {
      leds[*it][2] = 0;
    }
    // If they are all zero, foundNonZero will still be false

  }
  if (!foundNonZero) resetLights = true; // We want this effect to repeat, so this indicates to redo the setup
  return foundNonZero; // return false means end effect, return true means keep going
}

// This sets up a new effect as a constant fade
void makeConstFade(PlexFx::Effect& effect, PlexFx::TargetSet& targets, byte stepSize) {
  effect.targets = targets; // These are the LEDs we want to target
  effect.callback = constFade; // The "callback" is what's called each tick

  // Dynamically allocate data for our step size
  effect.data = (byte*) malloc(sizeof(byte));
  *(byte*)(effect.data) = stepSize;
}

// Resets the lights to an initial value
void doResetLights() {
  delay(5000); // Short delay to see the effect
  resetLights = false;

  // Set all to purple to start
  for (byte i = 0; i < NUM_LEDS; ++i)
    leds[i] = CRGB::Purple;
  FastLED.show();

  // Returns a reference to a new, blank effect
  PlexFx::Effect& e = ec.addEffect();

  // TargetSet is an abstract container for targeted LEDs
  // Range is a type of set. Here, we are targeting LEDs 0 to 25
  PlexFx::TargetSet targets(new PlexFx::Range(0, NUM_LEDS / 2));

  // Call the setup function we designed earlier
  makeConstFade(e, targets, 2);

}

void setup() {
  LEDS.addLeds<WS2812, 7, RGB>(leds, NUM_LEDS);
  LEDS.setBrightness(84);
}

void loop() {
  static unsigned long lastTick = 0;

  // Tick rate is 20 tps (every 50 ms)
  if (millis() - lastTick >= 50) {
    lastTick = millis();

    if (resetLights) doResetLights();

    // ec is our effect controller: this will run the callback for the effect
    ec.run();
    FastLED.show();
  }

}