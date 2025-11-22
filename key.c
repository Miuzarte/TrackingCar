#include "key.h"

#define KEY_1 P3_5
#define KEY_2 P3_4
#define KEY_3 P3_3
#define KEY_4 P3_2

/****
    * @brief  获取独立按键键码
    * @retval 按下按键的键码，范围：1 - 4，无按键按下时返回值为 0
    */
uint8 GetKey() {
    if (KEY_1 == 0) { Delay(10); while (KEY_1 == 0); Delay(10); return 1; }
    if (KEY_2 == 0) { Delay(10); while (KEY_2 == 0); Delay(10); return 2; }
    if (KEY_3 == 0) { Delay(10); while (KEY_3 == 0); Delay(10); return 3; }
    if (KEY_4 == 0) { Delay(10); while (KEY_4 == 0); Delay(10); return 4; }
    return 0;
}
