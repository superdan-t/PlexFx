#include "../PlexFx.h"

PlexFx::LinkedController ec;
unsigned char leds[50][3];
bool resetLights = true;

bool constFade(PlexFx::Effect& effect) {
  bool foundNonZero = false;
  for (auto it = effect.targets->begin(); it != effect.targets->end(); ++it) {
    //byte incr = effect.data ? *(byte*)(effect.data) : 5;
    unsigned char incr = 5;
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
  }
  if (!foundNonZero) {
    resetLights = true;
  }
  return foundNonZero;
}

void makeConstFade(PlexFx::Effect& effect, PlexFx::TargetSet& targets, unsigned char stepSize) {
  effect.targets = targets;
  effect.callback = constFade;
  //effect.data = (byte*) malloc(sizeof(byte));
  //*(byte*)(effect.data) = stepSize;
}

void doResetLights() {
  resetLights = false;
  for (int i = 0; i < 50; ++i) {
    leds[i][0] = 255;
	leds[i][1] = 255;
	leds[i][2] = 255;
  }

  PlexFx::Effect& e = ec.addEffect();
  PlexFx::TargetSet targets(new PlexFx::Range(0, 25));
  makeConstFade(e, targets, 2);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (resetLights) doResetLights();
  ec.run();
}

int main() {
	for (;;) loop();
}
