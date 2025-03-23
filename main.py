with open("gimme.txt","w") as f:
    f.write("15000\n")
    for i in range(1,15000*2+1,2): f.write(f"{i} {i+1}\n")