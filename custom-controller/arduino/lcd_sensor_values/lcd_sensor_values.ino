#include <Wire.h>
#include <LiquidCrystal_I2C.h>


const int buttonPin=2;
int buttonState = 0;
int count = 0;
int pressed;
int old_reading = 0;
int new_reading = 0;
int old_button = 0;
int new_button = 0;  
LiquidCrystal_I2C lcd(0x27,20,4);
int potPin1 = A1;         

/*
 * Prints a message on a screen
 * 
 * msg:  string to print
 * line: the line number (0 or 1)
 */
void print_msg (const char *msg, int line)
{
  for (int i = 16; i >= -16 ; --i)
  {
    lcd.setCursor(i,line);
    lcd.print(msg);
    delay(250);
    lcd.clear();
  }
}

/*
 * Setup function. Called at initial boot of the
 * program.
 */
void setup ()
{
  pinMode(buttonPin,INPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.clear();
  lcd.backlight();

  print_msg("Robotics Program", 0);
  print_msg("By:Mohammad Saad", 1);
  delay(1500);


  lcd.clear();
  pinMode(potPin1, INPUT);

  lcd.setCursor(0,0);
  lcd.print("POTValue: 0%"); // Prints Sensor Val: to LCD
  lcd.setCursor(0,1);
  lcd.print("ButtonValue: 0");
}

/*
 * Main program loop. Called to run
 * the program.
 */
void loop()
{
  char buffer[80] = {0};
  bool print_both = false;
  
  // Print the potentiometer value
  new_reading = analogRead(potPin1)/100;
  if (old_reading != new_reading) {
    old_reading = new_reading;
    print_both = true;
    lcd.clear();
    sprintf(buffer, "POTValue: %d%%", new_reading*10);
    lcd.setCursor(0,0);
    lcd.print(buffer);
  }

  // Print button state
  new_button = digitalRead(buttonPin);
  if (new_button == HIGH) {
    new_button = (1);
  } else {
    new_button = (0);
  }
  
  if (print_both || (new_button != old_button))
  {
    old_button = new_button;
    lcd.setCursor(0,1);
    lcd.print("ButtonValue: ");
    lcd.print(new_button);
    delay(250);
  }
}
