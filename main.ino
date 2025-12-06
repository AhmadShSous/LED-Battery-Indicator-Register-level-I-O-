#define LED1 PB3   // LED1 on Pin 11
#define LED2 PD6   // LED2 on Pin 6
#define BUTTON PD2 // Button on Pin 2

volatile bool batteryLowMode = false; //first the buttery is OK

void setup() {
  DDRB |= (1 << LED1);//led1 output
  DDRD |= (1 << LED2);//led2 output
  DDRD &= ~(1 << BUTTON); //button input
  PORTD |= (1 << BUTTON); // enable pull-up ddr=0, port=1
}

void loop() {
  // ==============================
  //Read button (toggle mode)
  // ==============================
  //when press the button PIND= 0X0100 0(0)00 (PULL UP) & 0000 0(1)00 = 0 SO NOT IT
  if (!(PIND & (1 << BUTTON))) {   // if the button pressed = LOW
    delay(50);                         // simple debounce
  	batteryLowMode = !batteryLowMode; // toggle buttery low 

   while (!(PIND & (1 << BUTTON))); // wait until button released
      delay(50);
  }

  // ==============================
  // Battery OK Mode
  // ==============================
  if (!batteryLowMode) {
    // LED1 ON so PB3 HIGH
    PORTB |= (1 << LED1);

    // LED2 OFF so PD6 LOW
    PORTD &= ~(1 << LED2);

  }

  // ==============================
  // Battery LOW Mode (blink LED2)
  // ==============================
  else {
    // LED1 OFF
    PORTB &= ~(1 << LED1);

    // LED2 Blink at 2 Hz → toggle every 250ms
    static unsigned long prev = 0;
    if (millis() - prev >= 250) {
      prev = millis();
      PORTD ^= (1 << LED2);   // Toggle LED2 using XOR
    }
  }
}

