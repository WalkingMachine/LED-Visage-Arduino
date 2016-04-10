# LED-VIsage-Arduino

Pour activer la communication seriel:
rosrun rosserial_python serial_node.py

Pour créé le publisher pour parler au arduino:
self.pubEmo = rospy.Publisher('/control_emo', UInt8, latch=True)
