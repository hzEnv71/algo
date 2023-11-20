
n = int(input())
nums = list(map(int, input().split()))

max_sum = -float('inf')
current_sum = 0

for i in range(n):
    current_sum += nums[i]
    if current_sum > max_sum:
        max_sum = current_sum
    if current_sum < 0:
        current_sum = 0

print(max_sum)
