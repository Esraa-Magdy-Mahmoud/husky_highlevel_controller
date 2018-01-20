#include "husky_highlevel_controller/HuskyHighlevelController.h"



namespace husky_highlevel_controller
{
   HuskyHighlevelController::HuskyHighlevelController(ros::NodeHandle& nodeHandle) :
    nodeHandle_(nodeHandle)
    {
        if (!readParameters()) 
        {
            ROS_ERROR("Could not read parameters.");
            ros::requestShutdown();
        }
        scan_sub_ = nodeHandle_.subscribe(subscriberTopic_, queue_size , &HuskyHighlevelController::scanCallback, this);
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
    void HuskyHighlevelController::scanCallback(const sensor_msgs::LaserScan &msg)
    {
        

    }

}


