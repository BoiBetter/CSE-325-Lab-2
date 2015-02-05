#include "common.h"
#define forever for(;;)

int main(){
    button_init(BUTTON3);
        led_init(LED2);

        forever{
            if(get_button_state(BUTTON3)){
                led_on(LED2);

            }
            else{
                led_off(LED2);
            }
        }
        return 0;
}
