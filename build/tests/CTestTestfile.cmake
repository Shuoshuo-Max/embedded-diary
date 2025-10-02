# CMake generated Testfile for 
# Source directory: C:/Users/21190/Desktop/embed/embedded-diary/tests
# Build directory: C:/Users/21190/Desktop/embed/embedded-diary/build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(RingQueueTests "C:/Users/21190/Desktop/embed/embedded-diary/build/tests/Debug/RingQueueTests.exe")
  set_tests_properties(RingQueueTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/21190/Desktop/embed/embedded-diary/tests/CMakeLists.txt;9;add_test;C:/Users/21190/Desktop/embed/embedded-diary/tests/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(RingQueueTests "C:/Users/21190/Desktop/embed/embedded-diary/build/tests/Release/RingQueueTests.exe")
  set_tests_properties(RingQueueTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/21190/Desktop/embed/embedded-diary/tests/CMakeLists.txt;9;add_test;C:/Users/21190/Desktop/embed/embedded-diary/tests/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(RingQueueTests "C:/Users/21190/Desktop/embed/embedded-diary/build/tests/MinSizeRel/RingQueueTests.exe")
  set_tests_properties(RingQueueTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/21190/Desktop/embed/embedded-diary/tests/CMakeLists.txt;9;add_test;C:/Users/21190/Desktop/embed/embedded-diary/tests/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(RingQueueTests "C:/Users/21190/Desktop/embed/embedded-diary/build/tests/RelWithDebInfo/RingQueueTests.exe")
  set_tests_properties(RingQueueTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/21190/Desktop/embed/embedded-diary/tests/CMakeLists.txt;9;add_test;C:/Users/21190/Desktop/embed/embedded-diary/tests/CMakeLists.txt;0;")
else()
  add_test(RingQueueTests NOT_AVAILABLE)
endif()
