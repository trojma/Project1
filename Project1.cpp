#include <iostream>
#include <string>
class Patient{
    private:
        std::string firstName;
        std::string lastName;
        std::string gender;
        int month, day, year;
        double height, weight;
        int ageInYears = 0;
    public:
        Patient(std::string, std::string, std::string, int, int,int, double,double);

        void setFirstName(std::string);
        void setLastName(std::string);
        void setGender(std::string);
        void setDOB(int, int, int);
        void setMonth(int);
        void setDay(int);
        void setYear(int);
        void setAge();
        void setHeight(int);
        void setWeight(int);

        std::string getFirstName();
        std::string getLastName();
        std::string getGender();
        int getMonth();
        int getDay();
        int getYear();
        void getDOB();
        int getAge();
        double getHeight();
        double getWeight();

        double getBMI();
        void getTargetHeartRate();
        int getMaxHeartRate();

        void showPatient();
        void printBMIInfo();
};
Patient::Patient(std::string fName, std::string lName, std::string sex, int m, int d, int y, double h, double w){
    setFirstName(fName);
    setLastName(lName);
    setGender(sex);
    setDOB(m,d,y);
    setHeight(h);
    setWeight(w);
    setAge();
}
void Patient::setFirstName(std::string fName){
    firstName = (fName.length() > 0) ? fName : "FirstName";
}
void Patient::setLastName(std::string lName){
    lastName = (lName.length() > 0) ? lName : "LastName";
}
void Patient::setGender(std::string sex){
    gender = (sex == "Male" || sex == "Female") ? sex : "Undefined";
}
void Patient::setDOB(int m, int d, int y) {
    setMonth(m);
    setDay(d);
    setYear(y);
}
void Patient::setMonth(int m) { month = (m > 0 && m <= 12) ? m : 1;}
void Patient::setDay(int d) { day = (d > 0 && d <=31) ? d : 1;}
void Patient::setYear(int y) { year = y; }
void Patient::setAge() {
    int cDay, cMonth, cYear;
    std::cout << "Enter the current date (mm dd yy): ";
    std::cin >> cMonth, cDay, cYear;
    if (cMonth < getMonth()){
        ageInYears = (cYear - getYear()) - 1;
    } else if (cMonth > getMonth()){
        ageInYears = cYear -  getYear();
    } else {
        if (cDay < getDay()){
            ageInYears = (cYear - getYear()) - 1;
        } else {
            ageInYears = cYear - getYear();
        }

    }

}
void Patient::setHeight(int h) {height = h; }
void Patient::setWeight(int w) {weight = w; }

std::string Patient::getFirstName() {return firstName; }
std::string Patient::getLastName() {return lastName; }
std::string Patient::getGender() {return gender; }
int Patient::getMonth() {return month; }
int Patient::getDay() {return day; }
int Patient::getYear() {return year; }
void Patient::getDOB() {
    std::cout << getMonth() << "/" << getDay() << "/" << getYear() << std::endl;
}
int Patient::getAge() {
    if (ageInYears == 0) setAge();
    return ageInYears;
}
double Patient::getHeight() {return height; }
double Patient::getWeight() {return weight; }
double Patient::getBMI() {
    return ((getWeight() * 703 / (getHeight() * getHeight())));
    }
void Patient::getTargetHeartRate() {
    std::cout << "Your target heart rate: ";
   std::cout << 0.5 * getMaxHeartRate() << " - " << 0.85 * getMaxHeartRate() 
    << std::endl;
}    
int Patient::getMaxHeartRate() {return 220 - getAge(); }
void Patient::showPatient() {
	system("clear");
    std::cout <<"HEALTH PROFILE FOR :"<< getFirstName() << " " << getLastName() << std::endl;
    std::cout <<"Gender :" <<getGender() << std::endl;
    std::cout <<"Age :" <<getAge() << std::endl;
    std::cout <<"BMI :" <<getBMI() << std::endl;
    getTargetHeartRate();
    std::cout <<"Max Heart Rate :" << getMaxHeartRate() <<std::endl;
    printBMIInfo();
}
void Patient::printBMIInfo() {
    std::cout << "\n BMI VALUES" << std::endl;
    std::cout << "Underweight : less than 18.5" << std::endl;
    std::cout << "Normal : between 18.5 and 24.9" <<std::endl;
    std::cout << "Overweight : between 25 and 29.9" <<std::endl;
    std::cout << "Obese : 30 or greater\n" <<std::endl;
}
#include <iostream>
int main(int argc, const char *argv[]) {
    std::string fName, lName, gender;
    int month, day, year;
    double weight, height;
    char character;
system("clear");
    std::cout << "\n\n\n\t\t\t  ---------------HEALTH SYSTEM---------------"<<std::endl;
	std::cout << "\t\t\t|                                             |"<<std::endl;
	std::cout << "\t\t\t|  Press Y to continue and press N to exit    |"<<std::endl;
	std::cout << "\t\t\t|                                             |"<<std::endl;
	std::cout << "\t\t\t|                                             |"<<std::endl;
	std::cout << "\t\t\t ---------------------------------------------"<<std::endl;
    	input:
	std::cout << "\n\t\t\tEnter Input [Y/N] : ";
	std::cin >> character;
	
	switch(character){
		case 'Y' :
		case 'y' :
			goto menu;
			break;
		case 'N' :
		case 'n' :
            system("PAUSE");
			std::cout<<"\n\t\t\tIf symptoms persist seek professional medical intervention\n";
        	exit(EXIT_SUCCESS);	
			break;
		default :
			std::cout << "\n\t\t\tWrong input"<<std::endl;
			goto input;
			break;
					
	}
    menu:
    system("clear");
    std::cout << "\n\n\t\tEnter your first and last name :";
    std::cin >> fName >> lName;
    std::cout << "\n\n\t\tEnter your gender (Male/Female) :";
    std::cin >> gender;
    std::cout << "\n\n\t\tEnter your date of birth (mm dd yyyy) :";
    std::cin >> month >> day >> year;
    std::cout << "\n\n\t\tEnter your weight in pounds :";
    std::cin >> weight;
    std::cout << "\n\n\t\tEnter your height in inches :";
	std::cin >> height;
    
    Patient hp(fName, lName, gender, month, day, year, height, weight);
    hp.showPatient();
    return 0;

}
