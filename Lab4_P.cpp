// Laboratório 4 - Controle Proporcional
// 
// Data: 24/10/2022
#define KP 3
//#define KI 90
//#define KA 0.0075
//#define KD 10*1e-6
#define TS 1e2 //us
#define PWM_PIN 3
#define ADC_PIN 0
#define rmax  550
#define rmin  450

int r[] = {rmin, rmax};
float u = 0, us[2], e[2], yf[2], usat = 0;
int i = 0, j = 0, k = 0, y[2];

// rotina de configuração:
void setup() 
{
  Serial.begin(115200);
//  Serial.begin(9600);
  for(i=0; i<2; i++) yf[i] = 0;
  for(i=0; i<2; i++) e[i] = 0;
  for(i=0; i<2; i++) y[i] = 0;
  for(i=0; i<2; i++) us[i] = 0;
}

// loop infinito:
void loop()
{
   k++;
   
   if(k >= 5000){
    k = 0;
    j++;
   if(j >= 2) j = 0;
   }
  
  us[1] = us[0];
  e[1] = e[0]; 
  y[1] = y[0];
  y[0] = analogRead(ADC_PIN);
  yf[1] = yf[0];
  
  // filtro passa-baixas:
  yf[0] = 0.05*y[1] + 0.95*yf[1];

  // Controle Proporcional
 e[0] = r[j] - yf[0];
 us[0] = KP*e[0];
   
  // Escrita sinal de controle
  usat = us[0];
  if(usat > 255) usat = 255;
  if(usat < 0) usat = 0;
  u = usat;
  
  analogWrite(PWM_PIN, u);
  delayMicroseconds(TS);

 Serial.print(yf[0]);
 Serial.print(" ");

 //Serial.print(y[0]);
 //Serial.print(" ");

 Serial.print(r[j]);
 Serial.print(" ");

 //Serial.println(u);
 //Serial.print(" ");

 Serial.println(0);
 Serial.print(" ");

//  Serial.print(255);
//  Serial.print(" ");

//  Serial.print(800);
//  Serial.print(" ");

  // Serial.println(255);

}
