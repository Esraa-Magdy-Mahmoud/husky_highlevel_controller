#ifndef HUSKYHIGHLEVELCONTROLLER_H_
#define HUSKYHIGHLEVELCONTROLLER_H_

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <string.h>
#include <geometry_msgs/Twist.h>
namespace husky_highlevel_controller
{
	class HuskyHighlevelController
	{
		public:
			// constructor
			HuskyHighlevelController(ros::NodeHandle& nodeHandle);
			// destructor
			virtual ~HuskyHighlevelController();
		private:
			// Read ros param, return true if successful
			bool readParameters();
			// Callback method
			void scanCallback(const sensor_msgs::LaserScan &scan_msg);

			//P-controller method
			void pController();

			// node habdle
			ros::NodeHandle& nodeHandle_;
			// subscriber to /scan topic
			ros::Subscriber  scan_sub_;
			//publisher to /cmd_vel
			ros::Publisher  cmd_pub_;
			
			//twist msg
			geometry_msgs::Twist vel_msg_;

			//pillar position
			float x_pillar;
			float y_pillar;
			// the angle of the pillar with respect to the x_axis
			float alpha_pillar;

 

			std::string subscriberTopic_;
			int queue_size;
			 
	};
	
}




#endif