import socket
import time

UDP_IP = "192.168.0.103"
UDP_PORT = 555
MESSAGE_ON = "Led3_ON".encode()
MESSAGE_OFF = "Led3_OFF".encode()

socket = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
while(True):
	socket.sendto(MESSAGE_ON,(UDP_IP,UDP_PORT))
	time.sleep(2)
	socket.sendto(MESSAGE_OFF,(UDP_IP,UDP_PORT))
	time.sleep(2)

