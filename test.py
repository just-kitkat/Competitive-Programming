import subprocess

INFO = {
    "f": "Practices\\", # Practices / Contests
    "cat": "640d4\\", # <num>d<div>
    "qn": "a", # a / b / c / d / e / f / g / h ...
    "ext": ".cpp", # .py / .cpp / .java / .c
    "sout": "c:\\Users\\HP\\Documents\\Python\\Codeforces\\Testcases\\sample.out",
    "tin": "c:\\Users\\HP\\Documents\\Python\\Codeforces\\Testcases\\test.in",
    "tout": "c:\\Users\\HP\\Documents\\Python\\Codeforces\\Testcases\\test.out",
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
