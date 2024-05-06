#include <iostream>
#include <string>

using namespace std;

// Global variables
string name;
int age, activityLevel;
double height, weight, bodyfat;

// Function prototypes
void getCredentials(string &name, int &age, double &height, double &weight, double &bodyfat, int &activityLevel);
void showMenu();
void calorieCalculator();
void calorieTracker();
void proteinCalculator();
void proteinTracker();
void newWorkoutSession();
void showWorkoutSummary(string exercises[], int reps[], int sets[], int weight_lifted[], int count);
void displaySessionSummary(string name, int age, double height, double weight, double bodyfat, int activityLevel, double proteinConsumed,
                            string exercises[], int reps[], int sets[], int weight_lifted[], int workoutCount);

int main()
{
    getCredentials(name, age, height, weight, bodyfat, activityLevel);

    int choice;
    bool prompt = true;
    double proteinConsumed = 0.0;

    do
    {
        showMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            calorieCalculator();
            break;
        case 2:
            calorieTracker();
            break;
        case 3:
            proteinCalculator();
            break;
        case 4:
            proteinTracker();
            break;
        case 5:
            newWorkoutSession();
            break;
        case 6:
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << "Do you want to continue? (1 for yes, 0 for no): ";
        cin >> prompt;

    } while (prompt);

    cout << "\nSummary of the session:" << endl;
    displaySessionSummary(name, age, height, weight, bodyfat, activityLevel, proteinConsumed, exercises, reps, sets, weight_lifted, count);


    return 0;
}

void getCredentials(string &name, int &age, double &height, double &weight, double &bodyfat, int &activityLevel)
{
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter your age: ";
    cin >> age;

    cout << "Enter your height (in centimeters): ";
    cin >> height;

    cout << "Enter your weight (in kilograms): ";
    cin >> weight;

    cout << "Enter your Body Fat(%): ";
    cin >> bodyfat;

    cout << "Enter your activity level (1- Sedentary, 2- Lightly active, 3- Moderately active, 4- Very active, 5- Extra active): ";
    cin >> activityLevel;
}

void showMenu()
{
    cout << "\n***************************************************************" << endl;
    cout << "**************************** GYMKI ****************************" << endl;
    cout << "***************************************************************" << endl;
    cout << "****************** 1. Calorie Calculator  *********************" << endl;
    cout << "****************** 2. Calorie Tracker     *********************" << endl;
    cout << "****************** 3. Protein Calculator  *********************" << endl;
    cout << "****************** 4. Protein Tracker     *********************" << endl;
    cout << "****************** 5. New Workout Session *********************" << endl;
    cout << "****************** 6. Exit                *********************" << endl;
    cout << "***************************************************************" << endl;
    cout << "Enter your choice: ";
}

void calorieCalculator()
{
    double Calories, deficit, surplus;

    Calories = 370 + 21.6 * (1 - (bodyfat / 100)) * weight;
    deficit = Calories * 0.79;
    surplus = Calories * 1.21;

    cout << "Your maintainance Calories are: " << Calories << endl;
    cout << "For weight loss(0.5kg/week): " << deficit << endl;
    cout << "For weight gain(0.5kg/week): " << surplus << endl;
}

void calorieTracker()
{
    double TotalCalories, Breakfast, Lunch, Snack, Dinner;

    cout << "Enter the calories you consumed in your Breakfast today: ";
    cin >> Breakfast;
    cout << "Enter the calories you consumed in your Lunch today: ";
    cin >> Lunch;
    cout << "Enter the calories you consumed in your Snack today: ";
    cin >> Snack;
    cout << "Enter the calories you consumed in your Dinner today: ";
    cin >> Dinner;

    TotalCalories = Breakfast + Lunch + Snack + Dinner;

    cout << "Breakfast= " << Breakfast << " kcal \n";
    cout << "Lunch =    " << Lunch << " kcal \n";
    cout << "Snack =    " << Snack << " kcal \n";
    cout << "Dnner =    " << Dinner << " kcal \n";
    cout << "Your Total Calories for the day = " << TotalCalories << " kcal \n";
}

