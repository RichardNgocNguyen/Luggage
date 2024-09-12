#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class luggage{
  protected:
    int sn;
    string type;
    static int genSN;

    static int total;
    static double volume;

    static int box_total;
    static double box_volume;

    static int cube_total;
    static double cube_volume;  

    static int sphere_total;
    static double sphere_volume; 

    static int pyramid_total;
    static double pyramid_volume;

    static int cylinder_total;
    static double cylinder_volume;  

    double radius, height, base, width, length;
  public:
    luggage(){
      total++;
      genSN++;
      cout << "Creating Luggage" << endl;
    }
    virtual ~luggage(){
      total--;
    }
    static int getTotal(){
      return total;
    }
    static double getTotalVolume(){
      return volume;
    }
    void increaseVolume(double add){
      volume = volume + add;
    }
    void reduceVolume(double sub){
      volume = volume - sub;
    }
    virtual int getSN() = 0;
    virtual string getType() = 0;
    virtual double getVolume() = 0;
};

class box:public luggage{
  public:
    box(double w, double h, double l){
      width = w;
      height = h;
      length = l;
      type = "Box";
      sn = luggage::genSN;
      increaseVolume(getVolume());
      box_volume = box_volume + getVolume();
      box_total++;
    }
    ~box(){
      box_total--;
      box_volume = box_volume - getVolume();
      reduceVolume(getVolume());
    }
    static int getTotal(){
      return box_total;
    }
    static double getTotalVolume(){
      return box_volume;
    }
    string getType(){
      return type;
    }
    int getSN(){
      return sn;
    }
  double getVolume(){
    return width*height*length;
   
  }
};

class cube:public luggage{
  public:
    cube(double w){   
      width = w;
      increaseVolume(getVolume());
      sn = luggage::genSN;
      type = "Cube";
      cube_volume = cube_volume + getVolume();
      cube_total++;
    }
    ~cube(){
      cube_total--;
      cube_volume = cube_volume - getVolume();
      reduceVolume(getVolume());
    }
    static int getTotal(){
      return cube_total;
    }
    static double getTotalVolume(){
      return cube_volume;
    }
    string getType(){
      return type;
    }
    int getSN(){
      return sn;
    }
    double getVolume(){
     return width*width*width;

    }
};

class sphere:public luggage{
  public:
    sphere(double r){   
      radius = r;
      increaseVolume(getVolume());
      sphere_volume = sphere_volume + getVolume();
      sn = luggage::genSN;
      type ="Sphere";
      sphere_total++;
    }
    ~sphere(){
      sphere_total--;
      sphere_volume = sphere_volume - getVolume();
      reduceVolume(getVolume());
    }
    static int getTotal(){
      return sphere_total;
    }
    static double getTotalVolume(){
      return sphere_volume;
    }
    string getType(){
      return type;
    }
    int getSN(){
      return sn;
    }
    double getVolume(){
      return 4  * (3.1415926 * radius * radius * radius) / 3;
  }
};

class pyramid:public luggage{
  public:
    pyramid(double b, double h){   
      base = b;
      height = h;
      increaseVolume(getVolume());
      pyramid_volume = pyramid_volume + getVolume();
      type = "Pyramid";
      sn = luggage::genSN;
      pyramid_total++;
    }
    ~pyramid(){ 
      pyramid_total--;
      pyramid_volume = pyramid_volume - getVolume();
      reduceVolume(getVolume());
    }
    static int getTotal(){
      return pyramid_total;
    }
    static double getTotalVolume(){
      return pyramid_volume;
    }
    string getType(){
      return type;
    }
    int getSN(){
      return sn;
    }
    double getVolume(){
      return base * height * 0.333333;
    }
};

class cylinder:public luggage{
  public:
    cylinder(double r, double h){   
    radius = r;
    height = h;
    increaseVolume(getVolume());
    cylinder_volume = cylinder_volume + getVolume();
    type = "Cylinder";
    sn = luggage::genSN;
    cylinder_total++;
    }
    ~cylinder(){
      cylinder_total--;
      cylinder_volume = cylinder_volume - getVolume();
      reduceVolume(getVolume());
      
    }
    static int getTotal(){
      return cylinder_total;
    }
    static double getTotalVolume(){
      return cylinder_volume;
    }
    string getType(){
      return type;
    }
    int getSN(){
      return sn;
    }
    double getVolume(){
      return height * 3.1415926 * radius * radius;
    }
};

ostream& operator<<(ostream& out, luggage *l){
  return out << left << setw(10) << l -> getType() << right << setw(10) << setprecision(1) << fixed << l -> getVolume() << right << setw(10) << " (SN:"<< l -> getSN() << ")" << endl;
  
}

int luggage::genSN = 0;

int luggage::total = 0;
int luggage::box_total = 0;
int luggage::cube_total = 0;
int luggage::sphere_total = 0;
int luggage::pyramid_total = 0;
int luggage::cylinder_total = 0;

