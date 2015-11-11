from graphics import giveMeTheGraphic
from matplotlib.pyplot import show
from DFSA import *

print ("Rodando Lower Bound...")
resultsLB = lowerBound()
print ("Agora rodando o EomLee...")
resultsEL = eomLee()
print ("Agora rodando o Chen...")
resultsCH = chen()

emptySlots = []
colli = []
totalSlots = []

emptySlots2 = []
colli2 = []
totalSlots2 = []

emptySlots3 = []
colli3 = []
totalSlots3 = []

for i in resultsLB:
	emptySlots.append(i[1])
	colli.append(i[2])
	totalSlots.append(i[0] + i[1] + i[2])

for j in resultsEL:
	emptySlots2.append(j[1])
	colli2.append(j[2])
	totalSlots2.append(j[0] + j[1] + j[2])

for k in resultsCH:
	emptySlots3.append(k[1])
	colli3.append(k[2])
	totalSlots3.append(k[0] + k[1] + k[2])

for rlb in resultsLB:
    print (rlb)
for rel in resultsEL:
    print (rel)
for rch in resultsCH:
    print (rch)

giveMeTheGraphic([(x+1)*100 for x in range(10)], emptySlots, "Iteracoes", "Slots Vazios", 1, "Lower Bound")
giveMeTheGraphic([(x+1)*100 for x in range(10)], emptySlots2, "Iteracoes", "Slots Vazios", 1, "Eom Lee")
giveMeTheGraphic([(x+1)*100 for x in range(10)], emptySlots3, "Iteracoes", "Slots Vazios", 1, "Chen")
giveMeTheGraphic([(x+1)*100 for x in range(10)], colli, "Iteracoes", "Colisoes", 2, "Lower Bound")
giveMeTheGraphic([(x+1)*100 for x in range(10)], colli2, "Iteracoes", "Colisoes", 2, "Eom Lee")
giveMeTheGraphic([(x+1)*100 for x in range(10)], colli3, "Iteracoes", "Colisoes", 2, "Chen")
giveMeTheGraphic([(x+1)*100 for x in range(10)], totalSlots, "Iteracoes", "Total de Slots", 3, "Lower Bound")
giveMeTheGraphic([(x+1)*100 for x in range(10)], totalSlots2, "Iteracoes", "Total de Slots", 3, "Eom Lee")
giveMeTheGraphic([(x+1)*100 for x in range(10)], totalSlots3, "Iteracoes", "Total de Slots", 3, "Chen")

show()
print ("Acabou.")
