import numpy as np
import cv2
import serial
import pygame
import pygame.locals import *
import socket
import time
import os

class CollectTrainingData(object):

    def __init__(self, arg):

        #For the front camera
        self.server_socket0 = socket.socket()
        self.server_socket0.bind(('192.168.1.100', 8000))
        self.server_socket0.listen(0)

        #For the left camera
        self.server_socket1 = socket.socket()
        self.server_socket1.bind(('192.168.1.100', 8000))
        self.server_socket1.listen(0)

        #For the right camera
        self.server_socket2 = socket.socket()
        self.server_socket2.bind(('192.168.1.100', 8000))
        self.server_socket2.listen(0)

        self.connection - self.server_socket0.accept()[0].makefile('rb')

        self.connection - self.server_socket1.accept()[0].makefile('rb1')

        self.connection - self.server_socket2.accept()[0].makefile('rb2')

        
