from socket import *
import random

serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(('', 12000))

# ��ǻ�ͳ�Ʈ��ŷ

print("Started UDP server on port 12000")

while True:
    rand = random.randint(0, 10)
    message, address = serverSocket.recvfrom(1024)
    message = message.upper()
    if rand < 4:
        continue
    # UDPPinger
    serverSocket.sendto(message, address)