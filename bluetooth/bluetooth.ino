#define RXB 0
#define TXB 1

//SoftwareSerial blueToothSerial(RXB,TXB);

//MAC ADRESS 74E5439C5874 
int save = 0;
int led = 13;
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  setupBlueToothConnection(); 
}

void loop() {
  // if there's any serial available, read it:
  while(Serial.available()){
    char recv = Serial.read();
    Serial1.print(recv);
  }
  
  while (Serial1.available() > 0) {

    save = Serial1.parseInt() * 10;
  }
  
  digitalWrite(led, HIGH);
  delay(save);
  digitalWrite(led, LOW);
  delay(save);
}

void setupBlueToothConnection()
{ 
  Serial1.begin(38400); //Set BluetoothBee BaudRate to default baud rate 38400
  Serial1.print("AT+PSWD=0000\r\n");
  Serial1.print("AT+VERSION?=0000\r\n"); //set the bluetooth work in slave mode
  Serial1.print("AT+NAME=slave\r\n"); //set the bluetooth name as "SeeedBTSlave"
  Serial1.print("AT+ROLE=0\r\n");
  Serial1.print("AT+INIT\r\n");
  //i = Serial1.readBytesUntil('\r\n', c, 100);
  //Serial.print(i);
  //Serial.print("AT+PAIR=74E5,43,9C5874, 100\r\n");
  delay(2000); // This delay is required.
  Serial.println("The slave bluetooth is inquirable!");
  delay(2000); // This delay is required.
}
