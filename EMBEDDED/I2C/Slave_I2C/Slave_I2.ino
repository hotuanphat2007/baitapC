/*
* File: Slave_I2C.ino
* Author: HO TUAN PHAT
* Date: 16/04/2023
* Description: Chương trình nhận data từ master
*/


#define I2C_SDA_Slave 4
#define I2C_SCK_Slave 3
#define adressOfTheSlave 0x66

int count_Number_Receive = 0;
uint8_t data_Receive = 0x00;

/*
* Function: setup
* Description: Hàm set up các giá trị và hàm ban đầu, chỉ thực hiện một lần
* Input:
*   void
* Output:
*   return: None
*/
void setup() {
  Serial.begin(115200);
  pinMode(I2C_SCK_Slave, INPUT);
  pinMode(I2C_SDA_Slave, INPUT);
  attachInterrupt(1, I2C_Receive_Data, RISING);
  //attachInterrupt(1, I2C_Receive_Data, RISING);
  delay(1000);

  ////////////////////////////////////////////////////////////////////
}

/*
* Function: I2C_Ack
* Description: Hàm trả về bit ack kích low
* Input:
*   void
* Output:
*   return: None
*/
void I2C_Ack(){
digitalWrite(I2C_SDA_Slave, LOW);
}

/*
* Function: I2C_NAck
* Description: Hàm trả về bit ack kích high
* Input:
*   void
* Output:
*   return: None
*/
void I2C_NAck(){
  digitalWrite(I2C_SDA_Slave, HIGH);
}

/*
* Function: I2C_Receive_Data
* Description: Hàm nhận data từ master
* Input:
*   void
* Output:
*   return: None
*/
void I2C_Receive_Data(){
    pinMode(I2C_SDA_Slave, INPUT);
    data_Receive = data_Receive << 1;
    data_Receive = data_Receive | digitalRead(I2C_SDA_Slave);
    count_Number_Receive ++;
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
  if(count_Number_Receive == 8)
    {
      Serial.print("data nhan duoc la: ");
      Serial.println(data_Receive,HEX);
      count_Number_Receive = 0;
      if(data_Receive == adressOfTheSlave)
      {
        pinMode(I2C_SDA_Slave, OUTPUT);
        delay(2);
        I2C_Ack();
        pinMode(I2C_SDA_Slave, INPUT);
        delay(2);
      }
      else
      {
        pinMode(I2C_SDA_Slave, OUTPUT);
        delay(2);
        I2C_NAck();
        pinMode(I2C_SDA_Slave, INPUT);
        delay(2);
      }
    data_Receive = 0x00;
    }     
}






