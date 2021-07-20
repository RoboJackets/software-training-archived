//
// Created by jason on 7/5/21.
//

#ifndef SRC_MOTION_MODEL_H
#define SRC_MOTION_MODEL_H

#include "particle.h"
#include <sensor_msgs/msg/imu.hpp>
#include <rclcpp/rclcpp.hpp>
#include "random"

namespace localization {

class IMUMotionModel {
public:
  IMUMotionModel(std::shared_ptr<ParticleNoise> noise, rclcpp::Node* node);

  void updateParticle(Particle & particle, double dt, sensor_msgs::msg::Imu::SharedPtr imu_msg);
  void updateParticles(std::vector<Particle> & particles,
                       sensor_msgs::msg::Imu::SharedPtr imu_msg);
  void ImuCallback(const sensor_msgs::msg::Imu::SharedPtr msg);
private:
  Particle sigmas_;
  rclcpp::Time last_message_time_;
  rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_sub_;

  std::shared_ptr<ParticleNoise> noise_;

};

}


#endif //SRC_MOTION_MODEL_H
