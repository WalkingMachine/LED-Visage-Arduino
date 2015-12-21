#ifndef _ROS_roboteq_msgs_Status_h
#define _ROS_roboteq_msgs_Status_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace roboteq_msgs
{

  class Status : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t fault;
      uint8_t status;
      float ic_temperature;
      float internal_voltage;
      float adc_voltage;
      enum { FAULT_OVERHEAT = 1 };
      enum { FAULT_OVERVOLTAGE = 2 };
      enum { FAULT_UNDERVOLTAGE = 4 };
      enum { FAULT_SHORT_CIRCUIT = 8 };
      enum { FAULT_EMERGENCY_STOP = 16 };
      enum { FAULT_SEPEX_EXCITATION_FAULT = 32 };
      enum { FAULT_MOSFET_FAILURE = 64 };
      enum { FAULT_STARTUP_CONFIG_FAULT = 128 };
      enum { STATUS_SERIAL_MODE = 1 };
      enum { STATUS_PULSE_MODE = 2 };
      enum { STATUS_ANALOG_MODE = 4 };
      enum { STATUS_POWER_STAGE_OFF = 8 };
      enum { STATUS_STALL_DETECTED = 16 };
      enum { STATUS_AT_LIMIT = 32 };
      enum { STATUS_MICROBASIC_SCRIPT_RUNNING = 128 };

    Status():
      header(),
      fault(0),
      status(0),
      ic_temperature(0),
      internal_voltage(0),
      adc_voltage(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->fault >> (8 * 0)) & 0xFF;
      offset += sizeof(this->fault);
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      union {
        float real;
        uint32_t base;
      } u_ic_temperature;
      u_ic_temperature.real = this->ic_temperature;
      *(outbuffer + offset + 0) = (u_ic_temperature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ic_temperature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ic_temperature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ic_temperature.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ic_temperature);
      union {
        float real;
        uint32_t base;
      } u_internal_voltage;
      u_internal_voltage.real = this->internal_voltage;
      *(outbuffer + offset + 0) = (u_internal_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_internal_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_internal_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_internal_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->internal_voltage);
      union {
        float real;
        uint32_t base;
      } u_adc_voltage;
      u_adc_voltage.real = this->adc_voltage;
      *(outbuffer + offset + 0) = (u_adc_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_adc_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_adc_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_adc_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->adc_voltage);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->fault =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->fault);
      this->status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status);
      union {
        float real;
        uint32_t base;
      } u_ic_temperature;
      u_ic_temperature.base = 0;
      u_ic_temperature.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ic_temperature.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ic_temperature.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ic_temperature.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ic_temperature = u_ic_temperature.real;
      offset += sizeof(this->ic_temperature);
      union {
        float real;
        uint32_t base;
      } u_internal_voltage;
      u_internal_voltage.base = 0;
      u_internal_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_internal_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_internal_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_internal_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->internal_voltage = u_internal_voltage.real;
      offset += sizeof(this->internal_voltage);
      union {
        float real;
        uint32_t base;
      } u_adc_voltage;
      u_adc_voltage.base = 0;
      u_adc_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_adc_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_adc_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_adc_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->adc_voltage = u_adc_voltage.real;
      offset += sizeof(this->adc_voltage);
     return offset;
    }

    const char * getType(){ return "roboteq_msgs/Status"; };
    const char * getMD5(){ return "d3a9b223fdfb0968255e25e5a859ac29"; };

  };

}
#endif