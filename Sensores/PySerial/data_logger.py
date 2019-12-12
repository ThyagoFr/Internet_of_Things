#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Dec 11 20:18:28 2019

@author: thyagofr
"""

import serial
import datetime
import csv

ser = serial.Serial('/dev/ttyUSB0')
ser.flushInput()

with open("data/data.csv",mode="a") as file:
    writer = csv.writer(file)
    while True:
        try:
            ser_bytes = ser.readline()
            decoded_bytes = ser_bytes[0:len(ser_bytes)-2].decode("utf-8").split(",")
            decoded_bytes.append(str(datetime.datetime.now()))
            writer.writerow(decoded_bytes)
        except Exception as error:
            print("Saindo e fechando arquivo...")
            break