# coding: utf-8


# Rating System:

#	 0	Haven't read it
#	 -5	Hated it
#	 -3 	Didn't like it
#	 1 	Ok. neither hot nor cold about it
#	 3	Liked it!
#	 5	Really liked it!


class Recommender:

	def __init__(self,books_filename,ratings_filename):
		# initialize variables
		self.avg_ratings_dict = {}
		self.ratings_dict = {}
		self.books_dict = {}
		self.books_dict = self.read_books(books_filename)
		self.ratings_dict = self.read_users(ratings_filename)
		self.avg_ratings_dict = self.calculate_average_rating()

	def read_books(self,file_name):
	# Takes the name of a file and returns a dictionary
		# Enclose the opening function in a try method so we can error handle
		try:
			with open(file_name, "r") as f:
				dictionary = {}
				line_num = 0
				for line in f:
					sub = line.split(',')
					# Strip new line character
					sub[1] = sub[1].replace("\n","")
					# Switch order of title and author
					temp_author = sub[0]
					temp_title = sub[1]
					sub[0] = temp_title
					sub[1] = temp_author
					# Append item to dictionary
					dictionary[line_num] = sub
					# Increment line number
					line_num = line_num + 1
				return dictionary
				# The function should return 'None' if the file could not be read. If the file is empty, return an empty dictionary
		except Exception as error:
			# The file could not be opened, therefore we need to return 'None'
			return "None"


	def read_users(self,user_file):
		try:
			with open(user_file, "r") as f:
				dictionary = {}
				for line in f:
					sub = line.split()
					name = sub[0]
					sub = sub[1:]
					dictionary[name] = sub
				return dictionary
				# The function should return 'None' if the file could not be read. If the file is empty, return an empty dictionary
		except Exception as error:
			# The file could not be opened, therefore we need to return 'None'
			return "None"

	def calculate_average_rating(self):
		avg_dict = {}
		overall_index = 0
		for key in self.ratings_dict:
			arr = self.ratings_dict[key]
			index = 0
			for item in arr:
				array_to_avg = []
				# Import previous scores

				if overall_index > 0:
					for i in avg_dict[index]:
						array_to_avg.append(i)

				array_to_avg.append(item)

				avg_dict[index] = array_to_avg
				index = index + 1
			overall_index = overall_index+1
			# print len(arr)

		return_dict = {}
		for key in avg_dict:
			array = avg_dict[key]
			total_sum = 0
			total_count = 0
			for value in array:
				if int(value) != 0:
					total_sum = total_sum + float(value)
					total_count = total_count+1
			avg = total_sum / total_count
			return_dict[key] = round(avg,2)
		return return_dict


	def lookup_average_rating(self,index):
		if index > len(self.books_dict):
			return "Error"

		for key in self.books_dict:
			if key == index:
				avg_rating = self.avg_ratings_dict[key]
				title_author = self.books_dict[key]
				return "("+str(avg_rating)+") "+title_author[0]+" by "+title_author[1]

				# (3.83) The Hitchhiker's Guide To The Galaxy by Douglas Adams

	def calc_similarity(self,user1, user2):
		# The most useless function in the world but whatever

		# print self.ratings_dict
		# Get the arrays for both users
		user1_arr = self.ratings_dict[user1]
		user2_arr = self.ratings_dict[user2]

		# Now to start the math
		sum = 0
		index = 0
		for rating in user1_arr:
			sum = sum + (int(rating) * int(user2_arr[index]))
			index = index+1
		return sum

	def get_most_similar_user(self,current_user_id):
		# The second most useless function in the world
		highest_similarity = 0
		similarity_key = ""
		for key in self.ratings_dict:
			if key != current_user_id:
				s = self.calc_similarity(current_user_id,key)
				if s > highest_similarity:
					highest_similarity = s
					similarity_key = key
		# print highest_similarity
		return similarity_key

	def recommend_books(self,current_user_id):
		return_list = []
		most_similar = self.get_most_similar_user(current_user_id)
		print current_user_id+"+"+most_similar

		similar_dict = self.ratings_dict[most_similar]
		user_dict = self.ratings_dict[current_user_id]

		index = 0
		for i in similar_dict:
			if int(i) == 0:
				if (int(user_dict[index]) == 3 or int(user_dict[index]) == 5):
					# print "MATCH"
					book_rec = self.lookup_average_rating(int(user_dict[index]))
					return_list.append(book_rec)
			index = index + 1
		return return_list

rec = Recommender("books.txt","ratings.txt")
# PASSED TESTS

### Test case for part 2
#### calc_similarity function:
print rec.calc_similarity('Cust8', 'Shannon')      # 369
print rec.calc_similarity('Megan', 'Strongbad')    # 95
print rec.calc_similarity('Leah', 'clipper')       # 0
print rec.calc_similarity('Apollo', 'James')       # -65


#### lookup_average_rating function
print rec.lookup_average_rating(0)            # (3.83) The Hitchhiker's Guide To The Galaxy by Douglas Adams
print rec.lookup_average_rating(7)            # (0.43) The Sisterhood of the Travelling Pants by Ann Brashares
print rec.lookup_average_rating(17)           # (2.38) Neuromancer by William Gibson
print rec.lookup_average_rating(30)           # (1.77) To Kill a Mockingbird by Harper Lee
print rec.lookup_average_rating(54)  	    # (1.56) The Chrysalids by John Wyndham



#### get_most_similar_user
print rec.get_most_similar_user("Leah")       # hidan
print rec.get_most_similar_user("Rudy_Ann")   # ROFLOL
print rec.get_most_similar_user("Martin")     # clipper
print rec.get_most_similar_user("KeeLed")     # Cust8
print rec.get_most_similar_user("Rudy.A")     # Cust8


# FAILED TESTS

#### recommend_books
print rec.recommend_books("Brian")
# []
print rec.recommend_books("Megan")
# ['(0.90) The Princess Diaries by Meg Cabot',
#  "(3.80) My Sister's Keeper by Jodi Picoult",
#  '(2.06) Bone Series by Jeff Smith']
print rec.recommend_books("Tiffany")
# ['(3.86) The Bourne Series by Robert Ludlum']
print rec.recommend_books("Moose")
# ['(3.50) The Princess Bride by William Goldman',
#  '(3.86) The Bourne Series by Robert Ludlum',
#  '(0.47) Twilight Series by Stephenie Meyer',
#  '(2.76) The Golden Compass by Philip Pullman',
#  '(3.57) Holes by Louis Sachar']
print rec.recommend_books("Ella")
# ["(3.83) The Hitchhiker's Guide To The Galaxy by Douglas Adams",
#  '(2.25) The Da Vinci Code by Dan Brown',
#  '(1.62) Naruto by Masashi Kishimoto',
#  '(3.86) The Bourne Series by Robert Ludlum',
#  "(3.80) My Sister's Keeper by Jodi Picoult",
#  '(3.61) Harry Potter Series by J.K. Rowling',
#  '(2.06) Bone Series by Jeff Smith',
#  '(3.04) The Lord of the Rings by J R R Tolkien',
#  '(2.85) The Hobbit by J R R Tolkien',
#  '(2.83) The War Of The Worlds by H G Wells']
# print rec.lookup_average_rating(0)
# print rec.recommend_books("Cust6")

# for key in rec.ratings_dict:
	# print rec.recommend_books(key)
# print lookup_average_rating(0,read_books("books.txt"),calculate_average_rating(read_users("ratings.txt")))