// Laboratório nº1 - Operação em MA e Relação Estática Entrada-Saída
// Considerando u_max = 255
// Modelo programa laboratório
// Data: 28/8/2023

#define PWM_PIN 3	    
#define ADC_PIN 0    
#define TS 	100 	    // Período de amostragem [us]
#define Ts   1        // Período de amostragem [ms]

/* variáveis utilizadas: */
//int u = 0;		        // sinal de controle
int y[2];		          // sinal do adc
float yf[2], uv, yv, yy, u=0;		      // sinal do adc filtrado
int i = 0, j = 0;	    // variáveis de contagem
int incremento = 25;	// incremento do sinal de controle 	

/* rotina de configuração: */
void setup() {
  Serial.begin(57600); // baud rate = 115200
  for(i=0; i<2; i++) y[i] = 0;
  for(i=0; i<2; i++) yf[i] = 0;
}

/* loop infinito: */
void loop()
{
  // filtro passa-baixas
  y[1] = y[0];
  y[0] = analogRead(ADC_PIN);
  yf[1] = yf[0];
  yf[0] = 0.05*y[1] + 0.95*yf[1];
 
  j++;
  if(j >= 2000) 
  {
    u += incremento;
    
    if (u >= 255) u = 0;
    j = 0;
    
  }

  yv = y[0];
  yy = yf[0]*5/1024;
  yv = yv*5/1024;
  uv = u*5/255;
  
  analogWrite(PWM_PIN, u);
  //delayMicroseconds(TS);
  delay(Ts);

 // Serial.print(yv);
 // Serial.print(" ");

 // Serial.print(yy);
 // Serial.print(" ");

 // Serial.print(uv);
 // Serial.print(" ");

  Serial.print(yf[0]);
  Serial.print(" ");

  Serial.print(y[0]);
  Serial.print(" ");

  Serial.print(u);
  Serial.print(" ");

  Serial.print(900);
  Serial.print(" ");

//  Serial.print(5);
//  Serial.print(" ");
  
  Serial.println(0);
  Serial.print(" ");

}
