file = open("C3.csv", mode="r")
file_new = open("C3out.csv", mode="w")
file_n1=  open("C3toan.inp", mode="w")
header = file.readline()
header= header.strip() + ", Diem TB, Hoc luc, GPA" + "\n"
file_new.write(header)
i = int(1)
while (1!=2):
    row = file.readline()
    if (row==""):
        break
    row_list = row.split(",")
    row_list[0] = str(i)
    i = i+1
    ave = 0
    for i in range(4, 12):
        ave = ave + float(row_list[i])
    ave = ave/9
    GPA = round(ave/10*4,2)
    ave = round(ave, 1)
    if (ave < 5):
        rank = "Yeu"
    if (ave >= 5 and ave < 6.5):
        rank = "trung Binh"
    if (ave >= 6.5 and ave < 8):
        rank = "kha"
    if (ave >= 8):
        rank = "Gioi"
    if (float(row_list[5])>=7 and float(row_list[5])<8):
        file_n1.write(row_list[2].strip()+ "\n")
    row_list = row.strip() + ", " +str(ave) + ", " + rank + ", " +str(GPA) + "\n" 
    file_new.write(row_list)
    


