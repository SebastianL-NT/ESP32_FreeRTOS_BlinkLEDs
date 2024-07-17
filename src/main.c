#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define GPIO_LED_PIN_1 25
#define GPIO_LED_PIN_2 26
#define GPIO_LED_PIN_3 27

void configurePIN_default(uint16_t pinNumber)
{
    gpio_config_t io_led_pin;
    io_led_pin.intr_type = GPIO_INTR_DISABLE;
    io_led_pin.mode = GPIO_MODE_OUTPUT;
    io_led_pin.pin_bit_mask = (1ULL<<pinNumber);
    io_led_pin.pull_down_en = 0;
    io_led_pin.pull_up_en = 0;
    gpio_config(&io_led_pin);
}

void blinkLED_1(void *pvParameter) {
    uint16_t period = 1000;
    uint8_t is_error = false;
    configurePIN_default(GPIO_LED_PIN_1);
    while(!is_error)
    {
        gpio_set_level(GPIO_LED_PIN_1, 1);
        vTaskDelay(period / portTICK_PERIOD_MS);
        gpio_set_level(GPIO_LED_PIN_1, 0);
        vTaskDelay(period / portTICK_PERIOD_MS);
    }
}

void blinkLED_2(void *pvParameter) {
    uint16_t period = 100;
    uint8_t is_error = false;
    configurePIN_default(GPIO_LED_PIN_2);
    while(!is_error)
    {
        gpio_set_level(GPIO_LED_PIN_2, 1);
        vTaskDelay(period / portTICK_PERIOD_MS);
        gpio_set_level(GPIO_LED_PIN_2, 0);
        vTaskDelay(period / portTICK_PERIOD_MS);
    }
}

void blinkLED_3(void *pvParameter) {
    uint16_t period = 500;
    uint8_t is_error = false;
    configurePIN_default(GPIO_LED_PIN_3);
    while(!is_error)
    {
        gpio_set_level(GPIO_LED_PIN_3, 1);
        vTaskDelay(period / portTICK_PERIOD_MS);
        gpio_set_level(GPIO_LED_PIN_3, 0);
        vTaskDelay(period / portTICK_PERIOD_MS);
    }
}

void app_main(void)
{
    BaseType_t Task1 = xTaskCreate(&blinkLED_1, "blinkLED_1", 2048, NULL, tskIDLE_PRIORITY, NULL);
    BaseType_t Task2 = xTaskCreate(&blinkLED_2, "blinkLED_2", 2048, NULL, tskIDLE_PRIORITY, NULL);
    BaseType_t Task3 = xTaskCreate(&blinkLED_3, "blinkLED_3", 2048, NULL, tskIDLE_PRIORITY, NULL);
}