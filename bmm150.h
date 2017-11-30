#ifndef _BMM150_H_
#define _BMM150_H_


/** Includes */
#include <Arduino.h>
#include <Wire.h>
#include "bmm150_defs.h"

class BMM150{

public:
  BMM150();
  /**
   * \brief initialze device 
   * 
  */
  int8_t initialize(void);
  
  /**
   * \brief Read magnetometer data
  */
  void read_mag_data();
  int16_t compensate_x(int16_t mag_data_z, uint16_t data_rhall);
  int16_t compensate_y(int16_t mag_data_z, uint16_t data_rhall);
  int16_t compensate_z(int16_t mag_data_z, uint16_t data_rhall);

  /**
   * \brief Set power mode
  */
  void set_op_mode(uint8_t op_mode);
  
  /**
   * @brief This internal API reads the trim registers of the sensor and stores
   * the trim values in the "trim_data" of device structure.
  */
  void read_trim_registers();

  /**
   * 
  */
  void write_op_mode(uint8_t op_mode);
  
  /**
   * \brief Set preset mode mode
  */
  void set_preset_mode(uint8_t mode);

  /** 
   * \brief
  */
  void set_power_control_bit(uint8_t pwrcntrl_bit);

  /**
   * 
   * 
  */
  void suspend_to_sleep_mode();
  
  /**
   * 
   * 
  */
  void set_presetmode(uint8_t preset_mode);
  
  /**
   * Self test functionality
  */
  /*
  int8_t perform_self_test(uint8_t self_test_mode);
  int8_t perform_normal_self_test();
  void enable_normal_self_test(uint8_t *self_test_enable);
  int8_t validate_normal_self_test();
  int8_t perform_adv_self_test();
  void adv_self_test_settings();
  void adv_self_test_measurement(uint8_t self_test_current, int16_t *data_z);
  int8_t validate_adv_self_test(int16_t positive_data_z, int16_t negative_data_z);
  void set_adv_self_test_current(uint8_t self_test_current);
  void set_control_measurement_xyz(struct bmm150_settings settings);
*/

  /**
   * 
  */
  void set_odr_xyz_rep(struct bmm150_settings settings);
  void set_xy_rep(struct bmm150_settings settings);
  void set_z_rep(struct bmm150_settings settings);
  void set_odr(struct bmm150_settings settings);

  void soft_reset();
  /**
   * 
  */
//   char* getErrorText(short errorCode);


// protected:
    struct bmm150_settings settings;
    struct bmm150_raw_mag_data raw_mag_data;
    struct bmm150_mag_data mag_data;
    struct bmm150_trim_registers trim_data;


    void i2c_write(short address, short byte);
    void i2c_read(short address, uint8_t *buffer, short length);
    uint8_t i2c_read(short address);

};


#endif
