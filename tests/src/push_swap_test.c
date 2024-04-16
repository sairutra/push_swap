#include "../gnirut/inc/gnirut.h"

#define PSLOGFILE "../logs/ps_output.txt"

int main (int argc, char **argv, char **envp)
{
	int index;
	char ** test;
	index = 0;
	int count;
	count = 0;
	(void)argc;
	(void)argv;
	// char *array[150] = {"84","29","62","16","95","7","48","53","20","3","60","90","73","13","67","42","56","89","11","45","36","74","1","14","28","51","32","88","71","22","57","49","68","6","80","38","78","34","85","65","17","46","26","39","21","87","70","96","61","82","64","10","18","94","77","4","69","27","24","52","12","66","25","9","54","91","59","40","55","5","47","98","33","76","81","31","50","35","2","83","72","37","23","97","8","41","63","30","86","93","19","15","92","79","75","58","99","43","44","100","0"};
	char **array = char_array_of_int(10, 0, 9);
	test = get_stdout("../../bin/push_swap", array, envp);
	remove(PSLOGFILE);
	while(test[index] != NULL)
	{
		write_to_logf(test[index], PSLOGFILE, "a");
		count++;
		index++;
	}
	printf("amount of operations %d\n", count);
}
