#!/usr/bin/python3
import serial
import csv
import pandas as pd
# Configuración del puerto serie
serial_port = "/dev/ttyACM0"  # Reemplaza con el puerto serie correcto
baudrate = 9600  # Ajusta la velocidad de baudios según corresponda

# Configuración del puerto serie
ser = serial.Serial(serial_port, baudrate)