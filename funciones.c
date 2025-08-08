#include <stdio.h>
#include "pico/stdlib.h"
#include "systick.h"
#include "hardware/pwm.h"
#include "funciones.h"


uint16_t pwm_level = 0;
uint16_t slice = 0;
uint16_t chan = 0;
uint16_t valor_adc_remoto;

void init(){
    stdio_init_all();
    init_systick();   

    // Inicialización de la UART
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
}

    uint16_t actualizar_pwm_desde_comando(char comando, uint8_t pin_velocidad){
   
    switch (comando) {
        case '0':valor_adc_remoto = 0;break;
        case '1':valor_adc_remoto = 1;break;
        case '2':valor_adc_remoto = 2;break;
        case '3':valor_adc_remoto = 3;break;
        case '4':valor_adc_remoto = 4;break;
        case '5':valor_adc_remoto = 5;break;
        case '6':valor_adc_remoto = 6;break;
        case '7':valor_adc_remoto = 7;break;
        case '8':valor_adc_remoto = 8;break;
        case '9':valor_adc_remoto = 9;break;
        default: valor_adc_remoto = 0;break;
    }

    gpio_set_function(pin_velocidad,GPIO_FUNC_PWM);
    pwm_level = (valor_adc_remoto)*455;
     slice = pwm_gpio_to_slice_num(15);
     chan = pwm_gpio_to_channel(15);
    // Aplicamos el nivel de PWM al canal del pin 15
    pwm_set_clkdiv(slice, 1.57f);     
    pwm_set_wrap(slice, 4095);                 
    pwm_set_enabled(slice, true); 
    pwm_set_chan_level(slice,chan,pwm_level); 
}


void configurar_giro_motor(uint8_t SENTIDO_PIN ,uint8_t APAGAR_SENTIDO_CONTRARIO){

    gpio_init(SENTIDO_PIN);
    gpio_init(APAGAR_SENTIDO_CONTRARIO);
    gpio_set_dir(APAGAR_SENTIDO_CONTRARIO,false);
    gpio_set_dir(SENTIDO_PIN,GPIO_OUT);
    gpio_put(SENTIDO_PIN,true);
  }

