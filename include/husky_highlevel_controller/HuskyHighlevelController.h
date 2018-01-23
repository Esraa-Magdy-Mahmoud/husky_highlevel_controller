#ifndef HUSKYHIGHLEVELCONTROLLER_H_
#define HUSKYHIGHLEVELCONTROLLER_H_

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <string.h>
#include <geometry_msgs/Twist.h>
#include <visualization_msgs/Marker.h>
#include <std_srvs/SetBool.h>
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
			// Callback methods
			void scanCallback(const sensor_msgs::LaserScan &scan_msg);

			bool srvCallback(std_srvs::SetBool::Request &request, std_srvs::SetBool::Response &response);

			//P-controller method
			void pController();
			// a Method to create marker visualization msg
			void visMsg();


			// node habdle
			ros::NodeHandle& nodeHandle_;
		    //----Subscribers----//
            // subscriber to /scan topic
			ros::Subscriber  scan_sub_;
			
			//-----Publishers-----//
			//publisher to /cmd_vel
			ros::Publisher  cmd_pub_;
			// publisher to /visualization_marker
			ros::Publisher  vis_pub_;

			//---Service server--//
			ros::ServiceServer serviceServer_;
			
			//------msgs-------//
			//twist msg
			geometry_msgs::Twist vel_msg_;
			visualization_msgs::Marker marker;

			//------Pillar info----//
			//pillar position
			float x_pillar;
			float y_pillar;
			// the orientation of the pillar with respect to the x_axis
			float alpha_pillar;

			bool start_stop = true ; // true moves , false stop

 

			std::string subscriberTopic_;
			int queue_size;
			 
	};
	
}




#endif