
#m="Life is short,I want to learn python!"
#print(m)
print("What is the temperature?",end="")
ori = input()
a=ori[:-1]
b=ori[-1].upper()
if b == "C":
    outcome=str(int(float(a)*1.8+32))+'F'
elif b == "F":
    outcome=str(int((float(a)-32)/1.8))+'C'
print("The converted temperature is", outcome)
