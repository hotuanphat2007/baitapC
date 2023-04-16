/*
* File: Slave.ino
* Author: HO TUAN PHAT
* Date: 12/04/2023
* Description: Chương trình nhận data từ master cho slave và truyền data lại cho master
*/


#define SCK_SLAVE 3
#define MISO_SLAVE 4
#define MOSI_SLAVE 5
#define SS1 6

uint8_t _data = 0x00;
uint8_t count_Data = 0;
uint8_t count_Data_Transmit = 0;
bool status = 1;
uint8_t _data_Transmit = 0x55;

/*
* Function: setup
* Description: Hàm chỉ chạy 1 lần duy nhất khi Arduino hoạt động
*/
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(SCK_SLAVE, INPUT);
  pinMode(MISO_SLAVE, OUTPUT);
  pinMode(MOSI_SLAVE, INPUT);
  pinMode(SS1, INPUT);
  attachInterrupt(1, SPI_Soft_Transmit_Receive, RISING); // Ngắt ngoài pin 3 để nhận biết tín hiệu SCK
}


/*
* Function: SPI_Soft_Transmit_Receive
* Description: Hàm thay đổi trạng thái truyền nhận liên tục
* Input:
*   void
* Output:
*   return: None
*/
void SPI_Soft_Transmit_Receive()
{
  if (digitalRead(SS1) == 1) return;
  if(status == 1)
  {
    SPI_receive(); 
  }
  else 
  {
    SPI_Soft_Transmit();
  }
}

/*
* Function: SPI_receive
* Description: Hàm nhận dữ liệu từ master
* Input:
*   void
* Output:
*   return: None
*/
void SPI_receive() {
  _data = _data << 1;
  _data = _data | digitalRead(MOSI_SLAVE);
  count_Data++;
}

/*
* Function: SPI_Soft_Transmit
* Description: Hàm truyền dữ liệu đến master
* Input:
*   void
* Output:
*   return: None
*/
void SPI_Soft_Transmit(){
  uint8_t x = 0x00;
   x = _data_Transmit & 0x80; // đưa bit cần truyền lên chân MOSI
    if(x>0)
      digitalWrite(MISO_SLAVE, HIGH); // MOSI=1;
    else
      digitalWrite(MISO_SLAVE, LOW); // MOSI=0;
    _data_Transmit = _data_Transmit << 1; // dịch dữ liệu cần gửi lên 1 bits
    count_Data_Transmit++;
}

/*
* Function: loop
* Description: Hàm loop thực hiện lặp lại liên tục trong quá trình chạy chương trình
* Input:
*   void
* Output:
*   return: None
*/
void loop() {

  if (digitalRead(SS1) == 1) {
    if (count_Data == 8) {
      Serial.print("data nhan tu master la: ");
      Serial.print(_data, HEX);
      Serial.print("\n");
      _data = 0x00;
      count_Data = 0;
      status = 0;
    }

    if(count_Data_Transmit == 8)
    {
      _data_Transmit = 0x55;   
      Serial.print("data truyen den master la: ");
      Serial.print(_data_Transmit, HEX);
      Serial.print("\n");
      count_Data_Transmit = 0;
      status = 1;      
    }
  }
}

