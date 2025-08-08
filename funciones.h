#ifndef _FUNCIONES_H_
#define _FUNCIONES_H_

uint16_t actualizar_pwm_desde_comando(char comando,uint8_t pin_velocidad);
void  configurar_giro_motor(uint8_t SENTIDO_PIN,uint8_t APAGAR_SENTIDO_CONTRARIO);

void init();
#define UART_TX_PIN 4
#define UART_RX_PIN 5
#define BAUD_RATE 9600
#define UART_ID uart1

#endif