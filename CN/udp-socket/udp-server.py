import socket 

HOST = "127.0.0.1"
PORT = 12345

sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

sock.bind((HOST,PORT))
print("waiting for client....")

while True : 
    data,addr = sock.recvfrom(1024)
    print(f'message received from client : {data.decode()} from {addr}')
    response = "message received"
    sock.sendto(response.encode(),addr)
    

print("server closed")
