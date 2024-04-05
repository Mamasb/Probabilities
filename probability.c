#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    /* Define probabilities */
    double prob_cheese_given_goat_milk = 0.0;  /* Probability of cheese made from goat's milk */
    double prob_cheese = 0.0;                   /* Probability of cheese */
    double prob_goat_milk = 0.0;                /* Probability of milk product being made from goat's milk */
    double prob_machine_given_defective[3];      /* Probability of a machine given that the component is defective */
         /* Probability of a component being defective given the machine */
    double prob_defective = 0.0;                 /* Probability of a defective component */
    double defect_rate[3];                       /* Defect rate for each machine */
	int i;
    
	
	/* Prompt the user to input probabilities */
    printf("Enter the probability of cheese made from goat's milk: ");
    scanf("%lf", &prob_cheese_given_goat_milk);

    printf("Enter the probability of cheese: ");
    scanf("%lf", &prob_cheese);

    printf("Enter the probability of milk product being made from goat's milk: ");
    scanf("%lf", &prob_goat_milk);

    /* Calculate the overall probability of a defective component */
    prob_defective = (prob_cheese_given_goat_milk * prob_goat_milk) + (prob_cheese * (1 - prob_goat_milk));

    /* Prompt the user to input defect rates for each machine */
    for ( i = 0; i < 3; i++) {
        printf("Enter the defect rate for Machine %c: ", 'A' + i);
        scanf("%lf", &defect_rate[i]);
    }

    /* Calculate the probability using Bayes' theorem */
    for ( i = 0; i < 3; i++) {
        prob_machine_given_defective[i] = defect_rate[i] * prob_cheese_given_goat_milk / prob_defective;
    }

    /* Print the result */
    printf("Probability that the defective component was produced by:\n");
    for ( i = 0; i < 3; i++) {
        printf("Machine %c: %.2f%%\n", 'A' + i, prob_machine_given_defective[i] * 100);
    }

    return 0;
}
