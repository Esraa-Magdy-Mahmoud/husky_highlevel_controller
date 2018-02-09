# husky_highlevel_controller

My solutions to the exercises presented in the [Programming for Robotics - ROS ](http://www.rsl.ethz.ch/education-students/lectures/ros.html) series. 


## Requirements:
  * Ubuntu 16.04.
  * ROS Kinetic.
  * gazebo 7.7.0.
  * husky-simulator.
  
 
## Setup your environment : 
  ### Install husky-simulator in kinetic:
 
    $ cd ~/catkin_ws/src
    $ git clone https://github.com/husky/husky.git
    $ git clone https://github.com/husky/husky_simulator.git
    $ git clone https://github.com/husky/husky_desktop.git
    $ cd ..
    $ catkin build
    $ sudo apt-get install ros-kinetic-gazebo-ros-pkgs ros-kinetic-gazebo-ros-control
    $ sudo apt-get install ros-kinetic-multimaster-launch
    $ sudo apt-get install ros-kinetic-lms1xx
    $ rosdep install --from-path src --ignore-src  
    $ source devel/setup.bash
  
    Set the environment variable HUSKY_GAZEBO_DESCRIPTION
    $ export HUSKY_URDF_EXTRAS=$(rospack find husky_description)/urdf/empty.urdf
    To launch the simulator :
    $ roslaunch husky_gazebo husky_empty_world.launch
    or 
    $ roslaunch husky_gazebo husky_playpen.launch 
  ### Experiment with husky_highlevel_controller:
    $ roslaunch husky_highlevel_controller husky_highlevel_controller.launch
  
  
