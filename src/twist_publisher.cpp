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

#include <twist_publisher/twist_publisher.hpp>

#include <rclcpp/create_timer.hpp>

void TwistPublisher::onTimer()
{
  twist_.header.stamp = this->now();
  twist_pub_->publish(twist_); 
}

TwistPublisher::TwistPublisher(const rclcpp::NodeOptions & node_options)
: Node("clock_publisher", node_options)
{
  twist_pub_ = this->create_publisher<geometry_msgs::msg::TwistStamped>("out/twist", 1);
  const int rate = this->declare_parameter("rate", 30);
  twist_.header.frame_id = this->declare_parameter("base_frame", "base_link");
  twist_.twist.linear.x = this->declare_parameter("vel", 0.0);
  twist_.twist.angular.z = this->declare_parameter("omega", 0.0);

  // Timer
  auto timer_callback = std::bind(&TwistPublisher::onTimer, this);
  auto period = std::chrono::duration_cast<std::chrono::nanoseconds>(
    std::chrono::duration<double>(1.0/static_cast<double>(rate)));

  timer_ = std::make_shared<rclcpp::GenericTimer<decltype(timer_callback)>>(
    this->get_clock(), period, std::move(timer_callback),
    this->get_node_base_interface()->get_context());
  this->get_node_timers_interface()->add_timer(timer_, nullptr);
}

#include <rclcpp_components/register_node_macro.hpp>

RCLCPP_COMPONENTS_REGISTER_NODE(TwistPublisher)
