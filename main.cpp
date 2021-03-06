#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <set>
#include <iomanip>   //setw..
#include <list>
#include <forward_list>
#include <typeinfo>
#include <string>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <deque>
#include <functional>
#include <typeinfo>
#include <iterator>
#include <set>
#include <chrono>
#include <thread>
#include <future>
#include "numbers.h"

using namespace std;

	// taka klasa może być oczywiście przed main() aby miała zasięg globalny!
	//{
		// klasa iteratora, iterująca po liczbach..
		class num_iterator { // musi ++
			long long i;
			bool increase; // rosnie? maleje?
		public:			
			// część : i(valueOfi) od razu ustawia this->i = valueOfi itd.
			num_iterator(long long valueOfi=0, bool inc=true) 
				: i(valueOfi),increase(inc) {}

			long long operator*() { return i; } // wyłuskanie

			num_iterator& operator++() { 
				if (increase) ++i; else --i;
				return *this; 
			}			

			bool operator!=(num_iterator& other) { return i != other.i; }
		};
		class range {
			long long a;
			long long b;
		public:
			range(long long from, long long to) : a{ from }, b{ to } {}
			num_iterator begin() { 
				if (a<b) return num_iterator{ a,true }; 
				return num_iterator{ a,false };
			}
			num_iterator end() { 				
				if (a<b) return num_iterator{ b + 1, true };
				return num_iterator{ b - 1, false };
			} 
		};


void function1(){

vector<int>vec;
int a,b;
cout << "od ilu " << "";
cin >> a;
cout << "do ilu " << "";
cin >> b;
for(int i : range(a,b)){
vec.push_back(i);
}
cout << "ZAWARTOSC KONTENERA: " << endl;
printSTL(vec , " " , true);

}

void function2(){
    cout << endl;

    vector<int>vec2;
int a,b;
cout << "od ilu " << "";
cin >> a;
cout << "do ilu " << "";
cin >> b;
for(int i : range(a,b)){
vec2.push_back(i * 2);
}
cout << "ZAWARTOSC KONTENERA MNOZONEGO RAZY 2: " << endl;
printSTL(vec2 , " " , true);

}

int main(){

for(int i : range(-100,10)){  // zasieg(od,do)..
    cout << i << " ";
}
cout << endl;
cout << endl;

for(int i : range (18,-18)){
    cout << i << " ";
}
cout << endl;

cout << endl << string(200,'%') << endl;
cout << endl << string(200,'#') << endl;
cout << endl << string(200,'$') << endl;

cout << endl;

function1();
function2();
    
    return 0;
}