// collection of values of different data types.
#include <stdio.h>
#include <string.h>

// user-defined datatype
struct student
{
    char name[100];
    int roll;
    float cgpa;
};

struct vector
{
    int x;
    int y;
};

typedef struct bankAccount
{
    char name[100];
    int accountNo;
    int balance;
} svacc; // svacc => savings account

void printInfo(struct student s5);
void calculateSum(struct vector v1, struct vector v2, struct vector sum);

int main()
{
    // Practice Question //
    /* 1) Write a program to store the data of 3 students.*/
    // Ans)
    // structure in line 6

    // info of 3 students

    // student-1
    printf("\nStudent-1\n");
    struct student s1;
    strcpy(s1.name, "Satrasala Tharun");
    s1.roll = 699;
    s1.cgpa = 9.4;
    printf("Student name = %s\n", s1.name);
    printf("Student roll no. = %d\n", s1.roll);
    printf("Student cgpa = %.2f\n", s1.cgpa);

    // student-2
    printf("\nStudent-2\n");
    struct student s2;
    strcpy(s2.name, "Arjun Reddy");
    s2.roll = 143;
    s2.cgpa = 9.9;
    printf("Student name = %s\n", s2.name);
    printf("Student roll no. = %d\n", s2.roll);
    printf("Student cgpa = %.2f\n", s2.cgpa);

    // student-3
    printf("\nStudent-3\n");
    struct student s3;
    strcpy(s3.name, "Sai Suhasini");
    s3.roll = 738;
    s3.cgpa = 8.5;
    printf("Student name = %s\n", s3.name);
    printf("Student roll no. = %d\n", s3.roll);
    printf("Student cgpa = %.2f\n", s3.cgpa);

    // Array of Structures //

    struct student ECE[100];
    // ece student
    ECE[0].roll = 1897;
    ECE[0].cgpa = 5.9;
    strcpy(ECE[0].name, "Bhargavi");
    printf("\nECE Student\n");
    printf("Student name = %s\n", ECE[0].name);
    printf("Student roll no. = %d\n", ECE[0].roll);
    printf("Student cgpa = %.1f\n", ECE[0].cgpa);

    // Intializing Structures //

    // student-4
    printf("\nStudent-4 (special)\n");
    struct student s4 = {"Itachi uchicha", 9620, 10};
    printf("Student name = %s\n", s4.name);

    // Pointers to Structures //
    struct student *ptr = &s4;
    printf("Student.roll no. = %d\n", (*ptr).roll);
    printf("Student.cgpa = %.1f\n", (*ptr).cgpa);

    // same s4 to ptr1,ptr2

    // Arrow Operator //
    printf("\nArrow Operators in structures\n");
    struct student *ptr2 = &s4;
    printf("Student -> name = %s\n", ptr2->name);
    printf("Student -> roll no. = %d\n", ptr2->roll);
    printf("Student -> cgpa = %.1f\n", ptr2->cgpa);

    // Passing structure to function //
    struct student s5 = {"Tony Stark", 3000, 10.00};
    printInfo(s5);

    // Typedef keyword //
    typedef struct computerEngineeringStudent
    {
        char name[100];
        int roll;
        float cgpa;
    } cse;

    cse student1 = {"Chanukya", 1689, 8.7};
    printf("\nStudent1 name in cse is %s\n", student1.name);

    // Practice Questions //
    /* 2) Enter address (house no,block,city,state) of 5 people*/
    // Ans)
    typedef struct address
    {
        int houseNo;
        int block;
        char city[100];
        char state[100];
    } ad;

    // five peoples
    ad person1 = {278, 2, "Chennai", "Tamil Nadu"};
    ad person2 = {167, 1, "Madanapalle", "Andhra Pradesh"};
    ad person3 = {0456, 4, "Mumbai", "Maharashtra"};
    ad person4 = {590, 3, "Rajkot", "Gujarat"};
    ad person5 = {679, 8, "Bangalore", "Karnataka"};

    printf("\nSOME INFO OF 5 PEOPLE\n");
    printf("person1 city is %s\n", person1.city);
    printf("person2 state is %s\n", person2.state);
    printf("person3 house number is %d\n", person3.houseNo);
    printf("person4 block is %d\n", person4.block);
    printf("person5 city is %s\n", person5.city);

    /* 3) Create a structure to store vectors.Then make a function
    to return a sum of 2 vectors.*/
    // Ans)
    // Structure in line 13
    struct vector v1, v2;
    printf("Enter values of v1 and v2 = ");
    scanf("%d%d%d%d", &(v1.x), &(v1.y), &(v2.x), &(v2.y));
    struct vector sum = {0};
    calculateSum(v1, v2, sum);

    /* 4) Create a structure to store complex numbers.
    (use arrow operator) */
    // Ans)
    struct complexNum
    {
        int real;
        int img;
    };
    struct complexNum z1 = {18, 3};
    struct complexNum *ptr0 = &z1;
    printf("\nTHE COMPLEX NUMBER\n");
    printf("The real part = %d\n", ptr0->real);
    printf("The Imaginary part = %d\n", ptr0->img);
    printf("The General form is z1 = %d+%di\n", z1.real, z1.img);

    /* 5) Make a structure to store Bank Account Information
    of a customer of ABC Bank.Also,make an alias for it.*/
    // Ans)
    // structure in line 19
    svacc user1 = {"Deva", 12978, 19000};
    svacc user2 = {"Varada", 12979, 1780000};
    svacc user3 = {"Yash", 12980, 135600000};
    printf("\nUSERS INFORMATION :\n");
    printf("User1 account number = %d\n", user1.accountNo);
    printf("User2 name = %s\n", user2.name);
    printf("User3 account balance = %d\n", user3.balance);

    return 0;
}

void printInfo(struct student s5)
{
    printf("\nStudent-5 Information : \n");
    printf("Student.name = %s\n", s5.name);
    printf("Student.roll = %d\n", s5.roll);
    printf("Student.cgpa = %.1f\n", s5.cgpa);
}

void calculateSum(struct vector v1, struct vector v2, struct vector sum)
{
    sum.x = v1.x + v2.x;
    sum.y = v1.y + v2.y;
    printf("Sum of v1 and v2 = %di + %dj\n", sum.x, sum.y);
}