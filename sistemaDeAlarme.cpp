const int LED = 2;
const int sirene = 3;
const int sala = 4;
const int cozinha = 5;
const int garagem = 6;
const int chave = 7;
#define pulsos 100
#define pausa 3000

bool flagMsgInicial = false;
bool flagMsg = false;

void setup() {
  
  iniciaPortas();  // chama uma função para designar as portas
  Serial.begin(9600);
  Serial.println("Ativando sistema de alarme");
  
}
  
void iniciaPortas(){
  pinMode(LED, OUTPUT);
  pinMode(sirene, OUTPUT);
  pinMode(chave, INPUT);
  pinMode(sala, INPUT);
  pinMode(garagem, INPUT);
  pinMode(cozinha, INPUT);

}

void loop() {
  bool acionado = digitalRead(chave);
  bool sensorS = digitalRead(sala);
  bool sensorC = digitalRead(cozinha);
  bool sensorG = digitalRead(garagem);

  delay(200);
  flagMsg = false;
    if (acionado == true) {
      if (flagMsgInicial == false){
        Serial.println("Sistema de alarme ligado");
        flagMsgInicial = true;  // Impede que a mensagem se repita em loop
      }
      if (sensorS == true) {  // sensor da sala ativado
      if (flagMsg == false) {
        Serial.println("O sensor da sala foi ativado");
        flagMsg = true;  // Impede que a mensagem se repita em loop
        alarme();  // chama a função alarme
      }}

      if (sensorC == true) {  // sensor da cozinha ativado
      if (flagMsg == false){
        Serial.println("O sensor da cozinha foi ativado");
        flagMsg = true;  // Impede que a mensagem se repita em loop
        alarme();  // Chama a função alarme
      }}

      if (sensorG == true) {  // sensor da garagem ativado
      if (flagMsg == false) { 
        Serial.println("O sensor da garagem foi ativado"); // mensagem aparece no serial
        flagMsg = true;  // impede que a mensagem se repita em loop
        alarme();  // Chama a função alarme
      }}
      
     }
   }
    
  void alarme(){  
  for (int i = 0; i <= 10; i++){  // loop de for para o led e o buzzer ativar 10x
    digitalWrite(LED, HIGH);      // led liga
    tone(sirene, 349);   // buzzer toca um Fá
    delay (pulsos);      // conta 100 MS
    digitalWrite(LED, LOW); // led apaga
    noTone(sirene);
    delay(pulsos);  // conta 100 MS
    }
    delay(pausa);  // conta 3S
   }




