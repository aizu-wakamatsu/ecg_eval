#define SIZE 7
int raw_array[SIZE];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int c = 0;
  for (c = 0; c < SIZE; c++) {
    raw_array[c] = analogRead(A0);
    delay(10);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int c, raw_ave = 0, raw_sum = 0, raw_value = 0;
  raw_value = analogRead(A0);
  for (c = 0 ; c < SIZE - 1 ; c++) {
    raw_array[c] = raw_array[c + 1];
  }
  raw_array[SIZE - 1] = raw_value;
  for (c = 0 ; c < SIZE ; c++) {
    raw_sum += raw_array[c];
  }
  raw_ave = raw_sum / SIZE;
  Serial.print(raw_value);
  Serial.print(',');
  Serial.println(raw_ave);
  delay(10);
}
