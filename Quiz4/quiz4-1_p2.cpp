#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main()  {
  //assuming user is told to round
  int weight;     //0 < weight < 20 (kg)
  int distance;   //min:10 mi, max: 3000 mi
  float const rate1 = 1.10;
  float const rate2 = 2.20;
  float const rate3 = 3.70;
  float const rate4 = 4.80;
  float charges;  //based on rate & distance

  //user prompts
  cout << "Please enter weight of your package in kg\n";
  cout << "as a whole number. Round up: ";
  cin >> weight;
  cout << "Please enter the distance, and you may round down: ";
  cin >> distance;

  //input validation
  if (weight > 0 && weight <= 20 && distance > 10 && distance <= 3000)  {
    if (distance >= 500)  {
      if (weight < 2.0) {
        charges = ((distance/500) * rate1);
        cout << "Amount to be charged: $ " << setprecision(2) << fixed << charges << endl;
        cout << "Distance: " << distance << " mi, and weight: " << weight << " kg.\n";
      } else if (weight >= 2.0 && weight < 6.0) {
          charges = ((distance/500) * rate2);
          cout << "Amount to be charged: $ " << setprecision(2) << fixed << charges << endl;
          cout << "Distance: " << distance << " mi, and weight: " << weight << " kg.\n";
      } else if (weight >= 6.0 && weight < 10.0)  {
          charges = ((distance/500) * rate3);
          cout << "Amount to be charged: $ " << setprecision(2) << fixed << charges << endl;
          cout << "Distance: " << distance << " mi, and weight: " << weight << " kg.\n";
      } else  {   //(weight >= 10.0 && weight < 20.0)
          charges = ((distance/500) * rate4);
          cout << "Amount to be charged: $ " << setprecision(2) << fixed << charges << endl;
        cout << "Distance: " << distance << " mi, and weight: " << weight << " kg.\n";
      }
    }
  } else if (weight > 0 && distance < 500)  {
    charges = rate1;
    cout << "Amount to be charged: $ " << setprecision(2) << fixed << charges << endl;
    cout << "Distance: " << distance << " mi, and weight: " << weight << " kg.\n";
  } else { //when initial validation checks for weight and distance not satisfied
      cout << "\nYou may have entered invalid parameters, and we cannot serve your needs.\n";
  }

return 0;
  
}