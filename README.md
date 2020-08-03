# OzEngine
Second iteration of the Oz Engine, using new techniques learnt since uni 

Usage of precompiled headers are supported but have to be manually implemented due to technical limitations of cmake.

1. Create a folder in the directory called "build"
2. Build cmake by using the source folder directory (OzEngine) and output as "build"
3. Load "OzEngine.sln" edit properties of the OzEngine solution
4. Under C/C++ tab go to Precompiled Headers, select Use
5. Set the precompiled header file to "ozpch.h" and apply
