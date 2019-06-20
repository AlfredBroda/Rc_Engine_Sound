
// Choose the motor sound (uncomment the one you want)
#include "diesel.h" // Diesel Truck <------- The preferred one for old, big Diesel trucks

//#include "v8.h" // Generic V8
//#include "chevyNovaV8.h" // Chevy Nova Coupe 1975 <------- The best sounding!
//#include "Mustang68.h" // Ford Mustang 1968
//#include "MgBGtV8.h" // MG B GT V8
//#include "LaFerrari.h" // Ferrari "LaFerrari"

// PWM Throttle range calibration -----------------------------------------------------------------------------------
int16_t pulseZero = 1500; // Usually 1500 (range 1000 - 2000us) WPL B36 = 1520
int16_t pulseNeutral = 10; // pulseZero +/- this value
int16_t pulseSpan = 300; // pulseZero +/- this value (500) WPL B36 = 300
int16_t pulseLimit = 700; // pulseZero +/- this value (700)

// Mode settings - These could easily be 4 jumpers connected to spare pins, checked at startup to determine mode ----
boolean managedThrottle = true;     // Managed mode looks after the digipot if fitted for volume, and adds some mass to the engine
boolean potThrottle = false;        // A pot connected to A1, 0-1023 sets speed
boolean pwmThrottle = true;         // Takes a standard servo signal on pin 2 (UNO)
boolean spiThrottle = false;        // SPI mode, is an SPI slave, expects 1-255 for throttle position, with 0 being engine off

// Volume, max. speed -----------------------------------------------------------------------------------------------
#define DEFAULT_VOLUME 127      // Volume when in non managed mode
#define VOL_MIN 20              // Min volume in managed mode 0 - 127
#define VOL_MAX 127             // Max volume in managed mode 0 - 127
#define TOP_SPEED_MULTIPLIER 30 // RPM multiplier in managed mode, bigger the number the larger the rev range, 10 - 15 is a good place to start

