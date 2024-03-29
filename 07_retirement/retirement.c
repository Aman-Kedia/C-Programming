#include<stdio.h>
#include<stdlib.h>
struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
};

  typedef struct _retire_info retire_info;

double next_balance(double balance, retire_info ri)
{
  return balance * (1 + ri.rate_of_return) + ri.contribution;
}
void calc_y_m(int months, int *year, int *month) {
  *year = months / 12;
  *month = months % 12;
}
void balance_info(int months, double balance)
{
  int age;
  int month;
  calc_y_m(months, &age, &month);
  printf("Age %3d month %2d you have $%.2lf\n", age, month, balance);
}

void retirement(
  int startAge, //in months
  double initial, //initial saving in dollars
    retire_info working,  //info about working
    retire_info retired)  //info about being retired

    {
      int a;
      int age_months = startAge;
      double balance = initial;
      for(a=0; a<working.months; a++)
	{
	  balance_info(age_months, balance);
	  age_months++;
	  balance = next_balance(balance, working);
	}
      for(a=0; a<retired.months; a++)
	{
	  balance_info(age_months, balance);
	  age_months++;
	  balance = next_balance(balance, retired);
	}
    }
int main(void)
{
  retire_info working = {489, 1000.0, 0.045 / 12};
  retire_info retired = {384, -4000.0, 0.01 / 12};
  int start_age_months = 327;
  double savings = 21345;

  retirement(
    start_age_months,
      savings,
      working,
      retired);

  return EXIT_SUCCESS;
}
