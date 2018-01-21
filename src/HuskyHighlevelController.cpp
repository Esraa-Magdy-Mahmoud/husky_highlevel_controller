#include "husky_highlevel_controller/HuskyHighlevelController.h"



namespace husky_highlevel_controller
{
    //Constructor
   HuskyHighlevelController::HuskyHighlevelController(ros::NodeHandle& nodeHandle) :
    nodeHandle_(nodeHandle)
    {
        if (!readParameters()) 
        {
            ROS_ERROR("Could not read parameters.");
            ros::requestShutdown();
        }

        // subscribers
        scan_sub_ = nodeHandle_.subscribe(subscriberTopic_, queue_size , &HuskyHighlevelController::scanCallback, this);
        // publishers
        cmd_pub_  = nodeHandle_.advertise<geometry_msgs::Twist>("/cmd_vel",100);
        


        ROS_INFO("Successfully launched node.");
    }

    HuskyHighlevelController::~HuskyHighlevelController()
    {
    }
    
    bool HuskyHighlevelController::readParameters()
    {
        if (!nodeHandle_.getParam("scan_sub_topic", subscriberTopic_)) return false;
       
        if (!nodeHandle_.getParam("scan_sub_queue_size", queue_size))return false;
       
        return true;
    }
    void HuskyHighlevelController::scanCallback(const sensor_msgs::LaserScan &scan_msg)
    {
        float smallest_distance = 9999;
        // the angle corresponding to the minimum distance
      

        //number of the elements in ranges array
        int arr_size = floor((scan_msg.angle_max-scan_msg.angle_min)/scan_msg.angle_increment);
        for (int i=0 ; i< arr_size ;i++)
        {
            if (scan_msg.ranges[i] < smallest_distance)
            {
                smallest_distance = scan_msg.ranges[i];
                alpha_pillar = (scan_msg.angle_min + i*scan_msg.angle_increment);
            }
        }

        //Pillar position 
        x_pillar = smallest_distance*cos(alpha_pillar);
        y_pillar =  smallest_distance*sin(alpha_pillar);

        //ROS_INFO_STREAM("the smallest distance measurement from the laser scanner (m): "<<smallest_distance<<'\n');
                
        //P-Controller to drive husky towards the pillar
        HuskyHighlevelController::pController();
        cmd_pub_.publish(vel_msg_);
    }
    
    void HuskyHighlevelController::pController()
    {
        //propotinal gain
        float p_gain_vel = 0.2;
        float p_gain_ang = 10;
        if (x_pillar <= 0.5 )
        {
             vel_msg_.linear.x = 0;
             vel_msg_.linear.y = 0; 
             vel_msg_.angular.z =0;

        }
        else 
        {
             vel_msg_.linear.x = x_pillar * p_gain_vel  ;
             vel_msg_.linear.y = y_pillar * p_gain_vel ; 
             vel_msg_.angular.z = -alpha_pillar ;

        }
    }

}


