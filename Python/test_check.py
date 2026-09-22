# Student Report:------

# fucntion to calculate average marks
def calculate_average(marks):
    return sum(marks) /len(marks)

# defining a class
class student:
    def __init__(self, name, age, marks):
        self.name = name
        self.age = age
        self.marks = marks


    def show_result(self):
        average = calculate_average(self.marks)
        if average >=50:
            status = "Pass"
        else:
            status = "Fail"
        print(self.name, "has scored an average of", round(average,2), "and has", status)

student1 = student("Ali", 20, [60, 70, 80])
student2 = student("Sara", 22, [40, 50, 60])
student3 = student("Omer", 19, [30, 40, 50])

        
student1.show_result()
student2.show_result()
student3.show_result()