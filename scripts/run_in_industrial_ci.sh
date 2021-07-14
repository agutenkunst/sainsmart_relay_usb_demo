#!/usr/bin/env bash

# Needs ROS and industrial_ci sourced
bus_id=$(lsusb | grep 0403:6001 | grep -Po '(?<=Bus )\d+')
device_id=$(lsusb | grep 0403:6001 | grep -Po '(?<=Device )\d+')

# Execute this at the package root!
rosrun industrial_ci rerun_ci . DOCKER_RUN_OPTS="--device=/dev/bus/usb/$bus_id/$device_id" ROS_DISTRO="noetic"