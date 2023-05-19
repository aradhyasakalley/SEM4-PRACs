#sender side code 

num = int(input('enter the number of frames in the data'))
data_units = []

for i in range(num):
    data_unit = input('enter the data unit {}:'.format(i+1))
    data_units.append(data_unit)

result = ''
for data_unit in data_units : 
    length = len(data_unit) + 1
    result+= str(length) + data_unit

print('data to be sent is : ',result)



#reciever side 

frame = input('enter the data frame : ')
decoded = []

while frame : 
    length = int(frame[0]) - 1
    decoded = frame[1:length+1]
    frame = frame[length+1:]

print('the decoded frame is : ')
for data_unit in decoded :
    print(data_unit) 



