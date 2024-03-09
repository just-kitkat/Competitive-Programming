"""
low, high, number_of_elements, total = 10000000, -5, 0, 0
while True:
    number = input(\"""
Enter a positive integer 
(enter a negative integer if there are no more integers in the list): 
\""")
    number = int(number)
    if number < 0:
        break
    low = min(low, number)
    high = max(high, number)
    number_of_elements += 1
    total += number

average = round(total / number_of_elements, 1)

print("The minimum value is {}".format(low))
print("The maximum value is {}".format(high))
print("The average value is {}".format(average))

# Alternative
nums = []
while True:
    number = input(\"""
Enter a positive integer 
(enter a negative integer if there are no more integers in the list): 
\""")
    number = int(number)
    if number < 0:
        break
    nums.append(number)

average = round(sum(nums) / len(nums), 1)

print("The minimum value is {}".format(min(nums)))
print("The maximum value is {}".format(max(nums)))
print("The average value is {}".format(average))
"""

# Q4
def find_winner(grid):
    score_a, score_b = 0, 0
    for row in grid:
        score_b += max(row)
    for col_num in range(len(grid[0])):
        col = []
        for row in grid:
            col.append(row[col_num])
        score_a += max(col)
    if score_a == score_b: 
        return "It is a draw"
    if score_a > score_b: 
        return "Player A wins"
    else: 
        return "Player B wins"
# print(find_winner([ [10,2,5], [25,4,4], [9,3,2] ]))
    
# Q2
def get_grade(grades, grade):
    possible_grades = ["Distinction", "Merit", "Pass"]
    ans = "Fail"
    for cutoff in grades:
        if grade >= cutoff:
            ans = possible_grades[0]
            break
        else:
            possible_grades.pop(0)
    return "Henry attained a \"{}\" grade.".format(ans)
# print(get_grade([75, 65, 50], 80))

# Q3
def calculate_parity(data, parity):
    num_of_ones = data.count("1")
    if parity == "even":
        return str(num_of_ones % 2) + data
    if parity == "odd":
        return str((num_of_ones + 1) % 2) + data

print(calculate_parity("0110101", "odd"))
print(calculate_parity("0110101", "even"))