// Copyright 2020 Tier IV, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef TWIST_PUBLISHER__TWIST_PUBLISHER_HPP_
#define TWIST_PUBLISHER__TWIST_PUBLISHER_HPP_ 

#include <string>

#include <rclcpp/rclcpp.hpp>

#include <geometry_msgs/msg/twist_stamped.hpp>

class TwistPublisher : public rclcpp::Node
{
public:
  TwistPublisher(const rclcpp::NodeOptions & node_options);

private:
  void onTimer();
  // Timer
  rclcpp::Publisher<geometry_msgs::msg::TwistStamped>::SharedPtr twist_pub_;
  rclcpp::TimerBase::SharedPtr timer_;
  geometry_msgs::msg::TwistStamped twist_;
};

#endif  // TWIST_PUBLISHER__TWIST_PUBLISHER_HPP_
