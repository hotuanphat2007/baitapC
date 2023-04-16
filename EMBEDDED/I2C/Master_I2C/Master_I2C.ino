/*
* File: Master_I2C.ino
* Author: HO TUAN PHAT
* Date: 16/04/2023
* Description: Chương trình truyền data từ master cho slave và nhận bit từ slave
*/



#define I2C_SDA 4
#define I2C_SCK 3
#define adressOfTheSlave 0x66
#define transmitData 0x55

bool status_Master = 0;  // status = 1 thì được truyền data

/*
* Function: setup
* Description: Hàm chỉ chạy 1 lần duy nhất khi Arduino hoạt động
* Input: 
*/
void setup() {
  Serial.begin(115200);
  pinMode(I2C_SDA,OUTPUT);
  pinMode(I2C_SCK,OUTPUT);
  I2C_Init();
  I2C_Start();
  delay(5000); //delay 1s roi thuc hien truyen data
  I2C_Send_Byte_Adress(adressOfTheSlave);
    delay(3000);
    I2C_Wait_Ack();
    delay(1000);
}

/*
* Function: I2C_Init
* Description: Hàm khởi tạo 2 chân SDA và SCK để giao tiếp I2C
* Input:
*   void
* Output:
*   return: None
*/
void I2C_Init(){
  digitalWrite(I2C_SDA, HIGH);  // SDA = 1;
  digitalWrite(I2C_SCK, HIGH);  // SCK = 1;
}

/*
* Function: I2C_Start
* Description: Hàm bắt đầu quá trình giao tiếp
* Input:
*   void
* Output:
*   return: None
*/
void I2C_Start(){
  digitalWrite(I2C_SDA, HIGH);
  digitalWrite(I2C_SCK, HIGH);
  delayMicroseconds(4);
  digitalWrite(I2C_SDA, LOW);
  delayMicroseconds(4);
  digitalWrite(I2C_SCK, LOW);
}

/*
* Function: I2C_Stop
* Description: Hàm dừng giao tiếp
* Input:
*   void
* Output:
*   return: None
*/
void I2C_Stop(){
  digitalWrite(I2C_SDA, LOW);
  digitalWrite(I2C_SCK, LOW);
  delayMicroseconds(4);
  digitalWrite(I2C_SCK, HIGH);
  delayMicroseconds(4);
  digitalWrite(I2C_SDA, HIGH);
}
/*
* Function: I2C_Send_Byte_Adress
* Description: Hàm gửi địa chỉ mà master muốn giao tiếp đến slave
* Input:  uint8_t txd
*   void
* Output:
*   return: None
*/
void I2C_Send_Byte_Adress(uint8_t txd){
  pinMode(I2C_SDA, OUTPUT);
  delay(2);
  int i = 0;
  uint8_t x = 0x00;
  digitalWrite(I2C_SCK, LOW);
  for(i = 0; i < 8; i++){
    x = txd & 0x80;
    if(x > 0) {     digitalWrite(I2C_SDA, HIGH); }
    else {          digitalWrite(I2C_SDA, LOW); }
    txd <<= 1;
    delayMicroseconds(2);
    digitalWrite(I2C_SCK, HIGH);
    delayMicroseconds(2);
    digitalWrite(I2C_SCK, LOW);
  }
}
/*
* Function: I2C_Send_Byte
* Description: Hàm gửi dữ liệu đến slave
* Input:
*   void
* Output:
*   return: None
*/
void I2C_Send_Byte(uint8_t txd){
  pinMode(I2C_SDA, OUTPUT);
  delay(2);
  int i = 0;
  uint8_t x = 0x00;
  digitalWrite(I2C_SCK, LOW);
  for(i = 0; i < 8; i++){
    x = txd & 0x80;
    if(x > 0) {     digitalWrite(I2C_SDA, HIGH); }
    else {          digitalWrite(I2C_SDA, LOW); }
    txd <<= 1;
    delayMicroseconds(2);
    digitalWrite(I2C_SCK, HIGH);
    delayMicroseconds(2);
    digitalWrite(I2C_SCK, LOW);
  }
}
/*
* Function: I2C_Wait_Ack
* Description: Hàm đọc bit ack gửi từ slave đến
* Input:
*   void
* Output:
*   return: None
*/
uint8_t I2C_Wait_Ack(){
  pinMode(I2C_SDA, INPUT);
  delay(2);
  uint8_t time = 0;
  digitalWrite(I2C_SCK, HIGH);
  delayMicroseconds(1);
  while(digitalRead(I2C_SDA) == 1)
  {
    time++;
    if(time > 250)
    {
      Serial.print("SAI DIA CHI KHONG TRUYEN DUOC\n");
      I2C_Stop();
      return 1;
    }
  }
    Serial.print("TIEN HANH TRUYEN DU LIEU\n");
    digitalWrite(I2C_SCK, LOW);
    status_Master = 1;

    return 0;
}
/*
* Function: loop
* Description: Hàm thực hiện lặp đi lặp lại trong suốt quá trình chạy chương trình
* Input:
*   void
* Output:
*   return: None
*/
void loop() {
  if(status_Master == 1)
  {
    I2C_Send_Byte(transmitData);
    delay(1000);
  }
} 
