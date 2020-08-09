#include "std_msgs/String.h"
#include "ros/ros.h"
#include <geometry_msgs/PoseStamped.h>
#include <sstream>
#include "smach_msgs/SmachContainerStatus.h"

smach_msgs::SmachContainerStatus mbf_smach_status ;

geometry_msgs::PoseStamped goal1 , goal2 , goal3 , goal4 ;

void mbf_state_callback(smach_msgs::SmachContainerStatus mbf_state)
{
  std::string path = "/MBF_SM" ;
  if(mbf_state.path.c_str() == path)
  {
    mbf_smach_status = mbf_state ;
    ROS_INFO("Current active state : %s",mbf_smach_status.active_states.back().c_str()) ;
  }
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "sandbox_robot_goal_publisher");

  ros::NodeHandle nh;

  std::string goal_waiting_state = "WAIT_FOR_GOAL" ;

  ros::Publisher pub = nh.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal",1) ;
  ros::Subscriber mbf_smach_sub = nh.subscribe<smach_msgs::SmachContainerStatus>("/mbf_state_machine_server/smach/container_status",1000,mbf_state_callback);

  ros::Duration(3.0).sleep();

  mbf_smach_status.active_states.push_back("DEFAULT") ; 

  ros::Rate rate(100);

  int count = 1;
  double begin_time = ros::Time::now().toSec() ;

  goal1.header.seq = count ;
  goal1.header.stamp = ros::Time::now();
  goal1.header.frame_id="map";
  goal1.pose.position.x = 9.46627521515 ;
  goal1.pose.position.y = 0.744836807251 ;
  goal1.pose.position.z = 0.0 ;
  goal1.pose.orientation.x = 0.0 ;
  goal1.pose.orientation.y = 0.0 ;
  goal1.pose.orientation.z = -0.0188386461066 ;
  goal1.pose.orientation.w = 0.99982253696 ;

  pub.publish(goal1);

  ROS_INFO("Goal 1 published!!!!");

  ros::spinOnce();

  while(mbf_smach_status.active_states.back().c_str() == goal_waiting_state)
  {
    if(!ros::ok())
    {
        ros::shutdown();
        return 0;
    }
    ros::spinOnce();
    rate.sleep();
  }

  while(mbf_smach_status.active_states.back().c_str() != goal_waiting_state)
  {
    if(!ros::ok())
    {
        ros::shutdown();
        return 0;
    }
    ros::spinOnce();
    rate.sleep();
  }

  ROS_INFO("Successfully reached goal1!!!");
  ROS_INFO("Total Plan + Execution time(in secs) for Goal 1:%f",(ros::Time::now().toSec() - begin_time));
  begin_time = ros::Time::now().toSec() ;

  count += 1 ;

  goal2.header.seq = count ;
  goal2.header.stamp = ros::Time::now();
  goal2.header.frame_id="map";
  goal2.pose.position.x = 11.8795051575 ;
  goal2.pose.position.y = 6.65552043915 ;
  goal2.pose.position.z = 0.0 ;
  goal2.pose.orientation.x = 0.0 ;
  goal2.pose.orientation.y = 0.0 ;
  goal2.pose.orientation.z = 0.999964527808 ;
  goal2.pose.orientation.w = -0.00842277423604 ;

  pub.publish(goal2);

  ROS_INFO("Goal 2 published!!!!");

  ros::spinOnce();

  while(mbf_smach_status.active_states.back().c_str() == goal_waiting_state)
  {
    if(!ros::ok())
    {
        ros::shutdown();
        return 0;
    }
    ros::spinOnce();
    rate.sleep();
  }

  while(mbf_smach_status.active_states.back().c_str() != goal_waiting_state)
  {
    if(!ros::ok())
    {
        ros::shutdown();
        return 0;
    }
    ros::spinOnce();
    rate.sleep();
  }

  ROS_INFO("Successfully reached goal2!!!");
  ROS_INFO("Total Plan + Execution time(in secs) for Goal 2:%f",(ros::Time::now().toSec() - begin_time));
  begin_time = ros::Time::now().toSec() ;

  count += 1 ;

  goal3.header.seq = count ;
  goal3.header.stamp = ros::Time::now();
  goal3.header.frame_id="map";
  goal3.pose.position.x = -9.53570556641 ;
  goal3.pose.position.y = 1.49944114685 ;
  goal3.pose.position.z = 0.0 ;
  goal3.pose.orientation.x = 0.0 ;
  goal3.pose.orientation.y = 0.0 ;
  goal3.pose.orientation.z = 0.999974267207 ;
  goal3.pose.orientation.w = 0.00717390579975 ;

  pub.publish(goal3);

  ROS_INFO("Goal 3 published!!!!");

  ros::spinOnce();

  while(mbf_smach_status.active_states.back().c_str() == goal_waiting_state)
  {
    if(!ros::ok())
    {
        ros::shutdown();
        return 0;
    }
    ros::spinOnce();
    rate.sleep();
  }

  while(mbf_smach_status.active_states.back().c_str() != goal_waiting_state)
  {
    if(!ros::ok())
    {
        ros::shutdown();
        return 0;
    }
    ros::spinOnce();
    rate.sleep();
  }

  ROS_INFO("Successfully reached goal3!!!");
  ROS_INFO("Total Plan + Execution time(in secs) for Goal 3:%f",(ros::Time::now().toSec() - begin_time));
  begin_time = ros::Time::now().toSec() ;

  count += 1 ;

  goal4.header.seq = count ;
  goal4.header.stamp = ros::Time::now();
  goal4.header.frame_id="map";
  goal4.pose.position.x = 16.6139774323 ;
  goal4.pose.position.y = 0.68413567543 ;
  goal4.pose.position.z = 0.0 ;
  goal4.pose.orientation.x = 0.0 ;
  goal4.pose.orientation.y = 0.0 ;
  goal4.pose.orientation.z = 0.631084431127 ;
  goal4.pose.orientation.w = 0.775714148891 ;

  pub.publish(goal4);

  ROS_INFO("Goal 4 published!!!!");

  ros::spinOnce();

  while(mbf_smach_status.active_states.back().c_str() == goal_waiting_state)
  {
    if(!ros::ok())
    {
        ros::shutdown();
        return 0;
    }
    ros::spinOnce();
    rate.sleep();
  }

  while(mbf_smach_status.active_states.back().c_str() != goal_waiting_state)
  {
    if(!ros::ok())
    {
        ros::shutdown();
        return 0;
    }
    ros::spinOnce();
    rate.sleep();
  }

  ROS_INFO("Successfully reached goal4!!!");
  ROS_INFO("Total Plan + Execution time(in secs) for Goal 4:%f",(ros::Time::now().toSec() - begin_time));

  ros::shutdown();
  return 0;
}