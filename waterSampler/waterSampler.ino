/* CHANGE THESE PARAMETERS AS NEEDED*/

int controlPins[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int solenoidOpenTimeMillis = 2000;
float timeBetweenSamplesHours = (float) 1 / (60 * 60);

/* DO NOT ALTER BELOW THIS POINT*/

// Convert hours to millseconds
unsigned long timeBetweenSamplesMillis = 
  (unsigned long) timeBetweenSamplesHours * 60 * 60 * 1000;
// Sentinel to ensure solenoids open only once
bool hasFinishedSampling = false;

void setup() {
  //  Disables ADC, we aren't using it and it draws pretty high current
  ADCSRA = 0;

  for (int i = 0;
       i < sizeof(controlPins) / sizeof(controlPins[0]);
       i++) {
    pinMode(controlPins[i], OUTPUT);
  }
}

void loop() {
  if (!hasFinishedSampling) {
    for (int i = 0; i < 10; i++) {
      digitalWrite(i, HIGH);
      delay(solenoidOpenTimeMillis);
      digitalWrite(i, LOW);
      delay(timeBetweenSamplesMillis);
   }
    hasFinishedSampling = true;
  }
}
