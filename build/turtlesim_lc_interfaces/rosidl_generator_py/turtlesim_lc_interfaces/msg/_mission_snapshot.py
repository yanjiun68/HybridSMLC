# generated from rosidl_generator_py/resource/_idl.py.em
# with input from turtlesim_lc_interfaces:msg/MissionSnapshot.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MissionSnapshot(type):
    """Metaclass of message 'MissionSnapshot'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('turtlesim_lc_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'turtlesim_lc_interfaces.msg.MissionSnapshot')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__mission_snapshot
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__mission_snapshot
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__mission_snapshot
            cls._TYPE_SUPPORT = module.type_support_msg__msg__mission_snapshot
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__mission_snapshot

            from geometry_msgs.msg import Twist
            if Twist.__class__._TYPE_SUPPORT is None:
                Twist.__class__.__import_type_support__()

            from geometry_msgs.msg import Vector3
            if Vector3.__class__._TYPE_SUPPORT is None:
                Vector3.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MissionSnapshot(metaclass=Metaclass_MissionSnapshot):
    """Message class 'MissionSnapshot'."""

    __slots__ = [
        '_header',
        '_cmd_vel',
        '_trajectory_vector',
        '_completed_laps',
        '_current_side',
        '_phase',
        '_status',
        '_mission_done',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'cmd_vel': 'geometry_msgs/Twist',
        'trajectory_vector': 'geometry_msgs/Vector3',
        'completed_laps': 'uint32',
        'current_side': 'uint32',
        'phase': 'string',
        'status': 'string',
        'mission_done': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Twist'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        from geometry_msgs.msg import Twist
        self.cmd_vel = kwargs.get('cmd_vel', Twist())
        from geometry_msgs.msg import Vector3
        self.trajectory_vector = kwargs.get('trajectory_vector', Vector3())
        self.completed_laps = kwargs.get('completed_laps', int())
        self.current_side = kwargs.get('current_side', int())
        self.phase = kwargs.get('phase', str())
        self.status = kwargs.get('status', str())
        self.mission_done = kwargs.get('mission_done', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.cmd_vel != other.cmd_vel:
            return False
        if self.trajectory_vector != other.trajectory_vector:
            return False
        if self.completed_laps != other.completed_laps:
            return False
        if self.current_side != other.current_side:
            return False
        if self.phase != other.phase:
            return False
        if self.status != other.status:
            return False
        if self.mission_done != other.mission_done:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def cmd_vel(self):
        """Message field 'cmd_vel'."""
        return self._cmd_vel

    @cmd_vel.setter
    def cmd_vel(self, value):
        if __debug__:
            from geometry_msgs.msg import Twist
            assert \
                isinstance(value, Twist), \
                "The 'cmd_vel' field must be a sub message of type 'Twist'"
        self._cmd_vel = value

    @builtins.property
    def trajectory_vector(self):
        """Message field 'trajectory_vector'."""
        return self._trajectory_vector

    @trajectory_vector.setter
    def trajectory_vector(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'trajectory_vector' field must be a sub message of type 'Vector3'"
        self._trajectory_vector = value

    @builtins.property
    def completed_laps(self):
        """Message field 'completed_laps'."""
        return self._completed_laps

    @completed_laps.setter
    def completed_laps(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'completed_laps' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'completed_laps' field must be an unsigned integer in [0, 4294967295]"
        self._completed_laps = value

    @builtins.property
    def current_side(self):
        """Message field 'current_side'."""
        return self._current_side

    @current_side.setter
    def current_side(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'current_side' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'current_side' field must be an unsigned integer in [0, 4294967295]"
        self._current_side = value

    @builtins.property
    def phase(self):
        """Message field 'phase'."""
        return self._phase

    @phase.setter
    def phase(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'phase' field must be of type 'str'"
        self._phase = value

    @builtins.property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'status' field must be of type 'str'"
        self._status = value

    @builtins.property
    def mission_done(self):
        """Message field 'mission_done'."""
        return self._mission_done

    @mission_done.setter
    def mission_done(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'mission_done' field must be of type 'bool'"
        self._mission_done = value
