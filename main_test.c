#include "philo.h"

pthread_mutex_t entry_point = PTHREAD_MUTEX_INITIALIZER;

	void* eat(void *args)
	{
	t_philosopher_args *arg = (t_philosopher_args *) args;
	const t_philospher *philosopher = arg->philosopher;
	const t_table *table = arg->table;
	unsigned randint;

	do
	{
		printf("%s started dinner\n", philosopher->name);

		pthread_mutex_lock(&entry_point);
		pthread_mutex_lock(&table->forks[philosopher->left_fork]);
//		randint = rand();
//		randint %= 1000;
//		printf("randint: %d\n", randint);
//		Sleep(randint);
		usleep(500000);
		pthread_mutex_lock(&table->forks[philosopher->right_fork]);
		printf("check\n");
		pthread_mutex_unlock(&entry_point);

		printf("%s is eating after %d ms sleep\n", philosopher->name, 1);
		pthread_mutex_unlock(&table->forks[philosopher->right_fork]);
		pthread_mutex_unlock(&table->forks[philosopher->left_fork]);

		printf("%s finished dinner\n", philosopher->name);
//		wait();
	} while (1);
	}


	int main()
	{
	pthread_t						threads[PHT_SIZE];
	t_philospher 					philosophers[PHT_SIZE];
	t_philosopher_args 				arguments[PHT_SIZE];
	t_table							table;
	size_t							i;
	int								n;

	init_table(&table);
	init_philosopher(&philosophers[0], "Alice", 0, 1);
	init_philosopher(&philosophers[1], "Bob", 1, 2);
	init_philosopher(&philosophers[2], "Clark", 2, 3);
	init_philosopher(&philosophers[3], "Denis", 3, 4);
	init_philosopher(&philosophers[4], "Eugin", 4, 0);

	for (i = 0; i < PHT_SIZE; i++) {
		arguments[i].philosopher = &philosophers[i];
		arguments[i].table = &table;
	}

	for (i = 0; i < PHT_SIZE; i++) {
		pthread_create(&threads[i], NULL, eat, &arguments[i]);
//		Sleep(i*500);
	}

	for (i = 0; i < PHT_SIZE; i++) {
		pthread_join(threads[i], NULL);
	}

//	n = 5000;
//	wait(&n);
//	wait();
	return 0;
}