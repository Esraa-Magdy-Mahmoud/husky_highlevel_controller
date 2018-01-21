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
        //number of the elements in ranges array
        int arr_size = floor((scan_msg.angle_max-scan_msg.angle_min)/scan_msg.angle_increment);
        for (int i=0 ; i< arr_size ;i++)
        {
            if (scan_msg.ranges[i] < smallest_distance)
            {
                smallest_distance = scan_msg.ranges[i];
            }
        }
        ROS_INFO_STREAM("the smallest distance measurement from the laser scanner (m): "<<smallest_distance<<'\n');


    }

}


