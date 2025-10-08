// Laboratório nº6 - Controlador PID
// Modelo programa laboratório
// Data: 13/12/2022
#define KP 1
#define KI 50
#define KA KI
#define KD 1e-3
#define TS 1 //ms
#define PWM_PIN 3
#define ADC_PIN 0

int r[] = {300, 400};
float u = 0, ufa=0, us[2], e[2], ef[2], yf[2], uf[2], usat = 0, k1 = 0, k2 = 0, aw = 0;
int i = 0, j = 0, k = 0, y[2];


// rotina de configuração:
void setup() {
  Serial.begin(57600);
  for(i=0; i<2; i++) yf[i] = 0;
  for(i=0; i<2; i++) y[i] = 0;
  for(i=0; i<2; i++) e[i] = 0;
  for(i=0; i<2; i++) us[i] = 0;
  for(i=0; i<2; i++) uf[i] = 0;
  for(i=0; i<2; i++) ef[i] = 0;    
  // ganhos do controlador:
  k1 = KP + KI*TS*1e-3;
  k2 = -KP;
}

// loop infinito:
void loop()
{
   k++;
   
   if(k >= 1500){
    k = 0;
    j++;
    if(j >= 2) j = 0;
  }

  us[1] = us[0];
  e[1] = e[0]; 
  y[1] = y[0];
  y[0] = analogRead(ADC_PIN);
  yf[1] = yf[0];
  uf[1] = uf[0];
  ef[1] = ef[0];

  // controle PID:
  e[0] = r[j] - y[0];
  us[0] = us[1] + k1*e[0] + k2*e[1] - KD*(y[0] - y[1])/(1e-3*TS);
  //us[0] = us[1] + k1*e[0] + k2*e[1] + KD*(e[0] - e[1])/(1e-3*TS);

  // antiwindup
  usat = us[0];
  if(usat > 255) usat = 255;
  if(usat < 0) usat  = 0;
  aw = us[0] - usat;
  us[0] = us[0] - TS*1e-3*KA*aw;
  
  // Escrita sinal de controle
  ufa = u;
  u = us[0];
  if(u > 255) u = 255;
  if(u < 0) u  = 0;
  
  // filtro passa-baixas:
  yf[0] = 0.05*y[1] + 0.95*yf[1];
  uf[0] = 0.05*ufa + 0.95*uf[1];
  ef[0] = 0.05*e[1] + 0.95*ef[1];

  
  analogWrite(PWM_PIN, u);
  delay(TS);

  Serial.print(yf[0]);
  Serial.print(" ");

  Serial.print(r[j]);
  Serial.print(" ");

  Serial.print(uf[0]);
  Serial.print(" ");

  Serial.print(ef[0]);
  Serial.print(" ");

  // Serial.print(aw);
  // Serial.print(" ");

  Serial.print(0);
  Serial.print(" ");

  Serial.println(700);
  Serial.print(" ");

}
