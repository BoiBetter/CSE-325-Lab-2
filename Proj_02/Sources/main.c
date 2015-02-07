#include "support_common.h"
#include "dp_switch.h"
#include "led.h"
#include "button.h"
#include "dtim.h"

#define forever for(;;)

static void win_animation(){
    int i;
    for (i = 0; i < 3; i++){
        led_all_on();
        dtim0_delay_ms(250);
        led_all_off();
    }
}
/*static void lose_animation(){

    led_all_on();
    int i;
    for (i = 0; i < 4; i++){
        led_off(i);
        dtim0_delay_ms(500);
    }
}*/


/*static int choose_rand_led(){
    // random generator code goes here

    //return winning_led
}*/

int main(){
    //unsigned long delay = 1000; // This is 1s delay
    //led_all_init();
    //button_init(0);
    //dp_switch_init(1);
    led_all_init();
    button_init(1);
    dtim0_init();
    forever{
        led_on(1);
        dtim0_delay_ms(1000);
        led_off(1);
        dtim0_delay_ms(1000);

    }
    /*forever{

    /*int winning led = choose_rand_led();
     *int current led = 0;
     *led_on(winning_led);
     *dtim0_delay_ms(1000);
     *led_off(winning_led);
     */

    /*while(!button_get_state(0)){
     *  if(get_dp_switch_state(1)){
     *      led_all_off();
     *      led_on(current_led);
     *      current_led ++;
     *      dtim0_delay_ms(delay);
     *  }
     *  else{
     *      current_led =
     *      led_all_off();
     *      led_on(current_led);
     *      dtim0_delay_us(delay);
     *  }
     *
     *  current_led %= 3;
     *
     * }
     */

    /* if(winning_led == current_led){
     *  delay -= 100;
     *  win_animation();
     * }
     * else{
     *  delay = 1000;
     *  lose_animation();
     * }
     */


    //}
   return 0;
}
