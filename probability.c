#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description:
 * This program calculates the probability that a defective product was
 * produced by each of three machines (Machine A, Machine B, and Machine C)
 * in a milk product factory. The calculation is based on the probabilities
 * of defective products produced by each machine, the overall probabilities
 * of products produced by each machine, and the probabilities of each type
 * of product (cheese, yogurt, butter) being produced by each machine.
 *
 * Return:
 * Always 0 (Success)
 */
int main(void)
{
    double prob_machine_given_defective[3] = {0}; /*Probability of each machine given defective product*/
    double prob_defective_given_machine[3] = {0}; /*Probability of defective product given each machine*/
    double prob_machine[3] = {0}; /* Probability of each machine*/
    double prob_product_given_machine[3][3] = {0}; /* Probability of each product given each machine*/
    double total_prob_defective = 0; /*Total probability of defective product*/
    int i;

   /* Prompt the user to input probabilities*/
    printf("Enter the probability of defective products produced by Machine A: ");
    scanf("%lf", &prob_defective_given_machine[0]);

    printf("Enter the probability of defective products produced by Machine B: ");
    scanf("%lf", &prob_defective_given_machine[1]);

    printf("Enter the probability of defective products produced by Machine C: ");
    scanf("%lf", &prob_defective_given_machine[2]);

    printf("Enter the probability of products produced by Machine A: ");
    scanf("%lf", &prob_machine[0]);

    printf("Enter the probability of products produced by Machine B: ");
    scanf("%lf", &prob_machine[1]);

    printf("Enter the probability of products produced by Machine C: ");
    scanf("%lf", &prob_machine[2]);

    printf("Enter the probability of cheese being produced by Machine A: ");
    scanf("%lf", &prob_product_given_machine[0][0]);

    printf("Enter the probability of yogurt being produced by Machine A: ");
    scanf("%lf", &prob_product_given_machine[0][1]);

    printf("Enter the probability of butter being produced by Machine A: ");
    scanf("%lf", &prob_product_given_machine[0][2]);

    printf("Enter the probability of cheese being produced by Machine B: ");
    scanf("%lf", &prob_product_given_machine[1][0]);

    printf("Enter the probability of yogurt being produced by Machine B: ");
    scanf("%lf", &prob_product_given_machine[1][1]);

    printf("Enter the probability of butter being produced by Machine B: ");
    scanf("%lf", &prob_product_given_machine[1][2]);

    printf("Enter the probability of cheese being produced by Machine C: ");
    scanf("%lf", &prob_product_given_machine[2][0]);

    printf("Enter the probability of yogurt being produced by Machine C: ");
    scanf("%lf", &prob_product_given_machine[2][1]);

    printf("Enter the probability of butter being produced by Machine C: ");
    scanf("%lf", &prob_product_given_machine[2][2]);

    /* Calculate the total probability of defective products*/
    for (i = 0; i < 3; i++) {
        total_prob_defective += prob_machine[i] * prob_defective_given_machine[i];
    }

    /*Calculate the probability of each machine given defective product*/
    for (i = 0; i < 3; i++) {
        prob_machine_given_defective[i] = (prob_machine[i] * prob_defective_given_machine[i]) / total_prob_defective;
    }

    /* Print the results */
    printf("\nProbability that a defective product was produced by:\n");
    printf("Machine A: %.2f%%\n", prob_machine_given_defective[0] * 100);
    printf("Machine B: %.2f%%\n", prob_machine_given_defective[1] * 100);
    printf("Machine C: %.2f%%\n\n", prob_machine_given_defective[2] * 100);

    printf("Probability of cheese being produced:\n");
    for (i = 0; i < 3; i++) {
        printf("Machine %c: %.2f%%\n", 'A' + i, prob_product_given_machine[i][0] * 100);
    }

    printf("\nProbability of yogurt being produced:\n");
    for (i = 0; i < 3; i++) {
        printf("Machine %c: %.2f%%\n", 'A' + i, prob_product_given_machine[i][1] * 100);
    }

    printf("\nProbability of butter being produced:\n");
    for (i = 0; i < 3; i++) {
        printf("Machine %c: %.2f%%\n", 'A' + i, prob_product_given_machine[i][2] * 100);
    }

    return 0;
}
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
