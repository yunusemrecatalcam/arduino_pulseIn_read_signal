#define DATA 8

unsigned long pulse_time = 0;
int data_seq[48] = {0};
int cnt = 0;
int eight_bits=0;
int four_bit_seq[12]={0};
int a=0;

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
        //while(!digitalRead(DATA));
        ///Serial.print("t");
        pulse_time=pulseIn(DATA,HIGH);
        if(pulse_time>=680){
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
      
      Serial.print(" ");
      a=0;
      for(int i=0;i<48;i++){
        if(i%8==7){
          eight_bits=0;
          
          eight_bits += data_seq[(i-7)];
          eight_bits <<=1;  
          eight_bits += data_seq[(i-6)];
          eight_bits <<=1;
          eight_bits += data_seq[(i-5)];
          eight_bits <<=1;
          eight_bits += data_seq[(i-4)];
          eight_bits <<=1;
          eight_bits += data_seq[(i-3)];
          eight_bits <<=1;
          eight_bits += data_seq[(i-2)];
          eight_bits <<=1;
          eight_bits += data_seq[(i-1)];
          eight_bits <<=1;
          eight_bits += data_seq[(i)];
          
          four_bit_seq[a]=eight_bits;
          Serial.print(eight_bits,HEX);
          
          a++;
        }
      }
      cnt = 0;
      while(cnt<48){
      data_seq[cnt]=0;
      cnt++;
      }
      
      Serial.println("");
      Serial.print((four_bit_seq[0]^four_bit_seq[5]),HEX);
      Serial.print("  ");
      Serial.print(four_bit_seq[1]^four_bit_seq[4],HEX);
      Serial.print("  ");
      Serial.print(four_bit_seq[2]^four_bit_seq[3],HEX);
      Serial.println("  ");
      Serial.println("  ");
    }
    
    

  
  }
}

