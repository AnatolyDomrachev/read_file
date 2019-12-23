def turing(data):
    lenta = list(data)
    pos = 0
    state = 'q1'

    while(True):
        if state == "q1" and lenta[pos] in [" ", "0", "1", "2"]:
            pos += 1
        if state == "q1" and lenta[pos] == "+":
            state = "q2"
            pos += 1
        if state == "q1" and lenta[pos] == "-":
            state = "q3"
            pos += 1
        if state == "q2" and lenta[pos] == "0":
            state = "q20"
            pos -= 1
        if state == "q2" and lenta[pos] == "1":
            state = "q21"
            pos -= 1
        if state == "q2" and lenta[pos] == "2":
            state = "q22"
            pos -= 1
        if state == "q3" and lenta[pos] == "0":
            state = "q20"
            pos -= 1
        if state == "q3" and lenta[pos] == "1":
            state = "q31"
            pos -= 1
        if state == "q3" and lenta[pos] == "2":
            state = "q32"
            pos -= 1
        
        if state == "q20" and lenta[pos] in ["0", "1", "2"]:
            state = "q60"

        if state in ["q20", "q21", "q22"] and lenta[pos] in ["+", "-"]:
            pos -= 1
        
        if state == "q21" and lenta[pos] in ["0", "1"]:
            state = "q60"
            lenta[pos] = str(int(lenta[pos])+1)

        if state == "q21" and lenta[pos] == "2":
            state = "q40"
            lenta[pos] = "0"
            pos -= 1

        if state == "q22" and lenta[pos] == "0":
            state = "q60"
            lenta[pos] = "2"

        if state == "q22" and lenta[pos] in ["1", "2"]:
            state = "q40"
            lenta[pos] = str(int(lenta[pos])-1)
            pos -= 1
        
        if state == "q31" and lenta[pos] == "0":
            state = "q50"
            lenta[pos] = "2"
            pos -= 1

        if state == "q31" and lenta[pos] in ["1", "2"]:
            state = "q60"
            lenta[pos] = str(int(lenta[pos])-1)

        if state == "q31" and lenta[pos] in ["+", "-"]:
            pos -= 1

        if state == "q32" and lenta[pos] == "0":
            state = "q50"
            lenta[pos] = str(int(lenta[pos])+1)
            pos -= 1

        if state == "q32" and lenta[pos] == "2":
            state = "q60"
            lenta[pos] = "0"

        if state == "q32" and lenta[pos] in ["+", "-"]:
            pos -= 1

        if state == "q40" and lenta[pos] == "0":
            state = "q60"
            lenta[pos] = str(int(lenta[pos])+1)

        if state == "q40" and lenta[pos] == "2":
            lenta[pos] = "0"
            pos -= 1
        if state == "q40" and lenta[pos] == " ":
            state = "q60"
            lenta[pos] = "1"
        if state == "q50" and lenta[pos] == "0":
            lenta[pos] = "2"
            pos -= 1
        if state == "q50" and lenta[pos] == "1":
            state = "q51"
            lenta[pos] = "0"
            pos -= 1
        if state == "q50" and lenta[pos] == "2":
            state = "q60"
            lenta[pos] = "1"
        if state == "q51" and lenta[pos] == "0":
            pos -= 1

        if state == "q51" and lenta[pos] in ["1", "2"]:
            state = "q60"

        if state == "q51" and lenta[pos] == " ":
            state = "q52"
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
