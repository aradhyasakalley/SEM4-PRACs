data = input('Enter the data to be stuffed: ')
frame = list(data)
stuffed_data = []

count = 0

for bit in frame:
    if bit == '1':
        count += 1
        if count == 5:
            stuffed_data.append('0')
            count = 0
    else:
        count = 0

    stuffed_data.append(bit)

output = '01111110' + ''.join(stuffed_data) + '01111110'
print("The stuffed data is:", output)


data = input("Enter the data : ").replace('01111110','')
arr = list(data)
orig = []
count = 0;

for bit in arr :
    if count == 5 and bit == '1' :
        count = 0
        continue


    orig.append(bit)
    if bit == '1':
        count = count +1
    else :
        count = 0
    

print("the original data is : ",''.join(orig))