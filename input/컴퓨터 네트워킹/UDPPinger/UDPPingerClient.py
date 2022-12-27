import socket
import time

Socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
ServerAddress = ("localhost", 12000)
Socket.settimeout(1)

try:
    for i in range(1, 11):
        start = time.time()
        message = "Ping SN_" + str(i) + " | TIME : " + time.ctime(start)
        try:
            sent = Socket.sendto(message.encode(), ServerAddress)
            print("<SEND>\n " + message)
            data, server = Socket.recvfrom(4096)
            print("<RECIEVE>\n " + data.decode())
            end = time.time()
            elapsed = end - start
            print(" - RTT : " + str(elapsed) + "/s\n")
        except socket.timeout:
            print("<RECIEVE>\n Ping SN_" + str(i) + " --> Requested timed out\n")

# UDPPinger ÄÄ³×

finally:
    Socket.close()
    print("------------ Socket Server Close ------------\n\n")