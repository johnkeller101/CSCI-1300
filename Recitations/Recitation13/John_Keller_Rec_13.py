# Recitation 13
# John Keller

def ReadEvens(filename):
	# takes a filename, reads all the values (one per line, integers) from a 
	# file and store the even numbers in a list. The function should return the list.

	evens = []

	a = open(filename,"r") 
	b = [float(v) for line in a for v in line.rstrip('\n').split('\t')]

	for value in b:
		if (value % 2 == 0):
			evens.append(value)

	a.close()
	return evens

def ReadDivBy(filename, multiplier):
	# reads all the values (one per line, integers) from file and store stores all
	# the numbers that are divisible by that multiplier in a list. Return the list.

	ret_list = []

	a = open(filename,"r") 
	b = [float(v) for line in a for v in line.rstrip('\n').split('\t')]

	for value in b:
		if (value % multiplier == 0):
			ret_list.append(value)

	a.close()
	return ret_list


print ReadEvens('integers_recitation13.csv')
print ReadDivBy('integers_recitation13.csv',9)