in_file = open("output2.txt", 'r')
l = False
operates = ["Assign", "Less", "Equal", "Mod", "Add" , "While", "If","Prti","Prts"]
d = False
p1 = False
p2 = False
zet = [0,0,0,0,0]
code = ""
node = []
nextt = True
t = -2
def reads():
    global node, l, code,nextt,d,p1,p2
    a = in_file.readline()
    b = a.split('\t')
    if (b[0]==''):
        nextt=False
    elif (len(b)==1 and b[0].strip(" \n") in operates):
        if ( 'While' in b[0].strip(' \n') or 'If' in b[0].strip(' \n')):
            code = code +"\n"b[0].strip(' \n')+"("
            d = True
            p2 = True
        elif ('Prti' in b[0].strip(' \n') or 'Prts' in b[0].strip(' \n')):
            code = code + 'print'
            p1 = True
        else:
            node.append(b[0])
            left = reads()
            l = True
            right = reads()
            l = False
    elif (len(b)==2):
        if (p1 == True):
            code = code + '(' + b[1].strip(" \n") + ')\n'
            p1= False
        elif("Assign" in node[-1] and l == False):
            code = code + b[1].strip(" \n")
        elif ("Assign" in node[-1]  and l == True):
            code = code + "=" + b[1].strip(" \n")
            del node[-1]
        elif("Add" in node[-1] and l == False):
            code = code + b[1].strip(" \n")
        elif ("Add" in node[-1]  and l == True):
            code = code + "+" + b[1].strip(" \n")
            del node[-1]
        elif("Equal" in node[-1] and l == False):
            code = code + b[1].strip(" \n")
        elif ("Equal" in node[-1]  and l == True):
            code = code + "==" + b[1].strip(" \n")
            del node[-1]
        elif("Mod" in node[-1] and l == False):
            code = code + b[1].strip(" \n")
        elif ("Mod" in node[-1]  and l == True):
            code = code + "%" + b[1].strip(" \n")
            del node[-1]
        elif("Less" in node[-1] and l == False):
            code = code + b[1].strip(" \n")
        elif ("Less" in node[-1]  and l == True):
            code = code + "<" + b[1].strip(" \n")
            del node[-1]
    elif (d):
        code += '):\n'
        d=False
            
    else:
        reads()
while True:
    if (nextt):
        reads()
    else:
        print(code)
        break

'''

for i in in_file.read.splitlines():
    if (len(i) == 1):
        if i[0] == 'Assign':
            zet[0] = 1
        if i[0] == operates[1] :
            zet[1] = 1
        if i[0] == operates[2] :
            zet[2] = 1
        if i[0] == operates[3] :
            zet[3] = 1
        if i[0] == operates[4] :
            zet[4] = 1
    elif (len(i) == 2):
'''

