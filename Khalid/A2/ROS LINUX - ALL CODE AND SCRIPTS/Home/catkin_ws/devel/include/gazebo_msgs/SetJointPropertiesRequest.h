// Generated by gencpp from file gazebo_msgs/SetJointPropertiesRequest.msg
// DO NOT EDIT!


#ifndef GAZEBO_MSGS_MESSAGE_SETJOINTPROPERTIESREQUEST_H
#define GAZEBO_MSGS_MESSAGE_SETJOINTPROPERTIESREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <gazebo_msgs/ODEJointProperties.h>

namespace gazebo_msgs
{
template <class ContainerAllocator>
struct SetJointPropertiesRequest_
{
  typedef SetJointPropertiesRequest_<ContainerAllocator> Type;

  SetJointPropertiesRequest_()
    : joint_name()
    , ode_joint_config()  {
    }
  SetJointPropertiesRequest_(const ContainerAllocator& _alloc)
    : joint_name(_alloc)
    , ode_joint_config(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _joint_name_type;
  _joint_name_type joint_name;

   typedef  ::gazebo_msgs::ODEJointProperties_<ContainerAllocator>  _ode_joint_config_type;
  _ode_joint_config_type ode_joint_config;




  typedef boost::shared_ptr< ::gazebo_msgs::SetJointPropertiesRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::gazebo_msgs::SetJointPropertiesRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SetJointPropertiesRequest_

typedef ::gazebo_msgs::SetJointPropertiesRequest_<std::allocator<void> > SetJointPropertiesRequest;

typedef boost::shared_ptr< ::gazebo_msgs::SetJointPropertiesRequest > SetJointPropertiesRequestPtr;
typedef boost::shared_ptr< ::gazebo_msgs::SetJointPropertiesRequest const> SetJointPropertiesRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::gazebo_msgs::SetJointPropertiesRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::gazebo_msgs::SetJointPropertiesRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace gazebo_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'trajectory_msgs': ['/opt/ros/kinetic/share/trajectory_msgs/cmake/../msg'], 'gazebo_msgs': ['/home/parallels/catkin_ws/src/gazebo_ros_pkgs/gazebo_msgs/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::gazebo_msgs::SetJointPropertiesRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::gazebo_msgs::SetJointPropertiesRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::gazebo_msgs::SetJointPropertiesRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::gazebo_msgs::SetJointPropertiesRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::gazebo_msgs::SetJointPropertiesRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::gazebo_msgs::SetJointPropertiesRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::gazebo_msgs::SetJointPropertiesRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "331fd8f35fd27e3c1421175590258e26";
  }

  static const char* value(const ::gazebo_msgs::SetJointPropertiesRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x331fd8f35fd27e3cULL;
  static const uint64_t static_value2 = 0x1421175590258e26ULL;
};

template<class ContainerAllocator>
struct DataType< ::gazebo_msgs::SetJointPropertiesRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "gazebo_msgs/SetJointPropertiesRequest";
  }

  static const char* value(const ::gazebo_msgs::SetJointPropertiesRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::gazebo_msgs::SetJointPropertiesRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string joint_name\n\
gazebo_msgs/ODEJointProperties ode_joint_config\n\
\n\
================================================================================\n\
MSG: gazebo_msgs/ODEJointProperties\n\
# access to low level joint properties, change these at your own risk\n\
float64[] damping             # joint damping\n\
float64[] hiStop              # joint limit\n\
float64[] loStop              # joint limit\n\
float64[] erp                 # set joint erp\n\
float64[] cfm                 # set joint cfm\n\
float64[] stop_erp            # set joint erp for joint limit \"contact\" joint\n\
float64[] stop_cfm            # set joint cfm for joint limit \"contact\" joint\n\
float64[] fudge_factor        # joint fudge_factor applied at limits, see ODE manual for info.\n\
float64[] fmax                # ode joint param fmax\n\
float64[] vel                 # ode joint param vel\n\
";
  }

  static const char* value(const ::gazebo_msgs::SetJointPropertiesRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::gazebo_msgs::SetJointPropertiesRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.joint_name);
      stream.next(m.ode_joint_config);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SetJointPropertiesRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::gazebo_msgs::SetJointPropertiesRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::gazebo_msgs::SetJointPropertiesRequest_<ContainerAllocator>& v)
  {
    s << indent << "joint_name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.joint_name);
    s << indent << "ode_joint_config: ";
    s << std::endl;
    Printer< ::gazebo_msgs::ODEJointProperties_<ContainerAllocator> >::stream(s, indent + "  ", v.ode_joint_config);
  }
};

} // namespace message_operations
} // namespace ros

#endif // GAZEBO_MSGS_MESSAGE_SETJOINTPROPERTIESREQUEST_H
