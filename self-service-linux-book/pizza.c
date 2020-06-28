/*
 * =====================================================================================
 *
 *       Filename:  pizza.c
 *
 *    Description:  Example for x86_64 stack
 *        Version:  1.0
 *        Created:  05/21/2020 07:08:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#define pizza       50
#define large       51
#define thin_crust  52
#define cheese      1
#define pepperoni   2
#define onions      3
#define peppers     4
#define mushrooms   5
#define sausage     6
#define pineapple   7
#define bacon       8
#define ham         9

int make_pizza(int size, int crust_type, int topping1, int topping2, 
    int topping3, int topping4, int topping5,  int topping6,
      int topping7, int topping8, int topping9 )
 {
    int return_value = 0;

    /* do stuff */
    return return_value;
}

int make_dinner(int meal_type)
{
    int return_value = 0;

    return_value = make_pizza(large, thin_crust, cheese, pepperoni, onions,
            peppers, mushrooms, sausage, pineapple, bacon, ham);
    
    return return_value;
}

int main(void)
{
    int return_value = 0;

    return_value = make_dinner(pizza);

    return return_value;
}
