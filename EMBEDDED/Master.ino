/*
* File: Master.ino
* Author: HO TUAN PHAT
* Date: 12/04/2023
* Description: Chương trình truyền data từ master cho slave và nhận data từ slave
*/


#define SCK_MASTER 3
#define MISO_MASTER 4
#define MOSI_MASTER 5
#define SS 6


/*
* Function: setup
* Description: Hàm chỉ chạy 1 lần duy nhất khi Arduino hoạt động
*/
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);  
  pinMode(SCK_MASTER, OUTPUT);  
  pinMode(MISO_MASTER, INPUT);
  pinMode(MOSI_MASTER, OUTPUT);
  pinMode(SS, OUTPUT);
  
  digitalWrite(SCK_MASTER,LOW);  // SCK   = 0;
  digitalWrite(MOSI_MASTER,LOW);  // MOSI   = 0;
  digitalWrite(SS,HIGH);  // SS   = 1;
}




/*
* Function: loop
* Description: Hàm cấp xung SCK để nhận biết quá trình truyền dữ liệu
* Input:
*   void
* Output:
*   return: None
*/
void Clock(){
  digitalWrite(SCK_MASTER,HIGH); // SCK = 1; 
  // delayMicroseconds(5);
  asm volatile("nop"::);
  digitalWrite(SCK_MASTER,LOW); // SCK = 0; 
  //delayMicroseconds(5);
  asm volatile("nop"::);
}



/*
* Function: SPI_Soft_Transmit
* Description: Hàm truyền data cho slave
* Input: uint8_t mData
* Output:
*   return: None
*/
void SPI_Soft_Transmit(uint8_t mData){
  uint8_t x = 0x00;
  digitalWrite(SS,LOW); // SS = 0
  for(int i = 0; i < 8; i++){ 
    x = mData&0x80; // đưa bit cần truyền lên chân MOSI 
    if(x>0)
      digitalWrite(MOSI_MASTER, HIGH); // MOSI=1;
    else
      digitalWrite(MOSI_MASTER, LOW); // MOSI=0;   
      mData=mData<<1; // dịch dữ liệu cần gửi lên 1 bits   
     Clock(); // phát 1 xung clock gửi dữ liệu đi
     delay(2);
  }
  digitalWrite(SS,HIGH); //Đã gửi xong,đưa chân SS lên mức 1
}

/*
* Function: SPI_Soft_Recieve
* Description: Hàm nhận data từ slave
* Input: none
* Output:
*   return: _data_Receive
*/
uint8_t SPI_Soft_Recieve(){
  uint8_t i = 0;
  uint8_t _data_Receive = 0x00;
  digitalWrite(SS,LOW); 
  for(i = 0; i < 8; i++)
  {
    Clock();
    _data_Receive = _data_Receive << 1;
    _data_Receive = _data_Receive | digitalRead(MISO_MASTER);
  }
  digitalWrite(SS,HIGH);
  return _data_Receive;
}

/*
* Function: loop
* Description: Hàm loop lặp lại liên tục trong khi chạy chương trình
* Input: none
* Output:
*   return: _data_Receive
*/
void loop() {
  uint8_t data = 0x34;
  SPI_Soft_Transmit(data);
  Serial.print("data truyen tu master la: ");
  Serial.print(data,HEX);
  Serial.print("\n");
  delay(1000);
  uint8_t data_receive;
  data_receive = SPI_Soft_Recieve();
  Serial.print("data nhan tu slave la: ");  
  Serial.print(data_receive,HEX);
  Serial.print("\n");
  delay(1000);
  }
