# Recitation 14
# John Keller

class wordCounter:
	wordCounts = {}
	numSentancesCollected = 0

	"""docstring for wordCounter"""
	def __init__(self):
		self.wordcounts = {}
		self.numSentancesCollected = 0

	def wordCollector(self,sentence):
		self.numSentancesCollected = self.numSentancesCollected + 1
		# I spent a ton of time reaseatching the most line effective way to perform this action, and here it is:
		reduce(lambda word, count: word.update([(count, word.get(count,0)+1)]) or word, sentence.split(), self.wordCounts)

	def printNumCollected(self):
		print "Counted %s sentences" % self.numSentancesCollected

	def getMostCommonWord(self):
		highestCount = 0
		highestCount_key = ""
		for key in self.wordCounts:
			if self.wordCounts[key] >= highestCount:
				highestCount = self.wordCounts[key]
				highestCount_key = key
		return highestCount_key


WC = wordCounter()
WC.wordCollector("this is a sentence")
WC.wordCollector("this is like a group of words")
WC.wordCollector("lists of characters are this")
WC.printNumCollected()
print "The most common word is:", WC.getMostCommonWord()
