import subprocess

INFO = {
    "f": "Contests\\", # Practices / Contests
    "cat": "937d4\\", # <num>d<div>
    "qn": "c", # a / b / c / d / e / f / g / h ...
    "ext": ".py", # .py / .cpp / .java / .c
    "sout": "./Testcases\\sample.out",
    "tin": "./Testcases\\test.in",
    "tout": "./Testcases\\test.out",
}

def main():
    # Inputs go in test.in
    with open(INFO["tin"], "r") as fin:

        with open(INFO["tout"], "w") as fout:
            py = "python " + INFO["f"] + INFO["cat"] + INFO["qn"] + INFO["ext"]
            cpp = 'cd "c:\\Users\\HP\\Documents\\Python\\Codeforces\\' + INFO["f"] + INFO["cat"] + '" ; if ($?) { g++ ' + INFO['qn'] + '.cpp -o ' + INFO["qn"] + ' } ; if ($?) { .\\' + INFO["qn"] + ' }'
            print(cpp)
            subprocess.run(
                py if INFO["ext"] ==".py" else cpp,
                stdin=fin, 
                stdout=fout,
                shell=True
                )
    
    with open(INFO["sout"], "r") as fsout:
        with open(INFO["tout"], "r") as faout:
            faoutc = faout.read()
            correct = fsout.read()==faoutc
            if not correct:
                print(faoutc)
            print("PASSED TESTCASES" if correct else "FAILED TESTCASES")
            
if __name__ == "__main__":
    main()
