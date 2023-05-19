import socket

HOST = "127.0.0.1"
PORT = 1234

with socket.socket(socket.AF_INET,socket.SOCK_STREAM) as client_socket : 
    client_socket.connect((HOST,PORT))
    message = "hello from client side..."
    client_socket.sendall(message.encode())
    response = client_socket.recv(1024)
    print(f'message received from server : {response.decode()}')
    
