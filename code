//C++
#define RS 12
#define EN 11
#define D4 5
#define D5 4
#define D6 3
#define D7 2

// Send a short pulse to the Enable pin to tell LCD to read data
void pulseEnable() {
  digitalWrite(EN, LOW);
  delayMicroseconds(1);
  digitalWrite(EN, HIGH);
  delayMicroseconds(1);
  digitalWrite(EN, LOW);
  delayMicroseconds(50);
}

// Send 4 bits to the LCD (one nibble)
void sendNibble(uint8_t nibble) {
  digitalWrite(D4, (nibble >> 0) & 1);
  digitalWrite(D5, (nibble >> 1) & 1);
  digitalWrite(D6, (nibble >> 2) & 1);
  digitalWrite(D7, (nibble >> 3) & 1);
  pulseEnable();
}

// Send a full byte (8 bits) by splitting it into two nibbles
void sendByte(uint8_t b, uint8_t rs) {
  digitalWrite(RS, rs);  // rs=0 → command, rs=1 → data
  sendNibble(b >> 4);    // send high 4 bits
  sendNibble(b & 0x0F);  // send low 4 bits
}

// Send a command to the LCD
void lcd_command(uint8_t cmd) {
  sendByte(cmd, 0);
  delay(2);
}

// Send a single character to the LCD
void lcd_data(uint8_t data) {
  sendByte(data, 1);
}

// Print a full string on the LCD
void lcd_print(const char *s) {
  while (*s) lcd_data(*s++);
}

// Initialize LCD in 4-bit mode
void lcd_init() {
  delay(50);  // wait for LCD to power up

  digitalWrite(RS, LOW);
  digitalWrite(EN, LOW);

  // Initialization sequence for 4-bit mode
  sendNibble(0x03);
  delay(5);
  sendNibble(0x03);
  delayMicroseconds(150);
  sendNibble(0x03);
  sendNibble(0x02);  // switch to 4-bit mode

  lcd_command(0x28); // 4-bit, 2-line mode
  lcd_command(0x0C); // display ON, cursor OFF
  lcd_command(0x01); // clear display
  delay(2);
  lcd_command(0x06); // auto-increment cursor
}

// Scroll display left by one step
void lcd_scroll_left() {
  lcd_command(0x18);
}

void setup() {
  // Set LCD pins as outputs
  pinMode(RS, OUTPUT);
  pinMode(EN, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);

  lcd_init();  // start LCD

  lcd_print("Hello Ahmad12!");  // print initial text
}

void loop() {

  // Number of scroll steps before text resets
  int total_shifts = 16;

  // Do the scrolling animation
  for (int i = 0; i < total_shifts; i++) {
    delay(350);
    lcd_scroll_left();
  }

  // Return the text to the starting position
  lcd_command(0x02);  // Return Home command
  delay(500);
}
