import time
import serial

if __name__ == '__main__':

    #Initialize Serial comms: Open a serial port to the
    # Arduino device name associated port, with 9600 baud rate
    # (maximum allowable transfer of bits per second), and a read
    # timeout value in seconds
    ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)

    #Flush any bytes that could already be in the input buffer at that point
    ser.reset_input_buffer()

    while True:
        #Check if some data is available
        #if ser.in_waiting > 0:

            #Read bytes until a newline character is detected.
            # Note can decode via utf-8 or ascii to decode data into different
            # formats.
            # rstrip allows us to remove trailing whitespaces/newlines.
            #line = ser.readline().decode('utf-8').rstrip()
            #print(line)

        #Read input from user
        angle = input("Please input an integer in degrees between 0 to +180: ")
        angle = int(angle)
        
        #Write to serial instead
        print("Sending a message ...")
        message = str(angle)
        byteArrOut = bytearray(message,'utf-8')
        ser.write(byteArrOut)
        time.sleep(1)
