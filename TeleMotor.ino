#define RXB 0
#define TXB 1

//SoftwareSerial blueToothSerial(RXB,TXB);

//MAC ADRESS 74E5439C5874 
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  setupBlueToothConnection(); 
}

void loop() {
  char recvChar;
  while(1){
   
    if(Serial1.available()){//check if there's any data sent from the local serial terminal, you can add the other applications here
      recvChar = Serial1.read();
      Serial.print(recvChar);
    } 
  }
}

void setupBlueToothConnection()
{ 
  Serial1.begin(38400); //Set BluetoothBee BaudRate to default baud rate 38400
  Serial1.print("AT+PSWD=0000\r\n"); //set the bluetooth work in slave mode
  Serial1.print("AT+VERSION?=0000\r\n"); //set the bluetooth work in slave mode
  char c[100];
  int i = Serial1.readBytesUntil('\r\n', c, 100);
  Serial.print(i);
  Serial1.print("AT+NAME=slave\r\n"); //set the bluetooth name as "SeeedBTSlave"
  i = Serial1.readBytesUntil('\r\n', c, 100);
  Serial.print(i);
  Serial.print("AT+PAIR=74E5,43,9C5874, 100\r\n");
  delay(2000); // This delay is required.
  Serial.println("The slave bluetooth is inquirable!");
  delay(2000); // This delay is required.
}
