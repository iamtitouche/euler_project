#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

int main()
{
    int count = 0;
    for (int n = 1; n <= 9; n++)
    {
        uint64_t power_of_10 = (uint64_t) pow(10, n);

        printf("n = %i, power_of_10 = %i\n", n, power_of_10);
        for(uint64_t p = 1; p <= 2 * power_of_10; p++) {
            // printf("   p = %i\n", p);
            uint64_t a_start = (uint64_t) power_of_10 / p;
            //if (p == 1)
           // {a_start++;}
            for (uint64_t a = a_start; a <= 2 * power_of_10 / p; a++)
            {
                if (p * a > power_of_10)
                {
                    if (a * power_of_10 % (p * a - power_of_10) == 0) {
                        count++;
                    }
                }
            }
        }
    }
    printf("Answer : %d\n", count);

    return EXIT_SUCCESS;
}


/*
int pgcd(int a, int b)
{
    int c;
    if (a < b)
    {
        c = b;
        b = a;
        a = c;
    }
    while (b != 0)
    {
        c = b;
        b = a % b;
        a = c;
    }
    return a;

    return EXIT_SUCCESS;
}*/
/*
int check_solution(int a, int b, int p, int power_of_10)
 {
  int div_1 = pgcd(a + b, a * b);
  printf("%i, %i, %i\n", a,b, div_1);
  int num_1 = (a + b) / div_1;
  int den_1 = a * b / div_1;
  int div_2 = pgcd(p, power_of_10);
  int num_2 = p / div_2;
  int den_2 = power_of_10 / div_2;
  if (num_1 == num_2 && den_1 == den_2) {return 1;}
  return 0;
 }*/