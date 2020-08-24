#include "../headers/Heart.h"


/**
 * Date - Constructor about Date Class
 * @month: (string) month where is located
 * @day: (string) month where is located
 * @year: (string) year where is located
 *
 */
HeartRates::HeartRates(std::string nam, std::string birth, int d, int m, int y)
  : name(nam), birthday(birth), day(d), month(m), year(y)
{

}


/**
 * set_month - Sanitize the value of name
 * @nam: (string) name of the value
 *
 */
void HeartRates::set_name(std::string nam)
{
  name = nam;
}


/**
 * set_birth - Sanitize the value of birth
 * @birth: (string) Birthday of the person
 *
 */
void HeartRates::set_birth(std::string birth)
{
  birthday = birth;
}


/**
 * set_month - Sanitize the value of month
 * @month: (string) month where is located
 *
 */
void HeartRates::set_month(int m)
{
  if (m >= 0 && m <= 12)
    month = m;
  else {
    month = 1;
    std::cerr << "Enter the number of the 1-12" << std::endl;
  }
}


/**
 * set_day - Sanitize the value of day
 * @day: (string) month where is located
 *
 */
void HeartRates::set_day(int d)
{
  if (d > 0 && d <= 31)
    day = d;
  else {
    day = 1;
    std::cerr << "Enter the number of the 0-31" << std::endl;
  }
}


/**
 * set_year - Sanitize the value of year
 * @year: (string) year where is located
 *
 */
void HeartRates::set_year(int y)
{
  if (y >= 1900 && y <= 2002)
    year = y;
  else {
    year = 2020;
    std::cerr << "Enter the number of the 1900-2002" << std::endl;
  }
}


/**
 * get_month - Show the month
 *
 * Return: (int) month of the year
 */
int HeartRates::get_month(void) const
{
  return month;
}


/**
 * get_day - Show the day
 *
 * Return: (int) day of the year
 */
int HeartRates::get_day(void) const
{
  return day;
}


/**
 * get_year - Show year
 *
 * Return: (int) Year
 */
int HeartRates::get_year(void) const
{
  return year;
}


/**
 * get_Maxiumum_Heart_Rate - Show the the maximum rate
 *
 */
void HeartRates::get_Maxiumum_Heart_Rate(void) const
{
  int y_curr = get_year();

  if (year < 2020)
  {
    y_curr = 2020 - y_curr;
    if (get_year() > 2020) {
      --y_curr;
    }
    if (get_month() == 2020) {
      if (14 > get_day())
        --y_curr;
    }
  }

  int frec_Max = 220 - y_curr;

  std::cout << "\nThe 100% is: " << frec_Max << std::endl;
}


/**
 * get_Maxiumum_Heart_Rate - Show the the maximum rate
 *
 */
void HeartRates::get_Target_Heart_Rate(void) const
{
  int y_curr = get_year();

  if (year < 2020)
  {
    y_curr = 2020 - y_curr;
    if (get_year() > 2020) {
      --y_curr;
    }
    if (get_month() == 2020) {
      if (14 > get_day())
        --y_curr;
    }
  }

  // Get the current Freq
  int frec_Max = 220 - y_curr;
  int percentage = ((frec_Max * 50) / 100);

  std::cout << "\nThe 50% is: " << percentage << std::endl;

  percentage = ((frec_Max * 85) / 100);
  std::cout << "The 85% is: " << percentage << std::endl;
}


/**
 * DisplayDate - Show date format
 *
 */
void HeartRates::DisplayHeartRates(void)
{
  std::cout << get_day() << "/" << get_month() << "/"
  << get_year() << std::endl;

  get_Maxiumum_Heart_Rate();
  get_Target_Heart_Rate();
}
