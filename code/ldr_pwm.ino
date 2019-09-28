const int entrada_LDR = A0;
const int saida_LED = 11;
int leituraLDR;
int leituraAjustada;

void setup() {
  // put your setup code here, to run once:
  pinMode (entrada_LDR, INPUT);
  pinMode (saida_LED, OUTPUT);
  Serial.begin (9600);
}

void loop() {
  Serial.print ("Leitura crua: ");
  leituraLDR = analogRead (entrada_LDR);
  Serial.println (leituraLDR);
  //0 - 1023
  //0 - 255
  // medir os valores maximo e minimo da leitura crua 
  // colocar esses valores no segundo e no terceiro argumento da funcao map
 
  leituraAjustada = map (leituraLDR, 200, 600, 0, 255);
  analogWrite (saida_LED, leituraAjustada);
  // put your main code here, to run repeatedly:
  // map(value, fromLow, fromHigh, toLow, toHigh);
}
