N = int(input())
lst = []
score_dict = {}
trans_dict = {}
trans_lst = []
for _ in range(N):
    word = input()
    lst.append(word)
    for i in range(len(word)):
        if score_dict.get(word[i]):
            score_dict[word[i]] += 10 ** (len(word) - i - 1)
        else:
            score_dict[word[i]] = 10 ** (len(word) - i - 1)
for k, v in score_dict.items():
    trans_lst.append((v, k))
trans_lst.sort(reverse=True)
num = 9
for _, k in trans_lst:
    trans_dict[k] = num
    num -= 1

ans = 0
for word in lst:
    for i in range(len(word)):
        ans += trans_dict[word[i]] * (10 ** (len(word) - i - 1))
print(ans)
