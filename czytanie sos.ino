#define GRANICA 600
#define DELAY 2

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(A0 , INPUT);
  Serial.begin(9600);
}
int tab[3000];
long long ile = 0;
void loop()
{
  int stage = 0 , ile2 = 0 , ile3 = 0;
  if(ile >= 3000){
    for(int i = 0; i < 3000; i++){
      if(stage == 0){
      	if(tab[i]) ile2++;
      	else{
        	if(ile2 < 90 || ile2 > 110)break;
        	stage = 1;
        	ile2 = 0;
      	}
      }
      if(stage == 1){
      	if(!tab[i]) ile2++;
        else{
        	if(ile2 < 90 || ile2 > 110) break;	
          	if(ile3 == 2) stage = 2;
          	else stage = 0;
          	ile3++;
          	ile2 = 0;
        }
      }
      if(stage == 2){
      	if(tab[i]) ile2++;
      	else{
        	if(ile2 < 290 || ile2 > 310)break;
        	stage = 3;
        	ile2 = 0;
      	}
      }
      if(stage == 3){
      	if(!tab[i]) ile2++;
        else{
        	if(ile2 < 290 || ile2 > 310) break;	
          	if(ile3 == 2) stage = 4;
          	else stage = 2;
          	ile3++;
          	ile2 = 0;
        }
      }
      if(stage == 4){
      	if(tab[i]) ile2++;
      	else{
        	if(ile2 < 90 || ile2 > 110)break;
        	stage = 5;
        	ile2 = 0;
      	}
      }
      if(stage == 5){
      	if(!tab[i]) ile2++;
        else{
        	if(ile2 < 90 || ile2 > 110) break;	
          	if(ile3 == 2){
          		Serial.println("Basia, pomocy!");
              	break;
            }
          	else stage = 4;
          	ile3++;
          	ile2 = 0;
        }
      }
    }
  }
  tab[ile % 3000] = (analogRead(A0) > GRANICA) ? 1 : 0;
  delay(DELAY);
}