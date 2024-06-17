# def twoSum(nums, target):
#     result = list()

#     for i in range(len(nums)-1):
#         for j in range(1, len(nums[i:])):
#             if nums[i] + nums[i+j] == target:
#                 result.append(i)
#                 result.append(i+j)
#                 return result

def twoSum(nums, target):
    result = list()

    numbers = {k:v for v, k in enumerate(nums)}
    for i in range(len(nums)-1):
        diff = target - nums[i]
        if diff in numbers.keys() and numbers[diff] != i:
            result.append(i)
            result.append(numbers[diff])
            return result

print(twoSum([3,2,4], 6))