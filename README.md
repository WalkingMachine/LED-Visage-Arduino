# LED-Visage-Arduino

## Instructions :
1. Start serial communication : rosrun rosserial_python serial_node.py _port:=/dev/ttyUSB0  
2. Call the ros service "sara_face/Start" with a Bool set to True.  
3. Publish the emotion on topic "sara_face/Emotion" with a UInt8.   
4. Brightness can be set (0-255) by sending the value on topic "sara_face/Brightness" with a UInt8.  

### Topic : "sara_face/Emotion"
* Type : std_msgs/UInt8
* Value : 1 = smile, 2 = sad, 3 = straight mouth, 4 = angry, 5 = surprise, 6 = blink, 7 = party   

### Topic : "sara_face/Brightness"
* Type : std_msgs/UInt8
* Value : (0-255)

### Service : "sara_face/Start"
* Type : std_msgs/Boolean


