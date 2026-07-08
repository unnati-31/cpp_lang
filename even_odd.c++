#include <iostream>
#include <vector>

int main() {
  //code for printing sum for even numbers and printing product for even numbers.  
  std::vector<int> num = {2, 4, 3, 6, 1, 9, 8, 0, 8, 5, 7, 3, 3};

  int sum = 0;
  int product = 1;

  for(int i = 0; i < num.size(); i++) {
    if(num[i] % 2 == 0) {
      sum+= num[i]; 
    }  
    else {
      product*=num[i];
      
    }
  } 
    
  std::cout << "The sum of even numbers: " << sum << "\n";
  std::cout << "The product of odd numbers: " << product << "\n";
}