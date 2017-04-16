#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

int MAX = 100000;

bool areTwinPrimes(int tab[], long long n, long long k){
    long long j = sqrt(n)+1;
    int i;
    for(i = 0; i < MAX && tab[i] <= j; i++){
        if(n % tab[i] == 0 || k % tab[i] == 0) {
            return 0;
        }
    }
    if(i >= MAX-1)
        std::cout<<"Czas juz zdecydowanie zamknac program, dalsze wyniki sa bledne."<<std::endl;
    return 1;
}
/* CREATING AN ARRAY WITH FIRST (MAX == 100000) PRIMES */
void initTab(int tab[]){
    bool isPrime = 1;
    for(int temp = 0, prime = 5; temp < MAX; temp++){
        for(;; prime++, isPrime = 1){
            for(long i = 2, j = sqrt(prime); i <= j; ++i){
                if(prime % i == 0) {
                    isPrime = 0;
                    break;
                }
            }
            if(isPrime){
                tab[temp] = prime;
                prime++;
                break;
            }
        }
    }
}

int main(){
	// used to print how much time was needed to find next 10.000 twin primes (in secs)
    long t;
    long long maybeLowerTwinNumber = 5;
    long  counter = 0;
	// array with prime numbers - primes
    int tab[MAX] = {};
    initTab(tab);
    t = time(NULL);
    for(;;maybeLowerTwinNumber += 6){
        if(areTwinPrimes(tab, maybeLowerTwinNumber, maybeLowerTwinNumber+2)){
            if(++counter % 10000 == 0){
                std::cout<<counter<<":  "<<maybeLowerTwinNumber<<"  "<<maybeLowerTwinNumber+2<<"  "<<time(NULL) - t<<"s"<<std::endl;
                t = time(NULL);
            }
        }
    }
    return 0;
}
