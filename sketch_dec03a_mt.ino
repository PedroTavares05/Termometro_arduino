#include <LiquidCrystal.h>

// Entrada analógica do termômetro
const int termometro = A5;
// Pinagem do LCD
const int rs = 11, en = 12, d4 = 2, d5 = 3, d6 = 4, d7 = 5;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
    lcd.begin(16, 6);            // Inicializa LCD
    lcd.setCursor(0, 0);         // Posiciona cursor no início da primeira linha
    lcd.print("Temperatura");    // Escreve "Temperatura" no LCD
    lcd.setCursor(11, 1);        // Posiciona cursor ao final da segunda linha
    lcd.print(" \xDF");          // Escreve símbolo '°'
    lcd.print("C   ");           // Escreve caractere 'C'
}

void loop() {
    float t = read_temp();                // Lê a temperatura
    lcd.setCursor((t >= 100.0)?4:5, 1);   // Posiciona cursor no LCD, alinha conteúdo à direita
    lcd.print(t);                         // Escreve no LCD
    delay(600);                           // Aguarda 600 ms para próxima leitura
}

float read_temp() {
    // Le o termômetro e retorna a temperatura (considera um sensor LM35)
    float aread = 5.0 * (analogRead(termometro) / 1023.0);    //Le a tensão de 0 a 5V
    float temp = floor(1000.0 * aread)/10.0; // Converte para temperatura, com uma casa decimal
    return temp;
}
