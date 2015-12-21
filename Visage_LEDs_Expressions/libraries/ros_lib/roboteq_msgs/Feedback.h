#ifndef _ROS_roboteq_msgs_Feedback_h
#define _ROS_roboteq_msgs_Feedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace roboteq_msgs
{

  class Feedback : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float motor_current;
      float motor_power;
      float commanded_velocity;
      float measured_velocity;
      float measured_position;
      float supply_voltage;
      float supply_current;
      float motor_temperature;
      float channel_temperature;

    Feedback():
      header(),
      motor_current(0),
      motor_power(0),
      commanded_velocity(0),
      measured_velocity(0),
      measured_position(0),
      supply_voltage(0),
      supply_current(0),
      motor_temperature(0),
      channel_temperature(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_motor_current;
      u_motor_current.real = this->motor_current;
      *(outbuffer + offset + 0) = (u_motor_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_motor_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_motor_current.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor_current);
      union {
        float real;
        uint32_t base;
      } u_motor_power;
      u_motor_power.real = this->motor_power;
      *(outbuffer + offset + 0) = (u_motor_power.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor_power.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_motor_power.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_motor_power.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor_power);
      union {
        float real;
        uint32_t base;
      } u_commanded_velocity;
      u_commanded_velocity.real = this->commanded_velocity;
      *(outbuffer + offset + 0) = (u_commanded_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_commanded_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_commanded_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_commanded_velocity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->commanded_velocity);
      union {
        float real;
        uint32_t base;
      } u_measured_velocity;
      u_measured_velocity.real = this->measured_velocity;
      *(outbuffer + offset + 0) = (u_measured_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_measured_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_measured_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_measured_velocity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->measured_velocity);
      union {
        float real;
        uint32_t base;
      } u_measured_position;
      u_measured_position.real = this->measured_position;
      *(outbuffer + offset + 0) = (u_measured_position.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_measured_position.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_measured_position.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_measured_position.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->measured_position);
      union {
        float real;
        uint32_t base;
      } u_supply_voltage;
      u_supply_voltage.real = this->supply_voltage;
      *(outbuffer + offset + 0) = (u_supply_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_supply_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_supply_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_supply_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->supply_voltage);
      union {
        float real;
        uint32_t base;
      } u_supply_current;
      u_supply_current.real = this->supply_current;
      *(outbuffer + offset + 0) = (u_supply_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_supply_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_supply_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_supply_current.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->supply_current);
      union {
        float real;
        uint32_t base;
      } u_motor_temperature;
      u_motor_temperature.real = this->motor_temperature;
      *(outbuffer + offset + 0) = (u_motor_temperature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor_temperature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_motor_temperature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_motor_temperature.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor_temperature);
      union {
        float real;
        uint32_t base;
      } u_channel_temperature;
      u_channel_temperature.real = this->channel_temperature;
      *(outbuffer + offset + 0) = (u_channel_temperature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_channel_temperature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_channel_temperature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_channel_temperature.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->channel_temperature);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_motor_current;
      u_motor_current.base = 0;
      u_motor_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_motor_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_motor_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_motor_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->motor_current = u_motor_current.real;
      offset += sizeof(this->motor_current);
      union {
        float real;
        uint32_t base;
      } u_motor_power;
      u_motor_power.base = 0;
      u_motor_power.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_motor_power.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_motor_power.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_motor_power.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->motor_power = u_motor_power.real;
      offset += sizeof(this->motor_power);
      union {
        float real;
        uint32_t base;
      } u_commanded_velocity;
      u_commanded_velocity.base = 0;
      u_commanded_velocity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_commanded_velocity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_commanded_velocity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_commanded_velocity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->commanded_velocity = u_commanded_velocity.real;
      offset += sizeof(this->commanded_velocity);
      union {
        float real;
        uint32_t base;
      } u_measured_velocity;
      u_measured_velocity.base = 0;
      u_measured_velocity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_measured_velocity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_measured_velocity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_measured_velocity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->measured_velocity = u_measured_velocity.real;
      offset += sizeof(this->measured_velocity);
      union {
        float real;
        uint32_t base;
      } u_measured_position;
      u_measured_position.base = 0;
      u_measured_position.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_measured_position.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_measured_position.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_measured_position.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->measured_position = u_measured_position.real;
      offset += sizeof(this->measured_position);
      union {
        float real;
        uint32_t base;
      } u_supply_voltage;
      u_supply_voltage.base = 0;
      u_supply_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_supply_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_supply_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_supply_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->supply_voltage = u_supply_voltage.real;
      offset += sizeof(this->supply_voltage);
      union {
        float real;
        uint32_t base;
      } u_supply_current;
      u_supply_current.base = 0;
      u_supply_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_supply_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_supply_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_supply_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->supply_current = u_supply_current.real;
      offset += sizeof(this->supply_current);
      union {
        float real;
        uint32_t base;
      } u_motor_temperature;
      u_motor_temperature.base = 0;
      u_motor_temperature.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_motor_temperature.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_motor_temperature.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_motor_temperature.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->motor_temperature = u_motor_temperature.real;
      offset += sizeof(this->motor_temperature);
      union {
        float real;
        uint32_t base;
      } u_channel_temperature;
      u_channel_temperature.base = 0;
      u_channel_temperature.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_channel_temperature.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_channel_temperature.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_channel_temperature.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->channel_temperature = u_channel_temperature.real;
      offset += sizeof(this->channel_temperature);
     return offset;
    }

    const char * getType(){ return "roboteq_msgs/Feedback"; };
    const char * getMD5(){ return "2b31653367731d6254182bb2f9dbb81a"; };

  };

}
#endif