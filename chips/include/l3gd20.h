#pragma once

#include <gpio.h>
#include <ssp.h>
#include <i2c.h>


// ought to be generic, cm3-specific for now
typedef enum {
    L3GD20_I2C,
    L3GD20_SPI,
} l3gd20_communication_t;

typedef enum {
    L3GD20_250DPS  = 0x00,
    L3GD20_500DPS  = 0x01,
    L3GD20_1000DPS = 0x02,//check if this was a typo or if it is 2000
    L3GD20_2000DPS = 0x03,
}l3gd20_scale_t;

typedef enum {
    L3GD20_95HZ    = 0x00,
    L3GD20_190HZ   = 0x01,
    L3GD20_380HZ   = 0x02,
    L3GD20_760HZ   = 0x03,
}l3gd20_datarate_t;

typedef enum {
    L3GD20_BW1     = 0x00,
    L3GD20_BW2     = 0x01,
    L3GD20_BW3     = 0x02,
    L3GD20_BW4     = 0x03,
}l3gd20_bandwidth_t;

typedef struct {
    // these are to be filled by caller
    pin_t cs;
    // private data
    l3gd20_communication_t comm;
    ssp_t ssp;
//    i2c_t i2c;
    uint8_t odr:2, bw:2, scale:2, power:1;
} l3gd20_t;


int l3gd20_init_ssp(l3gd20_t *l3gd20, ssp_port_t ssp_port);
//int l3gd20_init_i2c(l3gd20_t *l3gd20, i2c_port_t port);

void l3gd20_power(l3gd20_t *l3gd20, int power);
void l3gd20_scale(l3gd20_t *l3gd20, l3gd20_scale_t scale);
void l3gd20_frequency(l3gd20_t *l3gd20, l3gd20_datarate_t odr, l3gd20_bandwidth_t bw);
void l3gd20_filter(l3gd20_t *l3gd20, float cutoff);
void l3gd20_read(l3gd20_t *l3gd20, float axis[3]);


