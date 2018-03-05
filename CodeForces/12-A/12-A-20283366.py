matrix=[]
for i in range(3):
    matrix.append(input())
def check():
    for i in range(3):
        for j in range(3):
            if matrix[i][j]!=matrix[2-i][2-j]:
                return 0
    return 1
if check():
    print("YES")
else:
    print("NO")