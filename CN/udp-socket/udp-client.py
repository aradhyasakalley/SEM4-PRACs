import socket 

sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

HOST = "127.0.0.1"
PORT = 12345


msg = "hello"
sock.sendto(msg.encode(),(HOST,PORT))

response,addr = sock.recvfrom(1024)

print(f'received response from server : {response.decode()}')

print('client closed')