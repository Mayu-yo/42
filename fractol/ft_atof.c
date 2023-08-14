#include "fractal.h"
#include <stdio.h>

double ft_atof(char *num){
	int minus_flag;
	size_t i;
	size_t j;
	double ret;

	minus_flag = 1;
	i = 0;
	j = 1;
	ret = 0;
	if (num[i] == '-'){
		minus_flag = -1;
		i++;
	}
	if (num[i] == '.'){
		printf("invalid input");
		exit(0);
	}
	while ('0' <= num[i] && num[i] <= '9')
	{
		ret = ret * 10 + num[i] - '0';
		i++;
	}
	if (num[i] == '.'){
		i++;
		while ('0' <= num[i] && num[i] <= '9')
		{
			ret = ret + ((num[i] - '0') * pow((0.1), j));
			i++;
			j++;
		}
	}
	return (ret * minus_flag);
}

// #include <stdio.h>
// int main (){
// 	double num;
// 	num = ft_atof("10.5345");
// 	printf("%f\n",num);
// 	// for (int i = 0; i < 10; i++){
// 	// 	num = pow((0.1), i);
// 	// 	printf("%f\n",num);
// 	// }
// 	return 0;
// }