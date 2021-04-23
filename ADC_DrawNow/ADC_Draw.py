import serial, time
from matplotlib import pyplot as plt
from drawnow import *
#initialization and open the port

#possible timeout values:
#    1. None: wait forever, block call
#    2. 0: non-blocking mode, return immediately
#    3. x, x is bigger than 0, float allowed, timeout block call

ser = serial.Serial()
#ser.port = "/dev/ttyUSB0"
ser.port = "com2"
#ser.port = "/dev/ttyS2"
ser.baudrate = 9600
ser.bytesize = serial.EIGHTBITS #number of bits per bytes
ser.parity = serial.PARITY_NONE #set parity check: no parity
ser.stopbits = serial.STOPBITS_ONE #number of stop bits
#ser.timeout = None          #block read
#ser.timeout = 1            #non-block read
ser.timeout = 2              #timeout block read
ser.xonxoff = False     #disable software flow control
ser.rtscts = False     #disable hardware (RTS/CTS) flow control
ser.dsrdtr = False       #disable hardware (DSR/DTR) flow control
ser.writeTimeout = 2     #timeout for write
ser.open()
x=0
adc_array=[]
def ADC_PLOT():
    plt.ylim(0,5)
    plt.plot(adc_array,'r-')
    plt.title('plot ADC Value')
    plt.xlabel('X')
    plt.ylabel('Y')
    plt.grid(1)
'''
for i in range(0,5):
    adc_array.append(x)
'''
#Main Function
while(1):
    while(ser.inWaiting()==0):
        pass
    x=ser.read(1)
    y=hex( int.from_bytes(x, 'big', signed=True) )
    z=int(y,16)
    if (z<=5):
        adc_array.append(z)
        '''
     This instrcution is used for deleting pervous data why???
     for making the curve move not shrink the data 
        '''
        #adc_array.pop(0)
        drawnow(ADC_PLOT)
    else:
        print("error")
