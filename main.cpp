// main.cpp - C++ program with security issues for Codacy

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

// SECURITY ISSUE 1: Hardcoded password
const string ADMIN_PASSWORD = "admin12345";

// SECURITY ISSUE 2: Hardcoded API key
const char* API_KEY = "sk-abc123xyz789secret";

// SECURITY ISSUE 3: Buffer overflow vulnerability
void copy_string(char* input) {
    char buffer[10];
    // No bounds checking - buffer overflow!
    strcpy(buffer, input);
    cout << "Copied: " << buffer << endl;
}

// SECURITY ISSUE 4: Using gets() - dangerous function
void read_user_input() {
    char input[20];
    // gets() is dangerous and deprecated
    // gets(input);
    cout << "Input received" << endl;
}

// SECURITY ISSUE 5: System call with user input
void execute_command(string user_command) {
    string full_command = "ls " + user_command;
    // system() call with user input is dangerous!
    system(full_command.c_str());
}

// CODE SMELL 1: Using goto statement
void process_data(int value) {
    if (value < 0) {
        goto error_handler;
    }
    cout << "Processing: " << value << endl;
    return;
    
error_handler:
    cout << "Error occurred" << endl;
}

// CODE SMELL 2: Memory leak
void leak_memory() {
    int* ptr = new int[100];
    // No delete - memory leak!
    ptr[0] = 42;
    cout << "Memory allocated but never freed" << endl;
}

// SECURITY ISSUE 6: Integer overflow vulnerability
int multiply_large_numbers(int a, int b) {
    // No overflow check
    return a * b;
}

// CODE SMELL 3: Too many parameters
string concatenate_strings(string s1, string s2, string s3, string s4, string s5, 
                           string s6, string s7, string s8, string s9, string s10) {
    return s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8 + s9 + s10;
}

// SECURITY ISSUE 7: Format string vulnerability
void print_user_input(char* user_input) {
    // Dangerous - user input as format string
    // printf(user_input);
    cout << "Printing user input" << endl;
}

// CODE SMELL 4: Deep nested if statements
int nested_conditions(int a, int b, int c, int d) {
    if (a > 0) {
        if (b > 0) {
            if (c > 0) {
                if (d > 0) {
                    return a + b + c + d;
                } else {
                    return a + b + c;
                }
            } else {
                return a + b;
            }
        } else {
            return a;
        }
    }
    return 0;
}

// SECURITY ISSUE 8: Using rand() for security
int generate_weak_token() {
    // rand() is not cryptographically secure
    return rand() % 1000000;
}

// CODE SMELL 5: Unused parameter
int calculate_area(int length, int width, int unused_parameter) {
    return length * width;
}

// CODE SMELL 6: Very long function
void long_function() {
    cout << "Step 1" << endl;
    cout << "Step 2" << endl;
    cout << "Step 3" << endl;
    cout << "Step 4" << endl;
    cout << "Step 5" << endl;
    cout << "Step 6" << endl;
    cout << "Step 7" << endl;
    cout << "Step 8" << endl;
    cout << "Step 9" << endl;
    cout << "Step 10" << endl;
    cout << "Step 11" << endl;
    cout << "Step 12" << endl;
    cout << "Step 13" << endl;
    cout << "Step 14" << endl;
    cout << "Step 15" << endl;
    cout << "Step 16" << endl;
    cout << "Step 17" << endl;
    cout << "Step 18" << endl;
    cout << "Step 19" << endl;
    cout << "Step 20" << endl;
}

// CODE SMELL 7: Duplicate code
int add_one(int x) {
    return x + 1;
}

int increment_by_one(int x) {
    return x + 1;  // Same as add_one
}

// SECURITY ISSUE 9: Class with public sensitive data
class User {
public:
    string username;
    string password;  // Public password - bad practice!
    int ssn;
    
    void display() {
        cout << "User: " << username << ", Password: " << password << endl;
    }
};

int main() {
    cout << "Starting vulnerable C++ application" << endl;
    
    // Test vulnerabilities
    copy_string("This is a very long string that will overflow the buffer!");
    
    int big_result = multiply_large_numbers(1000000000, 1000000000);
    cout << "Multiplication result (may overflow): " << big_result << endl;
    
    weak_token = generate_weak_token();
    cout << "Weak token: " << token << endl;
    
    User admin;
    admin.username = "admin";
    admin.password = ADMIN_PASSWORD;
    admin.ssn = 123456789;
    admin.display();
    
    return 0;
}
