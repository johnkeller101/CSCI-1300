  # John Keller
  # CSCI 1300 Project

  # Jason Zietz, Section 101


# Import the regex lib
import re

def CalcNewPopulation(currentPopulation):
	# Define all the rates
	birthRate = 7
	deathRate = -13
	immRate = 35

	# Calculate number of seconds in 365 days
	secondsPerYear = 365 * 24 * 60 * 60

	# Apply all the rates
	secondsPerYear += secondsPerYear/birthRate
	secondsPerYear += secondsPerYear/deathRate
	secondsPerYear += secondsPerYear/immRate

	return secondsPerYear

# Test it to make sure we return the correct values
print CalcNewPopulation(100)

def BreakoutTime(seconds):
	# Perform necessary conversions
	dayInt = seconds/24/60/60
	hoursInt = (seconds - (dayInt*24*60*60)) / 60 / 60
	minutesInt = (seconds - (hoursInt*60*60) - (dayInt*24*60*60)) / 60
	secondsInt = (seconds - (hoursInt*60*60) - (dayInt*24*60*60) -  (minutesInt*60))
	# Format the return string correctly
	returnStr = 'Days: '+str(dayInt)+'\nHours: '+str(hoursInt)+'\nMinutes: '+str(minutesInt)+'\nSeconds: '+str(secondsInt)
	# Return the correct string
	return returnStr

# Test the function
print BreakoutTime(70000);

def listSequencePositions(search_string,larger_string):
	# Using regex, this function is easy to truncate to one line
	return [m.start() for m in re.finditer(search_string, larger_string)]

# Test the positions
print listSequencePositions("1","12314542145")

def MadLib(number):
	# Define a stories array and add all the stories
	stories = []
	stories.append("Be kind to your <noun>-footed <plural noun>, or a duck may be somebody's <noun>.")
	stories.append("It was the <adjective1> of <noun1>, it was the <adjective2> of <noun2>.")
	stories.append("<plural noun>? I don't have to show you any <adjective> <plural noun>!")
	stories.append("My <relative> always said <noun> was like a box of <noun>. You never know what you're gonna get.")
	stories.append("One <time of day>, I <verb> a <noun> in my pajamas. How he got in my pajamas, I don't know.")

	# Define the selected story (note the offset because arrays start with 0)
	story = stories[number-1]

	# Use regex to find all the strings we need to replace with new ones
	matches = re.findall(r'\<(.+?)\>',story)

	# Itterate through the strings and replace them based on the correct input
	for match in matches:
		# Define the input string (and where the user input goes)
		inp = raw_input('Enter '+match+": ")
		# Add the carrots to fix replacement of strings
		raw_match = "<"+match+">"
		# Run the replace function, and replace story with the new story
		story = story.replace(raw_match,inp)

	# Return the actual story
	return story

# Test the function
print MadLib(2)