#include "ft_printf.h"

char *ft_adjust_precision(char *number, int new_precision, struct flags *flags) {
	int to_skip = 0;
	int digits = 0;
	int zeros = 0;
	int i = 0;
	char *new_number;

	if (flags->space || flags->plus || number[0] == '-') {
		to_skip++;
	}

	if (flags->hash || flags->conversion == 'p') {
		to_skip += 2;
	}

	digits = ft_strlen(number + to_skip);
	if (digits < new_precision) {
		zeros = new_precision - digits;
		new_number = malloc(new_precision + to_skip + 1);
		ft_strlcpy(new_number, number, to_skip + 1);
		i = ft_strlen(new_number);
		while(zeros--) {
			new_number[i++] = '0';
		}
		new_number[i] = 0;
		ft_strlcat(new_number, number + to_skip, new_precision + to_skip + 1);

		free(number);
		return new_number;
	} else {
		return number;
	}
}
