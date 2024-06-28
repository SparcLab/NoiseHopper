#include <FastPwmPin.h>
// Download this library from: https://github.com/maxint-rd/FastPwmPin

byte x = 170;  // binary='10101010'

// As an example, seven and two, 2 digits from MNIST dataset is loaded for transmission
unsigned long seven[28] = { 0, 0, 0, 0, 0, 0, 0, 4128768, 4194240, 4194240, 131008, 960, 1920, 1920, 3840, 3584, 3584, 7168, 15360, 30720, 30720, 61440, 122880, 122880, 253952, 253952, 245760, 0 };
unsigned long two[28] = {0,0,0,260096,523264,1047552,2071552,1981440,801792,30720,63488,61440,126976,253952,245760,507904,1015808,1015808,983040,1044988,1048574,1048574,524160,0,0,0,0,0};

// Frequencies at which emanation can be generated and used as carriers. Remember that these are PWM frequencies,
// emanation frequency harmonics will be slightly different.
long freq[8] = {1000000L,1200000L, 1400000L, 2000000L, 2200000L, 2660000L, 3200000L, 4000000L};
bool FLAG = true;

int r = 6; // We are transmitting at 7th freq, i.e., 3.2 MHz as an example

// Start of the frame is marked by 8 consecutive 1s. Due to RZ coding scheme, the output will
// look like 1010101010101010
void preamble_frame() {
  for (int p = 0; p < 8; p++) {
    FastPwmPin::enablePwmPin(10, freq[r], 30);
    delayMicroseconds(1);
    FastPwmPin::enablePwmPin(10, freq[r], 1);
    delayMicroseconds(99);
  }
  delayMicroseconds(200);
}

// Start of the data transfer is marked by 20 consecutive 1s.
void preamble_data_xfer() {
  for (int q = 0; q < 20; q++) {
    FastPwmPin::enablePwmPin(10, freq[r], 30);
    delayMicroseconds(1);
    FastPwmPin::enablePwmPin(10, freq[r], 1);
    delayMicroseconds(99);
  }
  delayMicroseconds(200);
}


void setup() {
  pinMode(10, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW); // Just a check that Arduino is fine. Can be omitted.
  delay(5000); // Wait 5 second before starting data transmission. Can be omitted.
}

void loop() {
  preamble_data_xfer();
  for (int k = 0; k < 28; k++) {
    //start transferring each frame containing 28 pixel data
    preamble_frame();
    for (int i = 4; i >= 1; i--) {
      for (int j = i * 7; j > (i - 1) * 7; j--) {
        if (bitRead(seven[k], (j - 1)) == 1) {
          FastPwmPin::enablePwmPin(10, freq[r], 30);
          delayMicroseconds(1);
          FastPwmPin::enablePwmPin(10, freq[r], 1);
          delayMicroseconds(99);
        } else {
          FastPwmPin::enablePwmPin(10, freq[r], 1);
          delayMicroseconds(100);
        }
      }
    }
    FastPwmPin::enablePwmPin(10, freq[r], 1);
    delayMicroseconds(200);
  }
  FastPwmPin::enablePwmPin(10, freq[r], 1);
  delayMicroseconds(200);
}