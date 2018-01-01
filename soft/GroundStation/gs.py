import serial
import time
import datetime

ser = serial.Serial('COM32', 9600)

name = 'data_' + str(time.time())


while True:
    f = open(name, 'a')
    line = ser.readline()
    f.write(line.strip())
    splitted = line.split(",")
    print float(splitted[0])/10000000.0, float(splitted[1])/10000000.0, float(splitted[2])/100.0
    print splitted[3:]
    fhtml = open('map.html', 'w')
    text = "<iframe width=\"1000\" height=\"700\" src=\"http://maps.google.com/maps?q=" + str(float(splitted[0])/10000000.0) + "," + str(float(splitted[1])/10000000.0) + "&z=15&output=embed\"></iframe>"
    fhtml.write(text)
    fhtml.close()
    f.close()
