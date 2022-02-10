#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

class Wall {
        
        double dimensions[2]; //feet
        double area; //square feet
        const int length = 0; //placeholder for readability
        const int width = 1; //placeholder for readability

    public:
        Wall() {
            area = 0;
            for(int i=0; i<2; i++) {
                dimensions[i] = 0;
            }
        }
        void enterDimensions() {
            cin >> dimensions[length] >> dimensions[width] ;
        }
        void calculateArea() {
            area = dimensions[length]*dimensions[width];
        }
        double returnArea() {
            return area;
        }
};

class Paint {
    
        string name;
        string type;
        double costPerGallon; //dollars
        float coverage; //square feet
    protected:
        void enterName() {
            cin.ignore();
            cout << "Enter the name of the paint: " ;
            getline(cin, name); 
        }
         void enterType() {
            cout << "Enter the type of the paint: " ;
            getline(cin, type);
        }
        void enterCost() {
            cout << "Enter the cost of paint per gallon in dollars: " ;
            cin >> costPerGallon;
        }
        void enterCoverage() {
            cout << "Enter the coverage of one gallon of paint in square feet: " ;
            cin >> coverage;
        }

    public:
        Paint() {
            costPerGallon = 0;
            coverage = 0; 
        }
        void enterInfo() {
            cout << "Now enter the paint information for this room" <<endl;
            enterName();
            enterType();
            enterCost();
            enterCoverage();
        }
        void printName(ostream &out=cout) {
            out << name << endl;
        }
        void printType(ostream &out=cout) {
            out << type << endl;
        }
        double returnCost() {
            return costPerGallon;
        }
        double returnCoverage() {
            return coverage;
        }
};

class Room {
    
        vector<Wall> walls;
        Paint roomPaint;
        string name;
        double costEstimate; //dollars
        double paintNeeded; //gallons
        int numWalls;
        double area; // square feet

    protected:
        void enterName() {
            cin.ignore();
            cout << "Enter the name of the room: " ;
            getline(cin, name);
        }
        void createWalls() {
            cout << "Enter the number of walls in this room: " ;
            cin >> numWalls;
            for(int i=0; i<numWalls; i++) {
                Wall temp;
                cout << "Enter the length and width of wall " << i + 1 << " in feet: " ;
                temp.enterDimensions();
                temp.calculateArea();
                walls.push_back(temp);
            }
        }
    public:
        Room() {
            costEstimate = 0;
            paintNeeded = 0;
            numWalls = 0;
            area = 0; 
        }
        void createRoom() {
            enterName();
            createWalls();
            roomPaint.enterInfo();
        }
        double returnArea() {
            return area;
        }
        double returnPaintNeeded() {
            return paintNeeded;
        }
        double returnCostEstimate() {
            return costEstimate;
        }
        void printInfo(ostream &out=cout) {
            
            out << " " <<endl;
            out << name << " Room Information" <<endl;
            out << "Paint Name: " ;
            roomPaint.printName();
            out << "Paint Type: " ;
            roomPaint.printType();
            out << "Area of Walls: " << fixed << setprecision(2) << area << " square feet" <<endl;
            out << "Gallons Needed: " << fixed << setprecision(2) << paintNeeded << endl;
            out << "Total Cost Estimate: " << fixed << setprecision(2) << costEstimate << " dollars" <<endl;
        }
        void calculateTotals() {
            for(int i = 0; i<walls.size(); i++) {
                area += walls[i].returnArea();
            }
            paintNeeded = area/roomPaint.returnCoverage();
            costEstimate = paintNeeded*roomPaint.returnCost();
        }
};

class House {
    
    vector<Room> rooms;
    int numRooms;
    double totalArea; //square feet
    double totalPaint; //gallons
    double totalCostEstimate; //dollars
    

    protected:
        void calculateTotals() {
            for(int i=0; i<rooms.size(); i++) {
                rooms[i].calculateTotals();
                totalArea += rooms[i].returnArea();
                totalCostEstimate += rooms[i].returnCostEstimate();
                totalPaint += rooms[i].returnPaintNeeded();
            }
        }
    public:
        House(){
            numRooms = 0;
            totalArea = 0;
            totalPaint = 0;
            totalCostEstimate = 0;
        }
        void createHouse(int roomNum) {
            numRooms = roomNum;
            for(int i=1; i<=roomNum; i++) {
                Room temp;
                cout << "Information for Room " << i <<endl;
                temp.createRoom();
                rooms.push_back(temp);
            }
        }
        void printInfo(ostream &out=cout) {
            
            calculateTotals();
            
            out << "Information for Each Room " <<endl;
            for(int i=0; i<rooms.size(); i++) {
               rooms[i].printInfo();
            }   
            out << " " << endl;
            out << "Total Project Info" <<endl;
            out << "Number of Rooms: " << numRooms <<endl;
            out << "Total Area to Paint: " << fixed << setprecision(2) << totalArea << " square feet" <<endl;
            out << "Total Gallons of Paint Needed: " << fixed << setprecision(2) << totalPaint << endl;
            out << "Total Project Cost Estimate: " << fixed << setprecision(2) << totalCostEstimate << " dollars"<<endl; 
        }
};


int main() {
        
    int roomNum;
    House project;

    cout << "Welcome to the Paint Cost Calculator" <<endl;
    cout << "Enter the number of rooms in the house: " ;
    cin >> roomNum;

    project.createHouse(roomNum);
    project.printInfo();

   
    return 0;
}

