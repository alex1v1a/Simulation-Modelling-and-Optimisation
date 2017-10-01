// Generated by gencpp from file gazebo_msgs/SetPhysicsPropertiesResponse.msg
// DO NOT EDIT!


#ifndef GAZEBO_MSGS_MESSAGE_SETPHYSICSPROPERTIESRESPONSE_H
#define GAZEBO_MSGS_MESSAGE_SETPHYSICSPROPERTIESRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace gazebo_msgs
{
template <class ContainerAllocator>
struct SetPhysicsPropertiesResponse_
{
  typedef SetPhysicsPropertiesResponse_<ContainerAllocator> Type;

  SetPhysicsPropertiesResponse_()
    : success(false)
    , status_message()  {
    }
  SetPhysicsPropertiesResponse_(const ContainerAllocator& _alloc)
    : success(false)
    , status_message(_alloc)  {
  (void)_alloc;
    }



   typedef uint8_t _success_type;
  _success_type success;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _status_message_type;
  _status_message_type status_message;




  typedef boost::shared_ptr< ::gazebo_msgs::SetPhysicsPropertiesResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::gazebo_msgs::SetPhysicsPropertiesResponse_<ContainerAllocator> const> ConstPtr;

}; // struct SetPhysicsPropertiesResponse_

typedef ::gazebo_msgs::SetPhysicsPropertiesResponse_<std::allocator<void> > SetPhysicsPropertiesResponse;

typedef boost::shared_ptr< ::gazebo_msgs::SetPhysicsPropertiesResponse > SetPhysicsPropertiesResponsePtr;
typedef boost::shared_ptr< ::gazebo_msgs::SetPhysicsPropertiesResponse const> SetPhysicsPropertiesResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::gazebo_msgs::SetPhysicsPropertiesResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::gazebo_msgs::SetPhysicsPropertiesResponse_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::gazebo_msgs::SetPhysicsPropertiesResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::gazebo_msgs::SetPhysicsPropertiesResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::gazebo_msgs::SetPhysicsPropertiesResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::gazebo_msgs::SetPhysicsPropertiesResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::gazebo_msgs::SetPhysicsPropertiesResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::gazebo_msgs::SetPhysicsPropertiesResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::gazebo_msgs::SetPhysicsPropertiesResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2ec6f3eff0161f4257b808b12bc830c2";
  }

  static const char* value(const ::gazebo_msgs::SetPhysicsPropertiesResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2ec6f3eff0161f42ULL;
  static const uint64_t static_value2 = 0x57b808b12bc830c2ULL;
};

template<class ContainerAllocator>
struct DataType< ::gazebo_msgs::SetPhysicsPropertiesResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "gazebo_msgs/SetPhysicsPropertiesResponse";
  }

  static const char* value(const ::gazebo_msgs::SetPhysicsPropertiesResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::gazebo_msgs::SetPhysicsPropertiesResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool success\n\
string status_message\n\
\n\
";
  }

  static const char* value(const ::gazebo_msgs::SetPhysicsPropertiesResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::gazebo_msgs::SetPhysicsPropertiesResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.success);
      stream.next(m.status_message);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SetPhysicsPropertiesResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::gazebo_msgs::SetPhysicsPropertiesResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::gazebo_msgs::SetPhysicsPropertiesResponse_<ContainerAllocator>& v)
  {
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
    s << indent << "status_message: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.status_message);
  }
};

} // namespace message_operations
} // namespace ros

#endif // GAZEBO_MSGS_MESSAGE_SETPHYSICSPROPERTIESRESPONSE_H
