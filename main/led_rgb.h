#pragma once
#include "freertos/FreeRTOS.h"
#include "driver/rmt_tx.h"


/**
 * @brief Função para configura a GPIO e o RMT de forma a ser capaz de configurar o LED WS2812B
 */
void led_setup(uint8_t gpio);

/**
 * @brief Função para definir a cor do LED WS2812B
 * @param[in] red Valor da cor vermelha (0-255)
 * @param[in] green Valor da cor verde (0-255)
 * @param[in] blue Valor da cor azul (0-255)
 */
void led_color(uint8_t red, uint8_t green, uint8_t blue);

/**
 * @brief Type of led strip encoder configuration
 */
typedef struct {
    uint32_t resolution; /*!< Encoder resolution, in Hz */
} led_strip_encoder_config_t;

/**
 * @brief Create RMT encoder for encoding LED strip pixels into RMT symbols
 *
 * @param[in] config Encoder configuration
 * @param[out] ret_encoder Returned encoder handle
 * @return
 *      - ESP_ERR_INVALID_ARG for any invalid arguments
 *      - ESP_ERR_NO_MEM out of memory when creating led strip encoder
 *      - ESP_OK if creating encoder successfully
 */
esp_err_t rmt_new_led_strip_encoder(const led_strip_encoder_config_t *config, rmt_encoder_handle_t *ret_encoder);

