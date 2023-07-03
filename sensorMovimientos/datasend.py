#!/usr/bin/python3
import serial
import csv
import pandas as pd
# Configuración del puerto serie
serial_port = "/dev/ttyACM0"  # Reemplaza con el puerto serie correcto
baudrate = 9600  # Ajusta la velocidad de baudios según corresponda

# Configuración del puerto serie
ser = serial.Serial(serial_port, baudrate)

datos = []
encabezado = ["Prueba", "Eje x", "Eje y", "Eje z"]
datos.append(encabezado)
try:
    while True:
        # Ejemplo de línea recibida: "123 456 789"
        x = ser.readline(32).decode('utf-8')
        
        y = x.split('\t')
        
        datos_float = [int(y[0]), float(y[1]), float(y[2]), float(y[3])]
        
        datos.append(datos_float)
        
        # Dividir la línea en partes separadas por espacios
        # Verificar si se recibieron los tres valores esperados


except KeyboardInterrupt:
    print("\nInterrupción de Programa debido al usuario.")

finally:
    print(datos)
    ser.close()
    # Cerrar la conexión serial y desconectarse del broker MQTT al terminar
    with open('Golpe.csv', mode='w', newline='') as archivo_csv:
        writer = csv.writer(archivo_csv)
        writer.writerows(datos)