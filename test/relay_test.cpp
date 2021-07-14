#include <gtest/gtest.h>

#include <ros/ros.h>

#include <std_msgs/Byte.h>

class RelayTest : public testing::Test
{
};

TEST_F(RelayTest, basicTest)
{
    ros::NodeHandle nh;
    ros::Publisher command_pub = nh.advertise<std_msgs::Byte>("/relay_cmd", 1);
    ros::Duration(2).sleep();
    ros::spinOnce();

    for (size_t i = 0; i < 16; i++)
    {
        std_msgs::Byte relay_cmd;
        relay_cmd.data = i;

        std::cout << i << std::endl;

        command_pub.publish(relay_cmd);
        ros::spinOnce();

        ros::Duration(0.2).sleep();
    }

    ASSERT_TRUE(true);
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "relay_test");
    ros::NodeHandle nh;

    ros::AsyncSpinner spinner{1};
    spinner.start();

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
