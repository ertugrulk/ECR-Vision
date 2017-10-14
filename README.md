# ECR-Vision Development
## Overveiw
This repository contains all the current code examples and development made so far in ECR's vision processing code for the 2017-2018 FRC off-season.

NOTE: All C++ projects have been compiled in Visual Studio 2017


### Needed Libaries
To run this code you will need the 


## Camera Calibration 
The purpose of this class is to generate a file that contains the needed data to reverse distortion on an image taken by a specific camera. This program will not be included in any robot vision programs but the file that it generates will be. 

### Things that still need to be done to this project
- [x] Added the main class
- [x] Reads XML settings file and get calibration numbers
- [x] Outputs to XML file
- [x] Remove bad practice `using namespace std`
- [ ] Remove bad practice `using namespace cv`
- [ ] Put Settings class in a separate file
