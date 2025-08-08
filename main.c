#include <stdio.h>
#include "pico/stdlib.h"
#include "systick.h"
#include "hardware/pwm.h"
#include "funciones.h"

uint8_t pin_v = 15;
uint8_t pin_adelante = 14;
uint8_t pin_atras = 13;
bool marcha = false;
bool primer_marcha = false;
char memoria_comanndo;
char comando;

int main(){

init();

while(1){

          // Esperamos a recibir un byte por UART
          if (uart_is_readable(UART_ID)) {
            comando = uart_getc(UART_ID);

            if(comando == 'R'){
              marcha = true;

              if(primer_marcha = false){memoria_comanndo == '6';  primer_marcha = true;}
              primer_marcha = true;
              configurar_giro_motor(pin_adelante,pin_atras);
              actualizar_pwm_desde_comando(memoria_comanndo,pin_v);
              comando = memoria_comanndo;
            }

            if(comando == 'L'){
              marcha = false;
              comando = 0;
              actualizar_pwm_desde_comando(comando,pin_v);
            }


        //VELOCIDAD

        if(marcha == true){

          if(comando >= '0'&& comando <='9'){
          
            actualizar_pwm_desde_comando(comando,pin_v);
            memoria_comanndo = comando;
          }

          
          
        // GIRO ADELANTE

          if (comando == 'F') {
            configurar_giro_motor(pin_adelante,pin_atras);
            
          }
          
          if (comando == 'B') {

            configurar_giro_motor(pin_atras,pin_adelante);

         }
        }
       }
     }
   }