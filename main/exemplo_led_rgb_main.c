#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/rmt_tx.h"
#include "led_rgb.h"

#define RMT_LED_STRIP_RESOLUTION_HZ CONFIG_LED_RESOLUTION_HZ //10000000
#define RMT_LED_STRIP_GPIO_NUM      CONFIG_LED_GPIO_NUM //33

#define LED_NUMBERS                 CONFIG_LED_NUMBERS //1
#define EXAMPLE_CHASE_SPEED_MS      50

static const char *TAG = "example";

void app_main(void)
{
    volatile uint8_t red = 0;
    volatile uint8_t green = 1;
    volatile uint8_t blue = 1;

    ESP_LOGI(TAG, "Configurando RMT para o LED");
    led_setup(RMT_LED_STRIP_GPIO_NUM);

    while (1) {
        ESP_LOGI(TAG, "Envia a cor do LED");
        led_color(red,green,blue);
        vTaskDelay(pdMS_TO_TICKS(EXAMPLE_CHASE_SPEED_MS));
    }
}
