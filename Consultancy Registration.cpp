#include <iostream>
using namespace std;

double calcFee(int coursecode, int numPeople) {
    double totalFee = 0.0;
    switch(coursecode) {
        case 1:
            totalFee = numPeople * 150.0;
            break;
        case 2:
            totalFee = numPeople * 200.0;
            break;
        case 3:
            totalFee = numPeople * 300.0;
            break;
        default:
            cout << "Invalid course code" << endl;
    }
    return totalFee;
}

double getDisc(double totalFee, int numPeople) {
    if (numPeople >= 30) {
        return totalFee * 0.9;
    }
    return totalFee;
}

int main() {
    char userContinue;
    string courseNames[] = {"MS Office", "Web Development", "Mobile Apps Development"};
    double feesPerPerson[] = {150.0, 200.0, 300.0};
    double newFeesPerPerson[] = {150.0, 200.0, 300.0}; // Array to store new fee per person after discount

    // Arrays to store totals for each course
    double totalFees[3] = {0.0};
    double totalFeesAfterDiscount[3] = {0.0};
    int totalNumPeople[3] = {0};

    do {
        int coursecode, numPeople;

        cout << "##### ANN CONSULTANCY #####\n\n1. Ms Office\n2. Web Development\n3. Mobile Apps Development\n\n";
        cout << "Enter coursecode : ";
        cin >> coursecode;
        cout << "Enter number of people: ";
        cin >> numPeople;

        double totalFee = calcFee(coursecode, numPeople);
        double totalFeeAfterDiscount = getDisc(totalFee, numPeople);

        // Update totals for each course
        totalFees[coursecode - 1] += totalFee;
        totalFeesAfterDiscount[coursecode - 1] += totalFeeAfterDiscount;
        totalNumPeople[coursecode - 1] += numPeople;

        // Apply discount for new fee per person if applicable
        if (numPeople >= 30) {
            newFeesPerPerson[coursecode - 1] = feesPerPerson[coursecode - 1] * 0.9;
        }

        cout << "                                   ANN Consultancy \n ********************************************************************************** \n";
        cout << "Course                  		:	" << courseNames[coursecode - 1] << endl;
        cout << "Fees per person     	    		: 	RM" << feesPerPerson[coursecode - 1] << endl;
        cout << "Number of person enrolled		:  	" << numPeople << endl;
        cout << "Total Fees				:	RM" << totalFee << endl;
        cout << "Discount				:	RM" << totalFee - totalFeeAfterDiscount << endl;
        cout << "Total fee after discount 		:	RM" << totalFeeAfterDiscount << endl;
        cout << "New fee per person			:	RM" << newFeesPerPerson[coursecode - 1] << endl;

        cout << "\nContinue? (Y/N): ";
        cin >> userContinue;
    } while (userContinue == 'Y' || userContinue == 'y');

    // Output total receipt
    cout << "\nTotal Receipt:\n";
    for (int i = 0; i < 3; ++i) {
        cout << "********************************************************************************** \n";
        cout << "Course                  		:	" << courseNames[i] << endl;
        cout << "Total number of people enrolled	        :  	" << totalNumPeople[i] << endl;
        cout << "Total Fees				:	RM" << totalFees[i] << endl;
        cout << "Total discount				:	RM" << totalFees[i] - totalFeesAfterDiscount[i] << endl;
        cout << "Total fee after discount 		:	RM" << totalFeesAfterDiscount[i] << endl;
        cout << "New fee per person			:	RM" << newFeesPerPerson[i] << endl;
    }

    return 0;
}
