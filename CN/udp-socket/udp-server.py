import socket 

HOST = "127.0.0.1"
PORT = 12345

sock= socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

sock.bind((HOST,PORT))

print("waiting for client..")

while True : 
    data,addr = sock.recvfrom(1024)
    print(f'received message: {data.decode()} from {addr}')
    response = "message was received"
    sock.sendto(response.encode(),addr)

