susic = input()

for i in range(1, len(susic)):
    if susic[i] in ["+", "-", "*", "/"]:
        idx = i
        break
num1_minus = False
num2_minus = False
num1 = susic[:idx]
num2 = susic[idx + 1 :]
if num1[0] == "-":
    num1_minus = True
    num1 = num1[1:]
if num2[0] == "-":
    num2_minus = True
    num2 = num2[1:]

ten_num1 = 0
ten_num2 = 0
for i in range(1, len(num1) + 1):
    ten_num1 += int(num1[-i]) * (8 ** (i - 1))
for i in range(1, len(num2) + 1):
    ten_num2 += int(num2[-i]) * (8 ** (i - 1))

if num1_minus:
    ten_num1 *= -1
if num2_minus:
    ten_num2 *= -1

if susic[idx] == "/" and ten_num2 == 0:
    print("invalid")
else:
    if susic[idx] == "-":
        ten_ans = ten_num1 - ten_num2
    elif susic[idx] == "+":
        ten_ans = ten_num1 + ten_num2
    elif susic[idx] == "*":
        ten_ans = ten_num1 * ten_num2
    else:
        ten_ans = ten_num1 // ten_num2
    ten_ans = str(ten_ans)
    ten_minus = False

    if ten_ans[0] == "-":
        ten_minus = True
        ten_ans = ten_ans[1:]

    ten_ans = int(ten_ans)
    ans = []
    while ten_ans > 0:
        ans.append(str(ten_ans % 8))
        ten_ans = ten_ans // 8
    if ten_minus:
        ans.append("-")
    ans.reverse()
    if not ans:
        print(0)
    else:
        print("".join(ans))
