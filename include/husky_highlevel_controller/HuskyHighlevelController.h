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
			// Callback function
			void scanCallback(const sensor_msgs::LaserScan &scan_msg);

			ros::NodeHandle& nodeHandle_;
			ros::Subscriber  scan_sub_;
			std::string subscriberTopic_;
			int queue_size;
			 
	};
	
}




#endif