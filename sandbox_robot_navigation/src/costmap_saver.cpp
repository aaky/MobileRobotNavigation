#include <ros/ros.h>
#include <iostream>
//#include <move_base_msgs/MoveBaseAction.h>
//#include <actionlib/client/simple_action_client.h>

// #include <catkin_costmap_test/t.h>
#include <costmap_2d/costmap_2d.h>
#include <costmap_2d/costmap_2d_ros.h>

#include <nav_msgs/GridCells.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//
#define REFRESHING_FREQ (0.5f) // [s]
//

class LocalGoalPlanner
{
public:
    LocalGoalPlanner()
        :m_Handle("LocalGoalPlanner"),
        m_tf(),
        m_CostmapRos("local_costmap", m_tf)
    {
        m_CostmapRos.stop();
        m_Costmap = m_CostmapRos.getCostmap();
        //m_subObstacles=m_Handle.subscribe("/move_base_node/global_costmap/obstacles", 100, &LocalGoalPlanner::CostmapCallback, this);
        cv::namedWindow( "Costmap", cv::WINDOW_AUTOSIZE );

        //do odświeżania mapy
        m_Timer= m_Handle.createTimer(ros::Duration(REFRESHING_FREQ), boost::bind(&LocalGoalPlanner::OnTimeout ,this));

        m_CostmapRos.stop();
        m_CostmapRos.updateMap();
        m_CostmapRos.start();
    }
    void ReadManualy(){
        m_CostmapRos.updateMap();
        m_Costmap = m_CostmapRos.getCostmap();
        int max_x=m_Costmap->getSizeInCellsX();
        int max_y=m_Costmap->getSizeInCellsY();
        for(int x=0; x<max_x; x++){
            for(int y=0; y<max_y; y++){
                std::cout<<(int)m_Costmap->getCost(x,y)<<" ";
            }
            std::cout<<std::endl;

            std::cout<<std::endl;
        }
        std::cout<<std::endl;
        
        std::cout<<std::endl;
    }
    void PrintCostmap(){
        m_CostmapRos.updateMap();
        m_Costmap = m_CostmapRos.getCostmap();
        m_MatCostmap = cv::Mat(m_Costmap->getSizeInCellsX(), m_Costmap->getSizeInCellsY(),CV_8UC1, (unsigned char*)m_Costmap->getCharMap() );
        cv::imshow("Costmap", m_MatCostmap);
        cv::waitKey(5);
    }

private:
    tf::TransformListener           m_tf;
    costmap_2d::Costmap2D*           m_Costmap;
    costmap_2d::Costmap2DROS        m_CostmapRos;
    ros::NodeHandle                 m_Handle;
    ros::Subscriber                 m_subObstacles;
    nav_msgs::GridCellsConstPtr     m_CurrentObstacles;
    cv::Mat                         m_MatCostmap;
    ros::Timer                      m_Timer;

    void OnTimeout(){
        PrintCostmap();
        //ReadManualy();
    }
};

int main(int argc, char** argv){
    ros::init(argc, argv, "my_costmap");
    LocalGoalPlanner x;

    ros::spin();
    return 0;
}
