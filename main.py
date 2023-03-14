# define the hash map to store grades
grades = {}

# add a new class to the hash map
def add_class():
    class_name = input("Enter the name of the class to add: ")
    section_types_input = input("Enter the section types separated by commas: ")
    section_types = section_types_input.split(",")
    class_sections = {}
    for section_type in section_types:
        # create an empty list to store assignments
        assignments = []
        # prompt the user to add assignments to the section type
        while True:
            add_assignment = input(f"Enter 'add' to add an assignment to {section_type} or 'done' if finished: ")
            if add_assignment == 'done':
                break
            assignment_name = input(f"Enter the name of the assignment: ")
            assignment_percentage = float(input(f"Enter the percentage that you got on the assignment: "))
            assignments.append({'name': assignment_name, 'percentage': assignment_percentage})
        # calculate the grade percentage for the section type based on the average percentage of the assignments
        grade_percentage = sum([assignment['percentage'] for assignment in assignments]) / len(assignments)
        section_importance = float(input(f"Enter the section importance (percentage of total grade) for {section_type}: "))
        class_sections[section_type] = {'gradePercentage': grade_percentage, 
                                        'sectionImportance': section_importance, 
                                        'assignments': assignments}
    grades[class_name] = class_sections
    print("Class", class_name, "with section types", section_types_input, "has been added.")


# delete a class from the hash map
def delete_class():
    class_name = input("Enter the name of the class to delete: ")
    if class_name in grades:
        del grades[class_name]
        print("Class", class_name, "has been deleted.")
    else:
        print("Class", class_name, "does not exist in the hash map.")


# print all the variables for a specific class
def print_variables():
    class_name = input("Enter the name of the class to print variables: ")
    if class_name in grades:
        print("Class:", class_name)
        for section_type, variables in grades[class_name].items():
            print("  Section Type:", section_type)
            for variable_name, variable_value in variables.items():
                if variable_name == 'assignments':
                    print("    Assignments:")
                    for assignment in variable_value:
                        print("      Name:", assignment['name'])
                        print("      Percentage:", assignment['percentage'])
                else:
                    print("   ", variable_name + ":", variable_value)
    else:
        print("Class", class_name, "does not exist in the hash map.")


# main loop
while True:
    print("What do you want to do? Enter 'add' to add a new class, 'delete' to delete a class, 'print' to print variables, or 'exit' to quit the program.")
    choice = input()
    if choice == 'add':
        add_class()
    elif choice == 'delete':
        delete_class()
    elif choice == 'print':
        print_variables()
    elif choice == 'exit':
        break
    else:
        print("Invalid input. Please try again.")