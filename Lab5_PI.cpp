// Laboratório 5 - Controle PI
//
// Definição de Parâmetros
#define KP 1
#define KI 10
#define KA KI
#define TS 1 //ms
#define PWM_PIN 3
#define ADC_PIN 0

// Definição sinal de referência
int r[] = {400, 500};

// Inicialização de varíaveis
float u = 0, us[2], e[2], yf[2], usat = 0, k1 = 0, k2 = 0, aw = 0;
int i = 0, j = 0, k = 0, y[2];


// rotina de configuração:
void setup() {
  Serial.begin(57600);
  for(i=0; i<2; i++) yf[i] = 0;
  for(i=0; i<2; i++) y[i] = 0;
  for(i=0; i<2; i++) e[i] = 0;
  for(i=0; i<2; i++) us[i] = 0;
    
  // ganhos do controlador:
  k1 = KP + KI*TS*1e-3;
  k2 = -KP;
}

// loop infinito:
void loop()
{
   k++;
   
   if(k >= 2000){
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

  // controle PI:
  e[0] = r[j] - yf[0];
  us[0] = us[1] + k1*e[0] + k2*e[1];

  // antiwindup
  usat = us[0];
  if(usat > 255) usat = 255;
  if(usat < 0) usat  = 0;
  aw = us[0] - usat;
  // aw = 0;
  us[0] = us[0] - KA*TS*1e-3*aw;
  
  // Escrita sinal de controle com limitação de valor máximo e mínimo
  u = us[0];
  if(u > 255) u = 255;
  if(u < 0) u  = 0;

  analogWrite(PWM_PIN, u);
  delayMicroseconds(TS);

  Serial.print(yf[0]);
  Serial.print(" ");

  Serial.print(r[j]);
  Serial.print(" ");

  Serial.print(u);
  Serial.print(" ");

  Serial.print(e[0]);
  Serial.print(" ");

  // Serial.print(aw);
  // Serial.print(" ");

  Serial.print(0);
  Serial.print(" ");

  Serial.println(600);
  Serial.print(" ");

}
