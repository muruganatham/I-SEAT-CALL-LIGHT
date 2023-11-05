#define TRIG_PIN1 2 // Trigger pin for Ultrasonic Sensor 1
#define ECHO_PIN1 3 // Echo pin for Ultrasonic Sensor 1
#define TRIG_PIN2 4 // Trigger pin for Ultrasonic Sensor 2
#define ECHO_PIN2 5 // Echo pin for Ultrasonic Sensor 2
#define LED_PIN1 10  
#define LED_PIN2 9  
#define LED_PIN3 8 
#define LED_PIN4 7  // LED pin
#define TOUCH_SENSOR_PIN 6 // Touch sensor pin


void setup() {
  pinMode(TRIG_PIN1, OUTPUT);
  pinMode(ECHO_PIN1, INPUT);
  pinMode(TRIG_PIN2, OUTPUT);
  pinMode(ECHO_PIN2, INPUT);
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);
  pinMode(LED_PIN4, OUTPUT);
  pinMode(TOUCH_SENSOR_PIN, INPUT);
// Assuming the touch sensor is normally HIGH when not touched
  Serial.begin(9600);
}

void loop() {
  long duration1, distance1, duration2, distance2;
  
  // Trigger Ultrasonic Sensor 1
  digitalWrite(TRIG_PIN1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN1, LOW);
  duration1 = pulseIn(ECHO_PIN1, HIGH);
  distance1 = (duration1 / 2) / 29.1; // Calculate distance in centimeters
  
  // Trigger Ultrasonic Sensor 2
  digitalWrite(TRIG_PIN2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN2, LOW);
  duration2 = pulseIn(ECHO_PIN2, HIGH);
  distance2 = (duration2 / 2) / 29.1; // Calculate distance in centimeters
  
  Serial.print("Distance 1: ");
  Serial.print(distance1);
  Serial.print(" cm, Distance 2: ");
  Serial.print(distance2);
  Serial.println(" cm");
  
  // Check if either sensor detects an object
  if (distance1 < 10 || distance2 < 10) { // Adjust the threshold (10 cm) as needed
    digitalWrite(LED_PIN1, HIGH); // Turn on the LED
  } else {
    digitalWrite(LED_PIN1, LOW); // Turn off the LED
  }
  delay(5000);
  // Delay for readability and to avoid rapid LED switching
  if (distance1 < 10 || distance2 < 10) { // Adjust the threshold (10 cm) as needed
    digitalWrite(LED_PIN2, HIGH); // Turn on the LED
  } else {
    digitalWrite(LED_PIN2, LOW); // Turn off the LED
  }
  delay(1000);
  // Delay for readability and to avoid rapid LED switching
  if (distance1 < 10 || distance2 < 10) { // Adjust the threshold (10 cm) as needed
    digitalWrite(LED_PIN3, HIGH); // Turn on the LED
  } else {
    digitalWrite(LED_PIN3, LOW); // Turn off the LED
  }
  delay(1500);
   // Delay for readability and to avoid rapid LED switching
  if (distance1 < 10 || distance2 < 10) { // Adjust the threshold (10 cm) as needed
    digitalWrite(LED_PIN4, HIGH); // Turn on the LED
  } else {
    digitalWrite(LED_PIN4, LOW); // Turn off the LED
  }
  
  delay(2000); // Delay for readability and to avoid rapid LED switching

 
  int touchValue = digitalRead(TOUCH_SENSOR_PIN);

  if (touchValue == HIGH) {
    digitalWrite(LED_PIN1, HIGH);
    digitalWrite(LED_PIN2, HIGH);
    digitalWrite(LED_PIN3, HIGH);
    digitalWrite(LED_PIN4, HIGH);
    delay(1000); // Adjust the delay as needed
  } else {
    digitalWrite(LED_PIN1, LOW);
    digitalWrite(LED_PIN2, LOW);
    digitalWrite(LED_PIN3, LOW);
    digitalWrite(LED_PIN4, LOW);
  }

  // Rest of your ultrasonic sensor code...
}
