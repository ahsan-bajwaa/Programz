// Initializing an empty array for students
let students = [];

// Regular Function: To load data from JSON string in LocalStorage
function loadData() {
    const savedData = localStorage.getItem("studentList");
    if (savedData) {
        // Using JSON.parse to convert string back to array
        students = JSON.parse(savedData);
        displayStudents(students);
    }
}

// Regular Function: To display students in the table
function displayStudents(studentArray) {
    const tableBody = document.getElementById("tableBody");
    tableBody.innerHTML = ""; // Clear existing rows

    // Using forEach (Array Method) and Template Literals
    studentArray.forEach((student, index) => {
        const row = `<tr>
            <td>${student.name}</td>
            <td>${student.email}</td>
            <td>${student.age}</td>
            <td>${student.course}</td>
            <td><button class="delete-btn" onclick="deleteStudent(${index})">Delete</button></td>
        </tr>`;
        tableBody.innerHTML += row;
    });
}

// Regular Function: To save data to LocalStorage
function saveData() {
    // Using JSON.stringify to convert array to string
    localStorage.setItem("studentList", JSON.stringify(students));
}

// Arrow Function: To add a student
const addStudent = (e) => {
    e.preventDefault(); // Stop form from refreshing the page (Submit event)

    // Using DOM manipulation to get values
    const nameVal = document.getElementById("name").value.trim(); // String Method
    const emailVal = document.getElementById("email").value.toLowerCase(); // String Method
    const ageVal = document.getElementById("age").value;
    const courseVal = document.getElementById("course").value.substring(0, 20); // String Method

    const newStudent = {
        name: nameVal,
        email: emailVal,
        age: ageVal,
        course: courseVal
    };

    students.push(newStudent); // Array Method
    saveData();
    displayStudents(students);
    document.getElementById("studentForm").reset(); // Clear form
};

// Arrow Function: To delete a student
const deleteStudent = (index) => {
    // Using filter (Array Method) to remove student
    students = students.filter((_, i) => i !== index);
    saveData();
    displayStudents(students);
};

// Event: Search/Filter Students (keyup event)
document.getElementById("searchInput").addEventListener("keyup", function() {
    const searchTerm = this.value.toLowerCase();
    
    // Using map and filter (Array Methods) to find matches
    const filtered = students.filter(s => 
        s.name.toLowerCase().includes(searchTerm)
    );
    
    displayStudents(filtered);
});

// Event: Form Submit
document.getElementById("studentForm").addEventListener("submit", addStudent);

// Load data when script runs
loadData();