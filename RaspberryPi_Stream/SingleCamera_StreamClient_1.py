#Single source Python stream from Raspberry Pi camera

#This code runs on the second Raspberry Pi
import io
import socket
import struct
import time
import picamera

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect(('#Enter the preffered IP connect address', 8002))
#Serverport different for all different streams

connection = client_socket.makefile('wb1'))

try:
    with picamera.PiCamera() as camera:
        camera.resolution(320,240) #Trying not to stream higher definition
        camera.framerate = 10
        time.sleep(2)
        start = time.time()
        stream= io.BytesIO()

        #Send the video stream in a jpeg format
        for foo in camera.capture_continuous(stream, 'jpeg', use_video_port = True):
            connection.write(struct.pack('L', stream.tell()))
            connection.flush
            stream.seek(0)
            connection.write(stream.read())
            if time.time() - start > 600:
                break
            stream.seek(0)
            stream.truncate()
    connection.write(struct.pack('L', 0))
finally:
    connection.close()
    client_socket.close()
