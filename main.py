def flatten(lst):
    """
    Flattens a list using recursion

    Arguments
    --------------
    lst: Any

    Return
    --------------
    Any
    """
    if type(lst)!=list:
        return lst
    res = []
    for i in lst:
        x = flatten(i)
        if type(x) == list:
            res.extend(x)
        else:
            res.extend([x])
    return res

testcase = [
    1, 2, 3, [4, [5, 6, 7], 8], [9, "9"], "10"
]
print(flatten(testcase))