void proteinCalculator()
{
    double ProteinL, ProteinU;

    ProteinL = weight * 0.8;
    ProteinU = weight * 1.8;

    cout << "You need atleast " << ProteinL << "-" << ProteinU << " grams/day\n";
}

void proteinTracker()
{
    double TotalProteins, Breakfast, Lunch, Snack, Dinner;

    cout << "Enter the protein you consumed in your Breakfast today: ";
    cin >> Breakfast;
    cout << "Enter the protein you consumed in your Lunch today: ";
    cin >> Lunch;
    cout << "Enter the protein you consumed in your Snack today: ";
    cin >> Snack;
    cout << "Enter the protein you consumed in your Dinner today: ";
    cin >> Dinner;

    TotalProteins = Breakfast + Lunch + Snack + Dinner;

    cout << "Breakfast= " << Breakfast << " kcal \n";
    cout << "Lunch =    " << Lunch << " kcal \n";
    cout << "Snack =    " << Snack << " kcal \n";
    cout << "Dnner =    " << Dinner << " kcal \n";
    cout << "Your Total Protein for the day = " << TotalProteins << " kcal \n";
}

void newWorkoutSession()
{
    const int MAX_EXERCISES = 8;
    int weight_lifted[MAX_EXERCISES];
    string exercises[MAX_EXERCISES];
    int reps[MAX_EXERCISES];
    int sets[MAX_EXERCISES];
    int count = 0;
    char continueWorkout = 'y';

    while (count < MAX_EXERCISES && (continueWorkout == 'y' || continueWorkout == 'Y'))
    {
        cout << "Enter exercise name: ";
        cin.ignore();
        getline(cin, exercises[count]);

        cout << "Enter the weight (in kgs): ";
        cin >> weight_lifted[count];

        cout << "Enter reps: ";
        cin >> reps[count];

        cout << "Enter sets: ";
        cin >> sets[count];

        count++;

        if (count < MAX_EXERCISES)
        {
            cout << "Do you want to add another exercise? (y/n): ";
            cin >> continueWorkout;
        }
    }

    cout << "\nWorkout Summary:" << endl;
    showWorkoutSummary(exercises, reps, sets, weight_lifted, count);

    int totalVolume = 0;
    for (int i = 0; i < count; i++)
    {
        totalVolume += (weight_lifted[i] * reps[i] * sets[i]);
    }

    cout << "Total Volume Lifted: " << totalVolume << " Kgs" << endl;
}

void showWorkoutSummary(string exercises[], int reps[], int sets[], int weight_lifted[], int count)
{
    cout << "Exercise\tReps\tSets\tWeight Lifted (Kgs)" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << exercises[i] << "\t" << reps[i] << "\t" << sets[i] << "\t" << weight_lifted[i] << endl;
    }
}

void displaySessionSummary(string name, int age, double height, double weight, double bodyfat, int activityLevel, double proteinConsumed,
                            string exercises[], int reps[], int sets[], int weight_lifted[], int workoutCount)
{   
    
    cout << "\nSession Summary:\n";
    cout << "Name: " << name << endl;
    cout << "Age: " << age << " years" << endl;
    cout << "Height: " << height << " cm" << endl;
    cout << "Weight: " << weight << " kg" << endl;
    cout << "Body Fat: " << bodyfat << "%" << endl;
    
    string activity;
    switch (activityLevel)
    {
        case 1:
            activity = "Sedentary";
            break;
        case 2:
            activity = "Lightly active";
            break;
        case 3:
            activity = "Moderately active";
            break;
        case 4:
            activity = "Very active";
            break;
        case 5:
            activity = "Extra active";
            break;
        default:
            activity = "Unknown";
    }
    
    cout << "Activity Level: " << activity << endl;
    cout << "Total Protein Consumed: " << proteinConsumed << " grams" << endl;
    
    cout << "\nWorkout Summary:\n";
    cout << "Exercise\tReps\tSets\tWeight Lifted (Kgs)" << endl;
    for (int i = 0; i < workoutCount; i++)
    {
        cout << exercises[i] << "\t" << reps[i] << "\t" << sets[i] << "\t" << weight_lifted[i] << endl;
    }
    
    cout << "Thank you for using GYMKI! Have a great day!\n";
}
please fix the error for me and give me the full code with all the hanges 