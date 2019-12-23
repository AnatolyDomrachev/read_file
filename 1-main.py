def turing(data):
    lenta = list(data)
    pos = 0
    state = 'q1'

    while(True):
        if state == "q1":
            if lenta[pos] == "0":
                state = "q1"
                lenta[pos] = "0"
                pos += 1
                continue
            if lenta[pos] == "1":
                state = "q1"
                lenta[pos] = "1"
                pos += 1
                continue
            if lenta[pos] == "2":
                state = "q1"
                lenta[pos] = "2"
                pos += 1
                continue
            if lenta[pos] == "+":
                state = "q2"
                lenta[pos] = "+"
                pos += 1
                continue
            if lenta[pos] == "-":
                state = "q3"
                lenta[pos] = "-"
                pos += 1
                continue
            if lenta[pos] == " ":
                state = "q1"
                lenta[pos] = " "
                pos += 1
        if state == "q2" :
            if lenta[pos] == "0":
                state = "q20"
                lenta[pos] = "0"
                pos -= 1
                continue
            if lenta[pos] == "1":
                state = "q21"
                lenta[pos] = "1"
                pos -= 1
                continue
            if lenta[pos] == "2":
                state = "q22"
                lenta[pos] = "2"
                pos -= 1
        if state == "q3" :
            if lenta[pos] == "0":
                state = "q20"
                lenta[pos] = "0"
                pos -= 1
                continue
            if lenta[pos] == "1":
                state = "q31"
                lenta[pos] = "1"
                pos -= 1
                continue
            if lenta[pos] == "2":
                state = "q32"
                lenta[pos] = "2"
                pos -= 1
        if state == "q20" :
            if lenta[pos] == "0":
                state = "q60"
                lenta[pos] = "0"
                continue
            if lenta[pos] == "1":
                state = "q60"
                lenta[pos] = "1"
                continue
            if lenta[pos] == "2":
                state = "q60"
                lenta[pos] = "2"
                continue
            if lenta[pos] == "+":
                state = "q20"
                lenta[pos] = "+"
                pos -= 1
                continue
            if lenta[pos] == "-":
                state = "q20"
                lenta[pos] = "-"
                pos -= 1
        if state == "q21" :
            if lenta[pos] == "0":
                state = "q60"
                lenta[pos] = "1"
                continue
            if lenta[pos] == "1":
                state = "q60"
                lenta[pos] = "2"
                continue
            if lenta[pos] == "2":
                state = "q40"
                lenta[pos] = "0"
                pos -= 1
                continue
            if lenta[pos] == "+":
                state = "q21"
                lenta[pos] = "+"
                pos -= 1
                continue
            if lenta[pos] == "-":
                state = "q21"
                lenta[pos] = "-"
                pos -= 1
        if state == "q22" :
            if lenta[pos] == "0":
                state = "q60"
                lenta[pos] = "2"
                continue
            if lenta[pos] == "1":
                state = "q40"
                lenta[pos] = "0"
                pos -= 1
                continue
            if lenta[pos] == "2":
                state = "q40"
                lenta[pos] = "1"
                pos -= 1
                continue
            if lenta[pos] == "+":
                state = "q22"
                lenta[pos] = "+"
                pos -= 1
                continue
            if lenta[pos] == "-":
                state = "q22"
                lenta[pos] = "-"
                pos -= 1
        if state == "q31" :
            if lenta[pos] == "0":
                state = "q50"
                lenta[pos] = "2"
                pos -= 1
                continue
            if lenta[pos] == "1":
                state = "q60"
                lenta[pos] = "0"
                continue
            if lenta[pos] == "2":
                state = "q60"
                lenta[pos] = "1"
                continue
            if lenta[pos] == "+":
                state = "q31"
                lenta[pos] = "+"
                pos -= 1
                continue
            if lenta[pos] == "-":
                state = "q31"
                lenta[pos] = "-"
                pos -= 1
        if state == "q32" :
            if lenta[pos] == "0":
                state = "q50"
                lenta[pos] = "1"
                pos -= 1
                continue
            if lenta[pos] == "1":
                state = "q50"
                lenta[pos] = "2"
                pos -= 1
                continue
            if lenta[pos] == "2":
                state = "q60"
                lenta[pos] = "0"
                continue
            if lenta[pos] == "+":
                state = "q32"
                lenta[pos] = "+"
                pos -= 1
                continue
            if lenta[pos] == "-":
                state = "q32"
                lenta[pos] = "-"
                pos -= 1
        if state == "q40" :
            if lenta[pos] == "0":
                state = "q60"
                lenta[pos] = "1"
                continue
            if lenta[pos] == "1":
                state = "q60"
                lenta[pos] = "2"
                continue
            if lenta[pos] == "2":
                state = "q40"
                lenta[pos] = "0"
                pos -= 1
                continue
            if state == "q40" and lenta[pos] == " ":
                state = "q60"
                lenta[pos] = "1"
        if state == "q50" :
            if lenta[pos] == "0":
                state = "q50"
                lenta[pos] = "2"
                pos -= 1
                continue
            if lenta[pos] == "1":
                state = "q51"
                lenta[pos] = "0"
                pos -= 1
                continue
            if lenta[pos] == "2":
                state = "q60"
                lenta[pos] = "1"
        if state == "q51" :
            if lenta[pos] == "0":
                state = "q51"
                lenta[pos] = "0"
                pos -= 1
        if state == "q51" :
            if lenta[pos] == "1":
                state = "q60"
                lenta[pos] = "1"
                continue
            if lenta[pos] == "2":
                state = "q60"
                lenta[pos] = "2"
                continue
            if lenta[pos] == " ":
                state = "q52"
                lenta[pos] = " "
                pos += 1
        if state == "q52" and lenta[pos] == "0":
            state = "q60"
            lenta[pos] = " "
        if state == "q60":
            return lenta

data = input()
out_arr = turing(data)
for d in out_arr:
    print(d, end = '')
print()
