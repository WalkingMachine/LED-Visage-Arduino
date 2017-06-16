## How to start the face :
1. Call the ros service "sara_face/Start" with a Bool set to True.
2. Publish the emotion on topic "sara_face/emotion" with a UInt8.
    1 = smile, 2 = sad, 3 = straight mouth, 4 = angry, 5 = surprise, 6 = blink, 7 = party
3. Brightness can be set (0-255) by sending the value on topic "sara_face/Brightness" with a UInt8.
