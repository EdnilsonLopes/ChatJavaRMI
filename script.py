#!/usr/bin/python
# -*- coding: iso-8859-1 -*-
import serial
comport = serial.Serial('COM4', 115200)
print 'Serial Iniciada...\n'

import mysql.connector
cnx = mysql.connector.connect(
    user='root', password='admin', host='localhost', database='sensores')
cursor = cnx.cursor()
add_sinais = (
    "INSERT INTO tb_sensores (val_sensor1, val_sensor2, val_sensor3,val_sensor4, val_sensor5, val_sensor6)VALUES (%s, %s, %s, %s, %s, %s)")
delete_sinais = ("DELETE FROM tb_sensores")
exe = 0
while (True):
    exe += 1
    serialValue = comport.readline()
    comport.write("Estou Aqui...")
    data_sinais = serialValue.split("|")
    print data_sinais
    cursor.execute(add_sinais, data_sinais)
    cnx.commit()
    

cursor.close()
cnx.close()
comport.close()
