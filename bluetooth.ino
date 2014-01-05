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
   
    if(Serial.available()){//check if there's any data sent from the local serial terminal, you can add the other applications here
      recvChar = Serial.read();
      Serial1.print(recvChar);
    }
  }
}

void setupBlueToothConnection()
{ 
  Serial1.begin(38400); //Set BluetoothBee BaudRate to default baud rate 38400
  Serial.read(Serial1.print("AT+PSWD=0000\r\n")); //set the bluetooth work in slave mode
  while(Serial1.available() > 0){
    Serial.print(Serial1.read());
  }
  Serial1.print("AT+NAME=slave\r\n"); //set the bluetooth name as "SeeedBTSlave"
  Serial.print("AT+PAIR=74E5,43,9C5874, 100\r\n");
  delay(2000); // This delay is required.
  Serial.println("The slave bluetooth is inquirable!");
  delay(2000); // This delay is required.
  Serial1.flush();
}