double luggage::volume = 0;
double luggage::box_volume = 0;
double luggage::cube_volume = 0;
double luggage::sphere_volume = 0;
double luggage::pyramid_volume = 0;
double luggage::cylinder_volume = 0;

int main(){
  vector<luggage*> container;
  luggage *lptr;  
  int choice = 0;
  int lugg = 0;
  while (choice != 5) { 
    double length;
    double height;
    double width;
    double base;
    double radius;
    cout << "1. Add Luggage or Storage Container" << endl;
    cout << "2. Remove Luggage from Strorage Container" << endl;
    cout << "3. Show All Luggage" << endl;
    cout << "4. Show Total Volume" << endl;
    cout << "5. Quit" << endl;
    cin >> choice;
    if (choice == 1){ 
      cout << "What luggage shape will you add?" << endl;
      cout << "1. Box" << endl;
      cout << "2. Cube" << endl;
      cout << "3. Sphere" << endl;
      cout << "4. Pyramid" << endl;
      cout << "5. Cylinder" << endl;
      cin >> lugg;
      switch(lugg) {
        case 1:
          cout << "Enter the Width, Height and Length in Order" << endl;
          cin >> width;
          cin >> height;
          cin >> length;
          cout << endl;
          lptr = new box(width, height, length);
          container.push_back(lptr);
          break;
        case 2:
          cout << "Enter the Width" << endl;
          cin >> width;
          cout << endl;
          lptr = new cube(width);
          container.push_back(lptr);
          break;
        case 3:
          cout << "Enter the Radius" << endl;
          cin >> radius;
          cout << endl;
          lptr = new sphere(radius);
          container.push_back(lptr);
          break;
        case 4:
          cout << "Enter Base and Height in Order" << endl;;
          cin >> base;
          cin >> height;
          cout << endl;
          lptr = new pyramid(base, height);
          container.push_back(lptr);
          break;
        case 5:
          cout << "Enter Radius and Length in Order" << endl;;
          cin >> radius;
          cin >> length;
          cout << endl;
          lptr = new cylinder(radius, length);
          container.push_back(lptr);
          break;
        default:
          cout << "Invalid Input! Program Ending" << endl;
          choice = 5;
          break;
      }
    }
    else if (choice == 2){ 
      int remove = 0;
      int count = 0;
      cout << endl;
      for(auto l:container) { 
        cout << ++count<<") "<< l  << endl;
      }
      cout << "Which lugguage do you want to remove?" << endl;
      cin >> remove;
      cout << endl;
      vector<luggage*>::iterator it = container.begin() + remove -1;
      delete* it;
      container.erase(it);
    }
          
    else if (choice == 3){ 
      int count = 0;
      cout << endl;
      for(auto l:container) { 
        cout << ++count<<") "<< l  << endl;
      }
      cout << left << setw(20) << "Total Volume:" << right << setw(5) << luggage::getTotalVolume() << endl << endl;
      cout << left << setw(20) << "Total Luggage:" << right << setw(10) << luggage::getTotal() << endl;
      cout << left << setw(20) << "Total Boxes:" << right << setw(10) << box::getTotal() << endl;
      cout << left << setw(20) << "Total Cubes:" << right << setw(10) << cube::getTotal() << endl;
      cout << left << setw(20) << "Total Spheres:" << right << setw(10) << sphere::getTotal() << endl;
      cout << left << setw(20) << "Total Pryamids:" << right << setw(10) << pyramid::getTotal() << endl;
      cout << left << setw(20) << "Total Cylinders:" << right << setw(10) << cylinder::getTotal() << endl;
      cout << endl;
    }
    else if (choice == 4){ 
      cout << endl;
      cout << left << setw(10) << "ITEM TYPE" << setprecision(1) << fixed << right << setw(20) << "TOTAL VOLUME" << endl;
      cout << left << setw(10) << "Box" << setprecision(1) << fixed << right << setw(20) << box::getTotalVolume() << endl;
      cout << left << setw(10) << "Cube" << setprecision(1) << fixed << right << setw(20) << cube::getTotalVolume() << endl;
      cout << left << setw(10) << "Sphere" << setprecision(1) << fixed << right << setw(20) << sphere::getTotalVolume() << endl;
      cout << left << setw(10) << "Pryamid" << setprecision(1) << fixed << right << setw(20) << pyramid::getTotalVolume() << endl;
      cout << left << setw(10) << "Cylinder" << setprecision(1) << fixed << right << setw(20) << cylinder::getTotalVolume() << endl;
      cout << left << setw(10) << "Luggage" << setprecision(1) << fixed << right << setw(20) << luggage::getTotalVolume() << endl;
      cout << endl;
    }
    else if (choice == 5){
      cout << "Bye Bye! Program Ending" << endl;
    }
    else {
      cout << "Invalid Input! Program Ending" << endl;
      choice = 5;
    }
  }
}