import speech_recognition as sr
import bluetooth

# Look for the HC-05 with default name        
device_name = "HC-05"
recognizer = sr.Recognizer()
microphone = sr.Microphone()

responses = {
"forward": "Forward",
"forwards": "Forward",
"backward": "Backward",
"left": "Left",
"lift": "Left",
"right": "Right",
"stop": "Stop",
}
        
# Discover nearby Bluetooth devices       
nearby_devices = bluetooth.discover_devices()
print(nearby_devices)
            
# Find the HC-05 device      
target_device = None
for d in nearby_devices:
    if device_name in  bluetooth.lookup_name(d):
        target_device = d
        break

             
# Connect to the HC-05                       
sock = bluetooth.BluetoothSocket( bluetooth.RFCOMM )        
sock.connect((target_device, 1))

            



while True:
  # Send data over Bluetooth to Arduino   
    try: 
        # Listen for a command
        print("Listening for a command...")
        with microphone as source: 
            recognizer.adjust_for_ambient_noise(source)
            audio = recognizer.listen(source)
    
        # Recognize the command using Google Speech Recognition
        response = recognizer.recognize_google(audio)
        response = response.lower()
    
        # Check if the command is in the dictionary
        if response in responses: 
            # Send data           
            if(response=="forward"):
                 sock.send("f")
            elif(response=="backward"):
                 sock.send("b")
            elif(response=="left"):
              sock.send("l")
            elif(response=="right"):
                sock.send("r")
            elif(response=="stop"):
                sock.send("s")

            
            print(f"Command: {response}")
            print(f"Response: {responses[response]}")
    
        else: 
            print(f"I did not recognize the command {response}")
    
    # Catch any errors 
    except sr.RequestError as e:
        print("Could not request results from Google Speech Recognition service; {0}".format(e))
    
    except sr.UnknownValueError:
        print("Speech was unintelligible")
  




#data = sock.recv(1024)
#print(data)        
            
# Close the connection        
sock.close()









  # Read any data sent from Arduino over Bluetooth
 # data = bluetooth.read()
 # print(data)



    
    
