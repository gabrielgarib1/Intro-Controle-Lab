// Laboratório Dois
// Resposta dinâmica entrada-saída
// Data: 22/08/2022
//#define KP 2
//#define KI 90
//#define KA 0.0075
//#define KD 10*1e-6
#define TS 1e2 //us
#define PWM_PIN 3
#define ADC_PIN 0

int r[] = {180, 210};
float u = 0, us[2], yf[2], yf2[2];
int i = 0, j = 0, k = 0, y[2];


// rotina de configuração:
void setup() {
  Serial.begin(115200);
//  Serial.begin(9600);
  for(i=0; i<2; i++) yf[i] = 0;
  for(i=0; i<2; i++) yf2[i] = 0;
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

  y[1] = y[0];
  y[0] = analogRead(ADC_PIN);
  yf[1] = yf[0];
  yf2[1] = yf2[0];
  
  // filtro passa-baixas:
  yf[0] = 0.05*y[1] + 0.95*yf[1];
  yf2[0] = 0.15*y[1] + 0.85*yf2[1];

  // Sinal de atuação
  us[0] = r[j];
  
  // Escrita sinal de controle
  u = us[0];
  if(u > 255) u = 255;
  if(u < 0) u  = 0;

  analogWrite(PWM_PIN, u);
  delayMicroseconds(TS);

 Serial.print(yf[0]);
 Serial.print(" ");

 // Serial.print(yf2[0]);
 // Serial.print(" ");

 // Serial.print(y[0]);
 // Serial.print(" ");

 // Serial.print(r[j]);
 // Serial.print(" ");

  Serial.println(u);
  Serial.print(" ");

  Serial.print(0);
  Serial.print(" ");

//  Serial.print(255);
//  Serial.print(" ");

  Serial.print(800);
  Serial.print(" ");

  // Serial.println(255);

}
