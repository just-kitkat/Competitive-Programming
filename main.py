import sys
sys.set_int_max_str_digits(1247819248)
for i in "123456789":
    import math
    i=i*math.factorial(6)
    print(all([int(i)%x==0 for x in (3,7,9)] or i=='5'))