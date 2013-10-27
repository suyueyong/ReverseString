============================================
<ReverseStringTest.cpp> is the test main file

<UnitTestBase.h> is the unit test base class

<ReverseStringClass.cpp> and <ReverseStringClass.h> is the code to be tested

============================================
In Windows visual studio evironment, just add all the 4 files into a win32 Console project, then can compile and run it.
============================================
In Linux using g++, the compile command is: g++ ReverseStringTest.cpp ReverseStringClass.cpp -o ReverseStringTest
Then use command ./ReverseStringTest to run it