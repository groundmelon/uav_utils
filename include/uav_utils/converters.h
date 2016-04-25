#ifndef __UAVUTILS_CONVERTERS_H
#define __UAVUTILS_CONVERTERS_H

#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Quaternion.h>

#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>
#include <cmath>

namespace uav_utils {
void extract_odometry(nav_msgs::OdometryConstPtr msg, Eigen::Vector3d& p, Eigen::Vector3d& v,
                      Eigen::Quaterniond& q, Eigen::Vector3d& w);
void extract_odometry(nav_msgs::OdometryConstPtr msg, Eigen::Vector3d& p, Eigen::Vector3d& v,
                      Eigen::Quaterniond& q);

template <typename Scalar_t = double>
Eigen::Matrix<Scalar_t, 3, 1> from_vector3_msg(const geometry_msgs::Vector3& msg) {
    return Eigen::Matrix<Scalar_t, 3, 1>(msg.x, msg.y, msg.z);
}

template <typename Derived>
geometry_msgs::Vector3 to_vector3_msg(const Eigen::DenseBase<Derived>& v) {
	EIGEN_STATIC_ASSERT_FIXED_SIZE(Derived);
    EIGEN_STATIC_ASSERT(Derived::RowsAtCompileTime == 3, THIS_METHOD_IS_ONLY_FOR_MATRICES_OF_A_SPECIFIC_SIZE);
    EIGEN_STATIC_ASSERT(Derived::ColsAtCompileTime == 1, THIS_METHOD_IS_ONLY_FOR_MATRICES_OF_A_SPECIFIC_SIZE);

    geometry_msgs::Vector3 msg;
    msg.x = v.x();
    msg.y = v.y();
    msg.z = v.z();
    return msg;
}

template <typename Scalar_t = double>
Eigen::Matrix<Scalar_t, 3, 1> from_point_msg(const geometry_msgs::Point& msg) {
    return Eigen::Matrix<Scalar_t, 3, 1>(msg.x, msg.y, msg.z);
}

template <typename Derived>
geometry_msgs::Point to_point_msg(const Eigen::DenseBase<Derived>& v) {
	EIGEN_STATIC_ASSERT_FIXED_SIZE(Derived);
    EIGEN_STATIC_ASSERT(Derived::RowsAtCompileTime == 3, THIS_METHOD_IS_ONLY_FOR_MATRICES_OF_A_SPECIFIC_SIZE);
    EIGEN_STATIC_ASSERT(Derived::ColsAtCompileTime == 1, THIS_METHOD_IS_ONLY_FOR_MATRICES_OF_A_SPECIFIC_SIZE);
    
    geometry_msgs::Point msg;
    msg.x = v.x();
    msg.y = v.y();
    msg.z = v.z();
    return msg;
}

template <typename Scalar_t = double>
Eigen::Quaternion<Scalar_t> from_quaternion_msg(const geometry_msgs::Quaternion& msg) {
    return Eigen::Quaternion<Scalar_t>(msg.w, msg.x, msg.y, msg.z);
}

template <typename Scalar_t>
geometry_msgs::Quaternion to_quaternion_msg(const Eigen::Quaternion<Scalar_t>& q) {
    geometry_msgs::Quaternion msg;
    msg.x = q.x();
    msg.y = q.y();
    msg.z = q.z();
    msg.w = q.w();
    return msg;
}
}

#endif