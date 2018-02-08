#define DATA 8

unsigned long pulse_time = 0;
int data_seq[48] = {0};
int cnt = 0;
int four_bits=0;

void setup() {
  // put your setup code here, to run once:
pinMode(DATA,INPUT);
Serial.begin(9600);
}

void loop() {

  while(1){
    if(pulseIn(DATA,HIGH)>=4200){   //4.2 ms pulsela data akışı başlıyor
      Serial.print("t");
      cnt=0;
      while(cnt<48){
        while(!digitalRead(DATA));
        ///Serial.print("t");
        pulse_time=pulseIn(DATA,HIGH);
        if(pulse_time>=700){
          //Serial.print("t");
          data_seq[cnt]=1;
        }else{
          data_seq[cnt]=0;
        }
        cnt++;
      }
      
      cnt = 0;
      while(cnt<48){
      Serial.print(data_seq[cnt]);
      cnt++;
      }
      
      
      for(int i=0;i<48;i++){
        if(i%4==3){
          four_bits=0;
          four_bits += data_seq[(i-3)];
          four_bits <<=1;
          four_bits += data_seq[(i-2)];
          four_bits <<=1;
          four_bits += data_seq[(i-1)];
          four_bits <<=1;
          four_bits += data_seq[i];
          Serial.print(four_bits,HEX);
          
        }
      }
      Serial.println("");
      cnt = 0;
      while(cnt<48){
      data_seq[cnt]=0;
      cnt++;
      }
    }

    

  
  }
}

